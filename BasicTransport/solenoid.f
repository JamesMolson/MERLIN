*#######################################################################
*23456789*123456789*123456789*123456789*123456789*123456789*123456789*12
*#######################################################################
 
      subroutine MAT4_SOL(l,ks,rs)

************************************************************************
***         Calculates the 4X4 transfer matrix of a solenoid         ***
***                           Ks = Bs/B*rho                          ***
***                     This matrix is sympleptic                    ***
***        It takes the entrance and exit effects into account       ***
************************************************************************

      real l,ks,rs(4,4)

      theta=ks/2.*l
      c=cos(theta)
      s=sin(theta)
      c2=c**2
      sc=s*c
      s2=s**2

      rs(1,1)=c2
      rs(2,2)=c2
      rs(3,3)=c2
      rs(4,4)=c2

      if(theta.eq.0.) then
         rs(1,2)=0.
         rs(3,4)=0.
      else
         rs(1,2)=2.*sc/ks
         rs(3,4)=2.*sc/ks
      endif

      rs(1,3)=sc
      rs(2,4)=sc
      rs(3,1)=-sc
      rs(4,2)=-sc

      if(theta.eq.0.) then
         rs(1,4)=0.
         rs(3,2)=0.
      else
         rs(1,4)= 2.*s2/ks
         rs(3,2)=-2.*s2/ks
      endif

      rs(2,1)=-ks*sc/2.
      rs(4,3)=-ks*sc/2.

      rs(2,3)=-ks*s2/2.
      rs(4,1)= ks*s2/2.

      return
      end

*#######################################################################
*23456789*123456789*123456789*123456789*123456789*123456789*123456789*12
*#######################################################################
 
      subroutine MAT4_SOL_IN(ks,rs)

************************************************************************
***          Calculates the 4x4 entrance matrix of a solenoid        ***
***                           Ks = Bs/B*rho                          ***
************************************************************************

      real ks,rs(4,4)

      do i=1,4
         rs(i,i)=1.
         do j=i+1,4
            rs(i,j)=0.
            rs(j,i)=0.
         enddo
      enddo

      rs(2,3)= ks/2.
      rs(4,1)=-ks/2

      return
      end

*#######################################################################
*23456789*123456789*123456789*123456789*123456789*123456789*123456789*12
*#######################################################################
 
      subroutine MAT4_SOL_OUT(ks,rs)

************************************************************************
***             Calculates the 4x4 exit matrix of a solenoid         ***
***                           Ks = Bs/B*rho                          ***
************************************************************************

      real ks,rs(4,4)

      do i=1,4
         rs(i,i)=1.
         do j=i+1,4
            rs(i,j)=0.
            rs(j,i)=0.
         enddo
      enddo

      rs(2,3)=-ks/2.
      rs(4,1)= ks/2

      return
      end

*#######################################################################
*23456789*123456789*123456789*123456789*123456789*123456789*123456789*12
*#######################################################################
 
      subroutine MAT4_Q_SOL(l,k1,ks,rs)

************************************************************************
***         Calculates the 4x4 transfer matrix of a combined         ***
***                       quadrupole & solenoid                      ***
***                                                                  ***
***                           Ks = Bs/B*rho                          ***
***                          K1 = B0/a*B*rho                         ***
***                                                                  ***
***                   This matrix is not sympleptic                  ***
***     The entrance and exit effects are not taken into account     ***
************************************************************************

      real l,ks,k1,rs(4,4)        
        
      if (k1.eq.0.) then

         if(ks.eq.0.) then
*****************
****  pure drift
*****************
            do i=1,4
            rs(i,i)=1.
            do j=i+1,4
               rs(i,j)=0.
               rs(j,i)=0.
            enddo
            enddo
            rs(1,2)=l
            rs(3,4)=l

         else
********************
****  pure solenoid
********************
            theta=ks*l
            c=cos(theta)
            s=sin(theta)

            rs(1,1)=1.
            rs(2,1)=0.
            rs(3,1)=0.
            rs(4,1)=0.

            rs(1,2)=s/ks
            rs(2,2)=c
            rs(3,2)=(c-1.)/ks
            rs(4,2)=-s

            rs(1,3)=0.
            rs(2,3)=0.
            rs(3,3)=1.
            rs(4,3)=0.

            rs(1,4)=(1.-c)/ks
            rs(2,4)=s
            rs(3,4)=s/ks
            rs(4,4)=c

         endif

      else
***********************************
****  combined quadrupole solenoid
***********************************

         alpha=sqrt( (-ks**2+sqrt(ks**4+4.*k1**2))/2. )
         beta=abs(k1)/alpha

         bpa=beta+alpha
         bma=beta-alpha
         den=beta**2+alpha**2

         c=cos(beta*l)
         s=sin(beta*l)
         ch=cosh(alpha*l)
         sh=sinh(alpha*l)

         if(k1.gt.0.) then

            rs(1,1)=(alpha*bpa*c+beta*bma*ch)/den
            rs(2,2)=(beta*bpa*c-alpha*bma*ch)/den
            rs(3,3)=(-alpha*bma*c+beta*bpa*ch)/den
            rs(4,4)=(beta*bma*c+alpha*bpa*ch)/den

            rs(1,2)=(bpa*s-bma*sh)/den
            rs(2,1)=k1*(-bpa*s+bma*sh)/den
            rs(3,4)=(bma*s+bpa*sh)/den
            rs(4,3)=k1*(bma*s+bpa*sh)/den

            rs(1,3)=-ks*(alpha*s-beta*sh)/den
            rs(1,4)=-ks*(c-ch)/den
            rs(2,3)=-k1*ks*(c-ch)/den
            rs(2,4)=ks*(beta*s+alpha*sh)/den

            rs(3,1)=k1*ks*(-s/beta+sh/alpha)/den
            rs(3,2)=ks*(c-ch)/den
            rs(4,1)=k1*ks*(-c+ch)/den
            rs(4,2)=-ks*(beta*s+alpha*sh)/den

         else

            rs(3,3)=(alpha*bpa*c+beta*bma*ch)/den
            rs(4,4)=(beta*bpa*c-alpha*bma*ch)/den
            rs(1,1)=(-alpha*bma*c+beta*bpa*ch)/den
            rs(2,2)=(beta*bma*c+alpha*bpa*ch)/den

            rs(3,4)=(bpa*s-bma*sh)/den
            rs(4,3)=-k1*(-bpa*s+bma*sh)/den
            rs(1,2)=(bma*s+bpa*sh)/den
            rs(2,1)=-k1*(bma*s+bpa*sh)/den

            rs(3,1)=ks*(alpha*s-beta*sh)/den
            rs(3,2)=ks*(c-ch)/den
            rs(4,1)=-k1*ks*(c-ch)/den
            rs(4,2)=-ks*(beta*s+alpha*sh)/den

            rs(1,3)=k1*ks*(-s/beta+sh/alpha)/den
            rs(1,4)=-ks*(c-ch)/den
            rs(2,3)=k1*ks*(-c+ch)/den
            rs(2,4)=ks*(beta*s+alpha*sh)/den

         endif

      endif

      return
      end

*#######################################################################
*23456789*123456789*123456789*123456789*123456789*123456789*123456789*12
*#######################################################################
