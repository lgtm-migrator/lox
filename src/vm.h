// SPDX-License-Identifier: Apache-2.0

#ifndef LOX_SRC_VM_H
#define LOX_SRC_VM_H

#define DEBUG_TRACE_EXECUTION true

#include <vector>

#include "chunk.h"
#include "compiler.h"

namespace lox {

enum class InterpretResult { kOk, kCompileError, kRuntimeError };

class VirtualMachine {
 public:
  VirtualMachine() = default;
  ~VirtualMachine() = default;

  auto Interpret(std::string_view source) -> InterpretResult;
  auto PushValue(Value value);
  auto PopValue() -> Value;

 private:
  auto Run() -> InterpretResult;

  Chunk *chunk_ = nullptr;
  std::uint8_t *ip_ = nullptr;
  std::vector<Value> temps_;
  Compiler compiler_;
};

}  // namespace lox

#endif  // LOX_SRC_VM_H