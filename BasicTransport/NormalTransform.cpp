#include <cmath>
#include <cassert>
#include "BasicTransport/NormalTransform.h"
#include "BasicTransport/MatrixMaps.h"

double ProjectedEmittance(const PSmoments& s, PScoord x1, PScoord x2)
{
	return sqrt(s.variance(x1)*s.variance(x2)-pow(s(x1,x2),2));	
}

RealMatrix CouplingMatrix(double a, double b, double c, double d)
{
  RealMatrix C=IdentityMatrix(6);

  const double detB2 = b*c-a*d;
  double detB;
  double h;
  double zeta;

  if(detB2==0)
    return C;

  if(detB2>0) {
    detB = sqrt(detB2);
    h=cos(detB);
    zeta=sin(detB)/detB;
  }
  else{
    detB = sqrt(-detB2);
    h=cosh(detB);
    zeta=sinh(detB)/detB;
  }

  a*=zeta;
  b*=zeta;
  c*=zeta;
  d*=zeta;

  C(0,0)=h;
  C(1,1)=h;
  C(2,2)=h;
  C(3,3)=h;
  C(0,2)=c;
  C(0,3)=d;
  C(1,2)=-a;
  C(1,3)=-b;
  C(2,0)=b;
  C(2,1)=d;
  C(3,0)=-a;
  C(3,1)=-c;

  return C;
}

RealMatrix AlphaMatrix(double ax, double ay)
{
  RealMatrix A = IdentityMatrix(6);
  A(1,0)=-ax;
  A(3,2)=-ay;
  return A;
}

RealMatrix BetaMatrix(double bx, double by)
{
  RealMatrix B = IdentityMatrix(6);
  const double sbx=sqrt(bx);
  const double sby=sqrt(by);
  B(0,0)=sbx;
  B(1,1)=1/sbx;
  B(2,2)=sby;
  B(3,3)=1/sby;
  return B;
}

RealMatrix DispersionMatrix(double Dx, double Dxp, double Dy, double Dyp)
{
  RealMatrix D=IdentityMatrix(6);
  D(0,5)=Dx;
  D(1,5)=Dxp;
  D(2,5)=Dy;
  D(3,5)=Dyp;
  return D;
}

RealMatrix NormalTransform(const BeamData& t)
{
  assert(t.ok());
  RealMatrix D=DispersionMatrix(t.Dx,t.Dxp,t.Dy,t.Dyp);
  RealMatrix B=BetaMatrix(t.beta_x,t.beta_y);
  RealMatrix A=AlphaMatrix(t.alpha_x,t.alpha_y);
  RealMatrix C=CouplingMatrix(t.c_xy,t.c_xyp,t.c_xpy,t.c_xpyp);

  return D*B*A*C;
}


PSmoments& BeamDataToSigmaMtrx(const BeamData& t, PSmoments& S)
{
	RMtrx R(NormalTransform(t));
	S.zero();
	/**
	S(PScoord::X,PScoord::X)=t.emit_x;
	S(PScoord::XP,PScoord::XP)=t.emit_x;
	S(PScoord::Y,PScoord::XP)=t.emit_y;
	S(PScoord::YP,PScoord::XP)=t.emit_y;
	S(PScoord::CT,PScoord::XP)=pow(t.sig_z,2);
	S(PScoord::DP,PScoord::XP)=pow(t.sig_dp,2);
	**/
	S(0,0)=t.emit_x;
	S(1,1)=t.emit_x;
	S(2,2)=t.emit_y;
	S(3,3)=t.emit_y;
	S(4,4)=pow(t.sig_z,2);
	S(5,5)=pow(t.sig_dp,2);
	R.Apply(S);
	return S;
}


BeamData& SigmaMatrixToBeamData(const PSmoments& S0, BeamData& t)
{
	// Note that we do not pay attention to cross-plane coupling here,
	// so the reported emittances and beta functions will correspond
	// to the 'projected' ellipses on the respective planes

	PSmoments S=S0;
	t=BeamData();
	
	// First check if we have dispersion:
	double d2 = S.variance(ps_DP);
	if(d2!=0) {
		t.Dx = S(ps_X,ps_DP)/d2;
		t.Dxp = S(ps_XP,ps_DP)/d2;
		t.Dy = S(ps_Y,ps_DP)/d2;
		t.Dyp = S(ps_YP,ps_DP)/d2;

		// Remove energy correlations
		RMtrx D(DispersionMatrix(-t.Dx,-t.Dxp,-t.Dy,-t.Dyp));
		D.Apply(S);
	}

	t.emit_x = ProjectedEmittance(S,ps_X,ps_XP);
	t.emit_y = ProjectedEmittance(S,ps_Y,ps_YP);

	t.beta_x = S.variance(ps_X)/t.emit_x;
	t.beta_y = S.variance(ps_Y)/t.emit_y;
	t.alpha_x = -S(ps_X,ps_XP)/t.emit_x;
	t.alpha_y = -S(ps_Y,ps_YP)/t.emit_y;

	t.sig_z  = S.std(ps_CT);
	t.sig_dp = S.std(ps_DP);

	return t;
}
