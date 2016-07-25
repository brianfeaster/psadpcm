function Ra = param_calculate_Ra(iid, ic)
% PARAM_CALCULATE_RA Get a spatializing matrix without phase info.
%
%   INPUT
%   iid: interchannel intensity difference
%   ic: interchannel coherence
%
%   OUTPUT
%   Ra: a 2x2 matrix for computing stereo signals in frequency domain

c = 10^(iid / 20);
csquared = c^2;

c1 = sqrt((2*csquared)/(1+csquared));
c2 = sqrt(2/(1+csquared));

mu = 0.5 * acos(ic);

v = (mu*(c2-c1))/sqrt(2);

Ra = [c1*cos(v+mu) c1*sin(v+mu); c2*cos(v-mu) c2*sin(v-mu)];

end