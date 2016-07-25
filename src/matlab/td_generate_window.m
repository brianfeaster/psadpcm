function [w, hop] = td_generate_window(enc, x)
% TD_GENERATE_WINDOW Analyze for transients and generate a window function.
%
%   Returns a short window if there's a transient coming up in x.
%
%   INPUTS
%   enc: encoder struct
%   x: signal
%
%   OUTPUTS
%   w: the window function appropriate to the signal
%   hop: the hop size of the segment you'll get by applying w to x

% windowing logic depends on what type of window we're expecting to make.
persistent windower_state;
if isempty(windower_state)
    windower_state = td_windower_state.normal;
end

% if there's been a transient, the start window trailing it needs to know
% how long the stop window was.
persistent stop_window_length;
if isempty(stop_window_length)
    stop_window_length = 0;
end

switch windower_state
        
    case td_windower_state.normal
        % if we're at the end, generate the last window.  caller will pad
        % the signal.
        if size(x,1) < enc.td_signal_test_length
            w = enc.seg_normal_window;  % Array of 2048 values
            hop = enc.hop_size;         % 1024
            clear windower_state;
            return;
        end
        
        % look ahead for transients
        trans_index = td_scan_normal_region(enc, x);
        if trans_index == 0
            % no transients concern us.  normal window.
            w = enc.seg_normal_window;
            hop = enc.hop_size;
            return;
        end
        
        % we didn't return just now, so there's a transient coming up.
        % we must generate a stop window.
        [w, hop] = window_generate_stop(enc, trans_index);
        stop_window_length = trans_index;
        windower_state = td_windower_state.transient;
        return;
        
    case td_windower_state.transient
        % a transient was detected in the prior scan.  we want a short
        % window.
        w = enc.seg_transient_window;
        hop = enc.seg_transient_window_half_length;
        windower_state = td_windower_state.start;
        return;
        
    case td_windower_state.start
        % we must get back on the grid after a transient, so we need to
        % generate a start window of appropriate length.
        length = (2 * enc.seg_normal_window_length) - stop_window_length;
        [w, hop] = window_generate_start(enc, length);
        windower_state = td_windower_state.normal;
        return
        
    otherwise
        fprintf('ERROR: td_generate_window: we should not be here\n');
end

end
