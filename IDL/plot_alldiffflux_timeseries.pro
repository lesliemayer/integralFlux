
pro plot_alldiffflux_timeseries, parameter, rmsunit
;=====================================================================
; IDL code to read in GOES observed differential flux data, and GOES 
; calculated differential flux data (or GOESR calculated differential flux data)
; and plot time series of *all* differential flux value
;
; to run:  
; idl> plot_alldiffflux_timeseries
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

Gxsize = 6
GRsize = 8

;indices of energies we want to plot
; 5, 15, 30, 50, 60, 100
; 0   1   2   3  4    5
; 1, 5, 10, 15, 30, 50, 60, 100
; 0  1   2   3   4   5   6   7
Grindex = [1, 3, 4, 5, 6, 7]

; 1  5 10 15 30 50 60 100
intervals = lonarr(6)
;           
intervals = [5, 15, 30, 50, 60, 100]

;###################################
; plot title
titlename = " : " + parameter.inst + " vs GOESR"



;---------------------------------------------------
; for differential flux calculations from goes data
;---------------------------------------------------
outdir = '../DATA/DIAGNOSTICS/PLOTS/'
;print,'outdir = ',outdir

;---------------------------------------
; GOESR alg. calculated differential flux
;---------------------------------------
indir = '../DATA/DIAGNOSTICS/OUTPUT/'

goesCalcfile = indir + parameter.goesCalcFile

print,'goesCalcfile = ',goesCalcfile

;-----------------------------------------------------------------------
; differential Flux Data from GOES database
; (leave this alone) !!!!!!!!!!!!!!!!
;------------------------------------------------------------------------
checkdir = '../DATA/ORIGINALGOES/'
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



;------------------------------------
; ymin & ymax for logarithmic Y axis
;------------------------------------
;ymin = .01
;ymax = 100000.



SET_PLOT,'Z'
DEVICE, Z_BUFFERING=0


;-----------------------------------------------------------------------
;12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
;12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
;(2x,a23,3x,10(1x,f13.5))

;----------------
; differential fluxes
;----------------
GxFlux = fltarr(Gxsize)
GCFlux = fltarr(GRsize)


; Don't touch this! ***********************
date = '                       '

jd = 0.D

;-------------------------
; Get # of rows in file
;-------------------------
nrow = FILE_LINES(goesfile)  

GxFluxes = REPLICATE( { date:date, jd:jd, Flux:GxFlux  }, nrow)
GCFluxes =  REPLICATE( { date:date, jd:jd, Flux:GCFlux  }, nrow)

;---------------------------------
; Initilize flux values to missing
;---------------------------------
CHECKMISS = -99999.0d0
GxFluxes.flux = CHECKMISS
GCFluxes.flux = CHECKMISS


;------------
; Open file
;------------
openr, inunit, goesfile, /get_lun

;--------------------------------------------------------------------
; size of flux array is # of lines in file, nGx is # of valid values 
;--------------------------------------------------------------------
nGx = 0L;

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
       reads, date, year, month, day, hour, minutes, seconds, $
              format='(i4,1x,i2,1x,i2,1x,i2,1x,i2,1x,f6.3)'

       ;print,'Gx date = ',date

       ;------------
       ; Get Fluxes
       ;------------
;12345678901234567890  
;x123456789012345  123456789012345     
;        0.084958       0.006869       0.000769       0.000323       0.000237       0.000544
       ;readf, inunit, format='(2x,6(f15.6))', GxFlux
       readf, inunit, format='(2x,f15.6,5(f15.6))', GxFlux

       ;print,'year, month, day, hour, minutes, seconds = ', $
       ;       year, month, day, hour, minutes, seconds
       ;print,'GxFlux = ',GxFlux

       if (strcmp(date,start_date) eq 1) then begin
           ok = 1
       endif

       if (ok eq 1) then begin
           GxFluxes[nGx].date = date
           ;----------------------------------------------
           ; Convert date to julday for plotting purposes
           ;----------------------------------------------
           GxFluxes[nGx].jd = JULDAY(month, day, year, hour, minutes, seconds)

           GxFluxes[nGx].flux = GxFlux
           ;print,'nGx, Gx jd, flux =  ', nGx, ' ', $
           ;        GxFluxes[nGx].jd, GxFluxes[nGx].flux

           nGx += 1

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
;12345678901234567890123x12345678901234xx12345678901234xx12345678901234     
;2006-12-09 00:00:00.000    2727.836692       71.730282       20.331939       13.342214        4.299786        1.001013        0.407308        0.030847

       ;-------------------
       ; Get date & Fluxes
       ;-------------------
       ;readf, inunit, format='(a23, 1x, f11.3, 7(1x, f12.3))', date, GCFlux
       readf, inunit, format='(a23, 1x, f14.6, 7(2x, f14.6))', date, GCFlux

       ; separate date into month, day, .....
       reads, date, year, month, day, hour, minutes, seconds, $
              format='(i4,1x,i2,1x,i2,1x,i2,1x,i2,1x,f6.3, 1x, f11.3, 7(1x, f12.3))'
       ;print, 'date, start_date = ',date, ' ',start_date
       ;print, 'year, month, day, hour, minutes, seconds = ',year, month, day, hour, minutes, seconds


       ;print,'year, month, day, hour, minutes, seconds = ', $
       ;       year, month, day, hour, minutes, seconds
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
if (nGx ne nGr) then begin
    print,'nGx ne nGr ******************'
    print,'nGx = ',nGx,'  nGr = ',nGr
endif

if (nGr lt 1) then begin
    print,'did not find anything w/in these dates*************'
    stop
endif


;------------------------------------------
; Get RMS value  & write out to a file
;-----------------------------------------
;print,'nGx, nGr = ',nGx, nGr

;----------------------------------------------------
; For calculating & writing out rms error to a file
;----------------------------------------------------
;rmsError = dblarr(8)
;for fv = 0, 6 do begin
;    rmsError[fv] = rms_norm_goesim_goesr( GxFluxes[0:nGx-1].flux[fv], $
;                                          GCFluxes[0:nGr-1].flux[fv], CHECKMISS )
;    print,'fv : rmsError[fv] = ', fv, rmsError[fv]
;endfor
;printf, rmsunit, parameter.goesCalcFile, rmsError, format='(A35,8f7.3)'
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
xmin = GxFluxes[0].jd
xmax = GxFluxes[nGr-1].jd

dummy = LABEL_DATE(DATE_FORMAT=['%N/%D!C%H:%I'])

;-------------------------------------------------------
; Determines how many x tick marks to put on bottom
; if IDL decides,  may not be what you want
;-------------------------------------------------------
numxticks = (round(xmax-xmin)) 

;----------------------------------------------------------------------
; Put up axes & titles
; position is the position of plot on the page in normalized units
;----------------------------------------------------------------------
title = 'Differential Flux Comparison' + titlename
plot, GxFluxes.jd, GxFluxes.flux[0], XRange=[xmin,xmax], $
      YRange=[parameter.ymin,parameter.ymax], $
      color=colors[0], BACKGROUND=white, $
      xtitle='', ytitle='Differential Flux (cm!u-2!N s!u-1!N sr!u-1!N MeV!u-1!N)', /YLOG,  $
      TITLE=title, XTICKFORMAT='LABEL_DATE',  XCHARSIZE=.8, $
      POSITION=[.1,.08,.9,.94], /NODATA, XTICKS=numxticks


for fv = 0, gxsize-1 do begin


  ;------------------------------------------
  ; do line plots
  ;------------------------------------------

  ; line
  oplot, GxFluxes.jd, GxFluxes.flux[fv], $
       color=red
  oplot, GCFluxes.jd, GCFluxes.flux[Grindex[fv]], $
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
  gap = double(xmax - xmin)/10.d

  markx = (xmin + gap)
  marky = 10.^(alog10(parameter.ymax) - .5)

  ;print,'markx = ',markx

  ;-----------
  ; label
  ;-----------
  xyouts, markx, marky, parameter.inst, color=0, size=1.0, align=0.5

  ;---------------------------------
  ; Make line after the above label
  ;---------------------------------
  linex[0] = xmin + .5*gap

  linex(1) = linex(0) + gap

  liney[0] =  10.^(alog10(parameter.ymax) - .7)
  liney(1) = liney(0)

  OPLOT, linex, liney, color=red, line=0, thick=3

  ;-----------
  ; label
  ;-----------
  markx = markx + 3.d*gap 
  
  linex[0] = markx 
  linex(1) = linex(0) + gap

  xyouts, markx, marky, 'GOESR algorithm', color=0, align=0.

  OPLOT, linex, liney, color=blue, line=0, thick=3

  ;-------------------
  ; Put on date label
  ;------------------- 
  xyouts, .5, .005, 'Dates', color=0, size=1.1,  /NORMAL, align=0.5

;-----------------------------------
; Put on y labels on the right
;-----------------------------------
;print,'last fluxes = ----------------------------'
for fv = 0, Gxsize-1 do begin
    string = ' ' + strtrim(intervals[fv],2) + ' Mev'
    xyouts, GxFluxes[nGx-1].jd[0], GxFluxes[nGx-1].flux[fv], string, /DATA, align=0., COLOR=black, $
            size=.8
endfor

outpng = outdir + parameter.outpng


TVLCT, pred, pgreen, pblue, /GET

print,'outpng = ',outpng
WRITE_PNG, outpng, TVRD(), pred,pgreen,pblue


;stop


end
