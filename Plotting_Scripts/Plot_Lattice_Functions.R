#change directory to working directory
    initial.dir<-getwd()
    options(stringAsFactors=F)
    
#name of file and title for plot pallete
    #name<-"LHC Loss Map 7TeV n = 6.4E6 Inefficiency IR7 23Oct13.png"
	
	title<-"HL_v1.2.1_All_Crossing_TWISS"
	particle_no<-""
	#region<-" IR7"
	region<-""
	type<-"_MADX_vs_MERLIN"
	date<-"_15Nov15"	
	ext<-".png"
	
	#Full
	xlimits <- c(0,26700)	
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
      height    = 30, 
      units     = "cm",
      res       = 480,
      pointsize = 4
    )

    
#create data frames
#~ 	madx_data<-data.frame(a=numeric(0), b=numeric(0), c=numeric(0), d=numeric(0), e=numeric(0), f=numeric(0), g=numeric(0), h=numeric(0), i=numeric(0))
#~ 	merlin_data<-data.frame(a=numeric(0), b=numeric(0), c=numeric(0), d=numeric(0), e=numeric(0), f=numeric(0), g=numeric(0), h=numeric(0), i=numeric(0))
#~ 	madx_data<-data.frame(a=numeric(0), b=numeric(0), c=numeric(0), d=numeric(0), e=numeric(0), f=numeric(0), g=numeric(0), h=numeric(0), i=numeric(0))
#~ 	merlin_data<-data.frame(a=numeric(0), b=numeric(0), c=numeric(0), d=numeric(0), e=numeric(0), f=numeric(0), g=numeric(0), h=numeric(0), i=numeric(0))
	
	madx_data<-read.table("madx_lf.dat")
	merlin_data<-read.table("merlin_lf.dat")
	
	colnames(madx_data)<- c('s', 'beta_x', 'beta_y', 'alpha_x', 'alpha_y', 'D_x', 'D_y', 'x', 'y')
	colnames(merlin_data)<- c('s', 'beta_x', 'beta_y', 'alpha_x', 'alpha_y', 'D_x', 'D_y', 'x', 'y')
	

#~ 	infile1<-read.table("madx_lf.dat")
#~ 	madx_data$s <- cbind(as.numeric(as.character(infile1$V1)))
#~ 	madx_data$beta_x <- cbind(as.numeric(as.character(infile1$V2)))
#~ 	madx_data$beta_y <- cbind(as.numeric(as.character(infile1$V3)))
#~ 	madx_data$alpha_x <- cbind(as.numeric(as.character(infile1$V4)))
#~ 	madx_data$alpha_y <- cbind(as.numeric(as.character(infile1$V5)))
#~ 	madx_data$D_x <- cbind(as.numeric(as.character(infile1$V6)))
#~ 	madx_data$D_y <- cbind(as.numeric(as.character(infile1$V7)))
#~ 	madx_data$x <- cbind(as.numeric(as.character(infile1$V8)))
#~ 	madx_data$y <- cbind(as.numeric(as.character(infile1$V9)))
	
#~ 	infile2<-read.table("merlin_lf.dat")
#~ 	merlin_data$s <- as.numeric(as.character(infile2$V1))
#~ 	merlin_data$beta_x <- as.numeric(as.character(infile2$V2))
#~ 	merlin_data$beta_y <- as.numeric(as.character(infile2$V3))
#~ 	merlin_data$alpha_x <- as.numeric(as.character(infile2$V4))
#~ 	merlin_data$alpha_y <- as.numeric(as.character(infile2$V5))
#~ 	merlin_data$D_x <- as.numeric(as.character(infile2$V6))
#~ 	merlin_data$D_y <- as.numeric(as.character(infile2$V7))
#~ 	merlin_data$x <- as.numeric(as.character(infile2$V8))
#~ 	merlin_data$y <- as.numeric(as.character(infile2$V9))

summary(merlin_data)
summary(madx_data)
	
	multi<-1.5

	#This controls plot pallete layout: 2 rows, 3 cols, margins of left, right, top, bottom
    par(mfrow=c(9,1), oma=c(0,0,4,0))


	plot( madx_data$s, madx_data$beta_x, type='l', lwd=0.5, log='y', main = "Beta_x", xlab="s[m]", ylab="Beta_x[m]", col='black')
	lines( merlin_data$s, merlin_data$beta_x, type='l', lty=3, lwd=0.5, col='orange', log='y')
		legend("topleft", col=c('black','orange'), legend =c("MADX", "MERLIN"), lty=c(1,3), cex = multi, bty='n') 
			
	plot( madx_data$s, madx_data$beta_y, type='l', lwd=0.5, log='y', main = "Beta_y", xlab="s[m]", ylab="Beta_y[m]", col='black')
	lines( merlin_data$s, merlin_data$beta_y, type='l', lty=3, lwd=0.5, col='orange', log='y')
		legend("topleft", col=c('black','orange'), legend =c("MADX", "MERLIN"), lty=c(1,3), cex = multi, bty='n') 
		
	plot( merlin_data$s, merlin_data$beta_y,  type='l', lty=1, lwd=0.5, log='y', main = "Betas",  xlab="s[m]", ylab="Beta_x[m]", col='black')
	lines( merlin_data$s, merlin_data$beta_x, type='l', lty=1, lwd=0.5, col='orange', log='y')
	legend("topleft", col=c('black','orange'), legend =c("MERLIN Beta_y","MERLIN Beta_x"), lty=c(1,1), cex = multi, bty='n') 
	
	plot( madx_data$s, madx_data$alpha_x, type='l', lwd=0.5, main = "Alpha_x", xlab="s[m]", ylab="Alpha_x", col='black', log='y')
	lines( merlin_data$s, merlin_data$alpha_x, type='l', lty=3, lwd=0.5, col='orange', log='y')
		legend("topleft", col=c('black','orange'), legend =c("MADX", "MERLIN"), lty=c(1,3), cex = multi, bty='n') 
	
	plot( madx_data$s, madx_data$alpha_y, type='l', lwd=0.5, main = "Alpha_y", xlab="s[m]", ylab="Alpha_y", col='black', log='y')
	lines( merlin_data$s, merlin_data$alpha_y, type='l', lty=3, lwd=0.5, col='orange', log='y')
		legend("topleft", col=c('black','orange'), legend =c("MADX", "MERLIN"), lty=c(1,3), cex = multi, bty='n') 
	
	plot( madx_data$s, madx_data$D_x, type='l', lwd=0.5, main = "D_x", xlab="s[m]", ylab="D_x", col='black', ylim=c(-3,3))
	lines( merlin_data$s, merlin_data$D_x, type='l', lty=3, lwd=0.5, col='orange', ylim=c(-3,3))
		legend("topleft", col=c('black','orange'), legend =c("MADX", "MERLIN"), lty=c(1,3), cex = multi, bty='n') 
	
#~ 	plot( merlin_data$s, merlin_data$D_y,type='l', lwd=0.5, main = "D_y", xlab="s[m]", ylab="D_y", col='orange', ylim=c(-3E-31,3E-31))
	plot( merlin_data$s, merlin_data$D_y,type='l', lwd=0.5, lty=1, main = "D_y", xlab="s[m]", ylab="D_y", col='orange')
#~ 	lines( merlin_data$s, merlin_data$D_y, type='l', lty=1, lwd=0.5, col='orange', ylim=c(-3E-31,3E-31))
	lines( madx_data$s, madx_data$D_y, type='l', lty=3, lwd=0.5, col='black')
		legend("topleft", col=c('orange'), legend =c("MERLIN"), lty=c(1,3), cex = multi, bty='n') 
	
#~ 	plot( merlin_data$s, merlin_data$x, type='l', lwd=0.5, main = "Closed_orbit_x", xlab="s[m]", ylab="x[m]", col='orange', ylim=c(-2E-15,2E-15))
	plot( merlin_data$s, merlin_data$x, type='l', lwd=0.5, lty=1, main = "Closed_orbit_x", xlab="s[m]", ylab="x[m]", col='orange')
#~ 	lines( merlin_data$s, merlin_data$x, type='l', lty=1, lwd=0.5, col='orange', ylim=c(-2E-15,2E-15))
	lines( madx_data$s, madx_data$x, type='l', lty=3, lwd=0.5, col='black')
		legend("topleft", col=c('orange'), legend =c("MERLIN"), lty=c(1,3), cex = multi, bty='n') 
	
#~ 	plot( merlin_data$s, merlin_data$y, type='l', lwd=0.5, lty=3, main = "Closed_orbit_y", xlab="s[m]", ylab="y[m]", col='orange', ylim=c(-3E-33,3E-33))
	plot( merlin_data$s, merlin_data$y, type='l', lwd=0.5, lty=1, main = "Closed_orbit_y", xlab="s[m]", ylab="y[m]", col='orange')
	lines( madx_data$s, madx_data$y, type='l', lty=3, lwd=0.5, col='black')
#~ 	lines( merlin_data$s, merlin_data$y, type='l', lty=1, lwd=0.5, col='orange', ylim=c(-3E-33,3E-33))
		legend("topleft", col=c('orange'), legend =c("MERLIN"), lty=c(1,3), cex = multi, bty='n') 
		
title(paste(name), outer=TRUE)
