// Copyright 2019 The IREE Authors
//
// Licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception

#include "iree/compiler/Dialect/VM/Analysis/RegisterAllocation.h"
#include "iree/compiler/Dialect/VM/IR/VMOps.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassRegistry.h"

namespace mlir {
namespace iree_compiler {

class RegisterAllocationTestPass
    : public PassWrapper<RegisterAllocationTestPass,
                         OperationPass<IREE::VM::FuncOp>> {
public:
  StringRef getArgument() const override {
    return "test-iree-vm-register-allocation";
  }

  StringRef getDescription() const override {
    return "Test pass used for register allocation";
  }

  void runOnOperation() override {
    if (failed(RegisterAllocation::annotateIR(getOperation()))) {
      signalPassFailure();
    }
  }
};

namespace IREE {
namespace VM {
std::unique_ptr<OperationPass<IREE::VM::FuncOp>>
createRegisterAllocationTestPass() {
  return std::make_unique<RegisterAllocationTestPass>();
}
} // namespace VM
} // namespace IREE

static PassRegistration<RegisterAllocationTestPass> pass;

} // namespace iree_compiler
} // namespace mlir
