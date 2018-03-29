#
# Copyright (C) 2017 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

TARGET_OTA_ASSERT_DEVICE := j7velte

# Inherit from Exynos7870-common
include device/samsung/exynos7870-common/BoardConfigCommon.mk

LOCAL_PATH := device/samsung/j7velte

# inherit the splitted configs
-include $(LOCAL_PATH)/board/*.mk

# Init
TARGET_INIT_VENDOR_LIB := libinit_sec

# Properties
TARGET_SYSTEM_PROP += $(LOCAL_PATH)/system.prop

# Hidl
DEVICE_MANIFEST_FILE := $(LOCAL_PATH)/manifest.xml

# Inherit from the proprietary version
-include vendor/samsung/j7velte/BoardConfigVendor.mk
