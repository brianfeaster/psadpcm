function [seg_x, w] = dec_reassemble_segment(enc, s, next_s)
% DEC_REASSEMBLE_SEGMENT Get a segment and window function for two frames.
%
%   INPUTS
%   enc: encoder struct
%   s: mono signal for the current frame.
%   s: mono signal for the next frame.
%
%   OUTPUTS
%   seg_x: the segment's mono signal, not yet windowed because the decorr
%       filter comes next
%   w: the window which fits this segment


% if the previous segment was a transient, we generate a start window here.
% store that state here.
persistent previous_window_was_transient
if isempty(previous_window_was_transient)
    previous_window_was_transient = 0;
end

if size(s,1) == enc.seg_transient_window_half_length
    % transient segment.  need to snip out a bit of the next signal.
    seg_x = [s; next_s(1:enc.seg_transient_window_half_length)];
    w = enc.seg_transient_window;
    previous_window_was_transient = 1;
    return;
end

if size(next_s,1) == enc.seg_transient_window_half_length
    % stop window immediately preceding a transient
    seg_x = [s; next_s];
    w = window_generate_stop(enc, size(seg_x,1));
    return;
end

if previous_window_was_transient == 1
    % start window immediately following a transient
    seg_x = [s; next_s(1:enc.seg_normal_window_half_length)];
    w = window_generate_start(enc, size(seg_x,1));
    previous_window_was_transient = 0;
    return
end

% we got down here, so it's a normal window and so is at least the first
% part of the next one
seg_x = [s; next_s(1:enc.seg_normal_window_half_length)];
w = enc.seg_normal_window;

end
