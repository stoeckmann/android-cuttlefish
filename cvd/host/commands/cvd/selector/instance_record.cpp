/*
 * Copyright (C) 2022 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "host/commands/cvd/instance_record.h"

#include "host/commands/cvd/instance_database_utils.h"

namespace cuttlefish {
namespace instance_db {

LocalInstance::LocalInstance(const unsigned instance_id,
                             const std::string& internal_group_name,
                             const std::string& group_name,
                             const std::string& instance_name)
    : instance_id_(instance_id),
      internal_name_(std::to_string(instance_id_)),
      internal_group_name_(internal_group_name),
      group_name_(group_name),
      per_instance_name_(instance_name) {}

unsigned LocalInstance::InstanceId() const { return instance_id_; }

std::string LocalInstance::InternalDeviceName() const {
  return LocalDeviceNameRule(internal_group_name_, internal_name_);
}

const std::string& LocalInstance::InternalName() const {
  return internal_name_;
}

std::string LocalInstance::DeviceName() const {
  return LocalDeviceNameRule(group_name_, per_instance_name_);
}

const std::string& LocalInstance::PerInstanceName() const {
  return per_instance_name_;
}

}  // namespace instance_db
}  // namespace cuttlefish