/*
 * Copyright (c) 2018-2019, The Aonecoin Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Aonecoin.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include <stddef.h>
#include <stdint.h>

#include "groestl.h"

void hash_extra_groestl(const void *data, size_t length, char *hash) {
  groestl(data, length * 8, (uint8_t*)hash);
}
