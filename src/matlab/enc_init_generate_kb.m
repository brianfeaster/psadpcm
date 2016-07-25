function kb = enc_init_generate_kb(enc)
% ENC_INIT_GENERATE_KB Generate a lookup table for per-band FFT indices.
%   INPUT: enc struct which must include Fs, B, and fft_length.
%   OUTPUT: frequency subband indices.
%
% Stereo parameters are calculated for B subbands. kb[b] is the index for
% X[k] where the band b begins.  kb[b+1]-1 is the last X[k] included in band
% b.
%
% kb must have B+1 elements so that this addressing scheme will work.
%
% The subbands are oriented in an Equivalent Rectancular Bandwidth-like way.
% That is calculated here as well.

% get an array of the frequencies represented by our chosen FFT.
fft_freqs = enc_init_get_fft_frequencies(enc);

% compute the low cutoff frequencies for B+1 bands
bands = enc_init_get_erb_subbands(enc);

kb = [];
i_fft = 1;
for b = 1:numel(bands)
    % for each band b, we wish to find the index of the first
    % frequency in fft_freqs which is above bands(b) and record that index
    % in kb.
    
    bands(b) = erb_get_lower_cutoff(enc.ERB_coeff, bands(b));

    while i_fft <= numel(fft_freqs)
        if fft_freqs(i_fft) > bands(b)
            kb = [kb; i_fft];
            break;
        end
        i_fft = i_fft + 1;
    end
    
    % uncomment this to get a diagnostic message about where the bands are
    % fprintf('Band %d begins at X[%d] : %d\n', b, kb(b), fft_freqs(kb(b)));

end
end
