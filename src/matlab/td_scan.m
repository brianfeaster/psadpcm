function indices = td_scan(enc, x)
% TD_SCAN Transient detector.
%
%   INPUTS
%   enc: encoder struct
%   x: signal
%
%   OUTPUTS
%   indices: a vector of sample indices where transients were detected.

bdf = backward_difference;
bdf.reset();

indices = [];

% move the window along and calculate change of power.
for i = 1:enc.td_power_interval:numel(x)
    % get a window (make sure it doesn't overflow the end of the signal)
    if numel(x) >= (i + enc.td_power_interval - 1)
        window = x(i:i+enc.td_power_interval-1);
    else
        window = x(i:numel(x));
    end
    
    % measure power, part 1
    localPowerChange = sum(window.*window) / numel(window);
    
    % scale & diff against the last window's power
    localPowerChange = 100 * bdf.filter(localPowerChange);
    
    if localPowerChange > enc.td_threshold
        indices = [indices;i];
    end
end

end