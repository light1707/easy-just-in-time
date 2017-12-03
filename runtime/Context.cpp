#include "easy/runtime/Context.h"

using namespace easy;

void Context::initDefaultArgumentMapping() {
  // identity mapping
  for(size_t i = 0, n = ArgumentMapping_.size(); i != n; ++i) {
    ArgumentMapping_[i].ty = Argument::Type::Forward;
    ArgumentMapping_[i].data.param_idx = i;
  }
}

void Context::setParameterIndex(unsigned arg_idx, unsigned param_idx) {
  auto &Arg = ArgumentMapping_[arg_idx];
  Arg.ty = Argument::Type::Forward;
  Arg.data.param_idx = param_idx;
} 

void Context::setParameterInt(unsigned arg_idx, int64_t val) {
  auto &Arg = ArgumentMapping_[arg_idx];
  Arg.ty = Argument::Type::Int;
  Arg.data.integer = val;
}

void Context::setParameterFloat(unsigned arg_idx, double val) {
  auto &Arg = ArgumentMapping_[arg_idx];
  Arg.ty = Argument::Type::Float;
  Arg.data.floating = val;
}

void Context::setParameterPtrVoid(unsigned arg_idx, void* val) {
  auto &Arg = ArgumentMapping_[arg_idx];
  Arg.ty = Argument::Type::Ptr;
  Arg.data.ptr = val;
}