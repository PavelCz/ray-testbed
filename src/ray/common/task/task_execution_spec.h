// Copyright 2019-2020 The Ray Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <vector>

#include "ray/common/grpc_util.h"
#include "ray/common/id.h"
#include "ray/common/task/task_common.h"

namespace ray {

/// Wrapper class of protobuf `TaskExecutionSpec`, see `common.proto` for details.
class TaskExecutionSpecification : public MessageWrapper<rpc::TaskExecutionSpec> {
 public:
  /// Construct an emtpy task execution specification. This should not be used
  /// directly.
  TaskExecutionSpecification() {}

  /// Construct from a protobuf message object.
  /// The input message will be **copied** into this object.
  ///
  /// \param message The protobuf message.
  explicit TaskExecutionSpecification(rpc::TaskExecutionSpec message)
      : MessageWrapper(std::move(message)) {}

  /// Construct from protobuf-serialized binary.
  ///
  /// \param serialized_binary Protobuf-serialized binary.
  explicit TaskExecutionSpecification(const std::string &serialized_binary)
      : MessageWrapper(serialized_binary) {}

  /// Get the number of times this task has been forwarded.
  ///
  /// \return The number of times this task has been forwarded.
  size_t NumForwards() const;

  /// Increment the number of times this task has been forwarded.
  void IncrementNumForwards();

  std::string DebugString() const;
};

}  // namespace ray
