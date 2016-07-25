function f_high = erb_get_upper_cutoff(E,fc)
% ERB_GET_UPPER_CUTOFF Get the upper cutoff frequency of an ERB band.
%
%   INPUTS
%   E: The standard value is 24.7
%   fc: The band's center frequency

bw = erb_get_bw(E,fc);
f_high = fc + (bw / 2);
end

