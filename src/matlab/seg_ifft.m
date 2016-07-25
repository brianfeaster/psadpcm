function x = seg_ifft(X, x_length, fft_length)
% SEG_IFFT Convert frequency-domain to time-domain.
%
%   INPUTS
%   X: frequency-domain signal
%   x_length: the length of the resulting time-domain signal
%   fft_length: how long of an FFT was done to get us here
%
%   OUTPUT
%   x: resulting time-domain signal.

channels = size(X,2);

% allocate
x = zeros(fft_length,channels);

% inverse FFT
for i = 1:channels
    x(:,i) = ifft(X(:,i), fft_length, 'symmetric');
end

% chop off the end
x = x(1:x_length, :);

end