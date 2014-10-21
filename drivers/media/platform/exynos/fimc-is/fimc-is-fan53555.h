/*
 * Samsung Exynos5 SoC series FIMC-IS driver
 *
 * exynos5 fimc-is core functions
 *
 * Copyright (c) 2011 Samsung Electronics Co., Ltd
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 */

#include <linux/i2c.h>
#include <linux/slab.h>
#include "fimc-is-core.h"

typedef unsigned char BYTE;

#define REG_VSEL0		0x00
#define VSEL0_NSEL0		0x3f
#define VSEL0_BUCK_EN0_SHIFT	7
#define VSEL0_BUCK_EN0		(0x01 << VSEL0_BUCK_EN0_SHIFT)
#define VSEL0_INIT_VAL		VSEL0_BUCK_EN0 | FAN53555_VOUT_1P00

// FAN53555UC08X : Vout = 0.60V + NSELx * 10mV
enum{
    FAN53555_VOUT_0P60 = 0,
	FAN53555_VOUT_0P61,
	FAN53555_VOUT_0P62,
	FAN53555_VOUT_0P63,
	FAN53555_VOUT_0P64,
	FAN53555_VOUT_0P65,
	FAN53555_VOUT_0P66,
	FAN53555_VOUT_0P67,
	FAN53555_VOUT_0P68,
	FAN53555_VOUT_0P69,

	FAN53555_VOUT_0P70 = 10,
	FAN53555_VOUT_0P71,
	FAN53555_VOUT_0P72,
	FAN53555_VOUT_0P73,
	FAN53555_VOUT_0P74,
	FAN53555_VOUT_0P75,
	FAN53555_VOUT_0P76,
	FAN53555_VOUT_0P77,
	FAN53555_VOUT_0P78,
	FAN53555_VOUT_0P79,

	FAN53555_VOUT_0P80 = 20,
	FAN53555_VOUT_0P81,
	FAN53555_VOUT_0P82,
	FAN53555_VOUT_0P83,
	FAN53555_VOUT_0P84,
	FAN53555_VOUT_0P85,
	FAN53555_VOUT_0P86,
	FAN53555_VOUT_0P87,
	FAN53555_VOUT_0P88,
	FAN53555_VOUT_0P89,

	FAN53555_VOUT_0P90 = 30,
	FAN53555_VOUT_0P91,
	FAN53555_VOUT_0P92,
	FAN53555_VOUT_0P93,
	FAN53555_VOUT_0P94,
	FAN53555_VOUT_0P95,
	FAN53555_VOUT_0P96,
	FAN53555_VOUT_0P97,
	FAN53555_VOUT_0P98,
	FAN53555_VOUT_0P99,

	FAN53555_VOUT_1P00 = 40,
	FAN53555_VOUT_1P01,
	FAN53555_VOUT_1P02,  // VSEL0 default, 08X
	FAN53555_VOUT_1P03,
	FAN53555_VOUT_1P04,
	FAN53555_VOUT_1P05,
	FAN53555_VOUT_1P06,
	FAN53555_VOUT_1P07,
	FAN53555_VOUT_1P08,
	FAN53555_VOUT_1P09,

	FAN53555_VOUT_1P10 = 50,
	FAN53555_VOUT_1P11,
	FAN53555_VOUT_1P12,
	FAN53555_VOUT_1P13,
	FAN53555_VOUT_1P14,
	FAN53555_VOUT_1P15,  // VSEL1 default, 08X
	FAN53555_VOUT_1P16,
	FAN53555_VOUT_1P17,
	FAN53555_VOUT_1P18,
	FAN53555_VOUT_1P19,

	FAN53555_VOUT_1P20 = 60,
	FAN53555_VOUT_1P21,
	FAN53555_VOUT_1P22,
	FAN53555_VOUT_1P23,
};

int fan53555_get_vout_val(int sel);
int fan53555_enable_vsel0(struct i2c_client *client, int on_off);
int fan53555_set_vsel0_vout(struct i2c_client *client, int vout);


