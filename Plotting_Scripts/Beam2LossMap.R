#change directory to working directory
    initial.dir<-getwd()
    options(stringAsFactors=F)
    
#name of file and title for plot pallete
    #name<-"LHC Loss Map 7TeV n = 6.4E6 Inefficiency IR7 23Oct13.png"
	
	title<-"HL_LHC_LossMap_7TeV_BEAM2_"
	particle_no<-"n=1E4_"
	#region<-" IR7"
	region<-""
	type<-"MERLINScatter_"
	date<-"14Nov15"	
	ext<-".png"
	
	#Full
	xlimits <- c(0,26659)	
#~ 	xlimits <- c(26659,0)	
	smax<-26659
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
      width     = 15,
      height    = 15, 
      units     = "cm",
      res       = 480,
      pointsize = 6
    )

#create data frame
sort <-0

#~ 	for (i in 0:fileno){
#~ 		infile<-read.table(paste("Node_",i,"_losses.txt", sep=""))
#~ 		sort0<-0
#~ 		sort0 <- rbind(infile)
#~ 		sort<-rbind(sort,sort0)
#~ 	}
	infile<-read.table(paste("Dustbin_losses.txt", sep=""))
#~ 	sort0<-0
	final <- rbind(infile)
#~ 	sort<-rbind(sort,sort0)

#	Name	s	bin_start	loss	temperature	length
#    sort <- rbind (input0, input1, input2, input3, input4, input5, input6, input7, input8, input9, input10, input11)
#~     colnames(sort) <- c( 'name', 's', 'bin_start', 'losses', 'coll/cold/warm', 'length' )
#~     sort
    colnames(final) <- c( 'name', 's', 'bin_start', 'losses', 'coll/cold/warm', 'length' )
    final
    
    finalrows<-nrow(final)
	finalrows

#sort according to s  
#~     sort <- sort[ order(sort$s),]
#~     sort
    
#~     sortrows<-nrow(sort)
    
#merge losses
#~ 	final<-data.frame(w = character(0), x = numeric(0), y = integer(0), z = numeric(0), a = numeric(0))
#~ 	colnames(final) <- c( 'label', 's', 'losses', 'coll/cold/warm', 'length' )
	
#~ 	final<-sort[1,]
#~ 	final
	
	
#~ 	j<-1
	
#~ 	for (i in 1:sortrows){
#~ 		if( (i!= sortrows) && final[j,2] == sort[i+1,2] ){
#~ 			final[j,3]<-(final[j,3] + sort[i+1,3])	
#~ 		} else{
#~ 			final[(j+1),]<-rbind(sort[i+1,])
#~ 			j <- (j+1)			
#~ 		}	
#~ 	}
	
#~ 	final
#~ 	finalrows<-nrow(final)
#~ 	finalrows
	
#~ 	final<-final[-finalrows,]
#~ 	finalrows<-nrow(final)
#~ 	finalrows

#read the highest loss
	#highestloss<-0
	#highestlosslocation<-data.frame(x = character(0))
	
	#for (i in 1:finalrows){
	#	if(final[i,3] > highestloss){
	#		highestloss <-final[i,3]
	#	}
	#}

	#highestloss

	
#old normalisation	
	#for (i in 1:finalrows){
	#	final[i,3] <- (final[i,3] / highestloss)		
	#}
	
	#final
	
#Seperate coll/warm/cold losses
	coll<-data.frame(w = character(0), x = numeric(0), y = numeric(0), z = integer(0), a = numeric(0), b = numeric(0))
	colnames(coll) <- c( 'label', 's', 'bin_start', 'losses', 'coll/cold/warm', 'length' )
	cold<-data.frame(w = character(0), x = numeric(0), y = numeric(0), z = integer(0), a = numeric(0), b = numeric(0))
	colnames(cold) <- c( 'label', 's', 'bin_start', 'losses', 'coll/cold/warm', 'length' )
	warm<-data.frame(w = character(0), x = numeric(0), y = numeric(0), z = integer(0), a = numeric(0), b = numeric(0))
	colnames(warm) <- c( 'label', 's', 'bin_start', 'losses', 'coll/cold/warm', 'length' )

	#Iterators
	j<-1
	k<-1
	l<-1

	for (i in 1:finalrows){
		if(final[i,5] == 0){
			coll[j,]<-rbind(final[i,])
			j<-(j + 1)
		}	
		else if (final[i,5] == 1){
			cold[k,] <- rbind(final[i,])
			k<-(k + 1)	
		}
		else if (final[i,5] == 2){
			warm[l,] <- rbind(final[i,])
			l<-(l + 1)
		}
	}	

coll
cold
warm

#total loss	
	totalloss<-0
	
	
	for (i in 1:finalrows){
		totalloss <- (totalloss + final[i,4])
	}
	
	totalloss
	bin_size <- 0.1
	
		collrows <- nrow(coll)
	
#Normalisation
	for (i in 1:collrows){
		coll[i,4] <- (coll[i,4] / (coll[i,6] * totalloss))
#~ 		coll[i,4] <- (coll[i,4] / (bin_size * totalloss))
	}
	coll
	
	coldrows <- nrow(cold)
	
	for (i in 1:coldrows){
#~ 		cold[i,4] <- (cold[i,4] / (cold[i,6] * totalloss))
		cold[i,4] <- (cold[i,4] / (bin_size * totalloss))
	}

	warmrows <- nrow(warm)
	
	for (i in 1:warmrows){
#~ 		warm[i,4] <- (warm[i,4] / (warm[i,6] * totalloss))
		warm[i,4] <- (warm[i,4] / (bin_size * totalloss))
	}	
	
	
#This controls plot pallete layout: 2 rows, 1 cols, margins of left, right, top, bottom
    par(mfrow=c(2,1), oma=c(1,0,0,0))
    
#tick marks for y axis
	ticks<-c(10^0, 10^-1, 10^-2, 10^-3, 10^-4, 10^-5, 10^-6, 10^-7)

#start plot at (0,0)
	par(xaxs='i', yaxs='i')

#plot coll losses in black
#~ 	plot(coll[,2], coll[,4], log='y', type='h', lwd=linewidth, lend=1, main = paste(name), xlab="s[m]", ylab = expression(paste("Inefficiency ", eta, " [", m^-1, "]")), xlim = xlimits, yaxt='n', panel.first=grid(equilogs=FALSE, lwd = linewidth/4 ), col = 'black' )	
	plot((smax-coll[,2]), coll[,4], log='y', type='h', lwd=linewidth, lend=1, main = paste(name), xlab="s[m]", ylab = expression(paste("Inefficiency ", eta, " [", m^-1, "]")), xlim = xlimits, yaxt='n', panel.first=grid(equilogs=FALSE, lwd = linewidth/4 ), col = 'black' )	

#add y axis log marks
	axis(2, at = ticks, las=2)
	
#plot cold losses in blue
	lines(cold[,2], cold[,4], log='y', type='h', lwd=linewidth, lend=1, main = paste(name), xlab="s[m]", ylab = expression(paste("Inefficiency ", eta, " [", m^-1, "]")), xlim = xlimits, yaxt='n', col = 'blue' )
	
#plot warm losses in red
	lines(warm[,2], warm[,4], log='y', type='h', lwd=linewidth, lend=1, main = paste(name), xlab="s[m]", ylab = expression(paste("Inefficiency ", eta, " [", m^-1, "]")), xlim = xlimits, yaxt='n', col = 'red' )

#IR7 loss map next
	xlimits <- c(19700, 20600)
#~ 	xlimits <- c((smax-20600), (smax-19700))
	
#start plot at (0,0)
	par(xaxs='i', yaxs='i')

#plot coll losses in black
	plot((smax-coll[,2]), coll[,4], log='y', type='h', lwd=linewidth, lend=1, main = "IR7", xlab="s[m]", ylab = expression(paste("Inefficiency ", eta, " [", m^-1, "]")), xlim = xlimits, yaxt='n', panel.first=grid(equilogs=FALSE, lwd = linewidth/4 ), col = 'black' )	

#add y axis log marks
	axis(2, at = ticks, las=2)
	
#plot cold losses in blue
	lines(cold[,2], cold[,4], log='y', type='h', lwd=linewidth, lend=1, main = "IR7", xlab="s[m]", ylab = expression(paste("Inefficiency ", eta, " [", m^-1, "]")), xlim = xlimits, yaxt='n', col = 'blue' )
	
#plot warm losses in red
	lines(warm[,2], warm[,4], log='y', type='h', lwd=linewidth, lend=1, main = "IR7", xlab="s[m]", ylab = expression(paste("Inefficiency ", eta, " [", m^-1, "]")), xlim = xlimits, yaxt='n', col = 'red' )

	
#plot everything in black
	#plot(final[,2], final[,3], log='y', type='h', lwd=linewidth, lend=1, main = paste(name), xlab="s[m]", ylab="# losses", xlim=c(0,30000), yaxt='n', panel.first=grid(equilogs=FALSE, lwd = linewidth/4 ) )

	
	
#IR7
	#hist(c, breaks = breakers, xlim=c(19700,20600))


