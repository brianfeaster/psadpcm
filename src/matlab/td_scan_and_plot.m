function td_scan_and_plot(enc, x)
% TD_SCAN_AND_PLOT Transient detector visualization.
%
%   INPUTS
%   enc: encoder struct
%   x: signal
%
%   No outputs.

x_mono = td_simple_downmix(x);
indices = td_scan(enc, x_mono);

% generate a plot of the indices
trans_plot = zeros(numel(x_mono), 1);
for i = 1:numel(indices)
    trans_plot(indices(i)) = 1;
end

plot(horzcat(x,trans_plot));

end