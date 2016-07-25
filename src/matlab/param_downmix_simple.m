function S = param_downmix_simple(X1, X2)
% PARAM_DOWNMIX_SIMPLE Get the average values between two channels.
%
%   This is just simple averaging.  It doesn't maintain power.

S = 0.5 * (X1 + X2);
end