function ici = param_quantize_ic(ICi, ic)
% PARAM_QUANTIZE_IC Convert an ic value to a table index.
%
%   INPUTS
%   ICi: the table to quantize against
%   ic: the value to quantize

lastdiff = abs(ic - ICi(1));
for i = 2:8
    diff = abs(ic - ICi(i));
    if lastdiff < diff
        % we have overshot. done.
        ici = i-2; % we really want the last index, but -2 because of matlab being 1-indexed.
        return;
    end
    lastdiff = diff;
end
ici = 7;

end