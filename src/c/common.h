#ifndef _COMMON_H
#define _COMMON_H

typedef unsigned int       u32;
typedef signed int         s32;
typedef unsigned long long u64;
typedef signed long long   s64;
typedef float              f32;
typedef double             f64;
typedef unsigned char     bool;

#define true  1
#define false 0

typedef struct {
    s32  Fs;
    s32  hop_size;
    s32  td_power_interval;
    f64  td_threshold;
    s32  fft_length;
    s32  B;
    s32  hf_start_band;
    f64  band_0_low_cutoff;
    f64  ERB_coeff;
    s32  Ns;
    bool adpcm;
    s32  seg_normal_window_length;
    s32  seg_normal_window_half_length;
    f64 *seg_normal_window;
    s32  seg_transient_window_length;
    s32  seg_transient_window_half_length;
    f64 *seg_transient_window;
    s32  td_signal_test_length;
    struct {
        s32 crit_start;
        s32 crit_stop;
        s32 scan_start;
        s32 scan_stop;
    } td_scan_zone;
    s32 *kb;
    s32 *IIDi;
    f64 *IPDi;
    f64 *ICi;
    f64 *OPDi;
    f64 *hd;
} Enc;

void ps_init (Enc *enc, s32 _Fs, bool _adpcm_flag);

#endif
