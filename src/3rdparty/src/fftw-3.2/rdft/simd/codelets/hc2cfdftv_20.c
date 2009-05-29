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
/* Generated on Mon Nov 10 21:03:18 EST 2008 */

#include "codelet-rdft.h"

#ifdef HAVE_FMA

/* Generated by: ../../../genfft/gen_hc2cdft_c -fma -reorder-insns -schedule-for-pipeline -simd -compact -variables 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 20 -dit -name hc2cfdftv_20 -include hc2cfv.h */

/*
 * This function contains 143 FP additions, 128 FP multiplications,
 * (or, 77 additions, 62 multiplications, 66 fused multiply/add),
 * 130 stack variables, 5 constants, and 40 memory accesses
 */
#include "hc2cfv.h"

static void hc2cfdftv_20(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP618033988, +0.618033988749894848204586834365638117720309180);
     INT m;
     for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 38)); m < me; m = m + VL, Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms), Im = Im - (VL * ms), W = W + (TWVL * 38), MAKE_VOLATILE_STRIDE(rs)) {
	  V T2g, T2f, T2w, T2k, T2A, T2u, T2e, T2o, T1O, T2b, T2i, T1R, T1X, T1k, TN;
	  V T1w, T1G, T1t, Ti, T2c, T12, T1x, T2j, T1U, T1y, T1d, T24, T2v, T2h, T2x;
	  V T2B, T2p, T2l, T2z, T2y, T2D, T2C, T2r, T2q, T2n, T2m;
	  {
	       V T3, T7, TC, T1Y, Tc, Tg, Tn, T1P, T1Z, Tw, T1S, TS, TY, TZ, T1Q;
	       V TL, T17, T21, TW, T19, TX, T1a, T8, T20, Th, Tx, T1u, T1v, TM, T10;
	       V T1b, T22, T11, T1T, T1c, T23;
	       {
		    V Ta, Tb, Tz, Te, TB, Tf, Tl, T9, Td, Tk, T1, T2, Ty, T5, T6;
		    V TA, T4, Tj, Tt, Tu, Ts, TQ, Tr, TP, Tp, Tq, Tm, To, TO, TG;
		    V T14, TK, T16, TE, TF, Tv, TD, T13, TR, TI, TJ, TH, T15, TU, TV;
		    V TT, T18;
		    T1 = LD(&(Rp[0]), ms, &(Rp[0]));
		    T2 = LD(&(Rm[0]), -ms, &(Rm[0]));
		    Ty = LDW(&(W[0]));
		    T5 = LD(&(Rp[WS(rs, 5)]), ms, &(Rp[WS(rs, 1)]));
		    T6 = LD(&(Rm[WS(rs, 5)]), -ms, &(Rm[WS(rs, 1)]));
		    TA = LDW(&(W[TWVL * 20]));
		    T4 = LDW(&(W[TWVL * 18]));
		    Ta = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
		    Tb = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
		    T3 = VFMACONJ(T2, T1);
		    Tz = VZMULIJ(Ty, VFNMSCONJ(T2, T1));
		    Tj = LDW(&(W[TWVL * 6]));
		    Te = LD(&(Rp[WS(rs, 7)]), ms, &(Rp[WS(rs, 1)]));
		    TB = VZMULIJ(TA, VFNMSCONJ(T6, T5));
		    T7 = VZMULJ(T4, VFMACONJ(T6, T5));
		    Tf = LD(&(Rm[WS(rs, 7)]), -ms, &(Rm[WS(rs, 1)]));
		    Tl = LDW(&(W[TWVL * 26]));
		    T9 = LDW(&(W[TWVL * 8]));
		    Td = LDW(&(W[TWVL * 28]));
		    Tk = VZMULJ(Tj, VFMACONJ(Tb, Ta));
		    Tp = LD(&(Rp[WS(rs, 4)]), ms, &(Rp[0]));
		    TC = VADD(Tz, TB);
		    T1Y = VSUB(TB, Tz);
		    Tq = LD(&(Rm[WS(rs, 4)]), -ms, &(Rm[0]));
		    Tm = VZMULJ(Tl, VFMACONJ(Tf, Te));
		    Tc = VZMULIJ(T9, VFNMSCONJ(Tb, Ta));
		    Tg = VZMULIJ(Td, VFNMSCONJ(Tf, Te));
		    To = LDW(&(W[TWVL * 16]));
		    TO = LDW(&(W[TWVL * 14]));
		    Tt = LD(&(Rp[WS(rs, 9)]), ms, &(Rp[WS(rs, 1)]));
		    Tu = LD(&(Rm[WS(rs, 9)]), -ms, &(Rm[WS(rs, 1)]));
		    Ts = LDW(&(W[TWVL * 36]));
		    Tn = VADD(Tk, Tm);
		    T1P = VSUB(Tk, Tm);
		    TQ = LDW(&(W[TWVL * 34]));
		    Tr = VZMULIJ(To, VFNMSCONJ(Tq, Tp));
		    TP = VZMULJ(TO, VFMACONJ(Tq, Tp));
		    TE = LD(&(Rp[WS(rs, 8)]), ms, &(Rp[0]));
		    TF = LD(&(Rm[WS(rs, 8)]), -ms, &(Rm[0]));
		    Tv = VZMULIJ(Ts, VFNMSCONJ(Tu, Tt));
		    TD = LDW(&(W[TWVL * 30]));
		    T13 = LDW(&(W[TWVL * 32]));
		    TR = VZMULJ(TQ, VFMACONJ(Tu, Tt));
		    TI = LD(&(Rp[WS(rs, 3)]), ms, &(Rp[WS(rs, 1)]));
		    TJ = LD(&(Rm[WS(rs, 3)]), -ms, &(Rm[WS(rs, 1)]));
		    TH = LDW(&(W[TWVL * 10]));
		    T15 = LDW(&(W[TWVL * 12]));
		    T1Z = VSUB(Tv, Tr);
		    Tw = VADD(Tr, Tv);
		    TG = VZMULJ(TD, VFMACONJ(TF, TE));
		    T14 = VZMULIJ(T13, VFNMSCONJ(TF, TE));
		    T1S = VSUB(TP, TR);
		    TS = VADD(TP, TR);
		    TK = VZMULJ(TH, VFMACONJ(TJ, TI));
		    T16 = VZMULIJ(T15, VFNMSCONJ(TJ, TI));
		    TU = LD(&(Rp[WS(rs, 6)]), ms, &(Rp[0]));
		    TV = LD(&(Rm[WS(rs, 6)]), -ms, &(Rm[0]));
		    TT = LDW(&(W[TWVL * 24]));
		    T18 = LDW(&(W[TWVL * 22]));
		    TY = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
		    TZ = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
		    T1Q = VSUB(TK, TG);
		    TL = VADD(TG, TK);
		    T17 = VADD(T14, T16);
		    T21 = VSUB(T16, T14);
		    TW = VZMULIJ(TT, VFNMSCONJ(TV, TU));
		    T19 = VZMULJ(T18, VFMACONJ(TV, TU));
		    TX = LDW(&(W[TWVL * 4]));
		    T1a = LDW(&(W[TWVL * 2]));
	       }
	       T1O = VSUB(T3, T7);
	       T8 = VADD(T3, T7);
	       T20 = VADD(T1Y, T1Z);
	       T2b = VSUB(T1Y, T1Z);
	       T2i = VADD(T1P, T1Q);
	       T1R = VSUB(T1P, T1Q);
	       Th = VADD(Tc, Tg);
	       T1X = VSUB(Tg, Tc);
	       Tx = VSUB(Tn, Tw);
	       T1u = VADD(Tn, Tw);
	       T1v = VADD(TC, TL);
	       TM = VSUB(TC, TL);
	       T10 = VZMULIJ(TX, VFNMSCONJ(TZ, TY));
	       T1b = VZMULJ(T1a, VFMACONJ(TZ, TY));
	       T1k = VADD(Tx, TM);
	       TN = VSUB(Tx, TM);
	       T22 = VSUB(T10, TW);
	       T11 = VADD(TW, T10);
	       T1T = VSUB(T1b, T19);
	       T1c = VADD(T19, T1b);
	       T1w = VADD(T1u, T1v);
	       T1G = VSUB(T1u, T1v);
	       T1t = VADD(T8, Th);
	       Ti = VSUB(T8, Th);
	       T23 = VADD(T21, T22);
	       T2c = VSUB(T21, T22);
	       T12 = VSUB(TS, T11);
	       T1x = VADD(TS, T11);
	       T2j = VADD(T1S, T1T);
	       T1U = VSUB(T1S, T1T);
	       T1y = VADD(T17, T1c);
	       T1d = VSUB(T17, T1c);
	       T2g = VSUB(T23, T20);
	       T24 = VADD(T20, T23);
	  }
	  {
	       V T2d, T2t, T29, T25, T1m, T1q, T1i, T1H, T1L, T1D, T1A, T28, T1W, T1h, T1g;
	       V T1e, T1l, T1z, T1F, T1V, T1f, T1C, T1B, T26, T27, T2a, T2s, T1j, T1p, T1K;
	       V T1E, T1n, T1o, T1s, T1r, T1I, T1J, T1N, T1M;
	       T2d = VFMA(LDK(KP618033988), T2c, T2b);
	       T2t = VFNMS(LDK(KP618033988), T2b, T2c);
	       T1e = VSUB(T12, T1d);
	       T1l = VADD(T12, T1d);
	       T1z = VADD(T1x, T1y);
	       T1F = VSUB(T1x, T1y);
	       T1V = VADD(T1R, T1U);
	       T29 = VSUB(T1R, T1U);
	       T2f = VFNMS(LDK(KP250000000), T24, T1X);
	       T25 = VADD(T1X, T24);
	       T1m = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1l, T1k));
	       T1q = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1k, T1l));
	       T1i = VSUB(TN, T1e);
	       T1f = VADD(TN, T1e);
	       T1H = VMUL(LDK(KP951056516), VFNMS(LDK(KP618033988), T1G, T1F));
	       T1L = VMUL(LDK(KP951056516), VFMA(LDK(KP618033988), T1F, T1G));
	       T1D = VSUB(T1w, T1z);
	       T1A = VADD(T1w, T1z);
	       T28 = VFNMS(LDK(KP250000000), T1V, T1O);
	       T1W = VADD(T1O, T1V);
	       T1h = VFNMS(LDK(KP250000000), T1f, Ti);
	       T1g = VMUL(LDK(KP500000000), VADD(Ti, T1f));
	       T2w = VFNMS(LDK(KP618033988), T2i, T2j);
	       T2k = VFMA(LDK(KP618033988), T2j, T2i);
	       T1C = VFNMS(LDK(KP250000000), T1A, T1t);
	       T1B = VCONJ(VMUL(LDK(KP500000000), VADD(T1t, T1A)));
	       T26 = VMUL(LDK(KP500000000), VFNMSI(T25, T1W));
	       T27 = VCONJ(VMUL(LDK(KP500000000), VFMAI(T25, T1W)));
	       T2a = VFMA(LDK(KP559016994), T29, T28);
	       T2s = VFNMS(LDK(KP559016994), T29, T28);
	       ST(&(Rp[0]), T1g, ms, &(Rp[0]));
	       T1j = VFMA(LDK(KP559016994), T1i, T1h);
	       T1p = VFNMS(LDK(KP559016994), T1i, T1h);
	       ST(&(Rm[WS(rs, 9)]), T1B, -ms, &(Rm[WS(rs, 1)]));
	       T1K = VFMA(LDK(KP559016994), T1D, T1C);
	       T1E = VFNMS(LDK(KP559016994), T1D, T1C);
	       ST(&(Rm[WS(rs, 4)]), T27, -ms, &(Rm[0]));
	       ST(&(Rp[WS(rs, 5)]), T26, ms, &(Rp[WS(rs, 1)]));
	       T2A = VFMA(LDK(KP951056516), T2t, T2s);
	       T2u = VFNMS(LDK(KP951056516), T2t, T2s);
	       T2e = VFNMS(LDK(KP951056516), T2d, T2a);
	       T2o = VFMA(LDK(KP951056516), T2d, T2a);
	       T1n = VCONJ(VMUL(LDK(KP500000000), VFNMSI(T1m, T1j)));
	       T1o = VMUL(LDK(KP500000000), VFMAI(T1m, T1j));
	       T1s = VCONJ(VMUL(LDK(KP500000000), VFMAI(T1q, T1p)));
	       T1r = VMUL(LDK(KP500000000), VFNMSI(T1q, T1p));
	       T1I = VCONJ(VMUL(LDK(KP500000000), VFNMSI(T1H, T1E)));
	       T1J = VMUL(LDK(KP500000000), VFMAI(T1H, T1E));
	       T1N = VCONJ(VMUL(LDK(KP500000000), VFMAI(T1L, T1K)));
	       T1M = VMUL(LDK(KP500000000), VFNMSI(T1L, T1K));
	       ST(&(Rp[WS(rs, 4)]), T1o, ms, &(Rp[0]));
	       ST(&(Rm[WS(rs, 3)]), T1n, -ms, &(Rm[WS(rs, 1)]));
	       ST(&(Rp[WS(rs, 8)]), T1r, ms, &(Rp[0]));
	       ST(&(Rm[WS(rs, 7)]), T1s, -ms, &(Rm[WS(rs, 1)]));
	       ST(&(Rp[WS(rs, 2)]), T1J, ms, &(Rp[0]));
	       ST(&(Rm[WS(rs, 1)]), T1I, -ms, &(Rm[WS(rs, 1)]));
	       ST(&(Rp[WS(rs, 6)]), T1M, ms, &(Rp[0]));
	       ST(&(Rm[WS(rs, 5)]), T1N, -ms, &(Rm[WS(rs, 1)]));
	  }
	  T2v = VFMA(LDK(KP559016994), T2g, T2f);
	  T2h = VFNMS(LDK(KP559016994), T2g, T2f);
	  T2x = VFNMS(LDK(KP951056516), T2w, T2v);
	  T2B = VFMA(LDK(KP951056516), T2w, T2v);
	  T2p = VFMA(LDK(KP951056516), T2k, T2h);
	  T2l = VFNMS(LDK(KP951056516), T2k, T2h);
	  T2z = VMUL(LDK(KP500000000), VFMAI(T2x, T2u));
	  T2y = VCONJ(VMUL(LDK(KP500000000), VFNMSI(T2x, T2u)));
	  T2D = VMUL(LDK(KP500000000), VFMAI(T2B, T2A));
	  T2C = VCONJ(VMUL(LDK(KP500000000), VFNMSI(T2B, T2A)));
	  T2r = VCONJ(VMUL(LDK(KP500000000), VFMAI(T2p, T2o)));
	  T2q = VMUL(LDK(KP500000000), VFNMSI(T2p, T2o));
	  T2n = VCONJ(VMUL(LDK(KP500000000), VFMAI(T2l, T2e)));
	  T2m = VMUL(LDK(KP500000000), VFNMSI(T2l, T2e));
	  ST(&(Rp[WS(rs, 3)]), T2z, ms, &(Rp[WS(rs, 1)]));
	  ST(&(Rm[WS(rs, 2)]), T2y, -ms, &(Rm[0]));
	  ST(&(Rp[WS(rs, 7)]), T2D, ms, &(Rp[WS(rs, 1)]));
	  ST(&(Rm[WS(rs, 6)]), T2C, -ms, &(Rm[0]));
	  ST(&(Rm[0]), T2r, -ms, &(Rm[0]));
	  ST(&(Rp[WS(rs, 1)]), T2q, ms, &(Rp[WS(rs, 1)]));
	  ST(&(Rm[WS(rs, 8)]), T2n, -ms, &(Rm[0]));
	  ST(&(Rp[WS(rs, 9)]), T2m, ms, &(Rp[WS(rs, 1)]));
     }
}

static const tw_instr twinstr[] = {
     VTW(1, 1),
     VTW(1, 2),
     VTW(1, 3),
     VTW(1, 4),
     VTW(1, 5),
     VTW(1, 6),
     VTW(1, 7),
     VTW(1, 8),
     VTW(1, 9),
     VTW(1, 10),
     VTW(1, 11),
     VTW(1, 12),
     VTW(1, 13),
     VTW(1, 14),
     VTW(1, 15),
     VTW(1, 16),
     VTW(1, 17),
     VTW(1, 18),
     VTW(1, 19),
     {TW_NEXT, VL, 0}
};

static const hc2c_desc desc = { 20, "hc2cfdftv_20", twinstr, &GENUS, {77, 62, 66, 0} };

void X(codelet_hc2cfdftv_20) (planner *p) {
     X(khc2c_register) (p, hc2cfdftv_20, &desc, HC2C_VIA_DFT);
}
#else				/* HAVE_FMA */

/* Generated by: ../../../genfft/gen_hc2cdft_c -simd -compact -variables 4 -pipeline-latency 8 -trivial-stores -variables 32 -no-generate-bytw -n 20 -dit -name hc2cfdftv_20 -include hc2cfv.h */

/*
 * This function contains 143 FP additions, 77 FP multiplications,
 * (or, 131 additions, 65 multiplications, 12 fused multiply/add),
 * 141 stack variables, 9 constants, and 40 memory accesses
 */
#include "hc2cfv.h"

static void hc2cfdftv_20(R *Rp, R *Ip, R *Rm, R *Im, const R *W, stride rs, INT mb, INT me, INT ms)
{
     DVK(KP293892626, +0.293892626146236564584352977319536384298826219);
     DVK(KP475528258, +0.475528258147576786058219666689691071702849317);
     DVK(KP559016994, +0.559016994374947424102293417182819058860154590);
     DVK(KP250000000, +0.250000000000000000000000000000000000000000000);
     DVK(KP125000000, +0.125000000000000000000000000000000000000000000);
     DVK(KP279508497, +0.279508497187473712051146708591409529430077295);
     DVK(KP587785252, +0.587785252292473129168705954639072768597652438);
     DVK(KP951056516, +0.951056516295153572116439333379382143405698634);
     DVK(KP500000000, +0.500000000000000000000000000000000000000000000);
     INT m;
     for (m = mb, W = W + ((mb - 1) * ((TWVL / VL) * 38)); m < me; m = m + VL, Rp = Rp + (VL * ms), Ip = Ip + (VL * ms), Rm = Rm - (VL * ms), Im = Im - (VL * ms), W = W + (TWVL * 38), MAKE_VOLATILE_STRIDE(rs)) {
	  V TW, T1x, T2i, T2A, T1r, T1s, T1a, T1y, T1l, Tn, TK, TL, T1p, T1o, T27;
	  V T2t, T2a, T2u, T2e, T2C, T20, T2w, T23, T2x, T2d, T2B, T1W, T1X, T1U, T1V;
	  V T2z, T2K, T2G, T2N, T2J, T2v, T2y, T2F, T2D, T2E, T2M, T2H, T2I, T2L;
	  {
	       V T1u, T5, Tg, T1c, TV, T13, Ta, T1w, TQ, T11, TI, T1j, Tx, T18, Tl;
	       V T1e, TD, T1h, Ts, T16, T2g, T2h, T14, T19, T1f, T1k, Tb, Tm, Ty, TJ;
	       V T25, T26, T28, T29, T1Y, T1Z, T21, T22;
	       {
		    V T4, T3, T2, T1, Tf, Te, Td, Tc, T1b, TU, TT, TS, TR, T12, T9;
		    V T8, T7, T6, T1v, TP, TO, TN, TM, T10, TH, TG, TF, TE, T1i, Tw;
		    V Tv, Tu, Tt, T17, Tk, Tj, Ti, Th, T1d, TC, TB, TA, Tz, T1g, Tr;
		    V Tq, Tp, To, T15;
		    T4 = LD(&(Rp[0]), ms, &(Rp[0]));
		    T2 = LD(&(Rm[0]), -ms, &(Rm[0]));
		    T3 = VCONJ(T2);
		    T1u = VADD(T4, T3);
		    T1 = LDW(&(W[0]));
		    T5 = VZMULIJ(T1, VSUB(T3, T4));
		    Tf = LD(&(Rp[WS(rs, 4)]), ms, &(Rp[0]));
		    Td = LD(&(Rm[WS(rs, 4)]), -ms, &(Rm[0]));
		    Te = VCONJ(Td);
		    Tc = LDW(&(W[TWVL * 16]));
		    Tg = VZMULIJ(Tc, VSUB(Te, Tf));
		    T1b = LDW(&(W[TWVL * 14]));
		    T1c = VZMULJ(T1b, VADD(Te, Tf));
		    TU = LD(&(Rp[WS(rs, 7)]), ms, &(Rp[WS(rs, 1)]));
		    TS = LD(&(Rm[WS(rs, 7)]), -ms, &(Rm[WS(rs, 1)]));
		    TT = VCONJ(TS);
		    TR = LDW(&(W[TWVL * 28]));
		    TV = VZMULIJ(TR, VSUB(TT, TU));
		    T12 = LDW(&(W[TWVL * 26]));
		    T13 = VZMULJ(T12, VADD(TT, TU));
		    T9 = LD(&(Rp[WS(rs, 5)]), ms, &(Rp[WS(rs, 1)]));
		    T7 = LD(&(Rm[WS(rs, 5)]), -ms, &(Rm[WS(rs, 1)]));
		    T8 = VCONJ(T7);
		    T6 = LDW(&(W[TWVL * 20]));
		    Ta = VZMULIJ(T6, VSUB(T8, T9));
		    T1v = LDW(&(W[TWVL * 18]));
		    T1w = VZMULJ(T1v, VADD(T9, T8));
		    TP = LD(&(Rp[WS(rs, 2)]), ms, &(Rp[0]));
		    TN = LD(&(Rm[WS(rs, 2)]), -ms, &(Rm[0]));
		    TO = VCONJ(TN);
		    TM = LDW(&(W[TWVL * 8]));
		    TQ = VZMULIJ(TM, VSUB(TO, TP));
		    T10 = LDW(&(W[TWVL * 6]));
		    T11 = VZMULJ(T10, VADD(TO, TP));
		    TH = LD(&(Rp[WS(rs, 1)]), ms, &(Rp[WS(rs, 1)]));
		    TF = LD(&(Rm[WS(rs, 1)]), -ms, &(Rm[WS(rs, 1)]));
		    TG = VCONJ(TF);
		    TE = LDW(&(W[TWVL * 4]));
		    TI = VZMULIJ(TE, VSUB(TG, TH));
		    T1i = LDW(&(W[TWVL * 2]));
		    T1j = VZMULJ(T1i, VADD(TG, TH));
		    Tw = LD(&(Rp[WS(rs, 3)]), ms, &(Rp[WS(rs, 1)]));
		    Tu = LD(&(Rm[WS(rs, 3)]), -ms, &(Rm[WS(rs, 1)]));
		    Tv = VCONJ(Tu);
		    Tt = LDW(&(W[TWVL * 12]));
		    Tx = VZMULIJ(Tt, VSUB(Tv, Tw));
		    T17 = LDW(&(W[TWVL * 10]));
		    T18 = VZMULJ(T17, VADD(Tw, Tv));
		    Tk = LD(&(Rp[WS(rs, 9)]), ms, &(Rp[WS(rs, 1)]));
		    Ti = LD(&(Rm[WS(rs, 9)]), -ms, &(Rm[WS(rs, 1)]));
		    Tj = VCONJ(Ti);
		    Th = LDW(&(W[TWVL * 36]));
		    Tl = VZMULIJ(Th, VSUB(Tj, Tk));
		    T1d = LDW(&(W[TWVL * 34]));
		    T1e = VZMULJ(T1d, VADD(Tj, Tk));
		    TC = LD(&(Rp[WS(rs, 6)]), ms, &(Rp[0]));
		    TA = LD(&(Rm[WS(rs, 6)]), -ms, &(Rm[0]));
		    TB = VCONJ(TA);
		    Tz = LDW(&(W[TWVL * 24]));
		    TD = VZMULIJ(Tz, VSUB(TB, TC));
		    T1g = LDW(&(W[TWVL * 22]));
		    T1h = VZMULJ(T1g, VADD(TB, TC));
		    Tr = LD(&(Rp[WS(rs, 8)]), ms, &(Rp[0]));
		    Tp = LD(&(Rm[WS(rs, 8)]), -ms, &(Rm[0]));
		    Tq = VCONJ(Tp);
		    To = LDW(&(W[TWVL * 32]));
		    Ts = VZMULIJ(To, VSUB(Tq, Tr));
		    T15 = LDW(&(W[TWVL * 30]));
		    T16 = VZMULJ(T15, VADD(Tr, Tq));
	       }
	       TW = VSUB(TQ, TV);
	       T1x = VSUB(T1u, T1w);
	       T2g = VADD(T1u, T1w);
	       T2h = VADD(TQ, TV);
	       T2i = VADD(T2g, T2h);
	       T2A = VSUB(T2g, T2h);
	       T14 = VSUB(T11, T13);
	       T19 = VSUB(T16, T18);
	       T1r = VADD(T14, T19);
	       T1f = VSUB(T1c, T1e);
	       T1k = VSUB(T1h, T1j);
	       T1s = VADD(T1f, T1k);
	       T1a = VSUB(T14, T19);
	       T1y = VADD(T1r, T1s);
	       T1l = VSUB(T1f, T1k);
	       Tb = VSUB(T5, Ta);
	       Tm = VSUB(Tg, Tl);
	       Tn = VADD(Tb, Tm);
	       Ty = VSUB(Ts, Tx);
	       TJ = VSUB(TD, TI);
	       TK = VADD(Ty, TJ);
	       TL = VADD(Tn, TK);
	       T1p = VSUB(Ty, TJ);
	       T1o = VSUB(Tb, Tm);
	       T25 = VADD(T1c, T1e);
	       T26 = VADD(TD, TI);
	       T27 = VADD(T25, T26);
	       T2t = VSUB(T25, T26);
	       T28 = VADD(Ts, Tx);
	       T29 = VADD(T1h, T1j);
	       T2a = VADD(T28, T29);
	       T2u = VSUB(T29, T28);
	       T2e = VADD(T27, T2a);
	       T2C = VADD(T2t, T2u);
	       T1Y = VADD(T11, T13);
	       T1Z = VADD(Tg, Tl);
	       T20 = VADD(T1Y, T1Z);
	       T2w = VSUB(T1Y, T1Z);
	       T21 = VADD(T5, Ta);
	       T22 = VADD(T16, T18);
	       T23 = VADD(T21, T22);
	       T2x = VSUB(T22, T21);
	       T2d = VADD(T20, T23);
	       T2B = VADD(T2w, T2x);
	  }
	  T1U = VADD(T1x, T1y);
	  T1V = VBYI(VADD(TW, TL));
	  T1W = VMUL(LDK(KP500000000), VSUB(T1U, T1V));
	  T1X = VCONJ(VMUL(LDK(KP500000000), VADD(T1V, T1U)));
	  ST(&(Rp[WS(rs, 5)]), T1W, ms, &(Rp[WS(rs, 1)]));
	  ST(&(Rm[WS(rs, 4)]), T1X, -ms, &(Rm[0]));
	  T2v = VSUB(T2t, T2u);
	  T2y = VSUB(T2w, T2x);
	  T2z = VMUL(LDK(KP500000000), VBYI(VFNMS(LDK(KP587785252), T2y, VMUL(LDK(KP951056516), T2v))));
	  T2K = VMUL(LDK(KP500000000), VBYI(VFMA(LDK(KP951056516), T2y, VMUL(LDK(KP587785252), T2v))));
	  T2F = VMUL(LDK(KP279508497), VSUB(T2B, T2C));
	  T2D = VADD(T2B, T2C);
	  T2E = VFNMS(LDK(KP125000000), T2D, VMUL(LDK(KP500000000), T2A));
	  T2G = VSUB(T2E, T2F);
	  T2N = VCONJ(VMUL(LDK(KP500000000), VADD(T2A, T2D)));
	  T2J = VADD(T2F, T2E);
	  ST(&(Rm[WS(rs, 9)]), T2N, -ms, &(Rm[WS(rs, 1)]));
	  T2M = VCONJ(VADD(T2K, T2J));
	  ST(&(Rm[WS(rs, 5)]), T2M, -ms, &(Rm[WS(rs, 1)]));
	  T2H = VADD(T2z, T2G);
	  ST(&(Rp[WS(rs, 2)]), T2H, ms, &(Rp[0]));
	  T2I = VCONJ(VSUB(T2G, T2z));
	  ST(&(Rm[WS(rs, 1)]), T2I, -ms, &(Rm[WS(rs, 1)]));
	  T2L = VSUB(T2J, T2K);
	  ST(&(Rp[WS(rs, 6)]), T2L, ms, &(Rp[0]));
	  {
	       V T2c, T2p, T2l, T2s, T2o, T24, T2b, T2f, T2j, T2k, T2r, T2m, T2n, T2q, T1n;
	       V T1Q, T1E, T1K, T1B, T1R, T1F, T1N, T1m, T1J, TZ, T1I, TX, TY, T1q, T1M;
	       V T1A, T1L, T1t, T1z, T1C, T1S, T1T, T1D, T1G, T1O, T1P, T1H;
	       T24 = VSUB(T20, T23);
	       T2b = VSUB(T27, T2a);
	       T2c = VMUL(LDK(KP500000000), VBYI(VFMA(LDK(KP951056516), T24, VMUL(LDK(KP587785252), T2b))));
	       T2p = VMUL(LDK(KP500000000), VBYI(VFNMS(LDK(KP587785252), T24, VMUL(LDK(KP951056516), T2b))));
	       T2f = VMUL(LDK(KP279508497), VSUB(T2d, T2e));
	       T2j = VADD(T2d, T2e);
	       T2k = VFNMS(LDK(KP125000000), T2j, VMUL(LDK(KP500000000), T2i));
	       T2l = VADD(T2f, T2k);
	       T2s = VMUL(LDK(KP500000000), VADD(T2i, T2j));
	       T2o = VSUB(T2k, T2f);
	       ST(&(Rp[0]), T2s, ms, &(Rp[0]));
	       T2r = VCONJ(VADD(T2p, T2o));
	       ST(&(Rm[WS(rs, 7)]), T2r, -ms, &(Rm[WS(rs, 1)]));
	       T2m = VADD(T2c, T2l);
	       ST(&(Rp[WS(rs, 4)]), T2m, ms, &(Rp[0]));
	       T2n = VCONJ(VSUB(T2l, T2c));
	       ST(&(Rm[WS(rs, 3)]), T2n, -ms, &(Rm[WS(rs, 1)]));
	       T2q = VSUB(T2o, T2p);
	       ST(&(Rp[WS(rs, 8)]), T2q, ms, &(Rp[0]));
	       T1m = VFMA(LDK(KP951056516), T1a, VMUL(LDK(KP587785252), T1l));
	       T1J = VFNMS(LDK(KP587785252), T1a, VMUL(LDK(KP951056516), T1l));
	       TX = VFMS(LDK(KP250000000), TL, TW);
	       TY = VMUL(LDK(KP559016994), VSUB(TK, Tn));
	       TZ = VADD(TX, TY);
	       T1I = VSUB(TY, TX);
	       T1n = VMUL(LDK(KP500000000), VBYI(VSUB(TZ, T1m)));
	       T1Q = VMUL(LDK(KP500000000), VBYI(VADD(T1I, T1J)));
	       T1E = VMUL(LDK(KP500000000), VBYI(VADD(TZ, T1m)));
	       T1K = VMUL(LDK(KP500000000), VBYI(VSUB(T1I, T1J)));
	       T1q = VFMA(LDK(KP475528258), T1o, VMUL(LDK(KP293892626), T1p));
	       T1M = VFNMS(LDK(KP293892626), T1o, VMUL(LDK(KP475528258), T1p));
	       T1t = VMUL(LDK(KP279508497), VSUB(T1r, T1s));
	       T1z = VFNMS(LDK(KP125000000), T1y, VMUL(LDK(KP500000000), T1x));
	       T1A = VADD(T1t, T1z);
	       T1L = VSUB(T1z, T1t);
	       T1B = VADD(T1q, T1A);
	       T1R = VADD(T1M, T1L);
	       T1F = VSUB(T1A, T1q);
	       T1N = VSUB(T1L, T1M);
	       T1C = VADD(T1n, T1B);
	       ST(&(Rp[WS(rs, 1)]), T1C, ms, &(Rp[WS(rs, 1)]));
	       T1S = VADD(T1Q, T1R);
	       ST(&(Rp[WS(rs, 7)]), T1S, ms, &(Rp[WS(rs, 1)]));
	       T1T = VCONJ(VSUB(T1R, T1Q));
	       ST(&(Rm[WS(rs, 6)]), T1T, -ms, &(Rm[0]));
	       T1D = VCONJ(VSUB(T1B, T1n));
	       ST(&(Rm[0]), T1D, -ms, &(Rm[0]));
	       T1G = VADD(T1E, T1F);
	       ST(&(Rp[WS(rs, 9)]), T1G, ms, &(Rp[WS(rs, 1)]));
	       T1O = VADD(T1K, T1N);
	       ST(&(Rp[WS(rs, 3)]), T1O, ms, &(Rp[WS(rs, 1)]));
	       T1P = VCONJ(VSUB(T1N, T1K));
	       ST(&(Rm[WS(rs, 2)]), T1P, -ms, &(Rm[0]));
	       T1H = VCONJ(VSUB(T1F, T1E));
	       ST(&(Rm[WS(rs, 8)]), T1H, -ms, &(Rm[0]));
	  }
     }
}

static const tw_instr twinstr[] = {
     VTW(1, 1),
     VTW(1, 2),
     VTW(1, 3),
     VTW(1, 4),
     VTW(1, 5),
     VTW(1, 6),
     VTW(1, 7),
     VTW(1, 8),
     VTW(1, 9),
     VTW(1, 10),
     VTW(1, 11),
     VTW(1, 12),
     VTW(1, 13),
     VTW(1, 14),
     VTW(1, 15),
     VTW(1, 16),
     VTW(1, 17),
     VTW(1, 18),
     VTW(1, 19),
     {TW_NEXT, VL, 0}
};

static const hc2c_desc desc = { 20, "hc2cfdftv_20", twinstr, &GENUS, {131, 65, 12, 0} };

void X(codelet_hc2cfdftv_20) (planner *p) {
     X(khc2c_register) (p, hc2cfdftv_20, &desc, HC2C_VIA_DFT);
}
#endif				/* HAVE_FMA */
