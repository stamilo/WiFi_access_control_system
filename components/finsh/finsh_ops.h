/*
 *  operations for finsh shell.
 *
 * COPYRIGHT (C) 2006 - 2013, RT-Thread Development Team
 *
 *  This file is part of RT-Thread (http://www.rt-thread.org)
 *  Maintainer: bernard.xiong <bernard.xiong at gmail.com>
 *
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Change Logs:
 * Date           Author       Notes
 * 2010-03-22     Bernard      first version
 */
#ifndef __FINSH_OP_H__
#define __FINSH_OP_H__

#include "finsh_vm.h"

/*
 * FinC VM specification
 * Memory
 * .VAR
 *
 * .STACK
 *
 * .HEAP
 *
 * .TEXT
 * OP [op1]
 */

#define FINSH_OP_NOOP            0x00

/* add @ r1 = r2 + r3 */
#define FINSH_OP_ADD_BYTE        0x01
#define FINSH_OP_ADD_WORD        0x02
#define FINSH_OP_ADD_DWORD        0x03

/* sub @ r1 = r2 - r3 */
#define FINSH_OP_SUB_BYTE        0x04
#define FINSH_OP_SUB_WORD        0x05
#define FINSH_OP_SUB_DWORD        0x06

/* div @ r1 = r2 / r3 */
#define FINSH_OP_DIV_BYTE        0x07
#define FINSH_OP_DIV_WORD        0x08
#define FINSH_OP_DIV_DWORD        0x09

/* mod @ r1 = r2 % r3 */
#define FINSH_OP_MOD_BYTE        0x0A
#define FINSH_OP_MOD_WORD        0x0B
#define FINSH_OP_MOD_DWORD        0x0C

/* mul @ r1 = r2 * r3 */
#define FINSH_OP_MUL_BYTE        0x0D
#define FINSH_OP_MUL_WORD        0x0E
#define FINSH_OP_MUL_DWORD        0x0F

/* and @ r1 = r2 & r3 */
#define FINSH_OP_AND_BYTE        0x10
#define FINSH_OP_AND_WORD        0x11
#define FINSH_OP_AND_DWORD        0x12

/* or  @ r1 = r2 | r3 */
#define FINSH_OP_OR_BYTE        0x13
#define FINSH_OP_OR_WORD        0x14
#define FINSH_OP_OR_DWORD        0x15

/* xor @ r1 = r2 ^ r3 */
#define FINSH_OP_XOR_BYTE        0x16
#define FINSH_OP_XOR_WORD        0x17
#define FINSH_OP_XOR_DWORD        0x18

/* bw  @ r1 = ~r2 */
#define FINSH_OP_BITWISE_BYTE    0x19
#define FINSH_OP_BITWISE_WORD    0x1A
#define FINSH_OP_BITWISE_DWORD    0x1B

/* shl @ r1 = r2 << r3 */
#define FINSH_OP_SHL_BYTE        0x1C
#define FINSH_OP_SHL_WORD        0x1D
#define FINSH_OP_SHL_DWORD        0x1E

/* shr @ r1 = r2 >> r3 */
#define FINSH_OP_SHR_BYTE        0x1F
#define FINSH_OP_SHR_WORD        0x20
#define FINSH_OP_SHR_DWORD        0x21

/* ld  @ r1 = [r2] */
#define FINSH_OP_LD_BYTE        0x22
#define FINSH_OP_LD_WORD        0x23
#define FINSH_OP_LD_DWORD        0x24

#define FINSH_OP_LD_VALUE_BYTE    0x25
#define FINSH_OP_LD_VALUE_WORD    0x26
#define FINSH_OP_LD_VALUE_DWORD    0x27

/* st  @ [r2] = r1 */
#define FINSH_OP_ST_BYTE        0x28
#define FINSH_OP_ST_WORD        0x29
#define FINSH_OP_ST_DWORD        0x2A

/* pop */
#define FINSH_OP_POP            0x2B

/* call r1 @ [r1](stack) */
#define FINSH_OP_SYSCALL        0x2C

/* load value from stack */
#define FINSH_OP_LD_VALUE_BYTE_STACK    0x2D
#define FINSH_OP_LD_VALUE_WORD_STACK    0x2E
#define FINSH_OP_LD_VALUE_DWORD_STACK    0x2F

/* halt */
#define FINSH_OP_HALT            0xFF

typedef void (*op_func)();
extern const op_func op_table[];

#endif
