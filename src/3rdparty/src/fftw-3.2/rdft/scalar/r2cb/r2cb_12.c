/*
 * Copyright (c) 2003, 2007-8 Matteo Frigo
 * Copyright (c) 2003, 2007-8 Massachusetts Institute of Technology
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 */

/* This file was automatically generated --- DO NOT EDIT */
/* Generated on Mon Nov 10 20:54:30 EST 2008 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_r2cb -fma -reorder-insns -schedule-for-pipeline -compact -variables 4 -pipeline-latency 4 -sign 1 -n 12 -name r2cb_12 -include r2cb.h */

/*
 * This function contains 38 FP additions, 16 FP multiplications,
 * (or, 22 additions, 0 multiplications, 16 fused multiply/add),
 * 31 stack variables, 2 constants, and 24 memory accesses
 */
#include "r2cb.h"

static void r2cb_12(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_732050807, +1.732050807568877293527446341505872366942805254);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     INT i;
     for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(rs), MAKE_VOLATILE_STRIDE(csr), MAKE_VOLATILE_STRIDE(csi)) {
	  E Ts, Tr;
	  {
	       E Tz, Te, Tn, Tk, Tc, Tw, Ty, Th, T4, T3, Td, T5;
	       {
		    E T8, Tu, Tl, Tm, Tb, T9, Ta, T1, T2, Tv;
		    T8 = Cr[WS(csr, 3)];
		    T9 = Cr[WS(csr, 5)];
		    Ta = Cr[WS(csr, 1)];
		    Tu = Ci[WS(csi, 3)];
		    Tl = Ci[WS(csi, 5)];
		    Tm = Ci[WS(csi, 1)];
		    Tb = T9 + Ta;
		    Tz = T9 - Ta;
		    Te = Ci[WS(csi, 4)];
		    Tn = Tl - Tm;
		    Tv = Tl + Tm;
		    Tk = FNMS(KP2_000000000, T8, Tb);
		    Tc = T8 + Tb;
		    T1 = Cr[0];
		    T2 = Cr[WS(csr, 4)];
		    Tw = Tu - Tv;
		    Ty = FMA(KP2_000000000, Tu, Tv);
		    Th = Ci[WS(csi, 2)];
		    T4 = Cr[WS(csr, 6)];
		    T3 = FMA(KP2_000000000, T2, T1);
		    Td = T1 - T2;
		    T5 = Cr[WS(csr, 2)];
	       }
	       {
		    E To, Tp, Tf, Tg, T6, TA, TC;
		    To = FMA(KP1_732050807, Tn, Tk);
		    Ts = FNMS(KP1_732050807, Tn, Tk);
		    Tp = FNMS(KP1_732050807, Te, Td);
		    Tf = FMA(KP1_732050807, Te, Td);
		    Tg = T4 - T5;
		    T6 = FMA(KP2_000000000, T5, T4);
		    TA = FMA(KP1_732050807, Tz, Ty);
		    TC = FNMS(KP1_732050807, Tz, Ty);
		    {
			 E Tt, T7, Ti, Tq, Tj, TB, Tx;
			 Tt = T3 - T6;
			 T7 = T3 + T6;
			 Ti = FNMS(KP1_732050807, Th, Tg);
			 Tq = FMA(KP1_732050807, Th, Tg);
			 R0[0] = FMA(KP2_000000000, Tc, T7);
			 R0[WS(rs, 3)] = FNMS(KP2_000000000, Tc, T7);
			 Tj = Tf + Ti;
			 TB = Tf - Ti;
			 Tr = Tp + Tq;
			 Tx = Tp - Tq;
			 R1[WS(rs, 5)] = TB + TC;
			 R1[WS(rs, 2)] = TB - TC;
			 R0[WS(rs, 4)] = Tj - To;
			 R0[WS(rs, 1)] = Tj + To;
			 R1[WS(rs, 3)] = Tx + TA;
			 R1[0] = Tx - TA;
			 R1[WS(rs, 4)] = FNMS(KP2_000000000, Tw, Tt);
			 R1[WS(rs, 1)] = FMA(KP2_000000000, Tw, Tt);
		    }
	       }
	  }
	  R0[WS(rs, 2)] = Tr - Ts;
	  R0[WS(rs, 5)] = Tr + Ts;
     }
}

static const kr2c_desc desc = { 12, "r2cb_12", {22, 0, 16, 0}, &GENUS };

void X(codelet_r2cb_12) (planner *p) {
     X(kr2c_register) (p, r2cb_12, &desc);
}

#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_r2cb -compact -variables 4 -pipeline-latency 4 -sign 1 -n 12 -name r2cb_12 -include r2cb.h */

/*
 * This function contains 38 FP additions, 10 FP multiplications,
 * (or, 34 additions, 6 multiplications, 4 fused multiply/add),
 * 25 stack variables, 2 constants, and 24 memory accesses
 */
#include "r2cb.h"

static void r2cb_12(R *R0, R *R1, R *Cr, R *Ci, stride rs, stride csr, stride csi, INT v, INT ivs, INT ovs)
{
     DK(KP1_732050807, +1.732050807568877293527446341505872366942805254);
     DK(KP2_000000000, +2.000000000000000000000000000000000000000000000);
     INT i;
     for (i = v; i > 0; i = i - 1, R0 = R0 + ovs, R1 = R1 + ovs, Cr = Cr + ivs, Ci = Ci + ivs, MAKE_VOLATILE_STRIDE(rs), MAKE_VOLATILE_STRIDE(csr), MAKE_VOLATILE_STRIDE(csi)) {
	  E T8, Tb, Tm, TA, Tw, Tx, Tp, TB, T3, Tr, Tg, T6, Ts, Tk;
	  {
	       E T9, Ta, Tn, To;
	       T8 = Cr[WS(csr, 3)];
	       T9 = Cr[WS(csr, 5)];
	       Ta = Cr[WS(csr, 1)];
	       Tb = T9 + Ta;
	       Tm = FMS(KP2_000000000, T8, Tb);
	       TA = KP1_732050807 * (T9 - Ta);
	       Tw = Ci[WS(csi, 3)];
	       Tn = Ci[WS(csi, 5)];
	       To = Ci[WS(csi, 1)];
	       Tx = Tn + To;
	       Tp = KP1_732050807 * (Tn - To);
	       TB = FMA(KP2_000000000, Tw, Tx);
	  }
	  {
	       E Tf, T1, T2, Td, Te;
	       Te = Ci[WS(csi, 4)];
	       Tf = KP1_732050807 * Te;
	       T1 = Cr[0];
	       T2 = Cr[WS(csr, 4)];
	       Td = T1 - T2;
	       T3 = FMA(KP2_000000000, T2, T1);
	       Tr = Td - Tf;
	       Tg = Td + Tf;
	  }
	  {
	       E Tj, T4, T5, Th, Ti;
	       Ti = Ci[WS(csi, 2)];
	       Tj = KP1_732050807 * Ti;
	       T4 = Cr[WS(csr, 6)];
	       T5 = Cr[WS(csr, 2)];
	       Th = T4 - T5;
	       T6 = FMA(KP2_000000000, T5, T4);
	       Ts = Th + Tj;
	       Tk = Th - Tj;
	  }
	  {
	       E T7, Tc, Tz, TC;
	       T7 = T3 + T6;
	       Tc = KP2_000000000 * (T8 + Tb);
	       R0[WS(rs, 3)] = T7 - Tc;
	       R0[0] = T7 + Tc;
	       {
		    E Tl, Tq, TD, TE;
		    Tl = Tg + Tk;
		    Tq = Tm - Tp;
		    R0[WS(rs, 1)] = Tl - Tq;
		    R0[WS(rs, 4)] = Tl + Tq;
		    TD = Tg - Tk;
		    TE = TB - TA;
		    R1[WS(rs, 2)] = TD - TE;
		    R1[WS(rs, 5)] = TD + TE;
	       }
	       Tz = Tr - Ts;
	       TC = TA + TB;
	       R1[0] = Tz - TC;
	       R1[WS(rs, 3)] = Tz + TC;
	       {
		    E Tv, Ty, Tt, Tu;
		    Tv = T3 - T6;
		    Ty = KP2_000000000 * (Tw - Tx);
		    R1[WS(rs, 4)] = Tv - Ty;
		    R1[WS(rs, 1)] = Tv + Ty;
		    Tt = Tr + Ts;
		    Tu = Tm + Tp;
		    R0[WS(rs, 5)] = Tt - Tu;
		    R0[WS(rs, 2)] = Tt + Tu;
	       }
	  }
     }
}

static const kr2c_desc desc = { 12, "r2cb_12", {34, 6, 4, 0}, &GENUS };

void X(codelet_r2cb_12) (planner *p) {
     X(kr2c_register) (p, r2cb_12, &desc);
}

#endif				/* HAVE_FMA */
