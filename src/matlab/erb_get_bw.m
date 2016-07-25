function bw = erb_get_bw(E,fc)
% ERB_GET_BW Get the bandwidth of an ERB band.
%
%   INPUTS
%   E: The standard value for this is 24.7
%   fc: the center frequency in Hertz

bw = E * ((0.00437*fc) + 1);
end

