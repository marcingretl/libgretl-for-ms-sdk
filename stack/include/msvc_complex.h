/*
 *  gretl -- Gnu Regression, Econometrics and Time-series Library
 *  Copyright (C) 2001 Allin Cottrell and Riccardo "Jack" Lucchetti
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef MSVC_COMPLEX_H
#define MSVC_COMPLEX_H

#include <math.h>

/* MSVC workaround: define a replacement struct and macros */
typedef struct {
    double real;
    double imag;
} gretl_complex;

static inline gretl_complex gretl_cexp (gretl_complex z)
{
    gretl_complex res;	
    double ex = exp(z.real);

    res.real = ex * cos(z.imag);
    res.imag = ex * sin(z.imag);

    return res;
}

#define creal(c)    ((c).real)
#define cimag(c)    ((c).imag)
#define cexp(c)		gretl_cexp(c)
#define I           (gretl_complex){0.0, 1.0}

#endif /* MSVC_COMPLEX_H */
