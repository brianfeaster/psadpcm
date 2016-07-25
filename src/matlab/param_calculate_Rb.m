function R = param_calculate_Rb(iid, ipd, ic, opd)
% PARAM_CALCULATE_RB Get a spatializing matrix from full parameters.
%
%   INPUTS
%   iid: interchannel intensity difference
%   ipd: interchannel phase difference
%   ic: interchannel coherence
%   opd: overall phase difference
%
%   OUTPUTS
%   R: a 2x2 matrix for reconstituting a stereo signal

% get c and mu
c = 10^(iid / 20);
mu = 1 + ((4*(ic^2) - 4)/((c + (1/c))^2));

% get gamma and alpha
root_mu = sqrt(mu);
gamma = atan(sqrt((1 - root_mu)/(1 + root_mu)));

if (ic == 0) && (c == 1)
    alpha = 0.25*pi;
else
    alpha = mod(0.5*atan((2*c*ic)/((c^2)-1)),0.5*pi);
end

% get P, A, and V
P = [exp(1i*opd) 0; 0 exp(1i*(opd - ipd))];
cos_alpha = cos(alpha);
sin_alpha = sin(alpha);
A = [cos_alpha -sin_alpha; sin_alpha cos_alpha];
V = [cos(gamma) 0; 0 sin(gamma)];

% finally get R
R = sqrt(2)*P*A*V;

end