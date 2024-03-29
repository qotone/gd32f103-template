/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-11-5      SummerGift   first version
 */

#ifndef __BOARD_H__
#define __BOARD_H__

#include <rtthread.h>
#include <gd32f10x.h>


#ifdef __cplusplus
extern "C" {
#endif

#define GD32_FLASH_START_ADRESS     ((uint32_t)0x08000000)
#define GD32_FLASH_SIZE             (512 * 1024)
#define GD32_FLASH_END_ADDRESS      ((uint32_t)(GD32_FLASH_START_ADRESS + GD32_FLASH_SIZE))

/* Internal SRAM memory size[Kbytes] <8-64>, Default: 64*/
#define GD32_SRAM_SIZE      64
#define GD32_SRAM_END       (0x20000000 + GD32_SRAM_SIZE * 1024)

#if defined(__CC_ARM) || defined(__CLANG_ARM)
extern int Image$$RW_IRAM1$$ZI$$Limit;
#define HEAP_BEGIN      ((void *)&Image$$RW_IRAM1$$ZI$$Limit)
#elif __ICCARM__
#pragma section="CSTACK"
#define HEAP_BEGIN      (__segment_end("CSTACK"))
#else
extern int __bss_end;
#define HEAP_BEGIN      ((void *)&__bss_end)
#endif

#define HEAP_END        GD32_SRAM_END



#ifdef __cplusplus
}
#endif

#endif /* __BOARD_H__ */
