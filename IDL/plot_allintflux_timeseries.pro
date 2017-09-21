
pro plot_allintflux_timeseries, parameter, rmsunit
;=====================================================================
; IDL code to read in GOES observed integral flux data, and GOES 
; calculated integral flux data (or GOESR calculated integral flux data)
; and plot time series of *all* integral flux value
;
; to run:  
; idl> plot_allintflux_timeseries
; 
; Written Feb 11, 2009 Leslie Mayer
;
; CHECK start_date, stop_date, and output filenames, input filenames
;        start_day, stop_day - used for output file name
; b/f running
; and ymin, ymax
; 
; check input/output directories
; check inst
; check PLOT TITLE *******
;====================================================================
; NO GOES 10 data b/t these dates**************
;date = 2006-12-05 21:15:00.000
;date = 2006-12-06 00:25:00.000
;*************************************
;###################################
; plot title
titlename = " : " + parameter.inst + " vs GOESR"



;---------------------------------------------------
; for integral flux calculations from goes data
;---------------------------------------------------
outdir = '../DATA/DIAGNOSTICS/PLOTS/'
print,'outdir = ',outdir

;---------------------------------------
; GOESR alg. calculated integral flux
;---------------------------------------
indir = '../DATA/DIAGNOSTICS/OUTPUT/'

;goesCalcfile = indir + '2004_07_25_GOES10_proxy_L2_INT.dat'
goesCalcfile = indir + parameter.goesCalcFile

print,'goesCalcfile = ',goesCalcfile

;-----------------------------------------------------------------------
; Integral Flux Data from GOES database
; (leave this alone) !!!!!!!!!!!!!!!!
;------------------------------------------------------------------------
checkdir = '../DATA/ORIGINALGOES/'
;goesfile = '/d2/data2/' + check_inst + '/' + check_inst + 'IF_' + strdate + '.format.dat'
;goesfile = checkdir + 'GOES10IF_Jul20_31_2004.format.dat'
goesfile = checkdir + parameter.goesfile
print,'goesfile = ',goesfile


;***************************************************************************************
;----------------------------------
; start, stop year & month & day
;----------------------------------
start_date = parameter.startdate
stop_date =  parameter.stopdate

print,'start_date, stop_date = ',start_date, ' ',stop_date
;-------------------------------------------------------------------------

;***************************************************************************************

intervals = lonarr(6)
;            0  1   2   3   4   5    6
intervals = [1, 5, 10, 30, 50, 60, 100]


;------------------------------------
; ymin & ymax for logarithmic Y axis
;------------------------------------
;         1      5      10      30     50    60   100
; calm period !
;ymin = [10.,     .1,    .01,  .001,   .001, .001, .001]
;ymax = [10000.,  100.,     1.,   1.,     1.,    1.,   1.]

; active period
;ymin = [100.,    10.,    10.,     1.,        1.,   1.,     .1]
;ymax = [100000., 10000., 10000.,   1000.,  1000.,    100.,   100.]
   
ymin = .01
ymax = 100000.



SET_PLOT,'Z'
DEVICE, Z_BUFFERING=0


;-----------------------------------------------------------------------
;12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
;12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
;(2x,a23,3x,10(1x,f13.5))

;----------------
; integral fluxes
;----------------
G11Flux = fltarr(7)
GCFlux = fltarr(7)


; Don't touch this! ***********************
date = '                       '

jd = 0.D

;-------------------------
; Get # of rows in file
;-------------------------
nrow = FILE_LINES(goesfile)  

G11Fluxes = REPLICATE( { date:date, jd:jd, Flux:G11Flux  }, nrow)
GCFluxes =  REPLICATE( { date:date, jd:jd, Flux:GCFlux  }, nrow)

;---------------------------------
; Initilize flux values to missing
;---------------------------------
CHECKMISS = -99999.0d0
G11Fluxes.flux = CHECKMISS
GCFluxes.flux = CHECKMISS


;------------
; Open file
;------------
openr, inunit, goesfile, /get_lun

;--------------------------------------------------------------------
; size of flux array is # of lines in file, nG11 is # of valid values 
;--------------------------------------------------------------------
nG11 = 0L;

;------------------------------------------
; Read GOES  flux 
;------------------------------------------
ok = 0;  Use to check if reached start_date
year = 0
month = 0
day = 0

;-------------------------------------------------------------------------
; can use either while statement below if have date and year, month, day
;-------------------------------------------------------------------------
while ( (not eof(inunit)) and (strcmp(date,stop_date) ne 1) )  do begin

       ;----------
       ; Get date
       ;----------
       ;2006-12-07 00:00:00.000 
       ;12345678901234567890123
       readf, inunit, format='(a23)', date

       ; separate date into month, day, .....
       reads, date, year, month, day, hour, minutes, seconds, format='(i4,1x,i2,1x,i2,1x,i2,1x,i2,1x,f6.3)'

       ;------------
       ; Get Fluxes
       ;------------
       readf, inunit, format='(2x,7(f15.6))', G11Flux

       ;print,'year, month, day, hour, minutes, seconds = ',year, month, day, hour, minutes, seconds
       ;print,'G11Flux = ',G11Flux

       if (strcmp(date,start_date) eq 1) then begin
           ok = 1
       endif

       if (ok eq 1) then begin
           G11Fluxes[nG11].date = date
           ;----------------------------------------------
           ; Convert date to julday for plotting purposes
           ;----------------------------------------------
           G11Fluxes[nG11].jd = JULDAY(month, day, year, hour, minutes, seconds)

           G11Fluxes[nG11].flux = G11Flux
           ;print,'nG11, G11 jd, flux =  ', nG11, ' ', G11Fluxes[nG11].jd, G11Fluxes[nG11].flux

           nG11 += 1

       endif

endwhile

close, inunit
free_lun, inunit


;=================================================================================

;print,'opening ',goesCalcfile
openr, inunit, goesCalcfile, /get_lun

date = '                       '
nGr = 0L;
;------------------------------------------
; Read GOES  calculated flux 
;------------------------------------------
ok = 0  ;  Use to check if reached start_date
year = 0
month = 0
day = 0

;-------------------------------------------------------------------------
; can use either while statement below if have date and year, month, day
;-------------------------------------------------------------------------
while ( (not eof(inunit)) and (strcmp(date,stop_date) ne 1) )  do begin

       ;123456789012345678901234567890123456789012345678901234
       ;2006-12-01 03:00:00.000 1.83413  0.24422  0.209068  0.160016  0.11879  0.0924318  0.05062
       ;eadf, inunit, format='(a23, 1x, 7(f15.7))', date, GCFlux
;12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234    
;2006-12-01 00:00:00.000      25.847        0.576        0.297        0.145        0.116        0.101        0.058  
;2006-12-01 01:55:00.000      10.827        0.188        0.151        0.086        0.057        0.047        0.027

       ;-------------------
       ; Get date & Fluxes
       ;-------------------
       readf, inunit, format='(a23, 1x, f11.3, 6(1x, f12.3))', date, GCFlux

       ; separate date into month, day, .....
       reads, date, year, month, day, hour, minutes, seconds, $
              format='(i4,1x,i2,1x,i2,1x,i2,1x,i2,1x,f6.3, 1x, f11.3, 6(1x, f12.3))'
       ;print, 'date, start_date = ',date, ' ',start_date
       ;print, 'year, month, day, hour, minutes, seconds = ',year, month, day, hour, minutes, seconds


       ;print,'year, month, day, hour, minutes, seconds = ',year, month, day, hour, minutes, seconds
       ;print,'GCFlux = ', GCFlux



       if (strcmp(date,start_date) eq 1) then begin
           ok = 1
       endif

       if (ok eq 1) then begin
           GCFluxes[nGr].date = date
           GCFluxes[nGr].jd = JULDAY(month, day, year, hour, minutes, seconds)
           GCFluxes[nGr].flux = GCFlux
           ;print,'nGr, GC jd, flux =  ', nGr, ' ', GCFluxes[nGr].jd, GCFluxes[nGr].flux
           nGr += 1
       endif

endwhile

close, inunit
free_lun, inunit

;print, 'GCFluxes[0].jd = ',GCFluxes[0].jd
;print, 'GCFluxes[0].flux = ',GCFluxes[0].flux
;print, 'GCFluxes[nGr-1].jd = ',GCFluxes[nGr-1].jd
;print, 'GCFluxes[nGr-1].flux = ',GCFluxes[nGr-1].flux

;print, '================================================'
if (nG11 ne nGr) then begin
    print,'nG11 ne nGr ******************'
    print,'nG11 = ',nG11,'  nGr = ',nGr
endif

if (nGr lt 1) then begin
    print,'did not find anything w/in these dates*************'
    stop
endif


;------------------------------------------
; Get RMS value  & write out to a file
;-----------------------------------------
;print,'nG11, nGr = ',nG11, nGr

;labels = strarr(7)
;labels = strtrim(intervals,2) + ' Mev'
;print,'labels = ',labels
;printf, rmsunit, 'L2 file', labels, format='(A35,7f7.3)'
;printf, rmsunit, '-----------------------------------------------------------'

;----------------------------------------------------
; For calculating & writing out rms error to a file
;----------------------------------------------------
;rmsError = dblarr(7)
;for fv = 0, 6 do begin
;    rmsError[fv] = rms_norm_goesim_goesr( G11Fluxes[0:nG11-1].flux[fv], $
;                                          GCFluxes[0:nGr-1].flux[fv], CHECKMISS )
;    print,'fv : rmsError[fv] = ', fv, rmsError[fv]
;endfor
;printf, rmsunit, parameter.goesCalcFile, rmsError, format='(A35,7f7.3)'
;printf, rmsunit, ' '

; 
;------------------------------------------------------------------------
; date format
;2006-12-01 00:00:00.000


;------------------------------
; load color table, set colors
;------------------------------
loadct, 39
white = 255
yellow = 200
black = 0
red = 250
purple = 40
blue = 50
green = 100
green2 = 150
green3 = 190
erase, white

;--------------------
; define color array
;--------------------
colors = intarr(9)
colors[0] = black
colors[1] = purple
colors[2] = blue
colors[3] = green
colors[4] = 222

;----------------------------------
; use constant max, min for plots
;----------------------------------
xmin = G11Fluxes[0].jd
xmax = G11Fluxes[nGr-1].jd

dummy = LABEL_DATE(DATE_FORMAT=['%N/%D!C%H:%I'])

;-------------------------------------------------------
; Determines how many x tick marks to put on bottom
; if IDL decides,  may not be what you want
;-------------------------------------------------------
;numxticks = (stop_day - start_day)*2
numxticks = (round(xmax-xmin)) 
;print,'numxticks = ',numxticks

;----------------------------------------------------------------------
; Put up axes & titles
; position is the position of plot on the page in normalized units
;----------------------------------------------------------------------
title = 'Integral Flux Comparison' + titlename
plot, G11Fluxes.jd, G11Fluxes.flux[0], XRange=[xmin,xmax], YRange=[ymin,ymax], $
      color=colors[0], BACKGROUND=white, $
      xtitle='', ytitle='Integral Flux (cm!u-2!N s!u-1!N sr!u-1!N)', /YLOG,  $
      TITLE=title, XTICKFORMAT='LABEL_DATE',  XCHARSIZE=.8, $
      POSITION=[.1,.08,.9,.94], /NODATA, XTICKS=numxticks


for fv = 0, 6 do begin


  ;------------------------------------------
  ; do line plots
  ;------------------------------------------

  ; line
  oplot, G11Fluxes.jd, G11Fluxes.flux[fv], $
       color=red
  oplot, GCFluxes.jd, GCFluxes.flux[fv], $
       color=blue



endfor ; fv

  ;-------------------------------------------
  ; draw example of  line at top
  ;--------------------------------------------
  linex = dblarr(2)
  liney = dblarr(2)

  ;-------------------------------------------------------
  ; calculate how much space to leave after xmin
  ;-------------------------------------------------------
  ;bottom = (stop_day - start_day)*4.D
  ;bottom = 8.D
  ;gap = (xmax - xmin)/bottom
  gap = double(xmax - xmin)/10.d

  markx = (xmin + gap)
  ;marky = 10.^(alog10(parameter.ymax) - 1)
  marky = 10.^(alog10(parameter.ymax) - .5)

  ;print,'markx = ',markx

  ;-----------
  ; label
  ;-----------
  xyouts, markx, marky, parameter.inst, color=0, size=1.0, align=0.5

  ;print,'markx = ',markx

  ;---------------------------------
  ; Make line after the above label
  ;---------------------------------
  ;space = .25D
  ;space = .35D  ; space b/t label & start of colored line
  ;linex(0) = markx + space
  linex[0] = xmin + .5*gap
  ;linex[

  linex(1) = linex(0) + gap

  ;print,'linex = ',linex

  ;liney(0) = marky 

  liney[0] =  10.^(alog10(parameter.ymax) - .7)
  liney(1) = liney(0)

  OPLOT, linex, liney, color=red, line=0, thick=3

  ;-----------
  ; label
  ;-----------
  ;markx = markx + 3.d*gap + .4D
  markx = markx + 3.d*gap 
  
  ;linex(0) = markx + gap
  linex[0] = markx 
  linex(1) = linex(0) + gap

  ;print,'linex = ',linex

  ;xyouts, markx, marky, 'GOESR algorithm', color=0, align=0.5
  xyouts, markx, marky, 'GOESR algorithm', color=0, align=0.

  OPLOT, linex, liney, color=blue, line=0, thick=3

  ;-------------------
  ; Put on date label
  ;------------------- 
  ;xyouts, .55, .02, 'Dates', color=0, size=1.2,  /NORMAL, align=0.5
  xyouts, .5, .005, 'Dates', color=0, size=1.1,  /NORMAL, align=0.5

;-----------------------------------
; Put on y labels on the right
;-----------------------------------
;print,'last fluxes = ----------------------------'
for fv = 0, 6 do begin
    string = ' >'+ strtrim(intervals[fv],2) + ' Mev'
    xyouts, G11Fluxes[nG11-1].jd[0], G11Fluxes[nG11-1].flux[fv], string, /DATA, align=0., COLOR=black, $
            size=.8
endfor


;outpng = outdir + 'ts_all_' + inst + strmon + strtrim(start_day,2) + '_' + $
;           strtrim(stop_day,2) + '_plot.png'
outpng = outdir + parameter.outpng



;xyouts, .6, .8, start_year, /NORMAL, COLOR=black
;xyouts, .6, .75, stop_year, /NORMAL, COLOR=black


TVLCT, pred, pgreen, pblue, /GET

print,'outpng = ',outpng
WRITE_PNG, outpng, TVRD(), pred,pgreen,pblue


;stop


end
