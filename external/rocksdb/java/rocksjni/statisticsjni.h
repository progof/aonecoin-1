// Copyright (c) 2011-present, Facebook, Inc.  All rights reserved.
// This source code is licensed under the BSD-style license found in the
// LICENSE file in the root directory of this source tree. An additional grant
// of patent rights can be found in the PATENTS file in the same directory.
//
// This file implements the callback "bridge" between Java and C++ for
// rocksdb::Statistics

#ifndef JAVA_ROCKSJNI_STATISTICSJNI_H_
#define JAVA_ROCKSJNI_STATISTICSJNI_H_

#include <memory>
#include <set>
#include <string>
#include "rocksdb/statistics.h"
#include "monitoring/statistics.h"

namespace rocksdb {

  class StatisticsJni : public StatisticsImpl {
   public:
     StatisticsJni(std::shared_ptr<Statistics> stats);
     StatisticsJni(std::shared_ptr<Statistics> stats,
         const std::set<uint32_t> ignore_histograms);
     virtual bool HistEnabledForType(uint32_t type) const override;

   private:
     const std::set<uint32_t> m_ignore_histograms;
 };

}  // namespace rocksdb

#endif  // JAVA_ROCKSJNI_STATISTICSJNI_H_