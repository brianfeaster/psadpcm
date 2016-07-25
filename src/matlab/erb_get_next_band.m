function fc_next = erb_get_next_band(E,fc)
% ERB_GET_NEXT_BAND Get the center of the adjacent higher ERB band.
%
%   INPUTS
%   E: The standard value is 24.7
%   fc: The center frequency of the known band.

F0Coeff = 0.5 * E * 0.00437;
fc_next = (((1 + F0Coeff) * fc) + E) / (1 - F0Coeff);
end