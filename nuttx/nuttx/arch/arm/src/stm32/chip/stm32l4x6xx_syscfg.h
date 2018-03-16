/****************************************************************************************************
 * arch/arm/src/stm32/chip/stm32l4x6xx_syscfg.h
 *
 *   Copyright (C) 2015 Motorola Mobility, LLC. All rights reserved.
 *   Copyright (C) 2013 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ****************************************************************************************************/

#ifndef __ARCH_ARM_SRC_STM32_CHIP_STM32L4X6XX_SYSCFG_H
#define __ARCH_ARM_SRC_STM32_CHIP_STM32L4X6XX_SYSCFG_H

/****************************************************************************************************
 * Included Files
 ****************************************************************************************************/

#include <nuttx/config.h>
#include "chip.h"

#ifdef CONFIG_STM32_STM32L4X6

/****************************************************************************************************
 * Pre-processor Definitions
 ****************************************************************************************************/

/* Register Offsets *********************************************************************************/

#define STM32_SYSCFG_MEMRMP_OFFSET     0x0000 /* SYSCFG memory remap register */
#define STM32_SYSCFG_CFGR1_OFFSET      0x0004 /* SYSCFG configuration register 1 */

#define STM32_SYSCFG_EXTICR_OFFSET(p)  (0x0008 + ((p) & 0x000c)) /* Registers are displaced by 4! */
#define STM32_SYSCFG_EXTICR1_OFFSET    0x0008 /* SYSCFG external interrupt configuration register 1 */
#define STM32_SYSCFG_EXTICR2_OFFSET    0x000c /* SYSCFG external interrupt configuration register 2 */
#define STM32_SYSCFG_EXTICR3_OFFSET    0x0010 /* SYSCFG external interrupt configuration register 3 */
#define STM32_SYSCFG_EXTICR4_OFFSET    0x0014 /* SYSCFG external interrupt configuration register 4 */

#define STM32_SYSCFG_SCSR_OFFSET       0x0018 /* SYSCFG control and status register */
#define STM32_SYSCFG_CFGR2_OFFSET      0x001c /* SYSCFG configuration register 2 */
#define STM32_SYSCFG_SWPR_OFFSET       0x0020 /* SYSCFG write protection register */
#define STM32_SYSCFG_SKR_OFFSET        0x0024 /* SYSCFG SRAM2 key register */

/* Register Addresses *******************************************************************************/

#define STM32_SYSCFG_MEMRMP            (STM32_SYSCFG_BASE+STM32_SYSCFG_MEMRMP_OFFSET)
#define STM32_SYSCFG_CFGR1             (STM32_SYSCFG_BASE+STM32_SYSCFG_CFGR1_OFFSET)

#define STM32_SYSCFG_EXTICR(p)         (STM32_SYSCFG_BASE+STM32_SYSCFG_EXTICR_OFFSET(p))
#define STM32_SYSCFG_EXTICR1           (STM32_SYSCFG_BASE+STM32_SYSCFG_EXTICR1_OFFSET)
#define STM32_SYSCFG_EXTICR2           (STM32_SYSCFG_BASE+STM32_SYSCFG_EXTICR2_OFFSET)
#define STM32_SYSCFG_EXTICR3           (STM32_SYSCFG_BASE+STM32_SYSCFG_EXTICR3_OFFSET)
#define STM32_SYSCFG_EXTICR4           (STM32_SYSCFG_BASE+STM32_SYSCFG_EXTICR4_OFFSET)

#define STM32_SYSCFG_SCSR              (STM32_SYSCFG_BASE+STM32_SYSCFG_SCSR_OFFSET)
#define STM32_SYSCFG_CFGR2             (STM32_SYSCFG_BASE+STM32_SYSCFG_CFGR2_OFFSET)
#define STM32_SYSCFG_SWPR              (STM32_SYSCFG_BASE+STM32_SYSCFG_SWPR_OFFSET)
#define STM32_SYSCFG_SKR               (STM32_SYSCFG_BASE+STM32_SYSCFG_SKR_OFFSET)

/* Register Bitfield Definitions ********************************************************************/

/* SYSCFG memory remap register */

/* SYSCFG configuration register */

/* SYSCFG external interrupt configuration register 1-4 */

#define SYSCFG_EXTICR_PORTA           (0)       /* 0000: PA[x] pin */
#define SYSCFG_EXTICR_PORTB           (1)       /* 0001: PB[x] pin */
#define SYSCFG_EXTICR_PORTC           (2)       /* 0010: PC[x] pin */
#define SYSCFG_EXTICR_PORTD           (3)       /* 0011: PD[x] pin */
#define SYSCFG_EXTICR_PORTE           (4)       /* 0100: PE[x] pin */
#define SYSCFG_EXTICR_PORTF           (5)       /* 0101: PF[x] pin */
#define SYSCFG_EXTICR_PORTG           (6)       /* 0110: PG[x] pin */
#define SYSCFG_EXTICR_PORTH           (7)       /* 0111: PH[x] pin */

#define SYSCFG_EXTICR_PORT_MASK       (15)
#define SYSCFG_EXTICR_EXTI_SHIFT(g)   (((g) & 3) << 2)
#define SYSCFG_EXTICR_EXTI_MASK(g)    (SYSCFG_EXTICR_PORT_MASK << (SYSCFG_EXTICR_EXTI_SHIFT(g)))

#define SYSCFG_EXTICR1_EXTI0_SHIFT    (0)       /* Bits 0-3: EXTI 0 coinfiguration */
#define SYSCFG_EXTICR1_EXTI0_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR1_EXTI0_SHIFT)
#define SYSCFG_EXTICR1_EXTI1_SHIFT    (4)       /* Bits 4-7: EXTI 1 coinfiguration */
#define SYSCFG_EXTICR1_EXTI1_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR1_EXTI1_SHIFT)
#define SYSCFG_EXTICR1_EXTI2_SHIFT    (8)       /* Bits 8-11: EXTI 2 coinfiguration */
#define SYSCFG_EXTICR1_EXTI2_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR1_EXTI2_SHIFT)
#define SYSCFG_EXTICR1_EXTI3_SHIFT    (12)      /* Bits 12-15: EXTI 3 coinfiguration */
#define SYSCFG_EXTICR1_EXTI3_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR1_EXTI3_SHIFT)

#define SYSCFG_EXTICR2_EXTI4_SHIFT    (0)       /* Bits 0-3: EXTI 4 coinfiguration */
#define SYSCFG_EXTICR2_EXTI4_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR2_EXTI4_SHIFT)
#define SYSCFG_EXTICR2_EXTI5_SHIFT    (4)       /* Bits 4-7: EXTI 5 coinfiguration */
#define SYSCFG_EXTICR2_EXTI5_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR2_EXTI5_SHIFT)
#define SYSCFG_EXTICR2_EXTI6_SHIFT    (8)       /* Bits 8-11: EXTI 6 coinfiguration */
#define SYSCFG_EXTICR2_EXTI6_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR2_EXTI6_SHIFT)
#define SYSCFG_EXTICR2_EXTI7_SHIFT    (12)      /* Bits 12-15: EXTI 7 coinfiguration */
#define SYSCFG_EXTICR2_EXTI7_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR2_EXTI7_SHIFT)

#define SYSCFG_EXTICR3_EXTI8_SHIFT    (0)       /* Bits 0-3: EXTI 8 coinfiguration */
#define SYSCFG_EXTICR3_EXTI8_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR3_EXTI8_SHIFT)
#define SYSCFG_EXTICR3_EXTI9_SHIFT    (4)       /* Bits 4-7: EXTI 9 coinfiguration */
#define SYSCFG_EXTICR3_EXTI9_MASK     (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR3_EXTI9_SHIFT)
#define SYSCFG_EXTICR3_EXTI10_SHIFT   (8)       /* Bits 8-11: EXTI 10 coinfiguration */
#define SYSCFG_EXTICR3_EXTI10_MASK    (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR3_EXTI10_SHIFT)
#define SYSCFG_EXTICR3_EXTI11_SHIFT   (12)      /* Bits 12-15: EXTI 11 coinfiguration */
#define SYSCFG_EXTICR3_EXTI11_MASK    (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR3_EXTI11_SHIFT)

#define SYSCFG_EXTICR4_EXTI12_SHIFT   (0)       /* Bits 0-3: EXTI 12 coinfiguration */
#define SYSCFG_EXTICR4_EXTI12_MASK    (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR4_EXTI12_SHIFT)
#define SYSCFG_EXTICR4_EXTI13_SHIFT   (4)       /* Bits 4-7: EXTI 13 coinfiguration */
#define SYSCFG_EXTICR4_EXTI13_MASK    (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR4_EXTI13_SHIFT)
#define SYSCFG_EXTICR4_EXTI14_SHIFT   (8)       /* Bits 8-11: EXTI 14 coinfiguration */
#define SYSCFG_EXTICR4_EXTI14_MASK    (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR4_EXTI14_SHIFT)
#define SYSCFG_EXTICR4_EXTI15_SHIFT   (12)      /* Bits 12-15: EXTI 15 coinfiguration */
#define SYSCFG_EXTICR4_EXTI15_MASK    (SYSCFG_EXTICR_PORT_MASK << SYSCFG_EXTICR4_EXTI15_SHIFT)

/* SYSCFG SRAM2 control and status register */

/* SYSCFG configuration register 2 */

#endif /* CONFIG_STM32_STM32L4X6 */
#endif /* __ARCH_ARM_SRC_STM32_CHIP_STM32L4X6XX_SYSCFG_H */

