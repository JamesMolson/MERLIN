#include <cmath>
#include "BeamModel/PSTypes.h"
#include "Random/RandomNG.h"
#include <fstream>
#include "NumericalUtils/utils.h"

namespace {

pair<double,double> CoulombScatter(double E, double x, double theta0)
{
    static const double root3 = sqrt(3.0);
    static const double root12 = sqrt(12.0);
    static const double c1 = root3/2.0;
    static const double c2 = sqrt(1.0-c1*c1);

    double z1 = RandomNG::normal(0,1);
    double z2 = RandomNG::normal(0,1);

    double xt=x*theta0;

    double yplane = z1*xt/root12+z2*xt/2.0;
    double tplane = z2*theta0;

    return make_pair(yplane,tplane);
}
};

void ScatterParticle(PSvector& p, double t, const double E0)
{
    // compute the random energy loss (approximate formulas)
    //
    static const double MAXDP=1.0-1.0e-7;

    double E1=E0*(1+p.dp());

    double t1 = t/log(2.0);
    double t2 = 0.5*((t1-1.0)/(t1+1.0));
    double ga = pow(t1*Gamma(t1),-1.0/t1);
    double gn = pow(RandomNG::uniform(0,1),1.0/t1)/ga;


    double dp = gn-t2*gn*gn+ga*(ga*(ga-1.0)+t2)*gn*gn*gn;
    if(dp>MAXDP)
        dp=MAXDP;

    p.dp() -= dp*(1.0+p.dp());

    double E2 = E0*(1.0+p.dp());

    // compute the random angle scatter assuming that the particle has
    // an average energy of (E+E0)/2 in the collimator
    //
    double Eav = (E1+E2)/2.0;
    double theta = 0.0136*sqrt(t)*(1.0+0.038*log(t))/Eav;

    pair<double,double> s = CoulombScatter(Eav,t,theta);
    p.x() += s.first;
    p.xp()+= s.second;

    s = CoulombScatter(Eav,t,theta);
    p.y() += s.first;
    p.yp()+= s.second;
}
