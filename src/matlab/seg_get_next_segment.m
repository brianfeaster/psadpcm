function [y, hop] = seg_get_next_segment(enc, x)
% SEG_GET_NEXT_SEGMENT Adaptive segment/windowing.
%
%   INPUT
%   enc: encoder struct
%   x: signal in time domain
%
%   OUTPUT
%   y: resulting signal, windowed for analysis
%   hop: the hop size to where the next segment should start.

% get a window
[w, hop] = td_generate_window(enc, x);

% apply it per-channel, pad x if needed
channels = size(x,2);
x_length = size(x,1);
w_length = numel(w);
if x_length < w_length
    x = [x;zeros(w_length - x_length,channels)];
end
y = zeros(w_length, channels);

for c = 1:channels
    y(:,c) = x(1:w_length,c) .* w;

end

end