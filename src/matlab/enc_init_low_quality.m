function enc = enc_init_low_quality( Fs )
% ENC_INIT Create an enc struct for sample rate Fs, low quality presets.
%
%   Low quality: 20 subbands and no phase information is used.

% Standard windowing hop size.  Also the parameter update interval.
enc.hop_size = 1024;

% Transient detector power measurement interval
enc.td_power_interval = 128;

% Transient detection threshold
enc.td_threshold = 1.3;

% FFT Length.  4096 works for 44.1 kHz.
enc.fft_length = 4096;

% Number of frequency bands used for parameter calculations.
enc.B = 20;
%enc.B = 64;

% the width of the bands is calculated using BW = ERB_coeff*(0.00437*f+1)
enc.ERB_coeff = 50.2;
%enc.ERB_coeff = 15.5;

% High-frequency start band.  Phase information is not transmitted for high
% frequencies.
enc.hf_start_band = 11;

% Where the first ERB band should begin
enc.band_0_low_cutoff = 29.7;



% decorrelation filter length
enc.Ns = 640;

%
% Now compute things it's nice to already have computed.
%

% sample rate
enc.Fs = Fs;

% normal segmenting window
enc.seg_normal_window_length = enc.hop_size*2;
enc.seg_normal_window_half_length = enc.seg_normal_window_length / 2;
enc.seg_normal_window = hann(enc.seg_normal_window_length,'periodic');

% transient segmenting window
enc.seg_transient_window_length = 128;
enc.seg_transient_window_half_length = enc.seg_transient_window_length / 2;
enc.seg_transient_window = hann(enc.seg_transient_window_length,'periodic');

% the length of signal the transient detector requires to do a scan
enc.td_signal_test_length = enc.seg_normal_window_length + enc.seg_transient_window_half_length + enc.td_power_interval;

% the region of signal we're interested in for normal lookahead scans
enc.td_scan_zone.crit_start = (enc.seg_normal_window_length + enc.seg_transient_window_length) / 2;
enc.td_scan_zone.crit_stop = enc.td_scan_zone.crit_start + (enc.seg_normal_window_length / 2);
enc.td_scan_zone.scan_start = enc.td_scan_zone.crit_start - enc.td_power_interval;
enc.td_scan_zone.scan_stop = enc.td_scan_zone.crit_stop + enc.td_power_interval;

% parameterization bands and quantize tables
enc.kb = enc_init_generate_kb(enc);
enc.IIDi = param_get_iid_table();
enc.IPDi = param_get_ipd_table();
enc.ICi = param_get_ic_table();
enc.OPDi = param_get_opd_table();

% decorrelation filter for the decoder
enc.hd = enc_init_generate_decorr_filter(enc.Ns);

end


function IIDi = param_get_iid_table()
IIDi = [-50;-45;-40;-35;-30;-25;-22;-19;-16;-13;-10;-8;-6;-4;-2;0;2;4;6;8;10;13;16;19;22;25;30;35;40;45;50];
end

function IPDi = param_get_ipd_table()
IPDi = [0; pi/4; 2*pi/4; 3*pi/4; pi; 5*pi/4; 6*pi/4; 7*pi/4];
end

function ICi = param_get_ic_table()
ICi = [1; 0.937; 0.84118; 0.60092; 0.36764; 0; -0.589; -1];
end

function OPDi = param_get_opd_table()
OPDi = [0; pi/4; 2*pi/4; 3*pi/4; pi; 5*pi/4; 6*pi/4; 7*pi/4];
end

