// Copyright 2021 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef IREE_COMPILER_DIALECT_STREAM_CONVERSION_HALTOSTREAM_PATTERNS_H_
#define IREE_COMPILER_DIALECT_STREAM_CONVERSION_HALTOSTREAM_PATTERNS_H_

#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/OperationSupport.h"
#include "mlir/Transforms/DialectConversion.h"

namespace mlir {
namespace iree_compiler {

// Populates conversion patterns that perform hal->stream conversion.
// These patterns ensure that nested types are run through the provided
// |typeConverter|.
void populateHALToStreamConversionPatterns(MLIRContext *context,
                                           TypeConverter &typeConverter,
                                           RewritePatternSet &patterns);
void populateHALToStreamConversionPatterns(MLIRContext *context,
                                           ConversionTarget &conversionTarget,
                                           TypeConverter &typeConverter,
                                           RewritePatternSet &patterns);

} // namespace iree_compiler
} // namespace mlir

#endif // IREE_COMPILER_DIALECT_STREAM_CONVERSION_HALTOSTREAM_PATTERNS_H_
