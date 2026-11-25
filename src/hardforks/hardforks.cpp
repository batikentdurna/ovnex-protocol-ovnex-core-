// Copyright (c) 2014-2023, The Monero Project
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without modification, are
// permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice, this list of
//    conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice, this list
//    of conditions and the following disclaimer in the documentation and/or other
//    materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors may be
//    used to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY
// EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
// MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
// THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
// THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

// ============================================================
// OVNEX Blockchain — Hardfork Schedule
// 
// OVNEX launches with a minimal hardfork schedule:
//   v1 — Genesis (block 1): Chain starts, standard CryptoNote
//   v2 — Block 10: Dev fee output + RingCT tx version stabilized
//
// All Zephyr stablecoin hardforks (v3-v11) map to HF_VERSION_DJED=99
// and will never activate. OVNEX is a pure CPU-mineable coin.
// ============================================================

#include "hardforks.h"

#undef MONERO_DEFAULT_LOG_CATEGORY
#define MONERO_DEFAULT_LOG_CATEGORY "blockchain.hardforks"

// OVNEX Mainnet hardfork schedule
// Timestamp: 1764547200 = November 22, 2026 00:00:00 UTC (OVNEX genesis date)
const hardfork_t mainnet_hard_forks[] = {
  // v1: Genesis — standard CryptoNote transfers, genesis premine (3% = 3M OVNX)
  { 1, 0, 0, 1764547200 },
  // v2: Block 10 — activate 5% protocol-level dev fee (HF_VERSION_DEV_FEE = 1 in config,
  //     but hardfork version 2 is used for RingCT tx stability confirmation)
  { 2, 10, 0, 1764547800 },
};
const size_t num_mainnet_hard_forks = sizeof(mainnet_hard_forks) / sizeof(mainnet_hard_forks[0]);
const uint64_t mainnet_hard_fork_version_1_till = 9; // v1 valid through block 9

// OVNEX Testnet hardfork schedule
const hardfork_t testnet_hard_forks[] = {
  { 1, 1, 0, 1764547200 },
  { 2, 5, 0, 1764547500 },
};
const size_t num_testnet_hard_forks = sizeof(testnet_hard_forks) / sizeof(testnet_hard_forks[0]);
const uint64_t testnet_hard_fork_version_1_till = 4;

// OVNEX Stagenet hardfork schedule
const hardfork_t stagenet_hard_forks[] = {
  { 1, 1, 0, 1764547200 },
  { 2, 5, 0, 1764547500 },
};
const size_t num_stagenet_hard_forks = sizeof(stagenet_hard_forks) / sizeof(stagenet_hard_forks[0]);
