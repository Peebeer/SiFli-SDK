/*
 * SPDX-FileCopyrightText: 2019-2025 SiFli Technologies(Nanjing) Co., Ltd
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __V2D_GPU_H
#define __V2D_GPU_H

typedef struct
{
    __IO uint32_t AQHICLOCKCONTROL;
    __IO uint32_t AQHIIDLE;
    __IO uint32_t AQAXICONFIG;
    __IO uint32_t AQAXISTATUS;
    __IO uint32_t AQINTRACKNOWLEDGE;
    __IO uint32_t AQINTRENBL;
    __IO uint32_t RSVD8[3];
    __IO uint32_t GCCHIPREV;
    __IO uint32_t GCCHIPDATE;
    __IO uint32_t RSVD7[27];
    __IO uint32_t GCREGHICHIPPATCHREV;
    __IO uint32_t RSVD6[3];
    __IO uint32_t GCPRODUCTID;
    __IO uint32_t RSVD5[21];
    __IO uint32_t GCMODULEPOWERCONTROLS;
    __IO uint32_t GCMODULEPOWERMODULECONTROL;
    __IO uint32_t GCMODULEPOWERMODULESTATUS;
    __IO uint32_t RSVD4[189];
    __IO uint32_t AQMEMORYFEPAGETABLE;
    __IO uint32_t RSVD3[4];
    __IO uint32_t AQMEMORYDEBUG;
    __IO uint32_t RSVD2[5];
    __IO uint32_t AQREGISTERTIMINGCONTROL;
    __IO uint32_t RSVD1[52];
    __IO uint32_t GCREGFETCHADDRESS;
    __IO uint32_t GCREGFETCHCONTROL;
    __IO uint32_t GCREGCURRENTFETCHADDRESS;
} V2D_GPU_TypeDef;


/************ Bit definition for V2D_GPU_AQHICLOCKCONTROL register ************/
#define V2D_GPU_AQHICLOCKCONTROL_CLK2D_DIS_Pos  (1U)
#define V2D_GPU_AQHICLOCKCONTROL_CLK2D_DIS_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_CLK2D_DIS_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_CLK2D_DIS  V2D_GPU_AQHICLOCKCONTROL_CLK2D_DIS_Msk
#define V2D_GPU_AQHICLOCKCONTROL_FSCALE_VAL_Pos  (2U)
#define V2D_GPU_AQHICLOCKCONTROL_FSCALE_VAL_Msk  (0x7FUL << V2D_GPU_AQHICLOCKCONTROL_FSCALE_VAL_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_FSCALE_VAL  V2D_GPU_AQHICLOCKCONTROL_FSCALE_VAL_Msk
#define V2D_GPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_Pos  (9U)
#define V2D_GPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD  V2D_GPU_AQHICLOCKCONTROL_FSCALE_CMD_LOAD_Msk
#define V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_Pos  (10U)
#define V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING  V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_CLOCK_GATING_Msk
#define V2D_GPU_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_Pos  (11U)
#define V2D_GPU_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS  V2D_GPU_AQHICLOCKCONTROL_DISABLE_DEBUG_REGISTERS_Msk
#define V2D_GPU_AQHICLOCKCONTROL_SOFT_RESET_Pos  (12U)
#define V2D_GPU_AQHICLOCKCONTROL_SOFT_RESET_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_SOFT_RESET_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_SOFT_RESET  V2D_GPU_AQHICLOCKCONTROL_SOFT_RESET_Msk
#define V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_POWER_OPT_Pos  (13U)
#define V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_POWER_OPT_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_POWER_OPT_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_POWER_OPT  V2D_GPU_AQHICLOCKCONTROL_DISABLE_RAM_POWER_OPT_Msk
#define V2D_GPU_AQHICLOCKCONTROL_IDLE3_D_Pos  (16U)
#define V2D_GPU_AQHICLOCKCONTROL_IDLE3_D_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_IDLE3_D_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_IDLE3_D  V2D_GPU_AQHICLOCKCONTROL_IDLE3_D_Msk
#define V2D_GPU_AQHICLOCKCONTROL_IDLE2_D_Pos  (17U)
#define V2D_GPU_AQHICLOCKCONTROL_IDLE2_D_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_IDLE2_D_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_IDLE2_D  V2D_GPU_AQHICLOCKCONTROL_IDLE2_D_Msk
#define V2D_GPU_AQHICLOCKCONTROL_IDLE_VG_Pos  (18U)
#define V2D_GPU_AQHICLOCKCONTROL_IDLE_VG_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_IDLE_VG_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_IDLE_VG  V2D_GPU_AQHICLOCKCONTROL_IDLE_VG_Msk
#define V2D_GPU_AQHICLOCKCONTROL_ISOLATE_GPU_Pos  (19U)
#define V2D_GPU_AQHICLOCKCONTROL_ISOLATE_GPU_Msk  (0x1UL << V2D_GPU_AQHICLOCKCONTROL_ISOLATE_GPU_Pos)
#define V2D_GPU_AQHICLOCKCONTROL_ISOLATE_GPU  V2D_GPU_AQHICLOCKCONTROL_ISOLATE_GPU_Msk

/**************** Bit definition for V2D_GPU_AQHIIDLE register ****************/
#define V2D_GPU_AQHIIDLE_IDLE_FE_Pos    (0U)
#define V2D_GPU_AQHIIDLE_IDLE_FE_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_FE_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_FE        V2D_GPU_AQHIIDLE_IDLE_FE_Msk
#define V2D_GPU_AQHIIDLE_IDLE_DE_Pos    (1U)
#define V2D_GPU_AQHIIDLE_IDLE_DE_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_DE_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_DE        V2D_GPU_AQHIIDLE_IDLE_DE_Msk
#define V2D_GPU_AQHIIDLE_IDLE_PE_Pos    (2U)
#define V2D_GPU_AQHIIDLE_IDLE_PE_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_PE_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_PE        V2D_GPU_AQHIIDLE_IDLE_PE_Msk
#define V2D_GPU_AQHIIDLE_IDLE_SH_Pos    (3U)
#define V2D_GPU_AQHIIDLE_IDLE_SH_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_SH_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_SH        V2D_GPU_AQHIIDLE_IDLE_SH_Msk
#define V2D_GPU_AQHIIDLE_IDLE_PA_Pos    (4U)
#define V2D_GPU_AQHIIDLE_IDLE_PA_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_PA_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_PA        V2D_GPU_AQHIIDLE_IDLE_PA_Msk
#define V2D_GPU_AQHIIDLE_IDLE_SE_Pos    (5U)
#define V2D_GPU_AQHIIDLE_IDLE_SE_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_SE_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_SE        V2D_GPU_AQHIIDLE_IDLE_SE_Msk
#define V2D_GPU_AQHIIDLE_IDLE_RA_Pos    (6U)
#define V2D_GPU_AQHIIDLE_IDLE_RA_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_RA_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_RA        V2D_GPU_AQHIIDLE_IDLE_RA_Msk
#define V2D_GPU_AQHIIDLE_IDLE_TX_Pos    (7U)
#define V2D_GPU_AQHIIDLE_IDLE_TX_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_TX_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_TX        V2D_GPU_AQHIIDLE_IDLE_TX_Msk
#define V2D_GPU_AQHIIDLE_IDLE_VG_Pos    (8U)
#define V2D_GPU_AQHIIDLE_IDLE_VG_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_VG_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_VG        V2D_GPU_AQHIIDLE_IDLE_VG_Msk
#define V2D_GPU_AQHIIDLE_IDLE_IM_Pos    (9U)
#define V2D_GPU_AQHIIDLE_IDLE_IM_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_IM_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_IM        V2D_GPU_AQHIIDLE_IDLE_IM_Msk
#define V2D_GPU_AQHIIDLE_IDLE_FP_Pos    (10U)
#define V2D_GPU_AQHIIDLE_IDLE_FP_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_FP_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_FP        V2D_GPU_AQHIIDLE_IDLE_FP_Msk
#define V2D_GPU_AQHIIDLE_IDLE_TS_Pos    (11U)
#define V2D_GPU_AQHIIDLE_IDLE_TS_Msk    (0x1UL << V2D_GPU_AQHIIDLE_IDLE_TS_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_TS        V2D_GPU_AQHIIDLE_IDLE_TS_Msk
#define V2D_GPU_AQHIIDLE_IDLE_BLT_Pos   (12U)
#define V2D_GPU_AQHIIDLE_IDLE_BLT_Msk   (0x1UL << V2D_GPU_AQHIIDLE_IDLE_BLT_Pos)
#define V2D_GPU_AQHIIDLE_IDLE_BLT       V2D_GPU_AQHIIDLE_IDLE_BLT_Msk
#define V2D_GPU_AQHIIDLE_AXI_LP_Pos     (31U)
#define V2D_GPU_AQHIIDLE_AXI_LP_Msk     (0x1UL << V2D_GPU_AQHIIDLE_AXI_LP_Pos)
#define V2D_GPU_AQHIIDLE_AXI_LP         V2D_GPU_AQHIIDLE_AXI_LP_Msk

/************** Bit definition for V2D_GPU_AQAXICONFIG register ***************/
#define V2D_GPU_AQAXICONFIG_AWCACHE_Pos  (8U)
#define V2D_GPU_AQAXICONFIG_AWCACHE_Msk  (0xFUL << V2D_GPU_AQAXICONFIG_AWCACHE_Pos)
#define V2D_GPU_AQAXICONFIG_AWCACHE     V2D_GPU_AQAXICONFIG_AWCACHE_Msk
#define V2D_GPU_AQAXICONFIG_ARCACHE_Pos  (12U)
#define V2D_GPU_AQAXICONFIG_ARCACHE_Msk  (0xFUL << V2D_GPU_AQAXICONFIG_ARCACHE_Pos)
#define V2D_GPU_AQAXICONFIG_ARCACHE     V2D_GPU_AQAXICONFIG_ARCACHE_Msk
#define V2D_GPU_AQAXICONFIG_AXDOMAIN_SHARED_Pos  (16U)
#define V2D_GPU_AQAXICONFIG_AXDOMAIN_SHARED_Msk  (0x3UL << V2D_GPU_AQAXICONFIG_AXDOMAIN_SHARED_Pos)
#define V2D_GPU_AQAXICONFIG_AXDOMAIN_SHARED  V2D_GPU_AQAXICONFIG_AXDOMAIN_SHARED_Msk
#define V2D_GPU_AQAXICONFIG_AXDOMAIN_NON_SHARED_Pos  (18U)
#define V2D_GPU_AQAXICONFIG_AXDOMAIN_NON_SHARED_Msk  (0x3UL << V2D_GPU_AQAXICONFIG_AXDOMAIN_NON_SHARED_Pos)
#define V2D_GPU_AQAXICONFIG_AXDOMAIN_NON_SHARED  V2D_GPU_AQAXICONFIG_AXDOMAIN_NON_SHARED_Msk
#define V2D_GPU_AQAXICONFIG_AXCACHE_OVERRIDE_SHARED_Pos  (20U)
#define V2D_GPU_AQAXICONFIG_AXCACHE_OVERRIDE_SHARED_Msk  (0xFUL << V2D_GPU_AQAXICONFIG_AXCACHE_OVERRIDE_SHARED_Pos)
#define V2D_GPU_AQAXICONFIG_AXCACHE_OVERRIDE_SHARED  V2D_GPU_AQAXICONFIG_AXCACHE_OVERRIDE_SHARED_Msk

/************** Bit definition for V2D_GPU_AQAXISTATUS register ***************/
#define V2D_GPU_AQAXISTATUS_WR_ERR_ID_Pos  (0U)
#define V2D_GPU_AQAXISTATUS_WR_ERR_ID_Msk  (0xFUL << V2D_GPU_AQAXISTATUS_WR_ERR_ID_Pos)
#define V2D_GPU_AQAXISTATUS_WR_ERR_ID   V2D_GPU_AQAXISTATUS_WR_ERR_ID_Msk
#define V2D_GPU_AQAXISTATUS_RD_ERR_ID_Pos  (4U)
#define V2D_GPU_AQAXISTATUS_RD_ERR_ID_Msk  (0xFUL << V2D_GPU_AQAXISTATUS_RD_ERR_ID_Pos)
#define V2D_GPU_AQAXISTATUS_RD_ERR_ID   V2D_GPU_AQAXISTATUS_RD_ERR_ID_Msk
#define V2D_GPU_AQAXISTATUS_DET_WR_ERR_Pos  (8U)
#define V2D_GPU_AQAXISTATUS_DET_WR_ERR_Msk  (0x1UL << V2D_GPU_AQAXISTATUS_DET_WR_ERR_Pos)
#define V2D_GPU_AQAXISTATUS_DET_WR_ERR  V2D_GPU_AQAXISTATUS_DET_WR_ERR_Msk
#define V2D_GPU_AQAXISTATUS_DET_RD_ERR_Pos  (9U)
#define V2D_GPU_AQAXISTATUS_DET_RD_ERR_Msk  (0x1UL << V2D_GPU_AQAXISTATUS_DET_RD_ERR_Pos)
#define V2D_GPU_AQAXISTATUS_DET_RD_ERR  V2D_GPU_AQAXISTATUS_DET_RD_ERR_Msk

/*********** Bit definition for V2D_GPU_AQINTRACKNOWLEDGE register ************/
#define V2D_GPU_AQINTRACKNOWLEDGE_INTR_VEC_Pos  (0U)
#define V2D_GPU_AQINTRACKNOWLEDGE_INTR_VEC_Msk  (0xFFFFFFFFUL << V2D_GPU_AQINTRACKNOWLEDGE_INTR_VEC_Pos)
#define V2D_GPU_AQINTRACKNOWLEDGE_INTR_VEC  V2D_GPU_AQINTRACKNOWLEDGE_INTR_VEC_Msk

/*************** Bit definition for V2D_GPU_AQINTRENBL register ***************/
#define V2D_GPU_AQINTRENBL_INTR_ENBL_VEC_Pos  (0U)
#define V2D_GPU_AQINTRENBL_INTR_ENBL_VEC_Msk  (0xFFFFFFFFUL << V2D_GPU_AQINTRENBL_INTR_ENBL_VEC_Pos)
#define V2D_GPU_AQINTRENBL_INTR_ENBL_VEC  V2D_GPU_AQINTRENBL_INTR_ENBL_VEC_Msk

/*************** Bit definition for V2D_GPU_GCCHIPREV register ****************/
#define V2D_GPU_GCCHIPREV_REV_Pos       (0U)
#define V2D_GPU_GCCHIPREV_REV_Msk       (0xFFFFFFFFUL << V2D_GPU_GCCHIPREV_REV_Pos)
#define V2D_GPU_GCCHIPREV_REV           V2D_GPU_GCCHIPREV_REV_Msk

/*************** Bit definition for V2D_GPU_GCCHIPDATE register ***************/
#define V2D_GPU_GCCHIPDATE_DATE_Pos     (0U)
#define V2D_GPU_GCCHIPDATE_DATE_Msk     (0xFFFFFFFFUL << V2D_GPU_GCCHIPDATE_DATE_Pos)
#define V2D_GPU_GCCHIPDATE_DATE         V2D_GPU_GCCHIPDATE_DATE_Msk

/********** Bit definition for V2D_GPU_GCREGHICHIPPATCHREV register ***********/
#define V2D_GPU_GCREGHICHIPPATCHREV_PATCH_REV_Pos  (0U)
#define V2D_GPU_GCREGHICHIPPATCHREV_PATCH_REV_Msk  (0xFFUL << V2D_GPU_GCREGHICHIPPATCHREV_PATCH_REV_Pos)
#define V2D_GPU_GCREGHICHIPPATCHREV_PATCH_REV  V2D_GPU_GCREGHICHIPPATCHREV_PATCH_REV_Msk

/************** Bit definition for V2D_GPU_GCPRODUCTID register ***************/
#define V2D_GPU_GCPRODUCTID_GRADE_LEVEL_Pos  (0U)
#define V2D_GPU_GCPRODUCTID_GRADE_LEVEL_Msk  (0xFUL << V2D_GPU_GCPRODUCTID_GRADE_LEVEL_Pos)
#define V2D_GPU_GCPRODUCTID_GRADE_LEVEL  V2D_GPU_GCPRODUCTID_GRADE_LEVEL_Msk
#define V2D_GPU_GCPRODUCTID_NUM_Pos     (4U)
#define V2D_GPU_GCPRODUCTID_NUM_Msk     (0xFFFFFUL << V2D_GPU_GCPRODUCTID_NUM_Pos)
#define V2D_GPU_GCPRODUCTID_NUM         V2D_GPU_GCPRODUCTID_NUM_Msk
#define V2D_GPU_GCPRODUCTID_TYPE_Pos    (24U)
#define V2D_GPU_GCPRODUCTID_TYPE_Msk    (0xFUL << V2D_GPU_GCPRODUCTID_TYPE_Pos)
#define V2D_GPU_GCPRODUCTID_TYPE        V2D_GPU_GCPRODUCTID_TYPE_Msk

/********* Bit definition for V2D_GPU_GCMODULEPOWERCONTROLS register **********/
#define V2D_GPU_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CG_Pos  (0U)
#define V2D_GPU_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CG_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CG_Pos)
#define V2D_GPU_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CG  V2D_GPU_GCMODULEPOWERCONTROLS_ENABLE_MODULE_CG_Msk
#define V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CG_Pos  (1U)
#define V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CG_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CG_Pos)
#define V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CG  V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STALL_MODULE_CG_Msk
#define V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CG_Pos  (2U)
#define V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CG_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CG_Pos)
#define V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CG  V2D_GPU_GCMODULEPOWERCONTROLS_DISABLE_STARVE_MODULE_CG_Msk
#define V2D_GPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_Pos  (4U)
#define V2D_GPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_Msk  (0xFUL << V2D_GPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_Pos)
#define V2D_GPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER  V2D_GPU_GCMODULEPOWERCONTROLS_TURN_ON_COUNTER_Msk
#define V2D_GPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_Pos  (16U)
#define V2D_GPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_Msk  (0xFFFFUL << V2D_GPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_Pos)
#define V2D_GPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER  V2D_GPU_GCMODULEPOWERCONTROLS_TURN_OFF_COUNTER_Msk

/******* Bit definition for V2D_GPU_GCMODULEPOWERMODULECONTROL register *******/
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FE_Pos  (0U)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FE_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FE_Pos)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FE  V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FE_Msk
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_PE_Pos  (2U)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_PE_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_PE_Pos)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_PE  V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_PE_Msk
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_VG_Pos  (8U)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_VG_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_VG_Pos)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_VG  V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_VG_Msk
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_IM_Pos  (9U)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_IM_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_IM_Pos)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_IM  V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_IM_Msk
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_TS_Pos  (11U)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_TS_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_TS_Pos)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_TS  V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_TS_Msk
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FLEXA_Pos  (12U)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FLEXA_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FLEXA_Pos)
#define V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FLEXA  V2D_GPU_GCMODULEPOWERMODULECONTROL_DISABLE_MODULE_CG_FLEXA_Msk

/******* Bit definition for V2D_GPU_GCMODULEPOWERMODULESTATUS register ********/
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FE_Pos  (0U)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FE_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FE_Pos)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FE  V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FE_Msk
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_PE_Pos  (2U)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_PE_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_PE_Pos)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_PE  V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_PE_Msk
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_VG_Pos  (8U)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_VG_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_VG_Pos)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_VG  V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_VG_Msk
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_IM_Pos  (9U)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_IM_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_IM_Pos)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_IM  V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_IM_Msk
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_TS_Pos  (11U)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_TS_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_TS_Pos)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_TS  V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_TS_Msk
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FLEXA_Pos  (12U)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FLEXA_Msk  (0x1UL << V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FLEXA_Pos)
#define V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FLEXA  V2D_GPU_GCMODULEPOWERMODULESTATUS_MODULE_CG_FLEXA_Msk

/********** Bit definition for V2D_GPU_AQMEMORYFEPAGETABLE register ***********/
#define V2D_GPU_AQMEMORYFEPAGETABLE_BASE_ADDRESS_Pos  (12U)
#define V2D_GPU_AQMEMORYFEPAGETABLE_BASE_ADDRESS_Msk  (0xFFFFFUL << V2D_GPU_AQMEMORYFEPAGETABLE_BASE_ADDRESS_Pos)
#define V2D_GPU_AQMEMORYFEPAGETABLE_BASE_ADDRESS  V2D_GPU_AQMEMORYFEPAGETABLE_BASE_ADDRESS_Msk

/************* Bit definition for V2D_GPU_AQMEMORYDEBUG register **************/
#define V2D_GPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_Pos  (0U)
#define V2D_GPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_Msk  (0xFFUL << V2D_GPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_Pos)
#define V2D_GPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS  V2D_GPU_AQMEMORYDEBUG_MAX_OUTSTANDING_READS_Msk

/******** Bit definition for V2D_GPU_AQREGISTERTIMINGCONTROL register *********/
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF1P_Pos  (0U)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF1P_Msk  (0xFFUL << V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF1P_Pos)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF1P  V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF1P_Msk
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF2P_Pos  (8U)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF2P_Msk  (0xFFUL << V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF2P_Pos)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF2P  V2D_GPU_AQREGISTERTIMINGCONTROL_FOR_RF2P_Msk
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_RTC_Pos  (16U)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_RTC_Msk  (0x3UL << V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_RTC_Pos)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_RTC  V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_RTC_Msk
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_WTC_Pos  (18U)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_WTC_Msk  (0x3UL << V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_WTC_Pos)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_WTC  V2D_GPU_AQREGISTERTIMINGCONTROL_FAST_WTC_Msk
#define V2D_GPU_AQREGISTERTIMINGCONTROL_POWER_DOWN_Pos  (20U)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_POWER_DOWN_Msk  (0x1UL << V2D_GPU_AQREGISTERTIMINGCONTROL_POWER_DOWN_Pos)
#define V2D_GPU_AQREGISTERTIMINGCONTROL_POWER_DOWN  V2D_GPU_AQREGISTERTIMINGCONTROL_POWER_DOWN_Msk

/*********** Bit definition for V2D_GPU_GCREGFETCHADDRESS register ************/
#define V2D_GPU_GCREGFETCHADDRESS_TYPE_Pos  (0U)
#define V2D_GPU_GCREGFETCHADDRESS_TYPE_Msk  (0x3UL << V2D_GPU_GCREGFETCHADDRESS_TYPE_Pos)
#define V2D_GPU_GCREGFETCHADDRESS_TYPE  V2D_GPU_GCREGFETCHADDRESS_TYPE_Msk
#define V2D_GPU_GCREGFETCHADDRESS_ADDRESS_Pos  (2U)
#define V2D_GPU_GCREGFETCHADDRESS_ADDRESS_Msk  (0x3FFFFFFFUL << V2D_GPU_GCREGFETCHADDRESS_ADDRESS_Pos)
#define V2D_GPU_GCREGFETCHADDRESS_ADDRESS  V2D_GPU_GCREGFETCHADDRESS_ADDRESS_Msk

/*********** Bit definition for V2D_GPU_GCREGFETCHCONTROL register ************/
#define V2D_GPU_GCREGFETCHCONTROL_COUNT_Pos  (0U)
#define V2D_GPU_GCREGFETCHCONTROL_COUNT_Msk  (0x1FFFFFUL << V2D_GPU_GCREGFETCHCONTROL_COUNT_Pos)
#define V2D_GPU_GCREGFETCHCONTROL_COUNT  V2D_GPU_GCREGFETCHCONTROL_COUNT_Msk

/******** Bit definition for V2D_GPU_GCREGCURRENTFETCHADDRESS register ********/
#define V2D_GPU_GCREGCURRENTFETCHADDRESS_ADDRESS_Pos  (0U)
#define V2D_GPU_GCREGCURRENTFETCHADDRESS_ADDRESS_Msk  (0xFFFFFFFFUL << V2D_GPU_GCREGCURRENTFETCHADDRESS_ADDRESS_Pos)
#define V2D_GPU_GCREGCURRENTFETCHADDRESS_ADDRESS  V2D_GPU_GCREGCURRENTFETCHADDRESS_ADDRESS_Msk

#endif