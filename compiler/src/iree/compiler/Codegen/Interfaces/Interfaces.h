// Copyright 2021 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#ifndef IREE_COMPILER_CODEGEN_INTERFACES_INTERFACES_H_
#define IREE_COMPILER_CODEGEN_INTERFACES_INTERFACES_H_

#include "mlir/IR/Dialect.h"

namespace mlir {
namespace iree_compiler {

/// Register all codegen related interfaces.
void registerCodegenInterfaces(DialectRegistry &registry);

} // namespace iree_compiler
} // namespace mlir

#endif // IREE_COMPILER_CODEGEN_INTERFACES_INTERFACES_H_
