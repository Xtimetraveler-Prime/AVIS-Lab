// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.2 (64-bit)
// Tool Version Limit: 2025.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
#ifndef XSNN_INFER_H
#define XSNN_INFER_H

#ifdef __cplusplus
extern "C" {
#endif

/***************************** Include Files *********************************/
#ifndef __linux__
#include "xil_types.h"
#include "xil_assert.h"
#include "xstatus.h"
#include "xil_io.h"
#else
#include <stdint.h>
#include <assert.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <stddef.h>
#endif
#include "xsnn_infer_hw.h"

/**************************** Type Definitions ******************************/
#ifdef __linux__
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
#else
typedef struct {
#ifdef SDT
    char *Name;
#else
    u16 DeviceId;
#endif
    u64 Ctrl_BaseAddress;
} XSnn_infer_Config;
#endif

typedef struct {
    u64 Ctrl_BaseAddress;
    u32 IsReady;
} XSnn_infer;

typedef u32 word_type;

/***************** Macros (Inline Functions) Definitions *********************/
#ifndef __linux__
#define XSnn_infer_WriteReg(BaseAddress, RegOffset, Data) \
    Xil_Out32((BaseAddress) + (RegOffset), (u32)(Data))
#define XSnn_infer_ReadReg(BaseAddress, RegOffset) \
    Xil_In32((BaseAddress) + (RegOffset))
#else
#define XSnn_infer_WriteReg(BaseAddress, RegOffset, Data) \
    *(volatile u32*)((BaseAddress) + (RegOffset)) = (u32)(Data)
#define XSnn_infer_ReadReg(BaseAddress, RegOffset) \
    *(volatile u32*)((BaseAddress) + (RegOffset))

#define Xil_AssertVoid(expr)    assert(expr)
#define Xil_AssertNonvoid(expr) assert(expr)

#define XST_SUCCESS             0
#define XST_DEVICE_NOT_FOUND    2
#define XST_OPEN_DEVICE_FAILED  3
#define XIL_COMPONENT_IS_READY  1
#endif

/************************** Function Prototypes *****************************/
#ifndef __linux__
#ifdef SDT
int XSnn_infer_Initialize(XSnn_infer *InstancePtr, UINTPTR BaseAddress);
XSnn_infer_Config* XSnn_infer_LookupConfig(UINTPTR BaseAddress);
#else
int XSnn_infer_Initialize(XSnn_infer *InstancePtr, u16 DeviceId);
XSnn_infer_Config* XSnn_infer_LookupConfig(u16 DeviceId);
#endif
int XSnn_infer_CfgInitialize(XSnn_infer *InstancePtr, XSnn_infer_Config *ConfigPtr);
#else
int XSnn_infer_Initialize(XSnn_infer *InstancePtr, const char* InstanceName);
int XSnn_infer_Release(XSnn_infer *InstancePtr);
#endif

void XSnn_infer_Start(XSnn_infer *InstancePtr);
u32 XSnn_infer_IsDone(XSnn_infer *InstancePtr);
u32 XSnn_infer_IsIdle(XSnn_infer *InstancePtr);
u32 XSnn_infer_IsReady(XSnn_infer *InstancePtr);
void XSnn_infer_EnableAutoRestart(XSnn_infer *InstancePtr);
void XSnn_infer_DisableAutoRestart(XSnn_infer *InstancePtr);

void XSnn_infer_Set_state_0(XSnn_infer *InstancePtr, u32 Data);
u32 XSnn_infer_Get_state_0(XSnn_infer *InstancePtr);
void XSnn_infer_Set_state_1(XSnn_infer *InstancePtr, u32 Data);
u32 XSnn_infer_Get_state_1(XSnn_infer *InstancePtr);
void XSnn_infer_Set_state_2(XSnn_infer *InstancePtr, u32 Data);
u32 XSnn_infer_Get_state_2(XSnn_infer *InstancePtr);
u32 XSnn_infer_Get_action(XSnn_infer *InstancePtr);
u32 XSnn_infer_Get_action_vld(XSnn_infer *InstancePtr);
u32 XSnn_infer_Get_log_prob(XSnn_infer *InstancePtr);
u32 XSnn_infer_Get_log_prob_vld(XSnn_infer *InstancePtr);

void XSnn_infer_InterruptGlobalEnable(XSnn_infer *InstancePtr);
void XSnn_infer_InterruptGlobalDisable(XSnn_infer *InstancePtr);
void XSnn_infer_InterruptEnable(XSnn_infer *InstancePtr, u32 Mask);
void XSnn_infer_InterruptDisable(XSnn_infer *InstancePtr, u32 Mask);
void XSnn_infer_InterruptClear(XSnn_infer *InstancePtr, u32 Mask);
u32 XSnn_infer_InterruptGetEnabled(XSnn_infer *InstancePtr);
u32 XSnn_infer_InterruptGetStatus(XSnn_infer *InstancePtr);

#ifdef __cplusplus
}
#endif

#endif
