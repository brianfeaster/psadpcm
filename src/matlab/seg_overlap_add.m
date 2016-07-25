function [x_output, new_leftover] = seg_overlap_add(leftover, x_new, x_hop)
% SEG_OVERLAP_ADD Reconstruct a signal from windowed segments.
%
%   INPUTS
%   leftover: whatever was left over from the last OLA operation.
%   x_new: the new segment to be added
%   x_hop: the segmenting hop of the new segment
%
%   OUTPUTS
%   x_output: resulting finished signal
%   new_leftover: unfinished signal leftover beyond the hop size.
%

leftover_length = size(leftover,1);
x_new(1:leftover_length,:) = x_new(1:leftover_length,:) + leftover;
x_output = x_new(1:x_hop,:);
new_leftover = x_new(1+x_hop:end,:);

end