function pitch = ac_pitch(samples)

LAG_MIN = 6;
LAG_MAX = 100;
SAMPLE_RATE = 8000;

best_r = 0;
best_lag = -1;

for lag = LAG_MIN:LAG_MAX+1
    %r = autocorr(samples, lag)/length(samples);
    ac=0;
    for i=1:1:(length(samples)-lag)
       ac = ac + samples(i)*samples(i+lag); 
    end
    r = ac/length(samples);
    if r > best_r
        best_r = r;
        best_lag = lag;
    end
    
    if r > 0.9
        break
    end
end

pitch = SAMPLE_RATE / best_lag;
end