function ipdi = param_quantize_ipd(ipd)
% PARAM_QUANTIZE_IPD Convert an ipd value to a table index.
%

ipdi = mod( floor( (4*ipd/pi) + 0.5 ), 8 );

end