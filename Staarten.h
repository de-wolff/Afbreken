/*
 * Staarten.h
 *
 *  Created on: Jan 18, 2014
 *      Author: jaap
 */

#ifndef STAARTEN_H_
#define STAARTEN_H_
#include <map>

#include "Letter.h"
#include "EnumComparer.h"
#include "VectorComparer.h"

namespace Afbreken
{
  typedef enum {
  st_b, st_bd, st_bs, st_bt, st_c, st_ck, st_ckt, st_cs, st_cst, st_ct,
  st_cts, st_ctst, st_d, st_ds, st_dst, st_dt, st_f, st_fd, st_fds, st_fdst,
  st_fdt, st_ff, st_fs, st_fst, st_ft, st_fts, st_ftst, st_g, st_gd, st_gdst,
  st_gdt, st_gn, st_gs, st_gst, st_gt, st_h, st_hn, st_hnd, st_i, st_id,
  st_idst, st_ig, st_il, st_in, st_ind, st_int, st_ir, st_irs, st_irst,
  st_irt, st_is, st_isd, st_ist, st_it, st_j, st_js, st_k, st_ks, st_kst,
  st_kt, st_ktst, st_l, st_ld, st_lds, st_ldst, st_ldt, st_lf, st_lfd,
  st_lfdst, st_lfs, st_lft, st_lfts, st_lg, st_lgd, st_lgdst, st_lgt, st_lk,
  st_lks, st_lkst, st_lkt, st_lktst, st_ll, st_lls, st_lm, st_lmd, st_lms,
  st_lmst, st_lmt, st_lp, st_lps, st_lpst, st_lpt, st_ls, st_lsd, st_lst,
  st_lt, st_lts, st_m, st_mb, st_mbt, st_mbts, st_md, st_mds, st_mdst, st_mdt,
  st_mf, st_mp, st_mps, st_mpst, st_mpt, st_mptst, st_ms, st_msj, st_msjt,
  st_mst, st_mt, st_n, st_nc, st_nct, st_nd, st_nds, st_ndst, st_ndt, st_ng,
  st_ngd, st_ngdst, st_ngs, st_ngst, st_ngt, st_nk, st_nks, st_nkst, st_nkt,
  st_ns, st_nsd, st_nst, st_nt, st_nts, st_ntst, st_nx, st_nch, st_p, st_ps,
  st_pst, st_pt, st_pts, st_ptst, st_r, st_rc, st_rct, st_rd, st_rds, st_rdst,
  st_rdt, st_rf, st_rfd, st_rfdst, st_rfst, st_rft, st_rftst, st_rg, st_rgd,
  st_rgdst, st_rgs, st_rgst, st_rgt, st_rk, st_rks, st_rkst, st_rkt, st_rktst,
  st_rl, st_rld, st_rlt, st_rm, st_rmd, st_rmdst, st_rms, st_rmst, st_rmt,
  st_rn, st_rnd, st_rndst, st_rns, st_rnst, st_rnt, st_rp, st_rps, st_rpst,
  st_rpt, st_rs, st_rsd, st_rst, st_rsch, st_rt, st_rts, st_rtst, st_rv,
  st_rw, st_rwd, st_rwst, st_rwt, st_rz, st_rch, st_rcht, st_s, st_sc, st_sd,
  st_sh, st_sht, st_sj, st_sk, st_sks, st_skst, st_sp, st_spt, st_st, st_sts,
  st_sch, st_scht, st_t, st_th, st_ts, st_tsj, st_tst, st_tsch, st_tz, st_v,
  st_w, st_wd, st_wds, st_wdst, st_wn, st_wns, st_ws, st_wst, st_wt, st_x,
  st_xt, st_z, st_ch, st_chs, st_cht, st_chts, st_chtst
} Staarten_e;

#define STAARTEN_SIZE 245

class Staarten
{
public:

  Staarten();
  Staarten_e Find(const vector<Letter> &wd, bool &ok);

private:
  VectorComparer<Letter, EnumComparer<Letter> > _Comparer;
  map<vector<Letter>, Staarten_e, VectorComparer<Letter, EnumComparer<Letter> > > _Ordered;
  static vector<Letter> _Value[STAARTEN_SIZE];
};
/*
#define StaartenBoomStart  493
extern const basischeck StaartenBoom[536];
*/

}; // namespace Afbreken




#endif /* STAARTEN_H_ */
