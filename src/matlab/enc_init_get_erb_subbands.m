function bands = enc_init_get_erb_subbands(enc)
% ENC_INIT_GET_ERB_SUBBANDS Calculate frequency bands used in analysis.
%
% Compute band cutoffs for enc.B subbands used in frequency analysis.
% Returns B+1 elements. B are lower bounds, the last one is the upper of
% the final band.

f_lowest_cutoff = enc.band_0_low_cutoff;
B = enc.B;
E = enc.ERB_coeff;

f_lowest_center = erb_get_band_center(E,f_lowest_cutoff);

frequencies = f_lowest_center;

for i=2:B
    frequencies = [frequencies;erb_get_next_band(E,frequencies(i-1))];
end

bands = erb_get_lower_cutoff(E,frequencies);
bands = [bands;erb_get_upper_cutoff(E,frequencies(B))];

end
