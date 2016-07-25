function f_low = erb_get_lower_cutoff(E,fc)
% ERB_GET_LOWER_CUTOFF Get the low cutoff frequency an ERB band.
%
%   INPUTS
%   E: The standard value is 24.7.
%   fc: The center frequency of the band.

bw = erb_get_bw(E,fc);
f_low = fc - (bw / 2);
end