      SUBROUTINE ACCEL(V,H,ENERGY,EGAIN,SL,PHIRF)
      IMPLICIT REAL*8 (A-H,O-Z)
C
C     THIS ROUTINE CALCULATES THE VERTICAL AND HORIZONTAL TRANSFER
C     MATRICES FOR AN ACCELERATOR SECTION
C     modification 2/98: standing wave cavity matrix
C     adiabatic damping removed by deviding all matrix elements
C     by SQRT(DET) !
C
C     INPUTS ARE:
C
C       - THE BEAM ENERGY AT THE ACC ELEMENT ENTRANCE, ENERGY (GeV)
C       - THE ACC ELEMENT ENERGY GAIN per m, EGAIN (MeV/m)
C       - THE ACC ELEMENT LENGTH, SL
C       - THE ACC ELEMENT RF PHASE PHIRF (RAD)
C
C     OUTPUTS ARE:
C
C       - THE (2X3) VERTICAL TRANSFER MATRIX, V
C       - THE (2X3) HORIZONTAL TRANSFER MATRIX, H
C
      DIMENSION V(2,3),H(2,3)
C
C----------------------------------------------------------------------
C
      CALL MUNIT(V)
      CALL MUNIT(H)
      SQ2=DSQRT(2.D0)
      SQ8=DSQRT(8.d0)
      DE=1.d-3*EGAIN*SL
C
      CP=DCOS(PHIRF)
      AL=DLOG((ENERGY+DE)/ENERGY)/(SQ8*CP)
      CA=DCOS(AL)
      SA=DSIN(AL)
C      DELTA=EGAIN/ENERGY
C      V(1,2)=SL*DLOG(1.0D0+DELTA)/DELTA
C      V(2,2)=1.0D0/(1.0D0+DELTA)
      V(1,1)=CA-SQ2*CP*SA
      V(1,2)=SQ8*SL*(ENERGY/DE)*CP*SA
      V(2,1)=-1.d-3*EGAIN/(ENERGY+DE)*(CP/SQ2+1./(SQ8*CP))*SA
      V(2,2)=(ENERGY/(ENERGY+DE))*(CA+SQ2*CP*SA)
      DET=V(1,1)*V(2,2)-V(1,2)*V(2,1)
      V(1,1)=V(1,1)/DSQRT(DET)
      V(1,2)=V(1,2)/DSQRT(DET)
      V(2,1)=V(2,1)/DSQRT(DET)
      V(2,2)=V(2,2)/DSQRT(DET)
      H(1,2)=V(1,2)
      H(2,2)=V(2,2)
      H(2,1)=V(2,1)
      H(1,1)=V(1,1)
C
      RETURN
      END
