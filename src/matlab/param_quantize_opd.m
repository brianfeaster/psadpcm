function opdi = param_quantize_opd(opd)
% PARAM_QUANTIZE_OPD Convert an opd value to a table index.

opdi = mod( floor( (4*opd/pi) + 0.5 ), 8 );

end