// ==============================================================
// Vitis HLS - High-Level Synthesis from C, C++ and OpenCL v2025.2 (64-bit)
// Tool Version Limit: 2025.11
// Copyright 1986-2022 Xilinx, Inc. All Rights Reserved.
// Copyright 2022-2025 Advanced Micro Devices, Inc. All Rights Reserved.
// 
// ==============================================================
// CTRL
// 0x00 : Control signals
//        bit 0  - ap_start (Read/Write/COH)
//        bit 1  - ap_done (Read/COR)
//        bit 2  - ap_idle (Read)
//        bit 3  - ap_ready (Read/COR)
//        bit 7  - auto_restart (Read/Write)
//        bit 9  - interrupt (Read)
//        others - reserved
// 0x04 : Global Interrupt Enable Register
//        bit 0  - Global Interrupt Enable (Read/Write)
//        others - reserved
// 0x08 : IP Interrupt Enable Register (Read/Write)
//        bit 0 - enable ap_done interrupt (Read/Write)
//        bit 1 - enable ap_ready interrupt (Read/Write)
//        others - reserved
// 0x0c : IP Interrupt Status Register (Read/TOW)
//        bit 0 - ap_done (Read/TOW)
//        bit 1 - ap_ready (Read/TOW)
//        others - reserved
// 0x10 : Data signal of state_0
//        bit 31~0 - state_0[31:0] (Read/Write)
// 0x14 : reserved
// 0x18 : Data signal of state_1
//        bit 31~0 - state_1[31:0] (Read/Write)
// 0x1c : reserved
// 0x20 : Data signal of state_2
//        bit 31~0 - state_2[31:0] (Read/Write)
// 0x24 : reserved
// 0x28 : Data signal of action
//        bit 31~0 - action[31:0] (Read)
// 0x2c : Control signal of action
//        bit 0  - action_ap_vld (Read/COR)
//        others - reserved
// 0x38 : Data signal of log_prob
//        bit 31~0 - log_prob[31:0] (Read)
// 0x3c : Control signal of log_prob
//        bit 0  - log_prob_ap_vld (Read/COR)
//        others - reserved
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XSNN_INFER_CTRL_ADDR_AP_CTRL       0x00
#define XSNN_INFER_CTRL_ADDR_GIE           0x04
#define XSNN_INFER_CTRL_ADDR_IER           0x08
#define XSNN_INFER_CTRL_ADDR_ISR           0x0c
#define XSNN_INFER_CTRL_ADDR_STATE_0_DATA  0x10
#define XSNN_INFER_CTRL_BITS_STATE_0_DATA  32
#define XSNN_INFER_CTRL_ADDR_STATE_1_DATA  0x18
#define XSNN_INFER_CTRL_BITS_STATE_1_DATA  32
#define XSNN_INFER_CTRL_ADDR_STATE_2_DATA  0x20
#define XSNN_INFER_CTRL_BITS_STATE_2_DATA  32
#define XSNN_INFER_CTRL_ADDR_ACTION_DATA   0x28
#define XSNN_INFER_CTRL_BITS_ACTION_DATA   32
#define XSNN_INFER_CTRL_ADDR_ACTION_CTRL   0x2c
#define XSNN_INFER_CTRL_ADDR_LOG_PROB_DATA 0x38
#define XSNN_INFER_CTRL_BITS_LOG_PROB_DATA 32
#define XSNN_INFER_CTRL_ADDR_LOG_PROB_CTRL 0x3c

