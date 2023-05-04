//===----------------------------------------------------------------------===//
//
// Copyright (C) 2022 Sophgo Technologies Inc.  All rights reserved.
//
// TPU-MLIR is licensed under the 2-Clause BSD License except for the
// third-party components.
//
//===----------------------------------------------------------------------===//

#include "tpu_mlir/Dialect/Tpu/Transforms/BM168x/ChipOptimize.h"
#include "tpu_mlir/Dialect/Tpu/IR/TpuOps.h"
#include "tpu_mlir/Support/Module.h"
#include <cstdint>

using namespace llvm;
namespace tpu_mlir {

namespace bm1684x {

void populateChipOptimizePatterns(RewritePatternSet *patterns) {
  // clang-format off
  patterns->add<
    MatMulHdimBatchPattern,
    MatMulLeftReusePattern,
    PermuteReorderPattern
  >(patterns->getContext());
  // clang-format on
};
} // namespace bm1684x

namespace bm1684 {

void populateChipOptimizePatterns(RewritePatternSet *patterns) {
  // clang-format off
  patterns->add<
    CastWithoutScalePattern
  >(patterns->getContext());
  // clang-format on
};
} // namespace bm1684

} // namespace tpu_mlir