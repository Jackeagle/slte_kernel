/*
 * 1-Wire SHA256 software implementation for the ds23el15 chip
 *
 * Copyright (C) 2013 maximintergrated
 *
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 */


#ifndef _W1_DS28EL15_SHA256_H
#define _W1_DS28EL15_SHA256_H

#include <linux/types.h>

int compute_sha256(unchar* message, short length, ushort skipconst, ushort reverse, unchar* digest);
int verify_mac256(unchar* MT, short lenght, unchar* compare_MAC);
int compute_mac256(unchar* message, short length, unchar* MAC);
int calculate_nextsecret256(unchar* binding, unchar* partial, int page_num, unchar* man_id);
void set_secret(unchar *secret_data);
void set_romid(unchar *romid_data);


#endif
