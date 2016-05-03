/*  ===== actuar: An R Package for Actuarial Science =====
 *
 *  Functions to calculate raw moments and the moment generating
 *  function for the normal distribution. See ../R/NormalSupp.R for
 *  details.
 *
 *  AUTHORS: Christophe Dutang and Vincent Goulet <vincent.goulet@act.ulaval.ca>
 */

#include <R.h>
#include <Rmath.h>
#include "locale.h"
#include "dpq.h"

double mnorm(double order, double mean, double sd, int give_log)
{
    if (!R_FINITE(mean)  ||
        !R_FINITE(sd)    ||
        !R_FINITE(order) ||
        sd <= 0.0 ||
        (int) order != order)
        return R_NaN;

    /* Trivial case */
    if (order == 0.0)
        return 1.0;

    /* Odd moments about 0 are equal to 0 */
    if ((int) order % 2 == 1 && mean == 0.0)
        return 0.0;

    int i, n = order;
    double res = 0.0;

    for (i = 0; i <= n/2; i++)
        res += R_pow_di(sd, 2 * i) * R_pow_di(mean, n - 2 * i) /
            (R_pow_di(2, i) * gammafn(i + 1) * gammafn(order - 2 * i + 1));

    return gammafn(order + 1) * res;
}

double mgfnorm(double x, double mean, double sd, int give_log)
{
    if (!R_FINITE(mean) ||
        !R_FINITE(sd)   ||
        sd <= 0.0)
        return R_NaN;

    if (x == 0.0)
        return ACT_D_exp(0.0);

    return ACT_D_exp(x * mean + 0.5 * x * x * sd * sd) ;
}
