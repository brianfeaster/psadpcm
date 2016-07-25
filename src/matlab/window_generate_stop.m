function [w, hop] = window_generate_stop(enc, length)
% WINDOW_GENERATE_STOP Generate a stop window to precede a transient.
%
%   INPUTS
%   enc: encoder struct
%   length: how long of a window we want
%
%   OUTPUTS
%   w: a window which opens normally and closes quickly.
%   hop: the index adjustment to get to the beginning of the next window.

hop = length - enc.seg_transient_window_half_length;

w = ones(length,1);
w(1:enc.seg_normal_window_half_length) = enc.seg_normal_window(1:enc.seg_normal_window_half_length);
w((end-enc.seg_transient_window_half_length)+1:end) = enc.seg_transient_window((end-enc.seg_transient_window_half_length)+1:end);

end