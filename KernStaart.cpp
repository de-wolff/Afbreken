#include <vector>
#include <array>
#include "KernStaart.h"


namespace Afbreken
{

bool KernStaart::Find(Staarten_e  staart, Kernen_e  kern)
{
  int nKern = (int)kern;
  if (nKern >= KERNEN_SIZE) return true;
  set<Staarten_e> &rstaart = _Value[nKern];
  return (rstaart.find(staart) != rstaart.end());
}

/*
short KernStaart::Cardinaliteit[]=
        {0x98,0x92,0x7B,0x9D,0x7A,0x18,0x46,0x0E,0x16,0x3F,0x05,0x1F,0x27,0x3D,0x06,0x2B,0x3C,0x46,0x20,0x2D,0x1B};

vector<Staarten_e> KernStaart::operator [](int index)
{
  return _Value[index];
}
*/

set<Staarten_e> KernStaart::_Value[KERNEN_SIZE]= {
{st_b,st_bd,st_bs,st_bt,st_c,st_ck,st_cs,st_ct,st_ctst,st_d,st_ds,st_dst,st_dt,st_f,st_fs,st_fst,st_ft,st_g,st_gd,st_gs,st_gt,st_h,st_is,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_lf,st_lfd,st_lfs,st_lft,st_lg,st_lgd,st_lgt,st_lk,st_lks,st_lkst,st_lkt,st_ll,st_lls,st_lm,st_lmd,st_lmst,st_lmt,st_lp,st_lpt,st_ls,st_lsd,st_lst,st_lt,st_lts,st_m,st_mb,st_mbt,st_mbts,st_md,st_mdst,st_mp,st_mps,st_mpt,st_ms,st_msj,st_msjt,st_mst,st_mt,st_n,st_nc,st_nct,st_nd,st_nds,st_ndst,st_ndt,st_ng,st_ngd,st_ngs,st_ngst,st_ngt,st_nk,st_nks,st_nkst,st_nkt,st_ns,st_nsd,st_nst,st_nt,st_nts,st_ntst,st_nch,st_p,st_ps,st_pst,st_pt,st_ptst,st_r,st_rc,st_rct,st_rd,st_rds,st_rdst,st_rdt,st_rf,st_rfd,st_rft,st_rg,st_rk,st_rks,st_rkt,st_rl,st_rld,st_rlt,st_rm,st_rmd,st_rms,st_rmst,st_rmt,st_rn,st_rnd,st_rns,st_rnt,st_rp,st_rpt,st_rs,st_rst,st_rt,st_rts,st_rtst,st_rch,st_s,st_sh,st_sht,st_sj,st_sp,st_spt,st_st,st_sts,st_t,st_ts,st_tst,st_tsch,st_w,st_ws,st_x,st_xt,st_z,st_ch,st_chs,st_cht,st_chts,st_chtst},
{st_b,st_bd,st_bs,st_bt,st_c,st_ck,st_ckt,st_cs,st_ct,st_ctst,st_d,st_ds,st_dt,st_f,st_fs,st_fst,st_ft,st_g,st_gd,st_gs,st_gt,st_h,st_i,st_in,st_ind,st_is,st_ist,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_lds,st_ldst,st_ldt,st_lf,st_lfd,st_lfdst,st_lfs,st_lft,st_lfts,st_lg,st_lgd,st_lgdst,st_lgt,st_lk,st_lks,st_lkt,st_lm,st_lmd,st_lms,st_lmst,st_lmt,st_lp,st_lpt,st_ls,st_lsd,st_lst,st_lt,st_m,st_md,st_mds,st_mdst,st_mp,st_mpt,st_ms,st_mt,st_n,st_nd,st_nds,st_ndst,st_ndt,st_ng,st_ngd,st_ngdst,st_ngs,st_ngst,st_ngt,st_nk,st_nkt,st_ns,st_nsd,st_nst,st_nt,st_nts,st_ntst,st_nch,st_p,st_ps,st_pt,st_r,st_rd,st_rds,st_rdst,st_rf,st_rfd,st_rfst,st_rft,st_rg,st_rgd,st_rgst,st_rgt,st_rk,st_rks,st_rkst,st_rkt,st_rktst,st_rm,st_rmd,st_rmst,st_rmt,st_rn,st_rns,st_rnst,st_rp,st_rps,st_rpst,st_rpt,st_rs,st_rst,st_rt,st_rts,st_rtst,st_rv,st_rw,st_rwt,st_rz,st_s,st_sk,st_sp,st_spt,st_st,st_sts,st_t,st_ts,st_tst,st_w,st_x,st_xt,st_z,st_ch,st_cht,st_chts,st_chtst}, {st_b,st_bd,st_bs,st_bt,st_c,st_ck,st_ckt,st_cs,st_cst,st_ct,st_cts,st_d,st_ds,st_dt,st_f,st_fst,st_ft,st_fts,st_g,st_gd,st_gdst,st_gn,st_gs,st_gst,st_gt,st_h,st_i,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_ldst,st_lg,st_lk,st_ll,st_lm,st_lmd,st_lms,st_lmt,st_lp,st_lpt,st_ls,st_lst,st_lt,st_lts,st_m,st_md,st_mf,st_mp,st_mpst,st_mpt,st_ms,st_mst,st_mt,st_n,st_nc,st_nct,st_nd,st_nds,st_ndst,st_ndt,st_ng,st_ngd,st_ngs,st_ngst,st_ngt,st_nk,st_nks,st_nkst,st_nkt,st_ns,st_nst,st_nt,st_nts,st_nx,st_nch,st_p,st_ps,st_pst,st_pt,st_pts,st_ptst,st_r,st_rd,st_rk,st_rks,st_rkt,st_rn,st_rp,st_rpt,st_rs,st_rsch,st_rt,st_rts,st_s,st_sc,st_sh,st_sj,st_sk,st_sks,st_sp,st_spt,st_st,st_sts,st_sch,st_scht,st_t,st_th,st_ts,st_tsj,st_tst,st_tsch,st_tz,st_x,st_xt,st_z,st_ch,st_cht,st_chts,st_chtst}, {st_b,st_bd,st_bs,st_bt,st_c,st_ck,st_ckt,st_d,st_ds,st_dt,st_f,st_ff,st_fs,st_fst,st_ft,st_fts,st_ftst,st_g,st_gd,st_gs,st_gst,st_gt,st_h,st_hn,st_hnd,st_i,st_id,st_in,st_int,st_ir,st_irs,st_irst,st_irt,st_is,st_j,st_js,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_lds,st_lf,st_lfd,st_lfdst,st_lfs,st_lft,st_lg,st_lgd,st_lgt,st_lk,st_lks,st_lkst,st_lkt,st_lktst,st_ll,st_lls,st_lm,st_lmd,st_lmt,st_lp,st_lpt,st_ls,st_lst,st_lt,st_lts,st_m,st_md,st_mdst,st_mf,st_mp,st_mpst,st_mpt,st_mptst,st_ms,st_mst,st_mt,st_n,st_nd,st_nds,st_ndst,st_ndt,st_ng,st_ngd,st_ngs,st_ngst,st_ngt,st_nk,st_nkt,st_ns,st_nsd,st_nst,st_nt,st_nts,st_ntst,st_p,st_ps,st_pt,st_ptst,st_r,st_rd,st_rds,st_rdst,st_rdt,st_rf,st_rfd,st_rft,st_rg,st_rgd,st_rgdst,st_rgs,st_rgt,st_rk,st_rkt,st_rktst,st_rm,st_rmd,st_rmdst,st_rms,st_rmst,st_rmt,st_rn,st_rnd,st_rns,st_rnt,st_rp,st_rps,st_rpst,st_rpt,st_rs,st_rst,st_rt,st_rts,st_rtst,st_rch,st_s,st_sk,st_st,st_sch,st_t,st_ts,st_tst,st_v,st_w,st_wd,st_wn,st_wns,st_ws,st_x,st_xt,st_z,st_ch,st_chs,st_cht,st_chtst}, {st_b,st_bd,st_bs,st_bt,st_c,st_ck,st_cs,st_ct,st_d,st_ds,st_dt,st_f,st_ff,st_fs,st_fst,st_ft,st_ftst,st_g,st_gd,st_gs,st_gst,st_gt,st_h,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_ldst,st_ldt,st_lf,st_lk,st_lks,st_lkt,st_ll,st_lp,st_lps,st_lpst,st_lpt,st_ls,st_lst,st_lt,st_m,st_md,st_mp,st_mps,st_mpt,st_ms,st_mt,st_n,st_nc,st_nct,st_nd,st_ng,st_nk,st_nks,st_nkt,st_ns,st_nsd,st_nst,st_nt,st_nts,st_ntst,st_nch,st_p,st_ps,st_pt,st_pts,st_ptst,st_r,st_rd,st_rdst,st_rf,st_rfd,st_rfdst,st_rft,st_rftst,st_rg,st_rgd,st_rgt,st_rk,st_rks,st_rkt,st_rm,st_rmd,st_rmt,st_rn,st_rnd,st_rnt,st_rp,st_rpt,st_rs,st_rst,st_rt,st_rts,st_rw,st_rwd,st_rwst,st_rwt,st_rch,st_rcht,st_s,st_sh,st_st,st_sts,st_t,st_ts,st_tst,st_tsch,st_w,st_wd,st_ws,st_wst,st_wt,st_x,st_z,st_ch,st_cht,st_chts,st_chtst},
{st_b,st_c,st_d,st_g,st_in,st_l,st_m,st_md,st_mf,st_mp,st_mt,st_n,st_nk,st_nx,st_nch,st_p,st_ps,st_pt,st_r,st_rs,st_s,st_t,st_x,st_ch},
{st_d,st_ds,st_dst,st_dt,st_f,st_fd,st_fdst,st_fs,st_fst,st_ft,st_g,st_gd,st_gdst,st_gdt,st_gs,st_gst,st_gt,st_i,st_id,st_idst,st_ist,st_it,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_lds,st_ldst,st_lf,st_ls,st_lst,st_lt,st_m,st_md,st_mdst,st_ms,st_mst,st_mt,st_n,st_nd,st_nds,st_ndst,st_ns,st_nst,st_nt,st_p,st_ps,st_pst,st_pt,st_r,st_rd,st_rds,st_rdst,st_rdt,st_rn,st_rns,st_rs,st_rsd,st_rst,st_rt,st_rts,st_s,st_sd,st_st,st_t,st_ts,st_tst},
{st_l,st_ls,st_m,st_md,st_ms,st_mt,st_n,st_nd,st_nt,st_r,st_rs,st_rst,st_s,st_t},
{st_c,st_d,st_ds,st_f,st_h,st_k,st_kt,st_l,st_lt,st_n,st_r,st_s,st_sd,st_st,st_t,st_ts,st_w,st_wd,st_wdst,st_ws,st_wst,st_wt},
{st_d,st_ds,st_dst,st_dt,st_f,st_fd,st_fdst,st_fs,st_fst,st_ft,st_fts,st_g,st_gd,st_gs,st_gst,st_gt,st_k,st_ks,st_kt,st_l,st_ld,st_lds,st_ldst,st_ldt,st_ls,st_lst,st_lt,st_m,st_md,st_mds,st_mdst,st_mdt,st_ms,st_mst,st_mt,st_n,st_nd,st_ns,st_nst,st_nt,st_p,st_ps,st_pst,st_pt,st_r,st_rd,st_rds,st_rdst,st_rn,st_rnd,st_rns,st_rnt,st_rs,st_rst,st_rt,st_s,st_sd,st_st,st_t,st_ts,st_tst,st_ch,st_cht},
{st_w,st_wd,st_ws,st_wst,st_wt},
{st_d,st_ds,st_dst,st_dt,st_g,st_gd,st_gt,st_j,st_js,st_k,st_ks,st_kt,st_l,st_ld,st_ls,st_lst,st_lt,st_m,st_n,st_nd,st_ndt,st_ns,st_nsd,st_nst,st_nt,st_s,st_sd,st_st,st_t,st_ts,st_tst},
{st_d,st_f,st_fd,st_g,st_gd,st_gdst,st_gt,st_ig,st_il,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_ls,st_lt,st_m,st_md,st_ms,st_mt,st_n,st_nd,st_nt,st_p,st_r,st_rd,st_rdst,st_rs,st_rst,st_rt,st_s,st_sd,st_st,st_t,st_ts,st_tst,st_ch},
{st_b,st_d,st_ds,st_dst,st_dt,st_f,st_fd,st_fdst,st_fs,st_fst,st_ft,st_g,st_gd,st_gt,st_k,st_ks,st_kst,st_kt,st_l,st_ld,st_ldst,st_lp,st_ls,st_lst,st_lt,st_m,st_md,st_mp,st_ms,st_mst,st_mt,st_n,st_nd,st_ndst,st_ndt,st_ns,st_nst,st_nt,st_p,st_pt,st_r,st_rd,st_rdst,st_rf,st_rp,st_rs,st_rst,st_rt,st_s,st_sd,st_sj,st_st,st_t,st_ts,st_tst,st_w,st_wd,st_ws,st_wt,st_ch,st_cht},
{st_w,st_wd,st_wdst,st_ws,st_wst,st_wt},
{st_d,st_ds,st_dst,st_dt,st_f,st_fd,st_fdst,st_fs,st_fst,st_ft,st_g,st_gd,st_gs,st_gt,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_ls,st_lst,st_lt,st_m,st_md,st_mt,st_n,st_nd,st_ndst,st_ns,st_nsd,st_nst,st_nt,st_p,st_ps,st_pst,st_pt,st_s,st_sd,st_st,st_t,st_ts},
{st_d,st_ds,st_dst,st_dt,st_f,st_fd,st_fdst,st_fs,st_fst,st_ft,st_g,st_gd,st_gdst,st_gs,st_gst,st_gt,st_i,st_id,st_idst,st_it,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_ls,st_lst,st_lt,st_m,st_md,st_mdst,st_mp,st_mpt,st_mt,st_n,st_nd,st_ndst,st_ng,st_ns,st_nst,st_nt,st_p,st_ps,st_pt,st_r,st_rd,st_rdst,st_rs,st_rst,st_rt,st_s,st_sd,st_st,st_t,st_ts,st_tsj,st_tst,st_ch},
{st_b,st_d,st_ds,st_dst,st_dt,st_f,st_fd,st_fds,st_fdt,st_fs,st_fst,st_ft,st_g,st_gd,st_gdst,st_gdt,st_gs,st_gst,st_gt,st_i,st_id,st_idst,st_is,st_isd,st_ist,st_it,st_k,st_kt,st_ktst,st_l,st_ld,st_ldst,st_ls,st_lst,st_lt,st_m,st_md,st_mdst,st_ms,st_mst,st_mt,st_n,st_nd,st_ns,st_nst,st_nt,st_p,st_ps,st_pst,st_pt,st_r,st_rd,st_rds,st_rdst,st_rdt,st_rn,st_rnd,st_rndst,st_rns,st_rnt,st_rs,st_rst,st_rt,st_rts,st_s,st_sd,st_st,st_t,st_ts,st_tst},
{st_c,st_d,st_ds,st_dst,st_dt,st_f,st_il,st_l,st_n,st_nd,st_nds,st_nt,st_p,st_ps,st_r,st_rd,st_rgs,st_rs,st_rt,st_s,st_sd,st_st,st_t,st_ts,st_tst,st_w,st_wd,st_wds,st_wdst,st_ws,st_wst,st_wt},
{st_d,st_ds,st_dst,st_dt,st_f,st_fd,st_ft,st_g,st_gd,st_gst,st_gt,st_j,st_k,st_ks,st_kst,st_kt,st_ktst,st_l,st_ld,st_ls,st_lst,st_lt,st_m,st_md,st_mdst,st_ms,st_mst,st_mt,st_n,st_nd,st_ns,st_nst,st_nt,st_p,st_ps,st_pt,st_r,st_s,st_sd,st_st,st_t,st_ts,st_tst,st_ch,st_cht},
{st_b,st_d,st_ds,st_g,st_gd,st_gt,st_k,st_kst,st_l,st_lst,st_m,st_ms,st_n,st_nst,st_r,st_rd,st_rs,st_rst,st_rt,st_s,st_sd,st_sk,st_skst,st_st,st_t,st_ts,st_tst}
};

};
