// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.2 (64-bit)
// Tool Version Limit: 2025.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#ifdef SDT
#include "xparameters.h"
#endif
#include "xsnn_infer.h"

extern XSnn_infer_Config XSnn_infer_ConfigTable[];

#ifdef SDT
XSnn_infer_Config *XSnn_infer_LookupConfig(UINTPTR BaseAddress) {
	XSnn_infer_Config *ConfigPtr = NULL;

	int Index;

	for (Index = (u32)0x0; XSnn_infer_ConfigTable[Index].Name != NULL; Index++) {
		if (!BaseAddress || XSnn_infer_ConfigTable[Index].Ctrl_BaseAddress == BaseAddress) {
			ConfigPtr = &XSnn_infer_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSnn_infer_Initialize(XSnn_infer *InstancePtr, UINTPTR BaseAddress) {
	XSnn_infer_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSnn_infer_LookupConfig(BaseAddress);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSnn_infer_CfgInitialize(InstancePtr, ConfigPtr);
}
#else
XSnn_infer_Config *XSnn_infer_LookupConfig(u16 DeviceId) {
	XSnn_infer_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XSNN_INFER_NUM_INSTANCES; Index++) {
		if (XSnn_infer_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XSnn_infer_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XSnn_infer_Initialize(XSnn_infer *InstancePtr, u16 DeviceId) {
	XSnn_infer_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XSnn_infer_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XSnn_infer_CfgInitialize(InstancePtr, ConfigPtr);
}
#endif

#endif

