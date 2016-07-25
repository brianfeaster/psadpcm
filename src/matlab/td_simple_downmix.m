function x_mono = td_simple_downmix(x)
% TD_SIMPLE_DOWNMIX A really basic downmix for the transient detector
%
%   INPUTS
%   x: multichannel signal
%
%   OUTPUTS
%   x_mono: all the channels averaged

channels = size(x,2);
length = size(x,1);

if channels == 1
    x_mono = x;
    return;
end

weight = 1 / channels;
x_mono = zeros(length, 1);

for c = 1:channels
    x_mono = x_mono + x(:,c);
end

x_mono = weight * x_mono;

end

