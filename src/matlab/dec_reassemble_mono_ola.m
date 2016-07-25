function s = dec_reassemble_mono_ola(enc, frames)
% DEC_REASSEMBLE_MONO_OLA Reassemble the mono signal using overlap-add.
%
%   This is for testing windowed OLA against a known result.
%
%   INPUTS
%   enc: an encoder struct
%   frames: an array of frame structs
%
%   OUTPUT
%   s: a mono PCM signal

s = [];
ola = 0;

% handle ADPCM if needed
if enc.adpcm == 1
    frames(1).s = double(ntd_adpcm_decode(frames(1).adpcm, frames(1).info)) ./ 32767;
end

for f = 1:numel(frames)-1
    
    % decode ADPCM
    if enc.adpcm == 1
        frames(f+1).s = double(ntd_adpcm_decode(frames(f+1).adpcm, frames(f+1).info)) ./ 32767;
    end
    
    % reassemble and window
    hop = size(frames(f).s,1);
    [x_s, w] = dec_reassemble_segment(enc, frames(f).s, frames(f+1).s);
    x_s = x_s .* w;
    
    % OLA, output
    [chunk, ola] = seg_overlap_add(ola, x_s, hop);
    s = [s; chunk];
    
end

s = [s; ola];

end
