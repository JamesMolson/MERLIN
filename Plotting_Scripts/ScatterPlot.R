#change directory to working directory
    initial.dir<-getwd()
    
   # library(plotmath)

#name of file and title for plot pallete
	title<-"LHC_7TeV_"
	particle_no<-"ScatterPlot_n=1E5_noPost+PreTracking_"
	type<-"@TestCollimator_1cm_C_"
	date<-"02Nov15"	
	ext<-".png"

	name<-paste(title, type, particle_no, date, ext, sep='')	
	
#Open output file
    png(
      paste(name),
      width     = 5,
      height    = 5,
      units     = "cm",
      res       = 720,
      pointsize = 2
    )

infile<-read.table("ScatterPlot.txt")
	id <- 0
	z <- 0
	y <- 0

	id <-cbind(as.numeric(as.character(infile$V1)))
	z <-cbind(as.numeric(as.character(infile$V2)))
	y <-cbind(as.numeric(as.character(infile$V3)))
#~ 	id <-infile$V1
#~ 	z <-infile$V2
#~ 	y <-infile$V3


    par(mfrow=c(1,1), oma=c(0,0,0,0))

#~ plot(z[0],y[0])
plot(z[1,1],y[1,1], xlim=c(0.0, 0.01), ylim=c(0.99998, 1.00002), xlab = "ct [m]", ylab = "y [m]", main = "50cm vertical collimator scattering",)
#~ plot(z[1,1],y[1,1], xlim=c(0.0, 0.01), ylim=c(0.9999998, 1.000002), lwd=0.1)

#Blue block for collimator
rect(0, 0.01, 0.5, 1, col='blue')

	
	max(id)
	
	currentid <- cbind(id[1,1])
	currentid
	
#~ 	miniid<-0
	miniz<-cbind(z[0,])
	miniy<-cbind(z[0,])
	
	miniz
	miniy
	
for(i in 1:(max(id))){
	
	newid <- id[i,]
	
	if(newid == currentid){
		miniz<-cbind(miniz,z[i,])
		miniy<-cbind(miniy,y[i,])
	}	
	
	else{
		#plot last lines
		lines(miniz, miniy,xlim=c(0.0, 0.01), ylim=c(0.99998, 1.00002), lwd=0.1)
		
		#Reset lines
		miniz<-0
		miniy<-0
		
		#Increment currentid		
		currentid<-(currentid+1)
		
		#start new lines
		miniz<-cbind(z[i,])
		miniy<-cbind(y[i,])		
		
	}
}

	miniz
	miniy
#points(x[,1], xp[,1], type = "p", pch = '.', col = col1)     	


