function X = seg_fft(x, fft_length)
% SEG_FFT Convert a windowed segment to frequency domain
%
%   INPUTS
%   x: A time-domain signal.  Hopefully windowed and real-valued.
%   fft_length: see 'help fft'.
%
%   OUTPUT
%   X: frequency domain signal.  (fft_length/2)+1 values.

channels = size(x,2);

% allocate
unique_points = (fft_length / 2) + 1;
X = zeros(fft_length, channels);

% FFT per-channel
for i = 1:channels
    X(:,i) = fft(x(:,i), fft_length);
end

% Hopefully x was real-valued so we can discard conjugate symmetric values
X = X(1:unique_points, :);

end