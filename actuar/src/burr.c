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

double rburr(double shape, double scale, double gamma)
{
	double a;
	
    if (!R_FINITE(shape) ||
	!R_FINITE(scale) ||
	!R_FINITE(gamma) ||
	shape <= 0.0 ||
	scale <= 0.0 ||
	gamma <= 0.0)
	error("invalid arguments");

	a = unif_rand();
	
    return scale * R_pow((1.0 - R_pow(a, (1.0 / shape))) / (R_pow(a, (1.0 / shape)) ), 1.0 / gamma);
}