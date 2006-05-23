/*  ===== actuar: an R package for Actuarial Science =====
 *
 *  Fonctions to compute density, cumulative distribution and quantile
 *  fonctions of the Pareto distribution, and to simulate random
 *  variates. See ../R/pareto.R for details.
 *
 *  AUTHORS: Mathieu Pigeon and Vincent Goulet <vincent.goulet@act.ulaval.ca>
 */

#include <R.h>
#include <Rmath.h>

double rbetatrans(double shape, double scale, double gamma, double tau)
{
	double a;	

    if (!R_FINITE(shape) ||
	!R_FINITE(scale) ||
	!R_FINITE(gamma) ||
	!R_FINITE(tau) ||
	shape <= 0.0 ||
	scale <= 0.0 ||
	gamma <= 0.0 ||
	tau <= 0.0)
	error("invalid arguments");
	
	a = unif_rand();

    return scale * R_pow((qbeta(a, tau, shape, 1, 0) / (1.0 - qbeta(a, tau, shape, 1, 0))), (1.0 / gamma));
}
