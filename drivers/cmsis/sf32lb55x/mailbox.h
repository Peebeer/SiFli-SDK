/*
 * SPDX-FileCopyrightText: 2019-2025 SiFli Technologies(Nanjing) Co., Ltd
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef __MAILBOX_H
#define __MAILBOX_H


typedef struct
{
    __IO uint32_t C1IER;
    __IO uint32_t C1ITR;
    __IO uint32_t C1ICR;
    __IO uint32_t C1ISR;
    __IO uint32_t C1MISR;
    __IO uint32_t C2IER;
    __IO uint32_t C2ITR;
    __IO uint32_t C2ICR;
    __IO uint32_t C2ISR;
    __IO uint32_t C2MISR;
    __IO uint32_t C1EXR;
    __IO uint32_t C2EXR;
} MAILBOX_TypeDef;

#define MAILBOX_CHANNEL_NUMBER          (16)
#define MUTEX_CHANNLE_NUM               (2)

/***************** Bit definition for MAILBOX_C1IER register ******************/
#define MAILBOX_C1IER_INT0_Pos          (0U)
#define MAILBOX_C1IER_INT0_Msk          (0x1UL << MAILBOX_C1IER_INT0_Pos)
#define MAILBOX_C1IER_INT0              MAILBOX_C1IER_INT0_Msk
#define MAILBOX_C1IER_INT1_Pos          (1U)
#define MAILBOX_C1IER_INT1_Msk          (0x1UL << MAILBOX_C1IER_INT1_Pos)
#define MAILBOX_C1IER_INT1              MAILBOX_C1IER_INT1_Msk
#define MAILBOX_C1IER_INT2_Pos          (2U)
#define MAILBOX_C1IER_INT2_Msk          (0x1UL << MAILBOX_C1IER_INT2_Pos)
#define MAILBOX_C1IER_INT2              MAILBOX_C1IER_INT2_Msk
#define MAILBOX_C1IER_INT3_Pos          (3U)
#define MAILBOX_C1IER_INT3_Msk          (0x1UL << MAILBOX_C1IER_INT3_Pos)
#define MAILBOX_C1IER_INT3              MAILBOX_C1IER_INT3_Msk
#define MAILBOX_C1IER_INT4_Pos          (4U)
#define MAILBOX_C1IER_INT4_Msk          (0x1UL << MAILBOX_C1IER_INT4_Pos)
#define MAILBOX_C1IER_INT4              MAILBOX_C1IER_INT4_Msk
#define MAILBOX_C1IER_INT5_Pos          (5U)
#define MAILBOX_C1IER_INT5_Msk          (0x1UL << MAILBOX_C1IER_INT5_Pos)
#define MAILBOX_C1IER_INT5              MAILBOX_C1IER_INT5_Msk
#define MAILBOX_C1IER_INT6_Pos          (6U)
#define MAILBOX_C1IER_INT6_Msk          (0x1UL << MAILBOX_C1IER_INT6_Pos)
#define MAILBOX_C1IER_INT6              MAILBOX_C1IER_INT6_Msk
#define MAILBOX_C1IER_INT7_Pos          (7U)
#define MAILBOX_C1IER_INT7_Msk          (0x1UL << MAILBOX_C1IER_INT7_Pos)
#define MAILBOX_C1IER_INT7              MAILBOX_C1IER_INT7_Msk
#define MAILBOX_C1IER_INT8_Pos          (8U)
#define MAILBOX_C1IER_INT8_Msk          (0x1UL << MAILBOX_C1IER_INT8_Pos)
#define MAILBOX_C1IER_INT8              MAILBOX_C1IER_INT8_Msk
#define MAILBOX_C1IER_INT9_Pos          (9U)
#define MAILBOX_C1IER_INT9_Msk          (0x1UL << MAILBOX_C1IER_INT9_Pos)
#define MAILBOX_C1IER_INT9              MAILBOX_C1IER_INT9_Msk
#define MAILBOX_C1IER_INT10_Pos         (10U)
#define MAILBOX_C1IER_INT10_Msk         (0x1UL << MAILBOX_C1IER_INT10_Pos)
#define MAILBOX_C1IER_INT10             MAILBOX_C1IER_INT10_Msk
#define MAILBOX_C1IER_INT11_Pos         (11U)
#define MAILBOX_C1IER_INT11_Msk         (0x1UL << MAILBOX_C1IER_INT11_Pos)
#define MAILBOX_C1IER_INT11             MAILBOX_C1IER_INT11_Msk
#define MAILBOX_C1IER_INT12_Pos         (12U)
#define MAILBOX_C1IER_INT12_Msk         (0x1UL << MAILBOX_C1IER_INT12_Pos)
#define MAILBOX_C1IER_INT12             MAILBOX_C1IER_INT12_Msk
#define MAILBOX_C1IER_INT13_Pos         (13U)
#define MAILBOX_C1IER_INT13_Msk         (0x1UL << MAILBOX_C1IER_INT13_Pos)
#define MAILBOX_C1IER_INT13             MAILBOX_C1IER_INT13_Msk
#define MAILBOX_C1IER_INT14_Pos         (14U)
#define MAILBOX_C1IER_INT14_Msk         (0x1UL << MAILBOX_C1IER_INT14_Pos)
#define MAILBOX_C1IER_INT14             MAILBOX_C1IER_INT14_Msk
#define MAILBOX_C1IER_INT15_Pos         (15U)
#define MAILBOX_C1IER_INT15_Msk         (0x1UL << MAILBOX_C1IER_INT15_Pos)
#define MAILBOX_C1IER_INT15             MAILBOX_C1IER_INT15_Msk

/***************** Bit definition for MAILBOX_C1ITR register ******************/
#define MAILBOX_C1ITR_INT0_Pos          (0U)
#define MAILBOX_C1ITR_INT0_Msk          (0x1UL << MAILBOX_C1ITR_INT0_Pos)
#define MAILBOX_C1ITR_INT0              MAILBOX_C1ITR_INT0_Msk
#define MAILBOX_C1ITR_INT1_Pos          (1U)
#define MAILBOX_C1ITR_INT1_Msk          (0x1UL << MAILBOX_C1ITR_INT1_Pos)
#define MAILBOX_C1ITR_INT1              MAILBOX_C1ITR_INT1_Msk
#define MAILBOX_C1ITR_INT2_Pos          (2U)
#define MAILBOX_C1ITR_INT2_Msk          (0x1UL << MAILBOX_C1ITR_INT2_Pos)
#define MAILBOX_C1ITR_INT2              MAILBOX_C1ITR_INT2_Msk
#define MAILBOX_C1ITR_INT3_Pos          (3U)
#define MAILBOX_C1ITR_INT3_Msk          (0x1UL << MAILBOX_C1ITR_INT3_Pos)
#define MAILBOX_C1ITR_INT3              MAILBOX_C1ITR_INT3_Msk
#define MAILBOX_C1ITR_INT4_Pos          (4U)
#define MAILBOX_C1ITR_INT4_Msk          (0x1UL << MAILBOX_C1ITR_INT4_Pos)
#define MAILBOX_C1ITR_INT4              MAILBOX_C1ITR_INT4_Msk
#define MAILBOX_C1ITR_INT5_Pos          (5U)
#define MAILBOX_C1ITR_INT5_Msk          (0x1UL << MAILBOX_C1ITR_INT5_Pos)
#define MAILBOX_C1ITR_INT5              MAILBOX_C1ITR_INT5_Msk
#define MAILBOX_C1ITR_INT6_Pos          (6U)
#define MAILBOX_C1ITR_INT6_Msk          (0x1UL << MAILBOX_C1ITR_INT6_Pos)
#define MAILBOX_C1ITR_INT6              MAILBOX_C1ITR_INT6_Msk
#define MAILBOX_C1ITR_INT7_Pos          (7U)
#define MAILBOX_C1ITR_INT7_Msk          (0x1UL << MAILBOX_C1ITR_INT7_Pos)
#define MAILBOX_C1ITR_INT7              MAILBOX_C1ITR_INT7_Msk
#define MAILBOX_C1ITR_INT8_Pos          (8U)
#define MAILBOX_C1ITR_INT8_Msk          (0x1UL << MAILBOX_C1ITR_INT8_Pos)
#define MAILBOX_C1ITR_INT8              MAILBOX_C1ITR_INT8_Msk
#define MAILBOX_C1ITR_INT9_Pos          (9U)
#define MAILBOX_C1ITR_INT9_Msk          (0x1UL << MAILBOX_C1ITR_INT9_Pos)
#define MAILBOX_C1ITR_INT9              MAILBOX_C1ITR_INT9_Msk
#define MAILBOX_C1ITR_INT10_Pos         (10U)
#define MAILBOX_C1ITR_INT10_Msk         (0x1UL << MAILBOX_C1ITR_INT10_Pos)
#define MAILBOX_C1ITR_INT10             MAILBOX_C1ITR_INT10_Msk
#define MAILBOX_C1ITR_INT11_Pos         (11U)
#define MAILBOX_C1ITR_INT11_Msk         (0x1UL << MAILBOX_C1ITR_INT11_Pos)
#define MAILBOX_C1ITR_INT11             MAILBOX_C1ITR_INT11_Msk
#define MAILBOX_C1ITR_INT12_Pos         (12U)
#define MAILBOX_C1ITR_INT12_Msk         (0x1UL << MAILBOX_C1ITR_INT12_Pos)
#define MAILBOX_C1ITR_INT12             MAILBOX_C1ITR_INT12_Msk
#define MAILBOX_C1ITR_INT13_Pos         (13U)
#define MAILBOX_C1ITR_INT13_Msk         (0x1UL << MAILBOX_C1ITR_INT13_Pos)
#define MAILBOX_C1ITR_INT13             MAILBOX_C1ITR_INT13_Msk
#define MAILBOX_C1ITR_INT14_Pos         (14U)
#define MAILBOX_C1ITR_INT14_Msk         (0x1UL << MAILBOX_C1ITR_INT14_Pos)
#define MAILBOX_C1ITR_INT14             MAILBOX_C1ITR_INT14_Msk
#define MAILBOX_C1ITR_INT15_Pos         (15U)
#define MAILBOX_C1ITR_INT15_Msk         (0x1UL << MAILBOX_C1ITR_INT15_Pos)
#define MAILBOX_C1ITR_INT15             MAILBOX_C1ITR_INT15_Msk

/***************** Bit definition for MAILBOX_C1ICR register ******************/
#define MAILBOX_C1ICR_INT0_Pos          (0U)
#define MAILBOX_C1ICR_INT0_Msk          (0x1UL << MAILBOX_C1ICR_INT0_Pos)
#define MAILBOX_C1ICR_INT0              MAILBOX_C1ICR_INT0_Msk
#define MAILBOX_C1ICR_INT1_Pos          (1U)
#define MAILBOX_C1ICR_INT1_Msk          (0x1UL << MAILBOX_C1ICR_INT1_Pos)
#define MAILBOX_C1ICR_INT1              MAILBOX_C1ICR_INT1_Msk
#define MAILBOX_C1ICR_INT2_Pos          (2U)
#define MAILBOX_C1ICR_INT2_Msk          (0x1UL << MAILBOX_C1ICR_INT2_Pos)
#define MAILBOX_C1ICR_INT2              MAILBOX_C1ICR_INT2_Msk
#define MAILBOX_C1ICR_INT3_Pos          (3U)
#define MAILBOX_C1ICR_INT3_Msk          (0x1UL << MAILBOX_C1ICR_INT3_Pos)
#define MAILBOX_C1ICR_INT3              MAILBOX_C1ICR_INT3_Msk
#define MAILBOX_C1ICR_INT4_Pos          (4U)
#define MAILBOX_C1ICR_INT4_Msk          (0x1UL << MAILBOX_C1ICR_INT4_Pos)
#define MAILBOX_C1ICR_INT4              MAILBOX_C1ICR_INT4_Msk
#define MAILBOX_C1ICR_INT5_Pos          (5U)
#define MAILBOX_C1ICR_INT5_Msk          (0x1UL << MAILBOX_C1ICR_INT5_Pos)
#define MAILBOX_C1ICR_INT5              MAILBOX_C1ICR_INT5_Msk
#define MAILBOX_C1ICR_INT6_Pos          (6U)
#define MAILBOX_C1ICR_INT6_Msk          (0x1UL << MAILBOX_C1ICR_INT6_Pos)
#define MAILBOX_C1ICR_INT6              MAILBOX_C1ICR_INT6_Msk
#define MAILBOX_C1ICR_INT7_Pos          (7U)
#define MAILBOX_C1ICR_INT7_Msk          (0x1UL << MAILBOX_C1ICR_INT7_Pos)
#define MAILBOX_C1ICR_INT7              MAILBOX_C1ICR_INT7_Msk
#define MAILBOX_C1ICR_INT8_Pos          (8U)
#define MAILBOX_C1ICR_INT8_Msk          (0x1UL << MAILBOX_C1ICR_INT8_Pos)
#define MAILBOX_C1ICR_INT8              MAILBOX_C1ICR_INT8_Msk
#define MAILBOX_C1ICR_INT9_Pos          (9U)
#define MAILBOX_C1ICR_INT9_Msk          (0x1UL << MAILBOX_C1ICR_INT9_Pos)
#define MAILBOX_C1ICR_INT9              MAILBOX_C1ICR_INT9_Msk
#define MAILBOX_C1ICR_INT10_Pos         (10U)
#define MAILBOX_C1ICR_INT10_Msk         (0x1UL << MAILBOX_C1ICR_INT10_Pos)
#define MAILBOX_C1ICR_INT10             MAILBOX_C1ICR_INT10_Msk
#define MAILBOX_C1ICR_INT11_Pos         (11U)
#define MAILBOX_C1ICR_INT11_Msk         (0x1UL << MAILBOX_C1ICR_INT11_Pos)
#define MAILBOX_C1ICR_INT11             MAILBOX_C1ICR_INT11_Msk
#define MAILBOX_C1ICR_INT12_Pos         (12U)
#define MAILBOX_C1ICR_INT12_Msk         (0x1UL << MAILBOX_C1ICR_INT12_Pos)
#define MAILBOX_C1ICR_INT12             MAILBOX_C1ICR_INT12_Msk
#define MAILBOX_C1ICR_INT13_Pos         (13U)
#define MAILBOX_C1ICR_INT13_Msk         (0x1UL << MAILBOX_C1ICR_INT13_Pos)
#define MAILBOX_C1ICR_INT13             MAILBOX_C1ICR_INT13_Msk
#define MAILBOX_C1ICR_INT14_Pos         (14U)
#define MAILBOX_C1ICR_INT14_Msk         (0x1UL << MAILBOX_C1ICR_INT14_Pos)
#define MAILBOX_C1ICR_INT14             MAILBOX_C1ICR_INT14_Msk
#define MAILBOX_C1ICR_INT15_Pos         (15U)
#define MAILBOX_C1ICR_INT15_Msk         (0x1UL << MAILBOX_C1ICR_INT15_Pos)
#define MAILBOX_C1ICR_INT15             MAILBOX_C1ICR_INT15_Msk

/***************** Bit definition for MAILBOX_C1ISR register ******************/
#define MAILBOX_C1ISR_INT0_Pos          (0U)
#define MAILBOX_C1ISR_INT0_Msk          (0x1UL << MAILBOX_C1ISR_INT0_Pos)
#define MAILBOX_C1ISR_INT0              MAILBOX_C1ISR_INT0_Msk
#define MAILBOX_C1ISR_INT1_Pos          (1U)
#define MAILBOX_C1ISR_INT1_Msk          (0x1UL << MAILBOX_C1ISR_INT1_Pos)
#define MAILBOX_C1ISR_INT1              MAILBOX_C1ISR_INT1_Msk
#define MAILBOX_C1ISR_INT2_Pos          (2U)
#define MAILBOX_C1ISR_INT2_Msk          (0x1UL << MAILBOX_C1ISR_INT2_Pos)
#define MAILBOX_C1ISR_INT2              MAILBOX_C1ISR_INT2_Msk
#define MAILBOX_C1ISR_INT3_Pos          (3U)
#define MAILBOX_C1ISR_INT3_Msk          (0x1UL << MAILBOX_C1ISR_INT3_Pos)
#define MAILBOX_C1ISR_INT3              MAILBOX_C1ISR_INT3_Msk
#define MAILBOX_C1ISR_INT4_Pos          (4U)
#define MAILBOX_C1ISR_INT4_Msk          (0x1UL << MAILBOX_C1ISR_INT4_Pos)
#define MAILBOX_C1ISR_INT4              MAILBOX_C1ISR_INT4_Msk
#define MAILBOX_C1ISR_INT5_Pos          (5U)
#define MAILBOX_C1ISR_INT5_Msk          (0x1UL << MAILBOX_C1ISR_INT5_Pos)
#define MAILBOX_C1ISR_INT5              MAILBOX_C1ISR_INT5_Msk
#define MAILBOX_C1ISR_INT6_Pos          (6U)
#define MAILBOX_C1ISR_INT6_Msk          (0x1UL << MAILBOX_C1ISR_INT6_Pos)
#define MAILBOX_C1ISR_INT6              MAILBOX_C1ISR_INT6_Msk
#define MAILBOX_C1ISR_INT7_Pos          (7U)
#define MAILBOX_C1ISR_INT7_Msk          (0x1UL << MAILBOX_C1ISR_INT7_Pos)
#define MAILBOX_C1ISR_INT7              MAILBOX_C1ISR_INT7_Msk
#define MAILBOX_C1ISR_INT8_Pos          (8U)
#define MAILBOX_C1ISR_INT8_Msk          (0x1UL << MAILBOX_C1ISR_INT8_Pos)
#define MAILBOX_C1ISR_INT8              MAILBOX_C1ISR_INT8_Msk
#define MAILBOX_C1ISR_INT9_Pos          (9U)
#define MAILBOX_C1ISR_INT9_Msk          (0x1UL << MAILBOX_C1ISR_INT9_Pos)
#define MAILBOX_C1ISR_INT9              MAILBOX_C1ISR_INT9_Msk
#define MAILBOX_C1ISR_INT10_Pos         (10U)
#define MAILBOX_C1ISR_INT10_Msk         (0x1UL << MAILBOX_C1ISR_INT10_Pos)
#define MAILBOX_C1ISR_INT10             MAILBOX_C1ISR_INT10_Msk
#define MAILBOX_C1ISR_INT11_Pos         (11U)
#define MAILBOX_C1ISR_INT11_Msk         (0x1UL << MAILBOX_C1ISR_INT11_Pos)
#define MAILBOX_C1ISR_INT11             MAILBOX_C1ISR_INT11_Msk
#define MAILBOX_C1ISR_INT12_Pos         (12U)
#define MAILBOX_C1ISR_INT12_Msk         (0x1UL << MAILBOX_C1ISR_INT12_Pos)
#define MAILBOX_C1ISR_INT12             MAILBOX_C1ISR_INT12_Msk
#define MAILBOX_C1ISR_INT13_Pos         (13U)
#define MAILBOX_C1ISR_INT13_Msk         (0x1UL << MAILBOX_C1ISR_INT13_Pos)
#define MAILBOX_C1ISR_INT13             MAILBOX_C1ISR_INT13_Msk
#define MAILBOX_C1ISR_INT14_Pos         (14U)
#define MAILBOX_C1ISR_INT14_Msk         (0x1UL << MAILBOX_C1ISR_INT14_Pos)
#define MAILBOX_C1ISR_INT14             MAILBOX_C1ISR_INT14_Msk
#define MAILBOX_C1ISR_INT15_Pos         (15U)
#define MAILBOX_C1ISR_INT15_Msk         (0x1UL << MAILBOX_C1ISR_INT15_Pos)
#define MAILBOX_C1ISR_INT15             MAILBOX_C1ISR_INT15_Msk

/***************** Bit definition for MAILBOX_C1MISR register *****************/
#define MAILBOX_C1MISR_INT0_Pos         (0U)
#define MAILBOX_C1MISR_INT0_Msk         (0x1UL << MAILBOX_C1MISR_INT0_Pos)
#define MAILBOX_C1MISR_INT0             MAILBOX_C1MISR_INT0_Msk
#define MAILBOX_C1MISR_INT1_Pos         (1U)
#define MAILBOX_C1MISR_INT1_Msk         (0x1UL << MAILBOX_C1MISR_INT1_Pos)
#define MAILBOX_C1MISR_INT1             MAILBOX_C1MISR_INT1_Msk
#define MAILBOX_C1MISR_INT2_Pos         (2U)
#define MAILBOX_C1MISR_INT2_Msk         (0x1UL << MAILBOX_C1MISR_INT2_Pos)
#define MAILBOX_C1MISR_INT2             MAILBOX_C1MISR_INT2_Msk
#define MAILBOX_C1MISR_INT3_Pos         (3U)
#define MAILBOX_C1MISR_INT3_Msk         (0x1UL << MAILBOX_C1MISR_INT3_Pos)
#define MAILBOX_C1MISR_INT3             MAILBOX_C1MISR_INT3_Msk
#define MAILBOX_C1MISR_INT4_Pos         (4U)
#define MAILBOX_C1MISR_INT4_Msk         (0x1UL << MAILBOX_C1MISR_INT4_Pos)
#define MAILBOX_C1MISR_INT4             MAILBOX_C1MISR_INT4_Msk
#define MAILBOX_C1MISR_INT5_Pos         (5U)
#define MAILBOX_C1MISR_INT5_Msk         (0x1UL << MAILBOX_C1MISR_INT5_Pos)
#define MAILBOX_C1MISR_INT5             MAILBOX_C1MISR_INT5_Msk
#define MAILBOX_C1MISR_INT6_Pos         (6U)
#define MAILBOX_C1MISR_INT6_Msk         (0x1UL << MAILBOX_C1MISR_INT6_Pos)
#define MAILBOX_C1MISR_INT6             MAILBOX_C1MISR_INT6_Msk
#define MAILBOX_C1MISR_INT7_Pos         (7U)
#define MAILBOX_C1MISR_INT7_Msk         (0x1UL << MAILBOX_C1MISR_INT7_Pos)
#define MAILBOX_C1MISR_INT7             MAILBOX_C1MISR_INT7_Msk
#define MAILBOX_C1MISR_INT8_Pos         (8U)
#define MAILBOX_C1MISR_INT8_Msk         (0x1UL << MAILBOX_C1MISR_INT8_Pos)
#define MAILBOX_C1MISR_INT8             MAILBOX_C1MISR_INT8_Msk
#define MAILBOX_C1MISR_INT9_Pos         (9U)
#define MAILBOX_C1MISR_INT9_Msk         (0x1UL << MAILBOX_C1MISR_INT9_Pos)
#define MAILBOX_C1MISR_INT9             MAILBOX_C1MISR_INT9_Msk
#define MAILBOX_C1MISR_INT10_Pos        (10U)
#define MAILBOX_C1MISR_INT10_Msk        (0x1UL << MAILBOX_C1MISR_INT10_Pos)
#define MAILBOX_C1MISR_INT10            MAILBOX_C1MISR_INT10_Msk
#define MAILBOX_C1MISR_INT11_Pos        (11U)
#define MAILBOX_C1MISR_INT11_Msk        (0x1UL << MAILBOX_C1MISR_INT11_Pos)
#define MAILBOX_C1MISR_INT11            MAILBOX_C1MISR_INT11_Msk
#define MAILBOX_C1MISR_INT12_Pos        (12U)
#define MAILBOX_C1MISR_INT12_Msk        (0x1UL << MAILBOX_C1MISR_INT12_Pos)
#define MAILBOX_C1MISR_INT12            MAILBOX_C1MISR_INT12_Msk
#define MAILBOX_C1MISR_INT13_Pos        (13U)
#define MAILBOX_C1MISR_INT13_Msk        (0x1UL << MAILBOX_C1MISR_INT13_Pos)
#define MAILBOX_C1MISR_INT13            MAILBOX_C1MISR_INT13_Msk
#define MAILBOX_C1MISR_INT14_Pos        (14U)
#define MAILBOX_C1MISR_INT14_Msk        (0x1UL << MAILBOX_C1MISR_INT14_Pos)
#define MAILBOX_C1MISR_INT14            MAILBOX_C1MISR_INT14_Msk
#define MAILBOX_C1MISR_INT15_Pos        (15U)
#define MAILBOX_C1MISR_INT15_Msk        (0x1UL << MAILBOX_C1MISR_INT15_Pos)
#define MAILBOX_C1MISR_INT15            MAILBOX_C1MISR_INT15_Msk

/***************** Bit definition for MAILBOX_C2IER register ******************/
#define MAILBOX_C2IER_INT0_Pos          (0U)
#define MAILBOX_C2IER_INT0_Msk          (0x1UL << MAILBOX_C2IER_INT0_Pos)
#define MAILBOX_C2IER_INT0              MAILBOX_C2IER_INT0_Msk
#define MAILBOX_C2IER_INT1_Pos          (1U)
#define MAILBOX_C2IER_INT1_Msk          (0x1UL << MAILBOX_C2IER_INT1_Pos)
#define MAILBOX_C2IER_INT1              MAILBOX_C2IER_INT1_Msk
#define MAILBOX_C2IER_INT2_Pos          (2U)
#define MAILBOX_C2IER_INT2_Msk          (0x1UL << MAILBOX_C2IER_INT2_Pos)
#define MAILBOX_C2IER_INT2              MAILBOX_C2IER_INT2_Msk
#define MAILBOX_C2IER_INT3_Pos          (3U)
#define MAILBOX_C2IER_INT3_Msk          (0x1UL << MAILBOX_C2IER_INT3_Pos)
#define MAILBOX_C2IER_INT3              MAILBOX_C2IER_INT3_Msk
#define MAILBOX_C2IER_INT4_Pos          (4U)
#define MAILBOX_C2IER_INT4_Msk          (0x1UL << MAILBOX_C2IER_INT4_Pos)
#define MAILBOX_C2IER_INT4              MAILBOX_C2IER_INT4_Msk
#define MAILBOX_C2IER_INT5_Pos          (5U)
#define MAILBOX_C2IER_INT5_Msk          (0x1UL << MAILBOX_C2IER_INT5_Pos)
#define MAILBOX_C2IER_INT5              MAILBOX_C2IER_INT5_Msk
#define MAILBOX_C2IER_INT6_Pos          (6U)
#define MAILBOX_C2IER_INT6_Msk          (0x1UL << MAILBOX_C2IER_INT6_Pos)
#define MAILBOX_C2IER_INT6              MAILBOX_C2IER_INT6_Msk
#define MAILBOX_C2IER_INT7_Pos          (7U)
#define MAILBOX_C2IER_INT7_Msk          (0x1UL << MAILBOX_C2IER_INT7_Pos)
#define MAILBOX_C2IER_INT7              MAILBOX_C2IER_INT7_Msk
#define MAILBOX_C2IER_INT8_Pos          (8U)
#define MAILBOX_C2IER_INT8_Msk          (0x1UL << MAILBOX_C2IER_INT8_Pos)
#define MAILBOX_C2IER_INT8              MAILBOX_C2IER_INT8_Msk
#define MAILBOX_C2IER_INT9_Pos          (9U)
#define MAILBOX_C2IER_INT9_Msk          (0x1UL << MAILBOX_C2IER_INT9_Pos)
#define MAILBOX_C2IER_INT9              MAILBOX_C2IER_INT9_Msk
#define MAILBOX_C2IER_INT10_Pos         (10U)
#define MAILBOX_C2IER_INT10_Msk         (0x1UL << MAILBOX_C2IER_INT10_Pos)
#define MAILBOX_C2IER_INT10             MAILBOX_C2IER_INT10_Msk
#define MAILBOX_C2IER_INT11_Pos         (11U)
#define MAILBOX_C2IER_INT11_Msk         (0x1UL << MAILBOX_C2IER_INT11_Pos)
#define MAILBOX_C2IER_INT11             MAILBOX_C2IER_INT11_Msk
#define MAILBOX_C2IER_INT12_Pos         (12U)
#define MAILBOX_C2IER_INT12_Msk         (0x1UL << MAILBOX_C2IER_INT12_Pos)
#define MAILBOX_C2IER_INT12             MAILBOX_C2IER_INT12_Msk
#define MAILBOX_C2IER_INT13_Pos         (13U)
#define MAILBOX_C2IER_INT13_Msk         (0x1UL << MAILBOX_C2IER_INT13_Pos)
#define MAILBOX_C2IER_INT13             MAILBOX_C2IER_INT13_Msk
#define MAILBOX_C2IER_INT14_Pos         (14U)
#define MAILBOX_C2IER_INT14_Msk         (0x1UL << MAILBOX_C2IER_INT14_Pos)
#define MAILBOX_C2IER_INT14             MAILBOX_C2IER_INT14_Msk
#define MAILBOX_C2IER_INT15_Pos         (15U)
#define MAILBOX_C2IER_INT15_Msk         (0x1UL << MAILBOX_C2IER_INT15_Pos)
#define MAILBOX_C2IER_INT15             MAILBOX_C2IER_INT15_Msk

/***************** Bit definition for MAILBOX_C2ITR register ******************/
#define MAILBOX_C2ITR_INT0_Pos          (0U)
#define MAILBOX_C2ITR_INT0_Msk          (0x1UL << MAILBOX_C2ITR_INT0_Pos)
#define MAILBOX_C2ITR_INT0              MAILBOX_C2ITR_INT0_Msk
#define MAILBOX_C2ITR_INT1_Pos          (1U)
#define MAILBOX_C2ITR_INT1_Msk          (0x1UL << MAILBOX_C2ITR_INT1_Pos)
#define MAILBOX_C2ITR_INT1              MAILBOX_C2ITR_INT1_Msk
#define MAILBOX_C2ITR_INT2_Pos          (2U)
#define MAILBOX_C2ITR_INT2_Msk          (0x1UL << MAILBOX_C2ITR_INT2_Pos)
#define MAILBOX_C2ITR_INT2              MAILBOX_C2ITR_INT2_Msk
#define MAILBOX_C2ITR_INT3_Pos          (3U)
#define MAILBOX_C2ITR_INT3_Msk          (0x1UL << MAILBOX_C2ITR_INT3_Pos)
#define MAILBOX_C2ITR_INT3              MAILBOX_C2ITR_INT3_Msk
#define MAILBOX_C2ITR_INT4_Pos          (4U)
#define MAILBOX_C2ITR_INT4_Msk          (0x1UL << MAILBOX_C2ITR_INT4_Pos)
#define MAILBOX_C2ITR_INT4              MAILBOX_C2ITR_INT4_Msk
#define MAILBOX_C2ITR_INT5_Pos          (5U)
#define MAILBOX_C2ITR_INT5_Msk          (0x1UL << MAILBOX_C2ITR_INT5_Pos)
#define MAILBOX_C2ITR_INT5              MAILBOX_C2ITR_INT5_Msk
#define MAILBOX_C2ITR_INT6_Pos          (6U)
#define MAILBOX_C2ITR_INT6_Msk          (0x1UL << MAILBOX_C2ITR_INT6_Pos)
#define MAILBOX_C2ITR_INT6              MAILBOX_C2ITR_INT6_Msk
#define MAILBOX_C2ITR_INT7_Pos          (7U)
#define MAILBOX_C2ITR_INT7_Msk          (0x1UL << MAILBOX_C2ITR_INT7_Pos)
#define MAILBOX_C2ITR_INT7              MAILBOX_C2ITR_INT7_Msk
#define MAILBOX_C2ITR_INT8_Pos          (8U)
#define MAILBOX_C2ITR_INT8_Msk          (0x1UL << MAILBOX_C2ITR_INT8_Pos)
#define MAILBOX_C2ITR_INT8              MAILBOX_C2ITR_INT8_Msk
#define MAILBOX_C2ITR_INT9_Pos          (9U)
#define MAILBOX_C2ITR_INT9_Msk          (0x1UL << MAILBOX_C2ITR_INT9_Pos)
#define MAILBOX_C2ITR_INT9              MAILBOX_C2ITR_INT9_Msk
#define MAILBOX_C2ITR_INT10_Pos         (10U)
#define MAILBOX_C2ITR_INT10_Msk         (0x1UL << MAILBOX_C2ITR_INT10_Pos)
#define MAILBOX_C2ITR_INT10             MAILBOX_C2ITR_INT10_Msk
#define MAILBOX_C2ITR_INT11_Pos         (11U)
#define MAILBOX_C2ITR_INT11_Msk         (0x1UL << MAILBOX_C2ITR_INT11_Pos)
#define MAILBOX_C2ITR_INT11             MAILBOX_C2ITR_INT11_Msk
#define MAILBOX_C2ITR_INT12_Pos         (12U)
#define MAILBOX_C2ITR_INT12_Msk         (0x1UL << MAILBOX_C2ITR_INT12_Pos)
#define MAILBOX_C2ITR_INT12             MAILBOX_C2ITR_INT12_Msk
#define MAILBOX_C2ITR_INT13_Pos         (13U)
#define MAILBOX_C2ITR_INT13_Msk         (0x1UL << MAILBOX_C2ITR_INT13_Pos)
#define MAILBOX_C2ITR_INT13             MAILBOX_C2ITR_INT13_Msk
#define MAILBOX_C2ITR_INT14_Pos         (14U)
#define MAILBOX_C2ITR_INT14_Msk         (0x1UL << MAILBOX_C2ITR_INT14_Pos)
#define MAILBOX_C2ITR_INT14             MAILBOX_C2ITR_INT14_Msk
#define MAILBOX_C2ITR_INT15_Pos         (15U)
#define MAILBOX_C2ITR_INT15_Msk         (0x1UL << MAILBOX_C2ITR_INT15_Pos)
#define MAILBOX_C2ITR_INT15             MAILBOX_C2ITR_INT15_Msk

/***************** Bit definition for MAILBOX_C2ICR register ******************/
#define MAILBOX_C2ICR_INT0_Pos          (0U)
#define MAILBOX_C2ICR_INT0_Msk          (0x1UL << MAILBOX_C2ICR_INT0_Pos)
#define MAILBOX_C2ICR_INT0              MAILBOX_C2ICR_INT0_Msk
#define MAILBOX_C2ICR_INT1_Pos          (1U)
#define MAILBOX_C2ICR_INT1_Msk          (0x1UL << MAILBOX_C2ICR_INT1_Pos)
#define MAILBOX_C2ICR_INT1              MAILBOX_C2ICR_INT1_Msk
#define MAILBOX_C2ICR_INT2_Pos          (2U)
#define MAILBOX_C2ICR_INT2_Msk          (0x1UL << MAILBOX_C2ICR_INT2_Pos)
#define MAILBOX_C2ICR_INT2              MAILBOX_C2ICR_INT2_Msk
#define MAILBOX_C2ICR_INT3_Pos          (3U)
#define MAILBOX_C2ICR_INT3_Msk          (0x1UL << MAILBOX_C2ICR_INT3_Pos)
#define MAILBOX_C2ICR_INT3              MAILBOX_C2ICR_INT3_Msk
#define MAILBOX_C2ICR_INT4_Pos          (4U)
#define MAILBOX_C2ICR_INT4_Msk          (0x1UL << MAILBOX_C2ICR_INT4_Pos)
#define MAILBOX_C2ICR_INT4              MAILBOX_C2ICR_INT4_Msk
#define MAILBOX_C2ICR_INT5_Pos          (5U)
#define MAILBOX_C2ICR_INT5_Msk          (0x1UL << MAILBOX_C2ICR_INT5_Pos)
#define MAILBOX_C2ICR_INT5              MAILBOX_C2ICR_INT5_Msk
#define MAILBOX_C2ICR_INT6_Pos          (6U)
#define MAILBOX_C2ICR_INT6_Msk          (0x1UL << MAILBOX_C2ICR_INT6_Pos)
#define MAILBOX_C2ICR_INT6              MAILBOX_C2ICR_INT6_Msk
#define MAILBOX_C2ICR_INT7_Pos          (7U)
#define MAILBOX_C2ICR_INT7_Msk          (0x1UL << MAILBOX_C2ICR_INT7_Pos)
#define MAILBOX_C2ICR_INT7              MAILBOX_C2ICR_INT7_Msk
#define MAILBOX_C2ICR_INT8_Pos          (8U)
#define MAILBOX_C2ICR_INT8_Msk          (0x1UL << MAILBOX_C2ICR_INT8_Pos)
#define MAILBOX_C2ICR_INT8              MAILBOX_C2ICR_INT8_Msk
#define MAILBOX_C2ICR_INT9_Pos          (9U)
#define MAILBOX_C2ICR_INT9_Msk          (0x1UL << MAILBOX_C2ICR_INT9_Pos)
#define MAILBOX_C2ICR_INT9              MAILBOX_C2ICR_INT9_Msk
#define MAILBOX_C2ICR_INT10_Pos         (10U)
#define MAILBOX_C2ICR_INT10_Msk         (0x1UL << MAILBOX_C2ICR_INT10_Pos)
#define MAILBOX_C2ICR_INT10             MAILBOX_C2ICR_INT10_Msk
#define MAILBOX_C2ICR_INT11_Pos         (11U)
#define MAILBOX_C2ICR_INT11_Msk         (0x1UL << MAILBOX_C2ICR_INT11_Pos)
#define MAILBOX_C2ICR_INT11             MAILBOX_C2ICR_INT11_Msk
#define MAILBOX_C2ICR_INT12_Pos         (12U)
#define MAILBOX_C2ICR_INT12_Msk         (0x1UL << MAILBOX_C2ICR_INT12_Pos)
#define MAILBOX_C2ICR_INT12             MAILBOX_C2ICR_INT12_Msk
#define MAILBOX_C2ICR_INT13_Pos         (13U)
#define MAILBOX_C2ICR_INT13_Msk         (0x1UL << MAILBOX_C2ICR_INT13_Pos)
#define MAILBOX_C2ICR_INT13             MAILBOX_C2ICR_INT13_Msk
#define MAILBOX_C2ICR_INT14_Pos         (14U)
#define MAILBOX_C2ICR_INT14_Msk         (0x1UL << MAILBOX_C2ICR_INT14_Pos)
#define MAILBOX_C2ICR_INT14             MAILBOX_C2ICR_INT14_Msk
#define MAILBOX_C2ICR_INT15_Pos         (15U)
#define MAILBOX_C2ICR_INT15_Msk         (0x1UL << MAILBOX_C2ICR_INT15_Pos)
#define MAILBOX_C2ICR_INT15             MAILBOX_C2ICR_INT15_Msk

/***************** Bit definition for MAILBOX_C2ISR register ******************/
#define MAILBOX_C2ISR_INT0_Pos          (0U)
#define MAILBOX_C2ISR_INT0_Msk          (0x1UL << MAILBOX_C2ISR_INT0_Pos)
#define MAILBOX_C2ISR_INT0              MAILBOX_C2ISR_INT0_Msk
#define MAILBOX_C2ISR_INT1_Pos          (1U)
#define MAILBOX_C2ISR_INT1_Msk          (0x1UL << MAILBOX_C2ISR_INT1_Pos)
#define MAILBOX_C2ISR_INT1              MAILBOX_C2ISR_INT1_Msk
#define MAILBOX_C2ISR_INT2_Pos          (2U)
#define MAILBOX_C2ISR_INT2_Msk          (0x1UL << MAILBOX_C2ISR_INT2_Pos)
#define MAILBOX_C2ISR_INT2              MAILBOX_C2ISR_INT2_Msk
#define MAILBOX_C2ISR_INT3_Pos          (3U)
#define MAILBOX_C2ISR_INT3_Msk          (0x1UL << MAILBOX_C2ISR_INT3_Pos)
#define MAILBOX_C2ISR_INT3              MAILBOX_C2ISR_INT3_Msk
#define MAILBOX_C2ISR_INT4_Pos          (4U)
#define MAILBOX_C2ISR_INT4_Msk          (0x1UL << MAILBOX_C2ISR_INT4_Pos)
#define MAILBOX_C2ISR_INT4              MAILBOX_C2ISR_INT4_Msk
#define MAILBOX_C2ISR_INT5_Pos          (5U)
#define MAILBOX_C2ISR_INT5_Msk          (0x1UL << MAILBOX_C2ISR_INT5_Pos)
#define MAILBOX_C2ISR_INT5              MAILBOX_C2ISR_INT5_Msk
#define MAILBOX_C2ISR_INT6_Pos          (6U)
#define MAILBOX_C2ISR_INT6_Msk          (0x1UL << MAILBOX_C2ISR_INT6_Pos)
#define MAILBOX_C2ISR_INT6              MAILBOX_C2ISR_INT6_Msk
#define MAILBOX_C2ISR_INT7_Pos          (7U)
#define MAILBOX_C2ISR_INT7_Msk          (0x1UL << MAILBOX_C2ISR_INT7_Pos)
#define MAILBOX_C2ISR_INT7              MAILBOX_C2ISR_INT7_Msk
#define MAILBOX_C2ISR_INT8_Pos          (8U)
#define MAILBOX_C2ISR_INT8_Msk          (0x1UL << MAILBOX_C2ISR_INT8_Pos)
#define MAILBOX_C2ISR_INT8              MAILBOX_C2ISR_INT8_Msk
#define MAILBOX_C2ISR_INT9_Pos          (9U)
#define MAILBOX_C2ISR_INT9_Msk          (0x1UL << MAILBOX_C2ISR_INT9_Pos)
#define MAILBOX_C2ISR_INT9              MAILBOX_C2ISR_INT9_Msk
#define MAILBOX_C2ISR_INT10_Pos         (10U)
#define MAILBOX_C2ISR_INT10_Msk         (0x1UL << MAILBOX_C2ISR_INT10_Pos)
#define MAILBOX_C2ISR_INT10             MAILBOX_C2ISR_INT10_Msk
#define MAILBOX_C2ISR_INT11_Pos         (11U)
#define MAILBOX_C2ISR_INT11_Msk         (0x1UL << MAILBOX_C2ISR_INT11_Pos)
#define MAILBOX_C2ISR_INT11             MAILBOX_C2ISR_INT11_Msk
#define MAILBOX_C2ISR_INT12_Pos         (12U)
#define MAILBOX_C2ISR_INT12_Msk         (0x1UL << MAILBOX_C2ISR_INT12_Pos)
#define MAILBOX_C2ISR_INT12             MAILBOX_C2ISR_INT12_Msk
#define MAILBOX_C2ISR_INT13_Pos         (13U)
#define MAILBOX_C2ISR_INT13_Msk         (0x1UL << MAILBOX_C2ISR_INT13_Pos)
#define MAILBOX_C2ISR_INT13             MAILBOX_C2ISR_INT13_Msk
#define MAILBOX_C2ISR_INT14_Pos         (14U)
#define MAILBOX_C2ISR_INT14_Msk         (0x1UL << MAILBOX_C2ISR_INT14_Pos)
#define MAILBOX_C2ISR_INT14             MAILBOX_C2ISR_INT14_Msk
#define MAILBOX_C2ISR_INT15_Pos         (15U)
#define MAILBOX_C2ISR_INT15_Msk         (0x1UL << MAILBOX_C2ISR_INT15_Pos)
#define MAILBOX_C2ISR_INT15             MAILBOX_C2ISR_INT15_Msk

/***************** Bit definition for MAILBOX_C2MISR register *****************/
#define MAILBOX_C2MISR_INT0_Pos         (0U)
#define MAILBOX_C2MISR_INT0_Msk         (0x1UL << MAILBOX_C2MISR_INT0_Pos)
#define MAILBOX_C2MISR_INT0             MAILBOX_C2MISR_INT0_Msk
#define MAILBOX_C2MISR_INT1_Pos         (1U)
#define MAILBOX_C2MISR_INT1_Msk         (0x1UL << MAILBOX_C2MISR_INT1_Pos)
#define MAILBOX_C2MISR_INT1             MAILBOX_C2MISR_INT1_Msk
#define MAILBOX_C2MISR_INT2_Pos         (2U)
#define MAILBOX_C2MISR_INT2_Msk         (0x1UL << MAILBOX_C2MISR_INT2_Pos)
#define MAILBOX_C2MISR_INT2             MAILBOX_C2MISR_INT2_Msk
#define MAILBOX_C2MISR_INT3_Pos         (3U)
#define MAILBOX_C2MISR_INT3_Msk         (0x1UL << MAILBOX_C2MISR_INT3_Pos)
#define MAILBOX_C2MISR_INT3             MAILBOX_C2MISR_INT3_Msk
#define MAILBOX_C2MISR_INT4_Pos         (4U)
#define MAILBOX_C2MISR_INT4_Msk         (0x1UL << MAILBOX_C2MISR_INT4_Pos)
#define MAILBOX_C2MISR_INT4             MAILBOX_C2MISR_INT4_Msk
#define MAILBOX_C2MISR_INT5_Pos         (5U)
#define MAILBOX_C2MISR_INT5_Msk         (0x1UL << MAILBOX_C2MISR_INT5_Pos)
#define MAILBOX_C2MISR_INT5             MAILBOX_C2MISR_INT5_Msk
#define MAILBOX_C2MISR_INT6_Pos         (6U)
#define MAILBOX_C2MISR_INT6_Msk         (0x1UL << MAILBOX_C2MISR_INT6_Pos)
#define MAILBOX_C2MISR_INT6             MAILBOX_C2MISR_INT6_Msk
#define MAILBOX_C2MISR_INT7_Pos         (7U)
#define MAILBOX_C2MISR_INT7_Msk         (0x1UL << MAILBOX_C2MISR_INT7_Pos)
#define MAILBOX_C2MISR_INT7             MAILBOX_C2MISR_INT7_Msk
#define MAILBOX_C2MISR_INT8_Pos         (8U)
#define MAILBOX_C2MISR_INT8_Msk         (0x1UL << MAILBOX_C2MISR_INT8_Pos)
#define MAILBOX_C2MISR_INT8             MAILBOX_C2MISR_INT8_Msk
#define MAILBOX_C2MISR_INT9_Pos         (9U)
#define MAILBOX_C2MISR_INT9_Msk         (0x1UL << MAILBOX_C2MISR_INT9_Pos)
#define MAILBOX_C2MISR_INT9             MAILBOX_C2MISR_INT9_Msk
#define MAILBOX_C2MISR_INT10_Pos        (10U)
#define MAILBOX_C2MISR_INT10_Msk        (0x1UL << MAILBOX_C2MISR_INT10_Pos)
#define MAILBOX_C2MISR_INT10            MAILBOX_C2MISR_INT10_Msk
#define MAILBOX_C2MISR_INT11_Pos        (11U)
#define MAILBOX_C2MISR_INT11_Msk        (0x1UL << MAILBOX_C2MISR_INT11_Pos)
#define MAILBOX_C2MISR_INT11            MAILBOX_C2MISR_INT11_Msk
#define MAILBOX_C2MISR_INT12_Pos        (12U)
#define MAILBOX_C2MISR_INT12_Msk        (0x1UL << MAILBOX_C2MISR_INT12_Pos)
#define MAILBOX_C2MISR_INT12            MAILBOX_C2MISR_INT12_Msk
#define MAILBOX_C2MISR_INT13_Pos        (13U)
#define MAILBOX_C2MISR_INT13_Msk        (0x1UL << MAILBOX_C2MISR_INT13_Pos)
#define MAILBOX_C2MISR_INT13            MAILBOX_C2MISR_INT13_Msk
#define MAILBOX_C2MISR_INT14_Pos        (14U)
#define MAILBOX_C2MISR_INT14_Msk        (0x1UL << MAILBOX_C2MISR_INT14_Pos)
#define MAILBOX_C2MISR_INT14            MAILBOX_C2MISR_INT14_Msk
#define MAILBOX_C2MISR_INT15_Pos        (15U)
#define MAILBOX_C2MISR_INT15_Msk        (0x1UL << MAILBOX_C2MISR_INT15_Pos)
#define MAILBOX_C2MISR_INT15            MAILBOX_C2MISR_INT15_Msk

/***************** Bit definition for MAILBOX_C1EXR register ******************/
#define MAILBOX_C1EXR_ID_Pos            (0U)
#define MAILBOX_C1EXR_ID_Msk            (0xFUL << MAILBOX_C1EXR_ID_Pos)
#define MAILBOX_C1EXR_ID                MAILBOX_C1EXR_ID_Msk
#define MAILBOX_C1EXR_EX_Pos            (31U)
#define MAILBOX_C1EXR_EX_Msk            (0x1UL << MAILBOX_C1EXR_EX_Pos)
#define MAILBOX_C1EXR_EX                MAILBOX_C1EXR_EX_Msk

/***************** Bit definition for MAILBOX_C2EXR register ******************/
#define MAILBOX_C2EXR_ID_Pos            (0U)
#define MAILBOX_C2EXR_ID_Msk            (0xFUL << MAILBOX_C2EXR_ID_Pos)
#define MAILBOX_C2EXR_ID                MAILBOX_C2EXR_ID_Msk
#define MAILBOX_C2EXR_EX_Pos            (31U)
#define MAILBOX_C2EXR_EX_Msk            (0x1UL << MAILBOX_C2EXR_EX_Pos)
#define MAILBOX_C2EXR_EX                MAILBOX_C2EXR_EX_Msk

#endif