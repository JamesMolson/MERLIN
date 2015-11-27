#change directory to working directory
    initial.dir<-getwd()
    options(stringAsFactors=F)
    
#name of file and title for plot pallete
    #name<-"LHC Loss Map 7TeV n = 6.4E6 Inefficiency IR7 23Oct13.png"
	
	title<-"HLv1.2.1_AllCrossingOn_LHC_TWISS"
	particle_no<-""
	#region<-" IR7"
	region<-""
	type<-"_MAD_vs_MERLIN_HEL"
	date<-"_15Nov15"	
	ext<-".png"
	
	#Full
	xlimits <- c(9800,10000)	
	#IR7
	#xlimits <- c(19700, 20600)
	
	name<-paste(title, particle_no, region, type, date, ext, sep="")	

	files<-1
	fileno<-files-1
	
#line width for plots
    linewidth<-1.0

#Open output file
    png(
      #"halo1 n=1k cut quarter jaw .png",
      paste(name),
      width     = 10,
      height    = 15, 
      units     = "cm",
      res       = 720,
      pointsize = 8
    )


	madx_data<-read.table("madx_lf.dat")
	merlin_data<-read.table("merlin_lf.dat")
	
	colnames(madx_data)<- c('s', 'beta_x', 'beta_y', 'alpha_x', 'alpha_y', 'D_x', 'D_y', 'x', 'y')
	colnames(merlin_data)<- c('s', 'beta_x', 'beta_y', 'alpha_x', 'alpha_y', 'D_x', 'D_y', 'x', 'y')
	
	merlin_disp<-read.table("Dispersion.dat")
	colnames(merlin_disp)<- c('s', 'D_x', 'D_y')


summary(merlin_data)
summary(madx_data)
summary(merlin_disp)
	
	multi<-1

	ylimits<-c(100,600)

	#This controls plot pallete layout: 2 rows, 3 cols, margins of left, right, top, bottom
    par(mfrow=c(2,1), oma=c(0,0,4,0))

	plot( madx_data$s, madx_data$beta_x, type='l', lwd=0.5, log='y', main = paste(name), xlab="s[m]", ylab="Beta function [m]", col='blue', xlim=xlimits, ylim=ylimits)
	lines( madx_data$s, madx_data$beta_y, type='l', lty=1, lwd=0.5, col='red')
	lines( merlin_data$s, merlin_data$beta_x, type='l', lty=3, lwd=0.5, col='purple')
	lines( merlin_data$s, merlin_data$beta_y, type='l', lty=3, lwd=0.5, col='orange')

	abline(v=9967.005, lty=3, col='grey')	#HEL-30m
	abline(v=9908.405, lty=3, col='grey')	#HEL-90m
	abline(v=9997.005, lty=3, col='black')	#IP4

#~ 	plot( madx_data$s, madx_data$D_x, type='l', lwd=0.5, xlab="s[m]", ylab="D_x[m]", col='blue', xlim=xlimits, ylim=c(-0.3,0.3))
	plot( madx_data$s, madx_data$D_x, type='l', lwd=0.5, xlab="s[m]", ylab="Dispersion [m]", xlim=xlimits, col='blue', ylim=c(-0.7,0.7))
	lines( madx_data$s, madx_data$D_y, type='l', lty=1, lwd=0.5, col='red')
	lines( merlin_disp$s, merlin_disp$D_x, type='l', lty=3, lwd=0.5, col='green')
	lines( merlin_disp$s, merlin_disp$D_y, type='l', lty=3, lwd=0.5, col='yellow')
	lines( merlin_data$s, merlin_data$D_x, type='l', lty=3, lwd=0.5, col='purple')
	lines( merlin_data$s, merlin_data$D_y, type='l', lty=3, lwd=0.5, col='orange')

#~ 	plot( merlin_data$s, merlin_data$D_x, type='l', lwd=0.5, xlab="s[m]", ylab="D_x[m]", xlim=xlimits, col='blue', ylim=c(-0.7,0.7))
#~ 	lines( merlin_data$s, merlin_data$D_y, type='l', lty=1, lwd=0.5, col='red')
#~ 	lines( merlin_data$s, merlin_data$D_x, type='l', lty=3, lwd=0.5, col='purple')
#~ 	lines( merlin_data$s, merlin_data$D_y, type='l', lty=3, lwd=0.5, col='orange')

	abline(v=9967.005, lty=3, col='grey')	#HEL-30m
	abline(v=9908.405, lty=3, col='grey')	#HEL-90m
	abline(v=9997.005, lty=3, col='black')	#IP4
	


