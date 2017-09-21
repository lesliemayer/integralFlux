pro make_all_plots

;Store a structure of type param into variable params. Define the values  
;of all fields. 
params = REPLICATE({param, inst:'GOES', startdate:' ', stopdate:' ',  $
                           goesCalcFile:' ', goesFile:' ', outpng:' ', $
                           ymin:.001, ymax:1000., year:2000} , 8)

params[0].inst = 'GOES10'
params[0].startdate = '2004-07-25 00:00:00.000'
params[0].stopdate =  '2004-07-29 23:55:00.000'
params[0].goesCalcFile = '2004_07_25_GOES10_proxy_L2_INT.dat'
params[0].goesFile = 'GOES10IF_Jul20_31_2004.format.dat'
params[0].ymin = .01
params[0].ymax = 10.^6
params[0].outpng = '2004_07_25_GOES10_proxy_L2_INT.png'

params[1].inst = 'GOES11'
params[1].startdate = '2004-07-25 00:00:00.000'
params[1].stopdate =  '2004-07-29 23:55:00.000'
params[1].goesCalcFile = '2004_07_25_GOES11_proxy_L2_INT.dat'
params[1].goesFile = 'GOES11IF_Jul20_31_2004.format.dat'
params[1].ymin = .01
params[1].ymax = 10.^6
params[1].outpng = '2004_07_25_GOES11_proxy_L2_INT.png'


params[2].inst = 'GOES08'
params[2].startdate = '2001-11-22 00:00:00.000'
params[2].stopdate =  '2001-11-29 23:55:00.000'
params[2].goesCalcFile = '2001_11_22_GOES08_proxy_L2_INT.dat'
params[2].goesFile = 'GOES8IF_Nov20_30_2001.format.dat'
params[2].ymin = .01
params[2].ymax = 10.^6
params[2].outpng = '2001_11_22_GOES08_proxy_L2_INT.png'


params[3].inst = 'GOES10'
params[3].startdate = '2001-11-22 00:00:00.000'
params[3].stopdate =  '2001-11-29 23:55:00.000'
params[3].goesCalcFile = '2001_11_22_GOES10_proxy_L2_INT.dat'
params[3].goesFile = 'GOES10IF_Nov20_30_2001.format.dat'
params[3].ymin = .01
params[3].ymax = 10.^6
params[3].outpng = '2001_11_22_GOES10_proxy_L2_INT.png'

params[4].inst = 'GOES08'
params[4].startdate = '2001-09-24 00:00:00.000'
params[4].stopdate =  '2001-10-02 23:55:00.000'
params[4].goesCalcFile = '2001_09_24_GOES08_proxy_L2_INT.dat'
params[4].goesFile = 'GOES8IF_Sep20_Oct2_2001.format.dat'
params[4].ymin = .01
params[4].ymax = 10.^6
params[4].outpng = '2001_09_24_GOES08_proxy_L2_INT.png'


params[5].inst = 'GOES10'
params[5].startdate = '2001-09-24 00:00:00.000'
params[5].stopdate =  '2001-10-02 23:55:00.000'
params[5].goesCalcFile = '2001_09_24_GOES10_proxy_L2_INT.dat'
params[5].goesFile = 'GOES10IF_Sep20_Oct2_2001.format.dat'
params[5].ymin = .01
params[5].ymax = 10.^6
params[5].outpng = '2001_09_24_GOES10_proxy_L2_INT.png'


params[6].inst = 'GOES10'
params[6].startdate = '2006-12-03 00:00:00.000'
params[6].stopdate =  '2006-12-08 23:55:00.000'
params[6].goesCalcFile = '2006_12_03_GOES10_proxy_L2_INT.dat'
params[6].goesFile = 'GOES10IF_Dec1_31_2006.format.dat'
params[6].ymin = .01
params[6].ymax = 10.^6
params[6].outpng = '2006_12_03_GOES10_proxy_L2_INT.png'
 
params[7].inst = 'GOES11'
params[7].startdate = '2006-12-03 00:00:00.000'
params[7].stopdate =  '2006-12-08 23:55:00.000'
params[7].goesCalcFile = '2006_12_03_GOES11_proxy_L2_INT.dat'
params[7].goesFile = 'GOES11IF_Dec01_30_2006.format.dat'
params[7].ymin = .01
params[7].ymax = 10.^6
params[7].outpng = '2006_12_03_GOES11_proxy_L2_INT.png'

; This is if we want RMS error written out to a file
;outdir = '../DATA/DIAGNOSTICS/PLOTS/'
;openw, rmsunit, outdir + 'RMS.dat', /get_lun
;printf, rmsunit, 'RMS error for GOESI-M VS GOESR'

for i = 0, 7 do begin

    plot_allintflux_timeseries, params[i], rmsunit

endfor

params[0].inst = 'GOES10'
params[0].startdate = '2006-12-03 00:00:00.000'
params[0].stopdate =  '2006-12-08 23:55:00.000'
params[0].goesCalcFile = '2006_12_03_GOES10_proxy_L2_DIFF.dat'
params[0].goesFile = 'GOES10DF_Dec1_31_2006.format.dat'
params[0].ymin = 10.^(-3)
params[0].ymax = 10.^4
params[0].outpng = '2006_12_03_GOES10_proxy_L2_DIFF.png'
plot_alldiffflux_timeseries, params[0], rmsunit


params[1].inst = 'GOES11'
params[1].startdate = '2006-12-03 00:00:00.000'
params[1].stopdate =  '2006-12-08 23:55:00.000'
params[1].goesCalcFile = '2006_12_03_GOES11_proxy_L2_DIFF.dat'
params[1].goesFile = 'GOES11DF_Dec1_31_2006.format.dat'
params[1].ymin = 10.^(-3)
params[1].ymax = 10.^4
params[1].outpng = '2006_12_03_GOES11_proxy_L2_DIFF.png'
plot_alldiffflux_timeseries, params[1], rmsunit

for i = 0, 1 do begin

    plot_alldiffflux_timeseries, params[i], rmsunit

endfor

;close, rmsunit



end
