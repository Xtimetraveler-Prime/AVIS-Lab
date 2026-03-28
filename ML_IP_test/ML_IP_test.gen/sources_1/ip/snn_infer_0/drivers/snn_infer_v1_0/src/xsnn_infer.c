// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.2 (64-bit)
// Tool Version Limit: 2025.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
/***************************** Include Files *********************************/
#include "xsnn_infer.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XSnn_infer_CfgInitialize(XSnn_infer *InstancePtr, XSnn_infer_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_BaseAddress = ConfigPtr->Ctrl_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XSnn_infer_Start(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_AP_CTRL) & 0x80;
    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_AP_CTRL, Data | 0x01);
}

u32 XSnn_infer_IsDone(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XSnn_infer_IsIdle(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XSnn_infer_IsReady(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XSnn_infer_EnableAutoRestart(XSnn_infer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_AP_CTRL, 0x80);
}

void XSnn_infer_DisableAutoRestart(XSnn_infer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_AP_CTRL, 0);
}

void XSnn_infer_Set_state_0(XSnn_infer *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_STATE_0_DATA, Data);
}

u32 XSnn_infer_Get_state_0(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_STATE_0_DATA);
    return Data;
}

void XSnn_infer_Set_state_1(XSnn_infer *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_STATE_1_DATA, Data);
}

u32 XSnn_infer_Get_state_1(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_STATE_1_DATA);
    return Data;
}

void XSnn_infer_Set_state_2(XSnn_infer *InstancePtr, u32 Data) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_STATE_2_DATA, Data);
}

u32 XSnn_infer_Get_state_2(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_STATE_2_DATA);
    return Data;
}

u32 XSnn_infer_Get_action(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_ACTION_DATA);
    return Data;
}

u32 XSnn_infer_Get_action_vld(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_ACTION_CTRL);
    return Data & 0x1;
}

u32 XSnn_infer_Get_log_prob(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_LOG_PROB_DATA);
    return Data;
}

u32 XSnn_infer_Get_log_prob_vld(XSnn_infer *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_LOG_PROB_CTRL);
    return Data & 0x1;
}

void XSnn_infer_InterruptGlobalEnable(XSnn_infer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_GIE, 1);
}

void XSnn_infer_InterruptGlobalDisable(XSnn_infer *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_GIE, 0);
}

void XSnn_infer_InterruptEnable(XSnn_infer *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_IER);
    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_IER, Register | Mask);
}

void XSnn_infer_InterruptDisable(XSnn_infer *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_IER);
    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_IER, Register & (~Mask));
}

void XSnn_infer_InterruptClear(XSnn_infer *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XSnn_infer_WriteReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_ISR, Mask);
}

u32 XSnn_infer_InterruptGetEnabled(XSnn_infer *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_IER);
}

u32 XSnn_infer_InterruptGetStatus(XSnn_infer *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XSnn_infer_ReadReg(InstancePtr->Ctrl_BaseAddress, XSNN_INFER_CTRL_ADDR_ISR);
}

