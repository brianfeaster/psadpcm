function fft_freqs = enc_init_get_fft_frequencies(enc)
% ENC_INIT_GET_FFT_FREQUENCIES Get the frequencies of fft coefficients.
%
% Return the sinusoid frequencies (in Hertz) of the fft bins corresponding
% to our chosen sample rate and FFT length.


Fs = enc.Fs;
N = enc.fft_length;
fft_bins = (N/2)+1;
Omega = (2*pi)/N;
omegas = [];

% figure out the angular frequency each FFT bin refers to
for k = 0:(fft_bins-1)
    omegas = [omegas; k*Omega];
end

% convert that to Hertz
fft_freqs = [];
for k = 1:numel(omegas)
    fft_freqs = [fft_freqs; ((omegas(k)*Fs)/(2*pi))];
end

end