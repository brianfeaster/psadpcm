#include <stdio.h>
#include <stdlib.h>
#include "common.h"

// TODO pad the samples by enc.seg_normal_window_length,channels for and aft!
/*
   x_length    the sample count including the padding (for now)
   in          array of channel samples
   out         array of processed channel samples
*/
void ps_encode(Enc *enc, s32 channels, s32 x_length, f64 *in[], f64 *out[]) {
    // Need to padd enc.seg_normal_window_length before and after (1024*2)
    s32 pos = 0;
    s32 ola_leftover = 0;

    return;
}


/*
function frames = ps_encode(enc, x)
% PS_ENCODE Encode a stereo signal into mono + stereo parameters.
%
%   INPUTS
%   enc: encoder struct
%   x: stereo signal arranged into two column vectors.
%
%   OUTPUT
%   frames: an array of frames, each containing parameters and a mono
%       downmix.
% Pad the signal so the first window doesn't apply a fade-in to the sound
% Basic setup


% this is the actual output
frames = [];

% go
while true
    
    % get a segment and a hop size
    [seg.x, hop] = seg_get_next_segment(enc, x(x_pos:end,:));
    seg_length = size(seg.x,1);
    
    % transform to frequency domain
    seg.X = seg_fft(seg.x, enc.fft_length);
    
    % get parameterization
    [seg.S, frame.IID, frame.IPD, frame.IC, frame.OPD] = seg_calculate_params(enc, seg.X(:,1), seg.X(:,2));
    
    % quantize those
    for b = 1:enc.B
        frame.IID(b) = param_quantize_iid(enc.IIDi, frame.IID(b));
        frame.IPD(b) = param_quantize_ipd(frame.IPD(b));
        frame.IC(b) = param_quantize_ic(enc.ICi, frame.IC(b));
        frame.OPD(b) = param_quantize_opd(frame.OPD(b));
    end
    
    % get the mono signal back into time domain.
    seg.s = seg_ifft(seg.S, seg_length, enc.fft_length);
    
    % assemble a frame! this is what will actually be bitstream'd.
    [seg.s, ola_leftover] = seg_overlap_add(ola_leftover, seg.s, hop);
    
    % adpcm, if the flag indicates it
    if enc.adpcm == 1
        [frame.adpcm, frame.info] = ntd_adpcm_encode(int16(32767*seg.s), enc.Fs);
    else
        frame.s = seg.s;
    end
    frames = [frames frame];
    
    % advance x_pos.  if x_pos is past the end, we're done.
    x_pos = x_pos + hop;
    if x_pos > x_length
        break;
    end
    
end

end

*/
