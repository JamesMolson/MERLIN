# Makefile for the MERLIN Examples
# -------------------------------------
# version 1.1 20.10.2005
# Nick Walker, DESY
#

#----- Edit these lines ---------------------------------------
# the compiler to use
CPP= g++
# the root directory for the Merlin source code
MERLIN_ROOT_DIR=/afs/desy.de/user/n/njwalker/public/C++/Merlin
MERLIN_LIB_PATH=/afs/desy.de/user/n/njwalker/public/C++/merlin-unix/lib
#---------------------------------------------------------------

INCPATH= -I${MERLIN_ROOT_DIR}
CCFLAGS= -w -O3 ${INCPATH}
LDFLAGS= -L${MERLIN_LIB_PATH} -static

EGDIRS= ClosedOrbit LatticeFunctions StrayFieldClosedOrbit \
        Tracking Trajectory HaloCollimation SpinTracking ILCML \
        Wakefields AcceleratorErrors

merlin_eg:
	for dirn in ${EGDIRS}; do \
		cd $${dirn}; \
		echo "building catagory " $${dirn}; \
		${MAKE}  "CPP=${CPP}" "CCFLAGS=${CCFLAGS}" \
	                  "LDFLAGS=${LDFLAGS}" ; \
                cd .. ; \
	done


