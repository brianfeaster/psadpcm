function transient_index = td_scan_normal_region(enc, x)
% TD_SCAN_NORMAL_REGION Scan a specific region of a signal for transients.
%
%   INPUT
%   enc: encoder struct
%   x: signal
%
%   OUTPUT
%   transient_index: the position of the earliest transient detected, or 0
%       if none were found

% pick out the region we want to scan, downmix it.
x_scan_material = td_simple_downmix(x(enc.td_scan_zone.scan_start:enc.td_scan_zone.scan_stop,:));

% now the actual scan
indices = td_scan(enc, x_scan_material);

% now convert "scan zone" indices to "full signal" indices
indices = indices + enc.td_scan_zone.scan_start;

% check each index for the first one in our critical zone.
for i = 1:numel(indices)
    
    if (indices(i) >= enc.td_scan_zone.crit_start) && (indices(i) <= enc.td_scan_zone.crit_stop)
        % it's a hit!
        transient_index = indices(i);
        return;
    end
    
end

transient_index = 0;

end