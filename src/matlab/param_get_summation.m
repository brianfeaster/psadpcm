function T = param_get_summation(enc,X1,X2,b)
% PARAM_GET_SUMMATION Intermediate parameter calculation.
%
%   See Breebaart, et al.  "parameter extraction"
%
%   INPUTS
%   enc: encoder struct
%   X1: First signal (frequency domain)
%   X2: Second signal (frequency domain)
%   b: which band we're computing for.
%
%   OUTPUT
%   T: Sum of signal products for indices within the band b.

T = 0;
start_index = enc.kb(b);
stop_index = enc.kb(b+1)-1;

for k = start_index:stop_index
    T = T + (X1(k) * X2(k));
end

end