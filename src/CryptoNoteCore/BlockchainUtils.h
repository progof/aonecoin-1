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

#include <vector>

#include "CachedTransaction.h"
#include "CryptoNote.h"
#include "CryptoNoteTools.h"

namespace CryptoNote {
namespace Utils {

bool restoreCachedTransactions(const std::vector<BinaryArray>& binaryTransactions, std::vector<CachedTransaction>& transactions);

} //namespace Utils
} //namespace CryptoNote
