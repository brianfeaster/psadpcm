function [w, hop] = window_generate_start(enc, length)
% WINDOW_GENERATE_START Generate a start window for after a transient.
%
%   INPUTS
%   enc: encoder struct
%   length: sample-length of the window we want.
%
%   OUTPUTS
%   w: a window which opens like a transient window and closes like a
%       normal one.
%   hop: the index-adjustment to get to the place where the next window
%       should begin.

hop = length - enc.seg_normal_window_half_length;

w = ones(length, 1);
w(1:enc.seg_transient_window_half_length) = enc.seg_transient_window(1:enc.seg_transient_window_half_length);
w((end-enc.seg_normal_window_half_length)+1:end) = enc.seg_normal_window((end-enc.seg_normal_window_half_length)+1:end);

end