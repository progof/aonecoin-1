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

#include <mutex>
#include "CommonLogger.h"

namespace Logging {

class StreamLogger : public CommonLogger {
public:
  StreamLogger(Level level = DEBUGGING);
  StreamLogger(std::ostream& stream, Level level = DEBUGGING);
  void attachToStream(std::ostream& stream);

protected:
  virtual void doLogString(const std::string& message) override;

protected:
  std::ostream* stream;

private:
  std::mutex mutex;
};

}
