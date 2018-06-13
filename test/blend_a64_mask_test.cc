/*
 * Copyright (c) 2016, Alliance for Open Media. All rights reserved
 *
 * This source code is subject to the terms of the BSD 2 Clause License and
 * the Alliance for Open Media Patent License 1.0. If the BSD 2 Clause License
 * was not distributed with this source code in the LICENSE file, you can
 * obtain it at www.aomedia.org/license/software. If the Alliance for Open
 * Media Patent License 1.0 was not distributed with this source code in the
 * PATENTS file, you can obtain it at www.aomedia.org/license/patent.
 */

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "third_party/googletest/src/googletest/include/gtest/gtest.h"
#include "test/register_state_check.h"
#include "test/function_equivalence_test.h"

#include "config/aom_config.h"
#include "config/aom_dsp_rtcd.h"
#include "config/av1_rtcd.h"

#include "aom/aom_integer.h"

#include "av1/common/enums.h"

#include "aom_dsp/blend.h"

using libaom_test::FunctionEquivalenceTest;

namespace {

template <typename BlendA64Func, typename SrcPixel, typename DstPixel>
class BlendA64MaskTest : public FunctionEquivalenceTest<BlendA64Func> {
 protected:
  static const int kIterations = 10000;
  static const int kMaxWidth = MAX_SB_SIZE * 5;  // * 5 to cover longer strides
  static const int kMaxHeight = MAX_SB_SIZE;
  static const int kBufSize = kMaxWidth * kMaxHeight;
  static const int kMaxMaskWidth = 2 * MAX_SB_SIZE;
  static const int kMaxMaskSize = kMaxMaskWidth * kMaxMaskWidth;

  virtual ~BlendA64MaskTest() {}

  virtual void Execute(const SrcPixel *p_src0, const SrcPixel *p_src1) = 0;

  template <typename Pixel>
  void GetSources(Pixel **src0, Pixel **src1, Pixel * /*dst*/) {
    switch (this->rng_(3)) {
      case 0:  // Separate sources
        *src0 = src0_;
        *src1 = src1_;
        break;
      case 1:  // src0 == dst
        *src0 = dst_tst_;
        src0_stride_ = dst_stride_;
        src0_offset_ = dst_offset_;
        *src1 = src1_;
        break;
      case 2:  // src1 == dst
        *src0 = src0_;
        *src1 = dst_tst_;
        src1_stride_ = dst_stride_;
        src1_offset_ = dst_offset_;
        break;
      default: FAIL();
    }
  }

  void GetSources(uint16_t **src0, uint16_t **src1, uint8_t * /*dst*/) {
    *src0 = src0_;
    *src1 = src1_;
  }

  uint8_t Rand1() { return this->rng_.Rand8() & 1; }

  void RunTest() {
    w_ = 4 << this->rng_(MAX_SB_SIZE_LOG2 - 1);
    h_ = 4 << this->rng_(MAX_SB_SIZE_LOG2 - 1);

    subx_ = Rand1();
    suby_ = Rand1();

    dst_offset_ = this->rng_(33);
    dst_stride_ = this->rng_(kMaxWidth + 1 - w_) + w_;

    src0_offset_ = this->rng_(33);
    src0_stride_ = this->rng_(kMaxWidth + 1 - w_) + w_;

    src1_offset_ = this->rng_(33);
    src1_stride_ = this->rng_(kMaxWidth + 1 - w_) + w_;

    mask_stride_ =
        this->rng_(kMaxWidth + 1 - w_ * (subx_ ? 2 : 1)) + w_ * (subx_ ? 2 : 1);

    SrcPixel *p_src0;
    SrcPixel *p_src1;

    p_src0 = src0_;
    p_src1 = src1_;

    GetSources(&p_src0, &p_src1, &dst_ref_[0]);

    Execute(p_src0, p_src1);

    for (int r = 0; r < h_; ++r) {
      for (int c = 0; c < w_; ++c) {
        ASSERT_EQ(dst_ref_[dst_offset_ + r * dst_stride_ + c],
                  dst_tst_[dst_offset_ + r * dst_stride_ + c])
            << w_ << "x" << h_ << " r: " << r << " c: " << c;
      }
    }
  }

  DstPixel dst_ref_[kBufSize];
  DstPixel dst_tst_[kBufSize];
  uint32_t dst_stride_;
  uint32_t dst_offset_;

  SrcPixel src0_[kBufSize];
  uint32_t src0_stride_;
  uint32_t src0_offset_;

  SrcPixel src1_[kBufSize];
  uint32_t src1_stride_;
  uint32_t src1_offset_;

  uint8_t mask_[kMaxMaskSize];
  size_t mask_stride_;

  int w_;
  int h_;

  int suby_;
  int subx_;
};

//////////////////////////////////////////////////////////////////////////////
// 8 bit version
//////////////////////////////////////////////////////////////////////////////

typedef void (*F8B)(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0,
                    uint32_t src0_stride, const uint8_t *src1,
                    uint32_t src1_stride, const uint8_t *mask,
                    uint32_t mask_stride, int w, int h, int subx, int suby);
typedef libaom_test::FuncParam<F8B> TestFuncs;

class BlendA64MaskTest8B : public BlendA64MaskTest<F8B, uint8_t, uint8_t> {
 protected:
  void Execute(const uint8_t *p_src0, const uint8_t *p_src1) {
    params_.ref_func(dst_ref_ + dst_offset_, dst_stride_, p_src0 + src0_offset_,
                     src0_stride_, p_src1 + src1_offset_, src1_stride_, mask_,
                     kMaxMaskWidth, w_, h_, subx_, suby_);
    ASM_REGISTER_STATE_CHECK(params_.tst_func(
        dst_tst_ + dst_offset_, dst_stride_, p_src0 + src0_offset_,
        src0_stride_, p_src1 + src1_offset_, src1_stride_, mask_, kMaxMaskWidth,
        w_, h_, subx_, suby_));
  }
};

TEST_P(BlendA64MaskTest8B, RandomValues) {
  for (int iter = 0; iter < kIterations && !HasFatalFailure(); ++iter) {
    for (int i = 0; i < kBufSize; ++i) {
      dst_ref_[i] = rng_.Rand8();
      dst_tst_[i] = rng_.Rand8();

      src0_[i] = rng_.Rand8();
      src1_[i] = rng_.Rand8();
    }

    for (int i = 0; i < kMaxMaskSize; ++i)
      mask_[i] = rng_(AOM_BLEND_A64_MAX_ALPHA + 1);

    RunTest();
  }
}

TEST_P(BlendA64MaskTest8B, ExtremeValues) {
  for (int iter = 0; iter < kIterations && !HasFatalFailure(); ++iter) {
    for (int i = 0; i < kBufSize; ++i) {
      dst_ref_[i] = rng_(2) + 254;
      dst_tst_[i] = rng_(2) + 254;
      src0_[i] = rng_(2) + 254;
      src1_[i] = rng_(2) + 254;
    }

    for (int i = 0; i < kMaxMaskSize; ++i)
      mask_[i] = rng_(2) + AOM_BLEND_A64_MAX_ALPHA - 1;

    RunTest();
  }
}

#if HAVE_SSE4_1
INSTANTIATE_TEST_CASE_P(SSE4_1, BlendA64MaskTest8B,
                        ::testing::Values(TestFuncs(
                            aom_blend_a64_mask_c, aom_blend_a64_mask_sse4_1)));
#endif  // HAVE_SSE4_1

//////////////////////////////////////////////////////////////////////////////
// 8 bit _d16 version
//////////////////////////////////////////////////////////////////////////////

typedef void (*F8B_D16)(uint8_t *dst, uint32_t dst_stride, const uint16_t *src0,
                        uint32_t src0_stride, const uint16_t *src1,
                        uint32_t src1_stride, const uint8_t *mask,
                        uint32_t mask_stride, int w, int h, int subx, int suby,
                        ConvolveParams *conv_params);
typedef libaom_test::FuncParam<F8B_D16> TestFuncs_d16;

class BlendA64MaskTest8B_d16
    : public BlendA64MaskTest<F8B_D16, uint16_t, uint8_t> {
 protected:
  // max number of bits used by the source
  static const int kSrcMaxBitsMask = 0x3fff;

  void Execute(const uint16_t *p_src0, const uint16_t *p_src1) {
    ConvolveParams conv_params;
    conv_params.round_0 = ROUND0_BITS;
    conv_params.round_1 = COMPOUND_ROUND1_BITS;
    params_.ref_func(dst_ref_ + dst_offset_, dst_stride_, p_src0 + src0_offset_,
                     src0_stride_, p_src1 + src1_offset_, src1_stride_, mask_,
                     kMaxMaskWidth, w_, h_, subx_, suby_, &conv_params);
    ASM_REGISTER_STATE_CHECK(params_.tst_func(
        dst_tst_ + dst_offset_, dst_stride_, p_src0 + src0_offset_,
        src0_stride_, p_src1 + src1_offset_, src1_stride_, mask_, kMaxMaskWidth,
        w_, h_, subx_, suby_, &conv_params));
  }
};

TEST_P(BlendA64MaskTest8B_d16, RandomValues) {
  for (int iter = 0; iter < kIterations && !HasFatalFailure(); ++iter) {
    for (int i = 0; i < kBufSize; ++i) {
      dst_ref_[i] = rng_.Rand8();
      dst_tst_[i] = rng_.Rand8();

      src0_[i] = rng_.Rand16() & kSrcMaxBitsMask;
      src1_[i] = rng_.Rand16() & kSrcMaxBitsMask;
    }

    for (int i = 0; i < kMaxMaskSize; ++i)
      mask_[i] = rng_(AOM_BLEND_A64_MAX_ALPHA + 1);

    RunTest();
  }
}

TEST_P(BlendA64MaskTest8B_d16, ExtremeValues) {
  for (int iter = 0; iter < kIterations && !HasFatalFailure(); ++iter) {
    for (int i = 0; i < kBufSize; ++i) {
      dst_ref_[i] = 255;
      dst_tst_[i] = 255;

      src0_[i] = kSrcMaxBitsMask;
      src1_[i] = kSrcMaxBitsMask;
    }

    for (int i = 0; i < kMaxMaskSize; ++i)
      mask_[i] = AOM_BLEND_A64_MAX_ALPHA - 1;

    RunTest();
  }
}

#if HAVE_SSE4_1
INSTANTIATE_TEST_CASE_P(
    SSE4_1, BlendA64MaskTest8B_d16,
    ::testing::Values(TestFuncs_d16(aom_lowbd_blend_a64_d16_mask_c,
                                    aom_lowbd_blend_a64_d16_mask_sse4_1)));
#endif  // HAVE_SSE4_1

//////////////////////////////////////////////////////////////////////////////
// High bit-depth version
//////////////////////////////////////////////////////////////////////////////

typedef void (*FHBD)(uint8_t *dst, uint32_t dst_stride, const uint8_t *src0,
                     uint32_t src0_stride, const uint8_t *src1,
                     uint32_t src1_stride, const uint8_t *mask,
                     uint32_t mask_stride, int w, int h, int subx, int suby,
                     int bd);
typedef libaom_test::FuncParam<FHBD> TestFuncsHBD;

class BlendA64MaskTestHBD : public BlendA64MaskTest<FHBD, uint16_t, uint16_t> {
 protected:
  void Execute(const uint16_t *p_src0, const uint16_t *p_src1) {
    params_.ref_func(CONVERT_TO_BYTEPTR(dst_ref_ + dst_offset_), dst_stride_,
                     CONVERT_TO_BYTEPTR(p_src0 + src0_offset_), src0_stride_,
                     CONVERT_TO_BYTEPTR(p_src1 + src1_offset_), src1_stride_,
                     mask_, kMaxMaskWidth, w_, h_, subx_, suby_, bit_depth_);
    ASM_REGISTER_STATE_CHECK(params_.tst_func(
        CONVERT_TO_BYTEPTR(dst_tst_ + dst_offset_), dst_stride_,
        CONVERT_TO_BYTEPTR(p_src0 + src0_offset_), src0_stride_,
        CONVERT_TO_BYTEPTR(p_src1 + src1_offset_), src1_stride_, mask_,
        kMaxMaskWidth, w_, h_, subx_, suby_, bit_depth_));
  }

  int bit_depth_;
};

TEST_P(BlendA64MaskTestHBD, RandomValues) {
  for (int iter = 0; iter < kIterations && !HasFatalFailure(); ++iter) {
    switch (rng_(3)) {
      case 0: bit_depth_ = 8; break;
      case 1: bit_depth_ = 10; break;
      default: bit_depth_ = 12; break;
    }

    const int hi = 1 << bit_depth_;

    for (int i = 0; i < kBufSize; ++i) {
      dst_ref_[i] = rng_(hi);
      dst_tst_[i] = rng_(hi);
      src0_[i] = rng_(hi);
      src1_[i] = rng_(hi);
    }

    for (int i = 0; i < kMaxMaskSize; ++i)
      mask_[i] = rng_(AOM_BLEND_A64_MAX_ALPHA + 1);

    RunTest();
  }
}

TEST_P(BlendA64MaskTestHBD, ExtremeValues) {
  for (int iter = 0; iter < 1000 && !HasFatalFailure(); ++iter) {
    switch (rng_(3)) {
      case 0: bit_depth_ = 8; break;
      case 1: bit_depth_ = 10; break;
      default: bit_depth_ = 12; break;
    }

    const int hi = 1 << bit_depth_;
    const int lo = hi - 2;

    for (int i = 0; i < kBufSize; ++i) {
      dst_ref_[i] = rng_(hi - lo) + lo;
      dst_tst_[i] = rng_(hi - lo) + lo;
      src0_[i] = rng_(hi - lo) + lo;
      src1_[i] = rng_(hi - lo) + lo;
    }

    for (int i = 0; i < kMaxMaskSize; ++i)
      mask_[i] = rng_(2) + AOM_BLEND_A64_MAX_ALPHA - 1;

    RunTest();
  }
}

#if HAVE_SSE4_1
INSTANTIATE_TEST_CASE_P(
    SSE4_1, BlendA64MaskTestHBD,
    ::testing::Values(TestFuncsHBD(aom_highbd_blend_a64_mask_c,
                                   aom_highbd_blend_a64_mask_sse4_1)));
#endif  // HAVE_SSE4_1

//////////////////////////////////////////////////////////////////////////////
// HBD _d16 version
//////////////////////////////////////////////////////////////////////////////

typedef void (*FHBD_D16)(uint8_t *dst, uint32_t dst_stride,
                         const CONV_BUF_TYPE *src0, uint32_t src0_stride,
                         const CONV_BUF_TYPE *src1, uint32_t src1_stride,
                         const uint8_t *mask, uint32_t mask_stride, int w,
                         int h, int subx, int suby, ConvolveParams *conv_params,
                         const int bd);
typedef libaom_test::FuncParam<FHBD_D16> TestFuncsHBD_d16;

class BlendA64MaskTestHBD_d16
    : public BlendA64MaskTest<FHBD_D16, uint16_t, uint16_t> {
 protected:
  // max number of bits used by the source
  static const int kSrcMaxBitsMask = (1 << 14) - 1;
  static const int kSrcMaxBitsMaskHBD = (1 << 16) - 1;

  void Execute(const uint16_t *p_src0, const uint16_t *p_src1) {
    ConvolveParams conv_params;
    conv_params.round_0 = (bit_depth_ == 12) ? ROUND0_BITS + 2 : ROUND0_BITS;
    conv_params.round_1 = COMPOUND_ROUND1_BITS;

    params_.ref_func(CONVERT_TO_BYTEPTR(dst_ref_ + dst_offset_), dst_stride_,
                     p_src0 + src0_offset_, src0_stride_, p_src1 + src1_offset_,
                     src1_stride_, mask_, kMaxMaskWidth, w_, h_, subx_, suby_,
                     &conv_params, bit_depth_);
    if (params_.tst_func) {
      ASM_REGISTER_STATE_CHECK(params_.tst_func(
          CONVERT_TO_BYTEPTR(dst_tst_ + dst_offset_), dst_stride_,
          p_src0 + src0_offset_, src0_stride_, p_src1 + src1_offset_,
          src1_stride_, mask_, kMaxMaskWidth, w_, h_, subx_, suby_,
          &conv_params, bit_depth_));
    }
  }

  int bit_depth_;
  int src_max_bits_mask_;
};

TEST_P(BlendA64MaskTestHBD_d16, RandomValues) {
  if (params_.tst_func == NULL) return;
  for (int iter = 0; iter < kIterations && !HasFatalFailure(); ++iter) {
    switch (rng_(3)) {
      case 0: bit_depth_ = 8; break;
      case 1: bit_depth_ = 10; break;
      default: bit_depth_ = 12; break;
    }
    src_max_bits_mask_ =
        (bit_depth_ == 8) ? kSrcMaxBitsMask : kSrcMaxBitsMaskHBD;

    for (int i = 0; i < kBufSize; ++i) {
      dst_ref_[i] = rng_.Rand8();
      dst_tst_[i] = rng_.Rand8();

      src0_[i] = rng_.Rand16() & src_max_bits_mask_;
      src1_[i] = rng_.Rand16() & src_max_bits_mask_;
    }

    for (int i = 0; i < kMaxMaskSize; ++i)
      mask_[i] = rng_(AOM_BLEND_A64_MAX_ALPHA + 1);

    RunTest();
  }
}

TEST_P(BlendA64MaskTestHBD_d16, SaturatedValues) {
  for (bit_depth_ = 8; bit_depth_ <= 12; bit_depth_ += 2) {
    src_max_bits_mask_ =
        (bit_depth_ == 8) ? kSrcMaxBitsMask : kSrcMaxBitsMaskHBD;

    for (int i = 0; i < kBufSize; ++i) {
      dst_ref_[i] = 0;
      dst_tst_[i] = (1 << bit_depth_) - 1;

      src0_[i] = src_max_bits_mask_;
      src1_[i] = src_max_bits_mask_;
    }

    for (int i = 0; i < kMaxMaskSize; ++i) mask_[i] = AOM_BLEND_A64_MAX_ALPHA;

    RunTest();
  }
}

INSTANTIATE_TEST_CASE_P(
    C, BlendA64MaskTestHBD_d16,
    ::testing::Values(TestFuncsHBD_d16(aom_highbd_blend_a64_d16_mask_c, NULL)));

// TODO(slavarnway): Enable the following in the avx2 commit. (56501)
#if 0
#if HAVE_AVX2
INSTANTIATE_TEST_CASE_P(
    SSE4_1, BlendA64MaskTestHBD,
    ::testing::Values(TestFuncsHBD(aom_highbd_blend_a64_mask_c,
                                   aom_highbd_blend_a64_mask_avx2)));
#endif  // HAVE_AVX2
#endif
}  // namespace
