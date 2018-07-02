/*
 * Copyright (c) 2018-2019, The Aonecoin Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Aonecoin.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#include "StringOutputStream.h"

namespace Common {

StringOutputStream::StringOutputStream(std::string& out) : out(out) {
}

size_t StringOutputStream::writeSome(const void* data, size_t size) {
  out.append(static_cast<const char*>(data), size);
  return size;
}

}