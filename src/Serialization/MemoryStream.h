/*
 * Copyright (c) 2018-2019, The Aonecoin Developers.
 * Portions Copyright (c) 2012-2017, The CryptoNote Developers, The Bytecoin Developers.
 *
 * This file is part of Aonecoin.
 *
 * This file is subject to the terms and conditions defined in the
 * file 'LICENSE', which is part of this source code package.
 */

#pragma once

#include <algorithm>
#include <cstdint>
#include <cstring> // memcpy
#include <vector>
#include <Common/IOutputStream.h>

namespace CryptoNote {

class MemoryStream: public Common::IOutputStream {
public:

  MemoryStream() : m_writePos(0) {
  }

  virtual size_t writeSome(const void* data, size_t size) override {
    if (size == 0) {
      return 0;
    }

    if (m_writePos + size > m_buffer.size()) {
      m_buffer.resize(m_writePos + size);
    }

    memcpy(&m_buffer[m_writePos], data, size);
    m_writePos += size;
    return size;
  }

  size_t size() {
    return m_buffer.size();
  }

  const uint8_t* data() {
    return m_buffer.data();
  }

  void clear() {
    m_writePos = 0;
    m_buffer.resize(0);
  }

private:
  size_t m_writePos;
  std::vector<uint8_t> m_buffer;
};

}
