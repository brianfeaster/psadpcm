function fc = erb_get_band_center(E,f_low)
% ERB_GET_BAND_CENTER Get the center frequency of an ERB band
%
%   INPUTS
%   E: the standard value for this is 24.7
%   f_low: the low-cutoff frequency of the band

F0Coeff = 0.5 * E * 0.00437;
fc = (f_low + (E / 2)) / (1 - F0Coeff);
end

