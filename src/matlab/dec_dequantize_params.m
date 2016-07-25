function [iid, ipd, ic, opd] = dec_dequantize_params(enc, frame, b)
% DEC_DEQUANTIZE_PARAMS Get parameter values for a band in a frame.
%
%   INPUTS
%   enc: encoder struct (which contains the lookup tables)
%   frame: frame struct (which contains the per-band indexes)
%   b: which band we care about
%
%   OUTPUTS
%   parameter values

% the +1 is just for matlab's +1 indexing

iid = enc.IIDi(frame.IID(b)+1);
ipd = enc.IPDi(frame.IPD(b)+1);
ic = enc.ICi(frame.IC(b)+1);
opd = enc.OPDi(frame.OPD(b)+1);

end