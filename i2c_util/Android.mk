# Copyright 2006 The Android Open Source Project

LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= i2c_util.c

LOCAL_MODULE:= i2c_util

include $(BUILD_EXECUTABLE)
