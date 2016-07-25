function [S, IID, IPD, IC, OPD] = seg_calculate_params(enc, X1, X2)
% SEG_CALCULATE_PARAMS Get downmix and stereo parameters.
%
%   INPUTS
%   enc: encoder struct
%   X1, X2: frequency-domain signals
%
%   OUTPUTS
%   S: mono signal in frequency-domain
%   IID, IPD, IC, OPD: vectors containing per-band stereo parameters
%   

% first get the downmix and complex conjugates
X1C = conj(X1);
X2C = conj(X2);

% allocations
IID = zeros(enc.B,1);
IPD = zeros(enc.B,1);
IC = zeros(enc.B,1);
OPD = zeros(enc.B,1);

% compute params per-band
for b = 1:enc.B
    % compute the summations that recur ...
    X1prod = param_get_summation(enc, X1, X1C, b);
    X2prod = param_get_summation(enc, X2, X2C, b);
    XXprod = param_get_summation(enc, X1, X2C, b);
    
    % and the parameters themselves
    IID(b) = 10 * log10( X1prod / X2prod );
    IC(b) = abs(XXprod) / sqrt( X1prod * X2prod );
    
    % calculate phase parameters for low frequencies only as per Breebaart
    if b < enc.hf_start_band
        IPD(b) = angle( XXprod );
    end
end

S = param_downmix_simple(X1, X2);
SC = conj(S);

% get OPD for low frequencies
for b = 1:(enc.hf_start_band-1)
    XSprod = param_get_summation(enc, X1, SC, b);
    OPD(b) = angle( XSprod );
end

end
