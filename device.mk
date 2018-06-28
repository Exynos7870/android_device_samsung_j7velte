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

LOCAL_PATH := device/samsung/j7velte

DEVICE_PACKAGE_OVERLAYS += $(LOCAL_PATH)/overlay

TARGET_SPECIFIC_HEADER_PATH += $(LOCAL_PATH)/include

# include splitted configs
-include $(LOCAL_PATH)/product/*.mk

# Dalvik Heap
$(call inherit-product, frameworks/native/build/phone-xxhdpi-3072-dalvik-heap.mk)

# Inherit from Exynos7870-common
$(call inherit-product, device/samsung/exynos7870-common/device-common.mk)

# call the proprietary setup
$(call inherit-product, vendor/samsung/j7velte/j7velte-vendor.mk)
