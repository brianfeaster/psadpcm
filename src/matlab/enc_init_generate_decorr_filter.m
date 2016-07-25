function hd = enc_init_generate_decorr_filter(Ns)
% ENC_INIT_GENERATE_DECORR_FILTER Get the impulse response for a
%   decorrelation filter of length Ns.

hd = zeros(Ns,1);

for n = 0:(Ns - 1)
    Sum = 0;
    for k = 0:(Ns / 2)
        Sum = Sum + cos( (2*pi*k*n/Ns) + (2*pi*k*(k-1)) );
    end
    hd(n+1,1) = Sum * 2 / Ns;
end

end
