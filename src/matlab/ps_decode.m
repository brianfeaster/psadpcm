function output = ps_decode(enc, frames)
% PS_DECODE Decode parametric stereo frames into a PCM signal.
%
%   INPUTS
%   enc: the encoder struct
%   frames: an array of PS-encoded frames
%
%   OUTPUT
%   output = a two-channel floating point PCM stream


% allocate stuff
ola_leftover = 0;
Y = zeros((enc.fft_length/2) + 1, 2);
output = [];

frame_count = numel(frames);

if enc.adpcm == 1
    frames(1).s = double(ntd_adpcm_decode(frames(1).adpcm, frames(1).info)) ./ 32767;
end

for i = 1:frame_count-1;
    
    % decode ADPCM
    if enc.adpcm == 1
        frames(i+1).s = double(ntd_adpcm_decode(frames(i+1).adpcm, frames(i+1).info)) ./ 32767;
    end
    
    % get a segment and hop size
    hop = length(frames(i).s);
    [s, w] = dec_reassemble_segment(enc, frames(i).s, frames(i+1).s);
    w_length = length(w);
    
    % decorrelate, window and transform
    sd = conv(s, enc.hd, 'same');
    s = s .* w;
    sd = sd .* w;
    S = seg_fft(s, enc.fft_length);
    SD = seg_fft(sd, enc.fft_length);
    
    % per band, we must:
    for b = 1:enc.B
        % retrieve parameterization
        [iid, ipd, ic, opd] = dec_dequantize_params(enc, frames(i), b);
        
        % generate R
        if b <= 17
            R = param_calculate_Rb(iid, ipd, ic, opd);
        else
            R = param_calculate_Ra(iid, ic);
        end
        
        % go through band b's range of k-values, as we have them in enc.kb
        k_start = enc.kb(b);
        k_stop = enc.kb(b+1)-1;
        for k = k_start:k_stop
            % Linear combination using R to get Y(k)
            Y(k,1) = R(1,1)*S(k) + R(1,2)*SD(k);
            Y(k,2) = R(2,1)*S(k) + R(2,2)*SD(k);
        end
    end
    
    % transform to time-domain windowed signal
    y = seg_ifft(Y, w_length, enc.fft_length);
    
    % overlap-add to get the final stream
    [chunk, ola_leftover] = seg_overlap_add(ola_leftover, y, hop);
    output = [output; chunk];
    
    
end

% add the last bit
output = [output; ola_leftover];

% remove the padding which was added at encode time
pad_length = enc.seg_normal_window_length;
output = output(1+pad_length:end-pad_length, :);

end
