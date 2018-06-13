// This file is generated. Do not edit.
#ifndef AV1_RTCD_H_
#define AV1_RTCD_H_

#ifdef RTCD_C
#define RTCD_EXTERN
#else
#define RTCD_EXTERN extern
#endif

/*
 * AV1
 */

#include "aom/aom_integer.h"
#include "aom_dsp/txfm_common.h"
#include "av1/common/common.h"
#include "av1/common/enums.h"
#include "av1/common/quant_common.h"
#include "av1/common/filter.h"
#include "av1/common/convolve.h"
#include "av1/common/av1_txfm.h"
#include "av1/common/odintrin.h"
#include "av1/common/restoration.h"

struct macroblockd;

/* Encoder forward decls */
struct macroblock;
struct txfm_param;
struct aom_variance_vtable;
struct search_site_config;
struct mv;
union int_mv;
struct yv12_buffer_config;

/* Function pointers return by CfL functions */
typedef void (*cfl_subsample_lbd_fn)(const uint8_t *input, int input_stride,
                                     int16_t *output_q3);

typedef void (*cfl_subsample_hbd_fn)(const uint16_t *input, int input_stride,
                                     int16_t *output_q3);

typedef void (*cfl_subtract_average_fn)(int16_t *pred_buf_q3);

typedef void (*cfl_predict_lbd_fn)(const int16_t *pred_buf_q3, uint8_t *dst,
                                   int dst_stride, int alpha_q3);

typedef void (*cfl_predict_hbd_fn)(const int16_t *pred_buf_q3, uint16_t *dst,
                                   int dst_stride, int alpha_q3, int bd);

#ifdef __cplusplus
extern "C" {
#endif

void apply_selfguided_restoration_c(const uint8_t *dat, int width, int height, int stride, int eps, const int *xqd, uint8_t *dst, int dst_stride, int32_t *tmpbuf, int bit_depth, int highbd);
void apply_selfguided_restoration_sse4_1(const uint8_t *dat, int width, int height, int stride, int eps, const int *xqd, uint8_t *dst, int dst_stride, int32_t *tmpbuf, int bit_depth, int highbd);
void apply_selfguided_restoration_avx2(const uint8_t *dat, int width, int height, int stride, int eps, const int *xqd, uint8_t *dst, int dst_stride, int32_t *tmpbuf, int bit_depth, int highbd);
RTCD_EXTERN void (*apply_selfguided_restoration)(const uint8_t *dat, int width, int height, int stride, int eps, const int *xqd, uint8_t *dst, int dst_stride, int32_t *tmpbuf, int bit_depth, int highbd);

int64_t av1_block_error_c(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
int64_t av1_block_error_avx2(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);
RTCD_EXTERN int64_t (*av1_block_error)(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz);

void av1_convolve_2d_copy_sr_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_convolve_2d_copy_sr_sse2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_convolve_2d_copy_sr_avx2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_convolve_2d_copy_sr)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);

void av1_convolve_2d_scale_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_qn, const int x_step_qn, const int subpel_y_q4, const int y_step_qn, ConvolveParams *conv_params);
void av1_convolve_2d_scale_sse4_1(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_qn, const int x_step_qn, const int subpel_y_q4, const int y_step_qn, ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_convolve_2d_scale)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_qn, const int x_step_qn, const int subpel_y_q4, const int y_step_qn, ConvolveParams *conv_params);

void av1_convolve_2d_sr_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_convolve_2d_sr_sse2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_convolve_2d_sr_avx2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_convolve_2d_sr)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);

void av1_convolve_horiz_rs_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const int16_t *x_filters, const int x0_qn, const int x_step_qn);
void av1_convolve_horiz_rs_sse4_1(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const int16_t *x_filters, const int x0_qn, const int x_step_qn);
RTCD_EXTERN void (*av1_convolve_horiz_rs)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, const int16_t *x_filters, const int x0_qn, const int x_step_qn);

void av1_convolve_x_sr_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_convolve_x_sr_sse2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_convolve_x_sr_avx2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_convolve_x_sr)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);

void av1_convolve_y_sr_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_convolve_y_sr_sse2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_convolve_y_sr_avx2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_convolve_y_sr)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);

int av1_diamond_search_sad_c(struct macroblock *x, const struct search_site_config *cfg,  struct mv *ref_mv, struct mv *best_mv, int search_param, int sad_per_bit, int *num00, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv);
#define av1_diamond_search_sad av1_diamond_search_sad_c

void av1_dr_prediction_z1_c(uint8_t *dst, ptrdiff_t stride, int bw, int bh, const uint8_t *above, const uint8_t *left, int upsample_above, int dx, int dy);
#define av1_dr_prediction_z1 av1_dr_prediction_z1_c

void av1_dr_prediction_z2_c(uint8_t *dst, ptrdiff_t stride, int bw, int bh, const uint8_t *above, const uint8_t *left, int upsample_above, int upsample_left, int dx, int dy);
#define av1_dr_prediction_z2 av1_dr_prediction_z2_c

void av1_dr_prediction_z3_c(uint8_t *dst, ptrdiff_t stride, int bw, int bh, const uint8_t *above, const uint8_t *left, int upsample_left, int dx, int dy);
#define av1_dr_prediction_z3 av1_dr_prediction_z3_c

void av1_filter_intra_edge_c(uint8_t *p, int sz, int strength);
void av1_filter_intra_edge_sse4_1(uint8_t *p, int sz, int strength);
RTCD_EXTERN void (*av1_filter_intra_edge)(uint8_t *p, int sz, int strength);

void av1_filter_intra_edge_high_c(uint16_t *p, int sz, int strength);
void av1_filter_intra_edge_high_sse4_1(uint16_t *p, int sz, int strength);
RTCD_EXTERN void (*av1_filter_intra_edge_high)(uint16_t *p, int sz, int strength);

void av1_filter_intra_predictor_c(uint8_t *dst, ptrdiff_t stride, TX_SIZE tx_size, const uint8_t *above, const uint8_t *left, int mode);
void av1_filter_intra_predictor_sse4_1(uint8_t *dst, ptrdiff_t stride, TX_SIZE tx_size, const uint8_t *above, const uint8_t *left, int mode);
RTCD_EXTERN void (*av1_filter_intra_predictor)(uint8_t *dst, ptrdiff_t stride, TX_SIZE tx_size, const uint8_t *above, const uint8_t *left, int mode);

int av1_full_range_search_c(const struct macroblock *x, const struct search_site_config *cfg, struct mv *ref_mv, struct mv *best_mv, int search_param, int sad_per_bit, int *num00, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv);
#define av1_full_range_search av1_full_range_search_c

int av1_full_search_sad_c(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);
int av1_full_search_sadx3(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);
int av1_full_search_sadx8(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);
RTCD_EXTERN int (*av1_full_search_sad)(const struct macroblock *x, const struct mv *ref_mv, int sad_per_bit, int distance, const struct aom_variance_vtable *fn_ptr, const struct mv *center_mv, struct mv *best_mv);

void av1_fwd_idtx_c(const int16_t *src_diff, tran_low_t *coeff, int stride, int bsx, int bsy, TX_TYPE tx_type);
#define av1_fwd_idtx av1_fwd_idtx_c

void av1_fwd_txfm2d_16x16_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
void av1_fwd_txfm2d_16x16_sse4_1(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
RTCD_EXTERN void (*av1_fwd_txfm2d_16x16)(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);

void av1_fwd_txfm2d_16x32_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_16x32 av1_fwd_txfm2d_16x32_c

void av1_fwd_txfm2d_16x4_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_16x4 av1_fwd_txfm2d_16x4_c

void av1_fwd_txfm2d_16x64_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_16x64 av1_fwd_txfm2d_16x64_c

void av1_fwd_txfm2d_16x8_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_16x8 av1_fwd_txfm2d_16x8_c

void av1_fwd_txfm2d_32x16_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_32x16 av1_fwd_txfm2d_32x16_c

void av1_fwd_txfm2d_32x32_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
void av1_fwd_txfm2d_32x32_sse4_1(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
RTCD_EXTERN void (*av1_fwd_txfm2d_32x32)(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);

void av1_fwd_txfm2d_32x64_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_32x64 av1_fwd_txfm2d_32x64_c

void av1_fwd_txfm2d_32x8_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_32x8 av1_fwd_txfm2d_32x8_c

void av1_fwd_txfm2d_4x16_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_4x16 av1_fwd_txfm2d_4x16_c

void av1_fwd_txfm2d_4x4_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
void av1_fwd_txfm2d_4x4_sse4_1(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
RTCD_EXTERN void (*av1_fwd_txfm2d_4x4)(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);

void av1_fwd_txfm2d_4x8_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_4x8 av1_fwd_txfm2d_4x8_c

void av1_fwd_txfm2d_64x16_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_64x16 av1_fwd_txfm2d_64x16_c

void av1_fwd_txfm2d_64x32_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_64x32 av1_fwd_txfm2d_64x32_c

void av1_fwd_txfm2d_64x64_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_64x64 av1_fwd_txfm2d_64x64_c

void av1_fwd_txfm2d_8x16_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_8x16 av1_fwd_txfm2d_8x16_c

void av1_fwd_txfm2d_8x32_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_8x32 av1_fwd_txfm2d_8x32_c

void av1_fwd_txfm2d_8x4_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_fwd_txfm2d_8x4 av1_fwd_txfm2d_8x4_c

void av1_fwd_txfm2d_8x8_c(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
void av1_fwd_txfm2d_8x8_sse4_1(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);
RTCD_EXTERN void (*av1_fwd_txfm2d_8x8)(const int16_t *input, int32_t *output, int stride, TX_TYPE tx_type, int bd);

void av1_fwht4x4_c(const int16_t *input, tran_low_t *output, int stride);
#define av1_fwht4x4 av1_fwht4x4_c

uint32_t av1_get_crc_value_c(void *crc_calculator, uint8_t *p, int length);
uint32_t av1_get_crc_value_sse4_2(void *crc_calculator, uint8_t *p, int length);
RTCD_EXTERN uint32_t (*av1_get_crc_value)(void *crc_calculator, uint8_t *p, int length);

void av1_get_nz_map_contexts_c(const uint8_t *const levels, const int16_t *const scan, const uint16_t eob, const TX_SIZE tx_size, const TX_TYPE tx_type, int8_t *const coeff_contexts);
void av1_get_nz_map_contexts_sse2(const uint8_t *const levels, const int16_t *const scan, const uint16_t eob, const TX_SIZE tx_size, const TX_TYPE tx_type, int8_t *const coeff_contexts);
RTCD_EXTERN void (*av1_get_nz_map_contexts)(const uint8_t *const levels, const int16_t *const scan, const uint16_t eob, const TX_SIZE tx_size, const TX_TYPE tx_type, int8_t *const coeff_contexts);

int64_t av1_highbd_block_error_c(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz, int bd);
int64_t av1_highbd_block_error_sse2(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz, int bd);
RTCD_EXTERN int64_t (*av1_highbd_block_error)(const tran_low_t *coeff, const tran_low_t *dqcoeff, intptr_t block_size, int64_t *ssz, int bd);

void av1_highbd_convolve8_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, int bps);
#define av1_highbd_convolve8 av1_highbd_convolve8_c

void av1_highbd_convolve8_horiz_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, int bps);
#define av1_highbd_convolve8_horiz av1_highbd_convolve8_horiz_c

void av1_highbd_convolve8_vert_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, int bps);
#define av1_highbd_convolve8_vert av1_highbd_convolve8_vert_c

void av1_highbd_convolve_2d_copy_sr_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_convolve_2d_copy_sr_sse2(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_convolve_2d_copy_sr_avx2(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
RTCD_EXTERN void (*av1_highbd_convolve_2d_copy_sr)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);

void av1_highbd_convolve_2d_scale_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int x_step_qn, const int subpel_y_q4, const int y_step_qn, ConvolveParams *conv_params, int bd);
void av1_highbd_convolve_2d_scale_sse4_1(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int x_step_qn, const int subpel_y_q4, const int y_step_qn, ConvolveParams *conv_params, int bd);
RTCD_EXTERN void (*av1_highbd_convolve_2d_scale)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int x_step_qn, const int subpel_y_q4, const int y_step_qn, ConvolveParams *conv_params, int bd);

void av1_highbd_convolve_2d_sr_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_convolve_2d_sr_ssse3(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_convolve_2d_sr_avx2(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
RTCD_EXTERN void (*av1_highbd_convolve_2d_sr)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);

void av1_highbd_convolve_avg_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, int bps);
#define av1_highbd_convolve_avg av1_highbd_convolve_avg_c

void av1_highbd_convolve_copy_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, int bps);
#define av1_highbd_convolve_copy av1_highbd_convolve_copy_c

void av1_highbd_convolve_horiz_rs_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, const int16_t *x_filters, const int x0_qn, const int x_step_qn, int bd);
void av1_highbd_convolve_horiz_rs_sse4_1(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, const int16_t *x_filters, const int x0_qn, const int x_step_qn, int bd);
RTCD_EXTERN void (*av1_highbd_convolve_horiz_rs)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, const int16_t *x_filters, const int x0_qn, const int x_step_qn, int bd);

void av1_highbd_convolve_x_sr_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_convolve_x_sr_ssse3(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_convolve_x_sr_avx2(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
RTCD_EXTERN void (*av1_highbd_convolve_x_sr)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);

void av1_highbd_convolve_y_sr_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_convolve_y_sr_ssse3(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_convolve_y_sr_avx2(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
RTCD_EXTERN void (*av1_highbd_convolve_y_sr)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);

void av1_highbd_dr_prediction_z1_c(uint16_t *dst, ptrdiff_t stride, int bw, int bh, const uint16_t *above, const uint16_t *left, int upsample_above, int dx, int dy, int bd);
#define av1_highbd_dr_prediction_z1 av1_highbd_dr_prediction_z1_c

void av1_highbd_dr_prediction_z2_c(uint16_t *dst, ptrdiff_t stride, int bw, int bh, const uint16_t *above, const uint16_t *left, int upsample_above, int upsample_left, int dx, int dy, int bd);
#define av1_highbd_dr_prediction_z2 av1_highbd_dr_prediction_z2_c

void av1_highbd_dr_prediction_z3_c(uint16_t *dst, ptrdiff_t stride, int bw, int bh, const uint16_t *above, const uint16_t *left, int upsample_left, int dx, int dy, int bd);
#define av1_highbd_dr_prediction_z3 av1_highbd_dr_prediction_z3_c

void av1_highbd_fwht4x4_c(const int16_t *input, tran_low_t *output, int stride);
#define av1_highbd_fwht4x4 av1_highbd_fwht4x4_c

void av1_highbd_jnt_convolve_2d_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_jnt_convolve_2d_sse4_1(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_jnt_convolve_2d_avx2(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
RTCD_EXTERN void (*av1_highbd_jnt_convolve_2d)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);

void av1_highbd_jnt_convolve_2d_copy_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_jnt_convolve_2d_copy_sse4_1(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_jnt_convolve_2d_copy_avx2(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
RTCD_EXTERN void (*av1_highbd_jnt_convolve_2d_copy)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);

void av1_highbd_jnt_convolve_x_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_jnt_convolve_x_sse4_1(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_jnt_convolve_x_avx2(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
RTCD_EXTERN void (*av1_highbd_jnt_convolve_x)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);

void av1_highbd_jnt_convolve_y_c(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_jnt_convolve_y_sse4_1(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
void av1_highbd_jnt_convolve_y_avx2(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);
RTCD_EXTERN void (*av1_highbd_jnt_convolve_y)(const uint16_t *src, int src_stride, uint16_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params, int bd);

void av1_highbd_quantize_fp_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan, int log_scale);
void av1_highbd_quantize_fp_sse4_1(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan, int log_scale);
void av1_highbd_quantize_fp_avx2(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan, int log_scale);
RTCD_EXTERN void (*av1_highbd_quantize_fp)(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan, int log_scale);

void av1_highbd_temporal_filter_apply_c(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);
#define av1_highbd_temporal_filter_apply av1_highbd_temporal_filter_apply_c

void av1_highbd_warp_affine_c(const int32_t *mat, const uint16_t *ref, int width, int height, int stride, uint16_t *pred, int p_col, int p_row, int p_width, int p_height, int p_stride, int subsampling_x, int subsampling_y, int bd, ConvolveParams *conv_params, int16_t alpha, int16_t beta, int16_t gamma, int16_t delta);
void av1_highbd_warp_affine_sse4_1(const int32_t *mat, const uint16_t *ref, int width, int height, int stride, uint16_t *pred, int p_col, int p_row, int p_width, int p_height, int p_stride, int subsampling_x, int subsampling_y, int bd, ConvolveParams *conv_params, int16_t alpha, int16_t beta, int16_t gamma, int16_t delta);
RTCD_EXTERN void (*av1_highbd_warp_affine)(const int32_t *mat, const uint16_t *ref, int width, int height, int stride, uint16_t *pred, int p_col, int p_row, int p_width, int p_height, int p_stride, int subsampling_x, int subsampling_y, int bd, ConvolveParams *conv_params, int16_t alpha, int16_t beta, int16_t gamma, int16_t delta);

void av1_highbd_wiener_convolve_add_src_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, const ConvolveParams *conv_params, int bps);
void av1_highbd_wiener_convolve_add_src_ssse3(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, const ConvolveParams *conv_params, int bps);
void av1_highbd_wiener_convolve_add_src_avx2(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, const ConvolveParams *conv_params, int bps);
RTCD_EXTERN void (*av1_highbd_wiener_convolve_add_src)(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, const ConvolveParams *conv_params, int bps);

void av1_inv_txfm2d_add_16x16_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
void av1_inv_txfm2d_add_16x16_sse4_1(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
RTCD_EXTERN void (*av1_inv_txfm2d_add_16x16)(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);

void av1_inv_txfm2d_add_16x32_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_16x32 av1_inv_txfm2d_add_16x32_c

void av1_inv_txfm2d_add_16x4_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_16x4 av1_inv_txfm2d_add_16x4_c

void av1_inv_txfm2d_add_16x64_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_16x64 av1_inv_txfm2d_add_16x64_c

void av1_inv_txfm2d_add_16x8_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_16x8 av1_inv_txfm2d_add_16x8_c

void av1_inv_txfm2d_add_32x16_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_32x16 av1_inv_txfm2d_add_32x16_c

void av1_inv_txfm2d_add_32x32_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
void av1_inv_txfm2d_add_32x32_avx2(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
RTCD_EXTERN void (*av1_inv_txfm2d_add_32x32)(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);

void av1_inv_txfm2d_add_32x64_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_32x64 av1_inv_txfm2d_add_32x64_c

void av1_inv_txfm2d_add_32x8_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_32x8 av1_inv_txfm2d_add_32x8_c

void av1_inv_txfm2d_add_4x16_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_4x16 av1_inv_txfm2d_add_4x16_c

void av1_inv_txfm2d_add_4x4_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
void av1_inv_txfm2d_add_4x4_sse4_1(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
RTCD_EXTERN void (*av1_inv_txfm2d_add_4x4)(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);

void av1_inv_txfm2d_add_4x8_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_4x8 av1_inv_txfm2d_add_4x8_c

void av1_inv_txfm2d_add_64x16_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_64x16 av1_inv_txfm2d_add_64x16_c

void av1_inv_txfm2d_add_64x32_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_64x32 av1_inv_txfm2d_add_64x32_c

void av1_inv_txfm2d_add_64x64_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
void av1_inv_txfm2d_add_64x64_sse4_1(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
RTCD_EXTERN void (*av1_inv_txfm2d_add_64x64)(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);

void av1_inv_txfm2d_add_8x16_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_8x16 av1_inv_txfm2d_add_8x16_c

void av1_inv_txfm2d_add_8x32_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_8x32 av1_inv_txfm2d_add_8x32_c

void av1_inv_txfm2d_add_8x4_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
#define av1_inv_txfm2d_add_8x4 av1_inv_txfm2d_add_8x4_c

void av1_inv_txfm2d_add_8x8_c(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
void av1_inv_txfm2d_add_8x8_sse4_1(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);
RTCD_EXTERN void (*av1_inv_txfm2d_add_8x8)(const int32_t *input, uint16_t *output, int stride, TX_TYPE tx_type, int bd);

void av1_inv_txfm_add_c(const tran_low_t *dqcoeff, uint8_t *dst, int stride, const TxfmParam *txfm_param);
void av1_inv_txfm_add_ssse3(const tran_low_t *dqcoeff, uint8_t *dst, int stride, const TxfmParam *txfm_param);
void av1_inv_txfm_add_avx2(const tran_low_t *dqcoeff, uint8_t *dst, int stride, const TxfmParam *txfm_param);
RTCD_EXTERN void (*av1_inv_txfm_add)(const tran_low_t *dqcoeff, uint8_t *dst, int stride, const TxfmParam *txfm_param);

void av1_jnt_convolve_2d_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_jnt_convolve_2d_ssse3(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_jnt_convolve_2d_avx2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_jnt_convolve_2d)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);

void av1_jnt_convolve_2d_copy_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_jnt_convolve_2d_copy_sse2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_jnt_convolve_2d_copy_avx2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_jnt_convolve_2d_copy)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);

void av1_jnt_convolve_x_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_jnt_convolve_x_sse2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_jnt_convolve_x_avx2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_jnt_convolve_x)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);

void av1_jnt_convolve_y_c(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_jnt_convolve_y_sse2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
void av1_jnt_convolve_y_avx2(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_jnt_convolve_y)(const uint8_t *src, int src_stride, uint8_t *dst, int dst_stride, int w, int h, InterpFilterParams *filter_params_x, InterpFilterParams *filter_params_y, const int subpel_x_q4, const int subpel_y_q4, ConvolveParams *conv_params);

void av1_lowbd_fwd_txfm_c(const int16_t *src_diff, tran_low_t *coeff, int diff_stride, TxfmParam *txfm_param);
void av1_lowbd_fwd_txfm_sse2(const int16_t *src_diff, tran_low_t *coeff, int diff_stride, TxfmParam *txfm_param);
RTCD_EXTERN void (*av1_lowbd_fwd_txfm)(const int16_t *src_diff, tran_low_t *coeff, int diff_stride, TxfmParam *txfm_param);

void av1_quantize_b_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan, const qm_val_t * qm_ptr, const qm_val_t * iqm_ptr, int log_scale);
#define av1_quantize_b av1_quantize_b_c

void av1_quantize_fp_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void av1_quantize_fp_sse2(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void av1_quantize_fp_avx2(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
RTCD_EXTERN void (*av1_quantize_fp)(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);

void av1_quantize_fp_32x32_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
void av1_quantize_fp_32x32_avx2(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
RTCD_EXTERN void (*av1_quantize_fp_32x32)(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);

void av1_quantize_fp_64x64_c(const tran_low_t *coeff_ptr, intptr_t n_coeffs, int skip_block, const int16_t *zbin_ptr, const int16_t *round_ptr, const int16_t *quant_ptr, const int16_t *quant_shift_ptr, tran_low_t *qcoeff_ptr, tran_low_t *dqcoeff_ptr, const int16_t *dequant_ptr, uint16_t *eob_ptr, const int16_t *scan, const int16_t *iscan);
#define av1_quantize_fp_64x64 av1_quantize_fp_64x64_c

void av1_selfguided_restoration_c(const uint8_t *dgd, int width, int height, int stride, int32_t *flt0, int32_t *flt1, int flt_stride, const sgr_params_type *params, int bit_depth, int highbd);
void av1_selfguided_restoration_sse4_1(const uint8_t *dgd, int width, int height, int stride, int32_t *flt0, int32_t *flt1, int flt_stride, const sgr_params_type *params, int bit_depth, int highbd);
void av1_selfguided_restoration_avx2(const uint8_t *dgd, int width, int height, int stride, int32_t *flt0, int32_t *flt1, int flt_stride, const sgr_params_type *params, int bit_depth, int highbd);
RTCD_EXTERN void (*av1_selfguided_restoration)(const uint8_t *dgd, int width, int height, int stride, int32_t *flt0, int32_t *flt1, int flt_stride, const sgr_params_type *params, int bit_depth, int highbd);

void av1_temporal_filter_apply_c(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);
void av1_temporal_filter_apply_sse2(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);
RTCD_EXTERN void (*av1_temporal_filter_apply)(uint8_t *frame1, unsigned int stride, uint8_t *frame2, unsigned int block_width, unsigned int block_height, int strength, int filter_weight, unsigned int *accumulator, uint16_t *count);

void av1_txb_init_levels_c(const tran_low_t *const coeff, const int width, const int height, uint8_t *const levels);
void av1_txb_init_levels_sse4_1(const tran_low_t *const coeff, const int width, const int height, uint8_t *const levels);
RTCD_EXTERN void (*av1_txb_init_levels)(const tran_low_t *const coeff, const int width, const int height, uint8_t *const levels);

void av1_upsample_intra_edge_c(uint8_t *p, int sz);
void av1_upsample_intra_edge_sse4_1(uint8_t *p, int sz);
RTCD_EXTERN void (*av1_upsample_intra_edge)(uint8_t *p, int sz);

void av1_upsample_intra_edge_high_c(uint16_t *p, int sz, int bd);
void av1_upsample_intra_edge_high_sse4_1(uint16_t *p, int sz, int bd);
RTCD_EXTERN void (*av1_upsample_intra_edge_high)(uint16_t *p, int sz, int bd);

void av1_warp_affine_c(const int32_t *mat, const uint8_t *ref, int width, int height, int stride, uint8_t *pred, int p_col, int p_row, int p_width, int p_height, int p_stride, int subsampling_x, int subsampling_y, ConvolveParams *conv_params, int16_t alpha, int16_t beta, int16_t gamma, int16_t delta);
void av1_warp_affine_sse4_1(const int32_t *mat, const uint8_t *ref, int width, int height, int stride, uint8_t *pred, int p_col, int p_row, int p_width, int p_height, int p_stride, int subsampling_x, int subsampling_y, ConvolveParams *conv_params, int16_t alpha, int16_t beta, int16_t gamma, int16_t delta);
RTCD_EXTERN void (*av1_warp_affine)(const int32_t *mat, const uint8_t *ref, int width, int height, int stride, uint8_t *pred, int p_col, int p_row, int p_width, int p_height, int p_stride, int subsampling_x, int subsampling_y, ConvolveParams *conv_params, int16_t alpha, int16_t beta, int16_t gamma, int16_t delta);

void av1_wedge_compute_delta_squares_c(int16_t *d, const int16_t *a, const int16_t *b, int N);
void av1_wedge_compute_delta_squares_sse2(int16_t *d, const int16_t *a, const int16_t *b, int N);
RTCD_EXTERN void (*av1_wedge_compute_delta_squares)(int16_t *d, const int16_t *a, const int16_t *b, int N);

int av1_wedge_sign_from_residuals_c(const int16_t *ds, const uint8_t *m, int N, int64_t limit);
int av1_wedge_sign_from_residuals_sse2(const int16_t *ds, const uint8_t *m, int N, int64_t limit);
RTCD_EXTERN int (*av1_wedge_sign_from_residuals)(const int16_t *ds, const uint8_t *m, int N, int64_t limit);

uint64_t av1_wedge_sse_from_residuals_c(const int16_t *r1, const int16_t *d, const uint8_t *m, int N);
uint64_t av1_wedge_sse_from_residuals_sse2(const int16_t *r1, const int16_t *d, const uint8_t *m, int N);
RTCD_EXTERN uint64_t (*av1_wedge_sse_from_residuals)(const int16_t *r1, const int16_t *d, const uint8_t *m, int N);

void av1_wiener_convolve_add_src_c(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, const ConvolveParams *conv_params);
void av1_wiener_convolve_add_src_sse2(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, const ConvolveParams *conv_params);
void av1_wiener_convolve_add_src_avx2(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, const ConvolveParams *conv_params);
RTCD_EXTERN void (*av1_wiener_convolve_add_src)(const uint8_t *src, ptrdiff_t src_stride, uint8_t *dst, ptrdiff_t dst_stride, const int16_t *filter_x, int x_step_q4, const int16_t *filter_y, int y_step_q4, int w, int h, const ConvolveParams *conv_params);

void cdef_filter_block_c(uint8_t *dst8, uint16_t *dst16, int dstride, const uint16_t *in, int pri_strength, int sec_strength, int dir, int pri_damping, int sec_damping, int bsize, int max, int coeff_shift);
void cdef_filter_block_sse2(uint8_t *dst8, uint16_t *dst16, int dstride, const uint16_t *in, int pri_strength, int sec_strength, int dir, int pri_damping, int sec_damping, int bsize, int max, int coeff_shift);
void cdef_filter_block_ssse3(uint8_t *dst8, uint16_t *dst16, int dstride, const uint16_t *in, int pri_strength, int sec_strength, int dir, int pri_damping, int sec_damping, int bsize, int max, int coeff_shift);
void cdef_filter_block_sse4_1(uint8_t *dst8, uint16_t *dst16, int dstride, const uint16_t *in, int pri_strength, int sec_strength, int dir, int pri_damping, int sec_damping, int bsize, int max, int coeff_shift);
void cdef_filter_block_avx2(uint8_t *dst8, uint16_t *dst16, int dstride, const uint16_t *in, int pri_strength, int sec_strength, int dir, int pri_damping, int sec_damping, int bsize, int max, int coeff_shift);
RTCD_EXTERN void (*cdef_filter_block)(uint8_t *dst8, uint16_t *dst16, int dstride, const uint16_t *in, int pri_strength, int sec_strength, int dir, int pri_damping, int sec_damping, int bsize, int max, int coeff_shift);

int cdef_find_dir_c(const uint16_t *img, int stride, int32_t *var, int coeff_shift);
int cdef_find_dir_sse2(const uint16_t *img, int stride, int32_t *var, int coeff_shift);
int cdef_find_dir_ssse3(const uint16_t *img, int stride, int32_t *var, int coeff_shift);
int cdef_find_dir_sse4_1(const uint16_t *img, int stride, int32_t *var, int coeff_shift);
int cdef_find_dir_avx2(const uint16_t *img, int stride, int32_t *var, int coeff_shift);
RTCD_EXTERN int (*cdef_find_dir)(const uint16_t *img, int stride, int32_t *var, int coeff_shift);

cfl_subsample_lbd_fn cfl_get_luma_subsampling_420_lbd_c(TX_SIZE tx_size);
cfl_subsample_lbd_fn cfl_get_luma_subsampling_420_lbd_ssse3(TX_SIZE tx_size);
cfl_subsample_lbd_fn cfl_get_luma_subsampling_420_lbd_avx2(TX_SIZE tx_size);
RTCD_EXTERN cfl_subsample_lbd_fn (*cfl_get_luma_subsampling_420_lbd)(TX_SIZE tx_size);

double compute_cross_correlation_c(unsigned char *im1, int stride1, int x1, int y1, unsigned char *im2, int stride2, int x2, int y2);
double compute_cross_correlation_sse4_1(unsigned char *im1, int stride1, int x1, int y1, unsigned char *im2, int stride2, int x2, int y2);
RTCD_EXTERN double (*compute_cross_correlation)(unsigned char *im1, int stride1, int x1, int y1, unsigned char *im2, int stride2, int x2, int y2);

void copy_rect8_16bit_to_16bit_c(uint16_t *dst, int dstride, const uint16_t *src, int sstride, int v, int h);
void copy_rect8_16bit_to_16bit_sse2(uint16_t *dst, int dstride, const uint16_t *src, int sstride, int v, int h);
void copy_rect8_16bit_to_16bit_ssse3(uint16_t *dst, int dstride, const uint16_t *src, int sstride, int v, int h);
void copy_rect8_16bit_to_16bit_sse4_1(uint16_t *dst, int dstride, const uint16_t *src, int sstride, int v, int h);
void copy_rect8_16bit_to_16bit_avx2(uint16_t *dst, int dstride, const uint16_t *src, int sstride, int v, int h);
RTCD_EXTERN void (*copy_rect8_16bit_to_16bit)(uint16_t *dst, int dstride, const uint16_t *src, int sstride, int v, int h);

void copy_rect8_8bit_to_16bit_c(uint16_t *dst, int dstride, const uint8_t *src, int sstride, int v, int h);
void copy_rect8_8bit_to_16bit_sse2(uint16_t *dst, int dstride, const uint8_t *src, int sstride, int v, int h);
void copy_rect8_8bit_to_16bit_ssse3(uint16_t *dst, int dstride, const uint8_t *src, int sstride, int v, int h);
void copy_rect8_8bit_to_16bit_sse4_1(uint16_t *dst, int dstride, const uint8_t *src, int sstride, int v, int h);
void copy_rect8_8bit_to_16bit_avx2(uint16_t *dst, int dstride, const uint8_t *src, int sstride, int v, int h);
RTCD_EXTERN void (*copy_rect8_8bit_to_16bit)(uint16_t *dst, int dstride, const uint8_t *src, int sstride, int v, int h);

cfl_predict_hbd_fn get_predict_hbd_fn_c(TX_SIZE tx_size);
cfl_predict_hbd_fn get_predict_hbd_fn_ssse3(TX_SIZE tx_size);
cfl_predict_hbd_fn get_predict_hbd_fn_avx2(TX_SIZE tx_size);
RTCD_EXTERN cfl_predict_hbd_fn (*get_predict_hbd_fn)(TX_SIZE tx_size);

cfl_predict_lbd_fn get_predict_lbd_fn_c(TX_SIZE tx_size);
cfl_predict_lbd_fn get_predict_lbd_fn_ssse3(TX_SIZE tx_size);
cfl_predict_lbd_fn get_predict_lbd_fn_avx2(TX_SIZE tx_size);
RTCD_EXTERN cfl_predict_lbd_fn (*get_predict_lbd_fn)(TX_SIZE tx_size);

cfl_subtract_average_fn get_subtract_average_fn_c(TX_SIZE tx_size);
cfl_subtract_average_fn get_subtract_average_fn_sse2(TX_SIZE tx_size);
cfl_subtract_average_fn get_subtract_average_fn_avx2(TX_SIZE tx_size);
RTCD_EXTERN cfl_subtract_average_fn (*get_subtract_average_fn)(TX_SIZE tx_size);

void av1_rtcd(void);

#ifdef RTCD_C
#include "aom_ports/x86.h"
static void setup_rtcd_internal(void)
{
    int flags = x86_simd_caps();

    (void)flags;

    apply_selfguided_restoration = apply_selfguided_restoration_c;
    if (flags & HAS_SSE4_1) apply_selfguided_restoration = apply_selfguided_restoration_sse4_1;
    if (flags & HAS_AVX2) apply_selfguided_restoration = apply_selfguided_restoration_avx2;
    av1_block_error = av1_block_error_c;
    if (flags & HAS_AVX2) av1_block_error = av1_block_error_avx2;
    av1_convolve_2d_copy_sr = av1_convolve_2d_copy_sr_c;
    if (flags & HAS_SSE2) av1_convolve_2d_copy_sr = av1_convolve_2d_copy_sr_sse2;
    if (flags & HAS_AVX2) av1_convolve_2d_copy_sr = av1_convolve_2d_copy_sr_avx2;
    av1_convolve_2d_scale = av1_convolve_2d_scale_c;
    if (flags & HAS_SSE4_1) av1_convolve_2d_scale = av1_convolve_2d_scale_sse4_1;
    av1_convolve_2d_sr = av1_convolve_2d_sr_c;
    if (flags & HAS_SSE2) av1_convolve_2d_sr = av1_convolve_2d_sr_sse2;
    if (flags & HAS_AVX2) av1_convolve_2d_sr = av1_convolve_2d_sr_avx2;
    av1_convolve_horiz_rs = av1_convolve_horiz_rs_c;
    if (flags & HAS_SSE4_1) av1_convolve_horiz_rs = av1_convolve_horiz_rs_sse4_1;
    av1_convolve_x_sr = av1_convolve_x_sr_c;
    if (flags & HAS_SSE2) av1_convolve_x_sr = av1_convolve_x_sr_sse2;
    if (flags & HAS_AVX2) av1_convolve_x_sr = av1_convolve_x_sr_avx2;
    av1_convolve_y_sr = av1_convolve_y_sr_c;
    if (flags & HAS_SSE2) av1_convolve_y_sr = av1_convolve_y_sr_sse2;
    if (flags & HAS_AVX2) av1_convolve_y_sr = av1_convolve_y_sr_avx2;
    av1_filter_intra_edge = av1_filter_intra_edge_c;
    if (flags & HAS_SSE4_1) av1_filter_intra_edge = av1_filter_intra_edge_sse4_1;
    av1_filter_intra_edge_high = av1_filter_intra_edge_high_c;
    if (flags & HAS_SSE4_1) av1_filter_intra_edge_high = av1_filter_intra_edge_high_sse4_1;
    av1_filter_intra_predictor = av1_filter_intra_predictor_c;
    if (flags & HAS_SSE4_1) av1_filter_intra_predictor = av1_filter_intra_predictor_sse4_1;
    av1_full_search_sad = av1_full_search_sad_c;
    if (flags & HAS_SSE3) av1_full_search_sad = av1_full_search_sadx3;
    if (flags & HAS_SSE4_1) av1_full_search_sad = av1_full_search_sadx8;
    av1_fwd_txfm2d_16x16 = av1_fwd_txfm2d_16x16_c;
    if (flags & HAS_SSE4_1) av1_fwd_txfm2d_16x16 = av1_fwd_txfm2d_16x16_sse4_1;
    av1_fwd_txfm2d_32x32 = av1_fwd_txfm2d_32x32_c;
    if (flags & HAS_SSE4_1) av1_fwd_txfm2d_32x32 = av1_fwd_txfm2d_32x32_sse4_1;
    av1_fwd_txfm2d_4x4 = av1_fwd_txfm2d_4x4_c;
    if (flags & HAS_SSE4_1) av1_fwd_txfm2d_4x4 = av1_fwd_txfm2d_4x4_sse4_1;
    av1_fwd_txfm2d_8x8 = av1_fwd_txfm2d_8x8_c;
    if (flags & HAS_SSE4_1) av1_fwd_txfm2d_8x8 = av1_fwd_txfm2d_8x8_sse4_1;
    av1_get_crc_value = av1_get_crc_value_c;
    if (flags & HAS_SSE4_2) av1_get_crc_value = av1_get_crc_value_sse4_2;
    av1_get_nz_map_contexts = av1_get_nz_map_contexts_c;
    if (flags & HAS_SSE2) av1_get_nz_map_contexts = av1_get_nz_map_contexts_sse2;
    av1_highbd_block_error = av1_highbd_block_error_c;
    if (flags & HAS_SSE2) av1_highbd_block_error = av1_highbd_block_error_sse2;
    av1_highbd_convolve_2d_copy_sr = av1_highbd_convolve_2d_copy_sr_c;
    if (flags & HAS_SSE2) av1_highbd_convolve_2d_copy_sr = av1_highbd_convolve_2d_copy_sr_sse2;
    if (flags & HAS_AVX2) av1_highbd_convolve_2d_copy_sr = av1_highbd_convolve_2d_copy_sr_avx2;
    av1_highbd_convolve_2d_scale = av1_highbd_convolve_2d_scale_c;
    if (flags & HAS_SSE4_1) av1_highbd_convolve_2d_scale = av1_highbd_convolve_2d_scale_sse4_1;
    av1_highbd_convolve_2d_sr = av1_highbd_convolve_2d_sr_c;
    if (flags & HAS_SSSE3) av1_highbd_convolve_2d_sr = av1_highbd_convolve_2d_sr_ssse3;
    if (flags & HAS_AVX2) av1_highbd_convolve_2d_sr = av1_highbd_convolve_2d_sr_avx2;
    av1_highbd_convolve_horiz_rs = av1_highbd_convolve_horiz_rs_c;
    if (flags & HAS_SSE4_1) av1_highbd_convolve_horiz_rs = av1_highbd_convolve_horiz_rs_sse4_1;
    av1_highbd_convolve_x_sr = av1_highbd_convolve_x_sr_c;
    if (flags & HAS_SSSE3) av1_highbd_convolve_x_sr = av1_highbd_convolve_x_sr_ssse3;
    if (flags & HAS_AVX2) av1_highbd_convolve_x_sr = av1_highbd_convolve_x_sr_avx2;
    av1_highbd_convolve_y_sr = av1_highbd_convolve_y_sr_c;
    if (flags & HAS_SSSE3) av1_highbd_convolve_y_sr = av1_highbd_convolve_y_sr_ssse3;
    if (flags & HAS_AVX2) av1_highbd_convolve_y_sr = av1_highbd_convolve_y_sr_avx2;
    av1_highbd_jnt_convolve_2d = av1_highbd_jnt_convolve_2d_c;
    if (flags & HAS_SSE4_1) av1_highbd_jnt_convolve_2d = av1_highbd_jnt_convolve_2d_sse4_1;
    if (flags & HAS_AVX2) av1_highbd_jnt_convolve_2d = av1_highbd_jnt_convolve_2d_avx2;
    av1_highbd_jnt_convolve_2d_copy = av1_highbd_jnt_convolve_2d_copy_c;
    if (flags & HAS_SSE4_1) av1_highbd_jnt_convolve_2d_copy = av1_highbd_jnt_convolve_2d_copy_sse4_1;
    if (flags & HAS_AVX2) av1_highbd_jnt_convolve_2d_copy = av1_highbd_jnt_convolve_2d_copy_avx2;
    av1_highbd_jnt_convolve_x = av1_highbd_jnt_convolve_x_c;
    if (flags & HAS_SSE4_1) av1_highbd_jnt_convolve_x = av1_highbd_jnt_convolve_x_sse4_1;
    if (flags & HAS_AVX2) av1_highbd_jnt_convolve_x = av1_highbd_jnt_convolve_x_avx2;
    av1_highbd_jnt_convolve_y = av1_highbd_jnt_convolve_y_c;
    if (flags & HAS_SSE4_1) av1_highbd_jnt_convolve_y = av1_highbd_jnt_convolve_y_sse4_1;
    if (flags & HAS_AVX2) av1_highbd_jnt_convolve_y = av1_highbd_jnt_convolve_y_avx2;
    av1_highbd_quantize_fp = av1_highbd_quantize_fp_c;
    if (flags & HAS_SSE4_1) av1_highbd_quantize_fp = av1_highbd_quantize_fp_sse4_1;
    if (flags & HAS_AVX2) av1_highbd_quantize_fp = av1_highbd_quantize_fp_avx2;
    av1_highbd_warp_affine = av1_highbd_warp_affine_c;
    if (flags & HAS_SSE4_1) av1_highbd_warp_affine = av1_highbd_warp_affine_sse4_1;
    av1_highbd_wiener_convolve_add_src = av1_highbd_wiener_convolve_add_src_c;
    if (flags & HAS_SSSE3) av1_highbd_wiener_convolve_add_src = av1_highbd_wiener_convolve_add_src_ssse3;
    if (flags & HAS_AVX2) av1_highbd_wiener_convolve_add_src = av1_highbd_wiener_convolve_add_src_avx2;
    av1_inv_txfm2d_add_16x16 = av1_inv_txfm2d_add_16x16_c;
    if (flags & HAS_SSE4_1) av1_inv_txfm2d_add_16x16 = av1_inv_txfm2d_add_16x16_sse4_1;
    av1_inv_txfm2d_add_32x32 = av1_inv_txfm2d_add_32x32_c;
    if (flags & HAS_AVX2) av1_inv_txfm2d_add_32x32 = av1_inv_txfm2d_add_32x32_avx2;
    av1_inv_txfm2d_add_4x4 = av1_inv_txfm2d_add_4x4_c;
    if (flags & HAS_SSE4_1) av1_inv_txfm2d_add_4x4 = av1_inv_txfm2d_add_4x4_sse4_1;
    av1_inv_txfm2d_add_64x64 = av1_inv_txfm2d_add_64x64_c;
    if (flags & HAS_SSE4_1) av1_inv_txfm2d_add_64x64 = av1_inv_txfm2d_add_64x64_sse4_1;
    av1_inv_txfm2d_add_8x8 = av1_inv_txfm2d_add_8x8_c;
    if (flags & HAS_SSE4_1) av1_inv_txfm2d_add_8x8 = av1_inv_txfm2d_add_8x8_sse4_1;
    av1_inv_txfm_add = av1_inv_txfm_add_c;
    if (flags & HAS_SSSE3) av1_inv_txfm_add = av1_inv_txfm_add_ssse3;
    if (flags & HAS_AVX2) av1_inv_txfm_add = av1_inv_txfm_add_avx2;
    av1_jnt_convolve_2d = av1_jnt_convolve_2d_c;
    if (flags & HAS_SSSE3) av1_jnt_convolve_2d = av1_jnt_convolve_2d_ssse3;
    if (flags & HAS_AVX2) av1_jnt_convolve_2d = av1_jnt_convolve_2d_avx2;
    av1_jnt_convolve_2d_copy = av1_jnt_convolve_2d_copy_c;
    if (flags & HAS_SSE2) av1_jnt_convolve_2d_copy = av1_jnt_convolve_2d_copy_sse2;
    if (flags & HAS_AVX2) av1_jnt_convolve_2d_copy = av1_jnt_convolve_2d_copy_avx2;
    av1_jnt_convolve_x = av1_jnt_convolve_x_c;
    if (flags & HAS_SSE2) av1_jnt_convolve_x = av1_jnt_convolve_x_sse2;
    if (flags & HAS_AVX2) av1_jnt_convolve_x = av1_jnt_convolve_x_avx2;
    av1_jnt_convolve_y = av1_jnt_convolve_y_c;
    if (flags & HAS_SSE2) av1_jnt_convolve_y = av1_jnt_convolve_y_sse2;
    if (flags & HAS_AVX2) av1_jnt_convolve_y = av1_jnt_convolve_y_avx2;
    av1_lowbd_fwd_txfm = av1_lowbd_fwd_txfm_c;
    if (flags & HAS_SSE2) av1_lowbd_fwd_txfm = av1_lowbd_fwd_txfm_sse2;
    av1_quantize_fp = av1_quantize_fp_c;
    if (flags & HAS_SSE2) av1_quantize_fp = av1_quantize_fp_sse2;
    if (flags & HAS_AVX2) av1_quantize_fp = av1_quantize_fp_avx2;
    av1_quantize_fp_32x32 = av1_quantize_fp_32x32_c;
    if (flags & HAS_AVX2) av1_quantize_fp_32x32 = av1_quantize_fp_32x32_avx2;
    av1_selfguided_restoration = av1_selfguided_restoration_c;
    if (flags & HAS_SSE4_1) av1_selfguided_restoration = av1_selfguided_restoration_sse4_1;
    if (flags & HAS_AVX2) av1_selfguided_restoration = av1_selfguided_restoration_avx2;
    av1_temporal_filter_apply = av1_temporal_filter_apply_c;
    if (flags & HAS_SSE2) av1_temporal_filter_apply = av1_temporal_filter_apply_sse2;
    av1_txb_init_levels = av1_txb_init_levels_c;
    if (flags & HAS_SSE4_1) av1_txb_init_levels = av1_txb_init_levels_sse4_1;
    av1_upsample_intra_edge = av1_upsample_intra_edge_c;
    if (flags & HAS_SSE4_1) av1_upsample_intra_edge = av1_upsample_intra_edge_sse4_1;
    av1_upsample_intra_edge_high = av1_upsample_intra_edge_high_c;
    if (flags & HAS_SSE4_1) av1_upsample_intra_edge_high = av1_upsample_intra_edge_high_sse4_1;
    av1_warp_affine = av1_warp_affine_c;
    if (flags & HAS_SSE4_1) av1_warp_affine = av1_warp_affine_sse4_1;
    av1_wedge_compute_delta_squares = av1_wedge_compute_delta_squares_c;
    if (flags & HAS_SSE2) av1_wedge_compute_delta_squares = av1_wedge_compute_delta_squares_sse2;
    av1_wedge_sign_from_residuals = av1_wedge_sign_from_residuals_c;
    if (flags & HAS_SSE2) av1_wedge_sign_from_residuals = av1_wedge_sign_from_residuals_sse2;
    av1_wedge_sse_from_residuals = av1_wedge_sse_from_residuals_c;
    if (flags & HAS_SSE2) av1_wedge_sse_from_residuals = av1_wedge_sse_from_residuals_sse2;
    av1_wiener_convolve_add_src = av1_wiener_convolve_add_src_c;
    if (flags & HAS_SSE2) av1_wiener_convolve_add_src = av1_wiener_convolve_add_src_sse2;
    if (flags & HAS_AVX2) av1_wiener_convolve_add_src = av1_wiener_convolve_add_src_avx2;
    cdef_filter_block = cdef_filter_block_c;
    if (flags & HAS_SSE2) cdef_filter_block = cdef_filter_block_sse2;
    if (flags & HAS_SSSE3) cdef_filter_block = cdef_filter_block_ssse3;
    if (flags & HAS_SSE4_1) cdef_filter_block = cdef_filter_block_sse4_1;
    if (flags & HAS_AVX2) cdef_filter_block = cdef_filter_block_avx2;
    cdef_find_dir = cdef_find_dir_c;
    if (flags & HAS_SSE2) cdef_find_dir = cdef_find_dir_sse2;
    if (flags & HAS_SSSE3) cdef_find_dir = cdef_find_dir_ssse3;
    if (flags & HAS_SSE4_1) cdef_find_dir = cdef_find_dir_sse4_1;
    if (flags & HAS_AVX2) cdef_find_dir = cdef_find_dir_avx2;
    cfl_get_luma_subsampling_420_lbd = cfl_get_luma_subsampling_420_lbd_c;
    if (flags & HAS_SSSE3) cfl_get_luma_subsampling_420_lbd = cfl_get_luma_subsampling_420_lbd_ssse3;
    if (flags & HAS_AVX2) cfl_get_luma_subsampling_420_lbd = cfl_get_luma_subsampling_420_lbd_avx2;
    compute_cross_correlation = compute_cross_correlation_c;
    if (flags & HAS_SSE4_1) compute_cross_correlation = compute_cross_correlation_sse4_1;
    copy_rect8_16bit_to_16bit = copy_rect8_16bit_to_16bit_c;
    if (flags & HAS_SSE2) copy_rect8_16bit_to_16bit = copy_rect8_16bit_to_16bit_sse2;
    if (flags & HAS_SSSE3) copy_rect8_16bit_to_16bit = copy_rect8_16bit_to_16bit_ssse3;
    if (flags & HAS_SSE4_1) copy_rect8_16bit_to_16bit = copy_rect8_16bit_to_16bit_sse4_1;
    if (flags & HAS_AVX2) copy_rect8_16bit_to_16bit = copy_rect8_16bit_to_16bit_avx2;
    copy_rect8_8bit_to_16bit = copy_rect8_8bit_to_16bit_c;
    if (flags & HAS_SSE2) copy_rect8_8bit_to_16bit = copy_rect8_8bit_to_16bit_sse2;
    if (flags & HAS_SSSE3) copy_rect8_8bit_to_16bit = copy_rect8_8bit_to_16bit_ssse3;
    if (flags & HAS_SSE4_1) copy_rect8_8bit_to_16bit = copy_rect8_8bit_to_16bit_sse4_1;
    if (flags & HAS_AVX2) copy_rect8_8bit_to_16bit = copy_rect8_8bit_to_16bit_avx2;
    get_predict_hbd_fn = get_predict_hbd_fn_c;
    if (flags & HAS_SSSE3) get_predict_hbd_fn = get_predict_hbd_fn_ssse3;
    if (flags & HAS_AVX2) get_predict_hbd_fn = get_predict_hbd_fn_avx2;
    get_predict_lbd_fn = get_predict_lbd_fn_c;
    if (flags & HAS_SSSE3) get_predict_lbd_fn = get_predict_lbd_fn_ssse3;
    if (flags & HAS_AVX2) get_predict_lbd_fn = get_predict_lbd_fn_avx2;
    get_subtract_average_fn = get_subtract_average_fn_c;
    if (flags & HAS_SSE2) get_subtract_average_fn = get_subtract_average_fn_sse2;
    if (flags & HAS_AVX2) get_subtract_average_fn = get_subtract_average_fn_avx2;
}
#endif

#ifdef __cplusplus
}  // extern "C"
#endif

#endif
