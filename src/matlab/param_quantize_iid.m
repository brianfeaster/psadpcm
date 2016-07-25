function iidi = param_quantize_iid(IIDi, iid)
% PARAM_QUANTIZE_IID Convert an iid value to a table index.
%
% INPUTS
%   IIDi: the lookup table to quantize against
%   iid: the value to quantize
%

lastdiff = abs(iid - IIDi(1));
for i = 2:31
    diff = abs(iid - IIDi(i));
    if lastdiff < diff
        % we have overshot. done.
        iidi = i-2; % we really want the last index, but -2 because of matlab being 1-indexed.
        return;
    end
    lastdiff = diff;
end
iidi = 30;

end





