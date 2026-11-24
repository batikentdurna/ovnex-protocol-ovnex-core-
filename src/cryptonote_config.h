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
// 
// Parts of this file are originally copyright (c) 2012-2013 The Cryptonote developers

// ============================================================
// OVNEX BLOCKCHAIN — cryptonote_config.h
// Forked from ZephyrProtocol/zephyr v2.3.0
// All Zephyr/ZEPH/Djed/ZSD/ZRS/Oracle parameters replaced.
// See: AI_MASTER_INSTRUCTIONS.md, ovnex_config.json
// ============================================================

#pragma once

#include <array>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <boost/uuid/uuid.hpp>

#define CRYPTONOTE_DNS_TIMEOUT_MS                       20000

#define CRYPTONOTE_MAX_BLOCK_NUMBER                     500000000
#define CRYPTONOTE_MAX_TX_SIZE                          1000000
#define CRYPTONOTE_MAX_TX_PER_BLOCK                     0x10000000
#define CRYPTONOTE_PUBLIC_ADDRESS_TEXTBLOB_VER          0
#define CRYPTONOTE_MINED_MONEY_UNLOCK_WINDOW            60
#define CURRENT_TRANSACTION_VERSION                     2
// DJED_TRANSACTION_VERSION kept for compile compat but never activated (HF_VERSION_DJED = 99)
#define DJED_TRANSACTION_VERSION                        3
#define CURRENT_BLOCK_MAJOR_VERSION                     1
#define CURRENT_BLOCK_MINOR_VERSION                     1
#define CRYPTONOTE_BLOCK_FUTURE_TIME_LIMIT              60*60*2
#define CRYPTONOTE_DEFAULT_TX_SPENDABLE_AGE             10

#define BLOCKCHAIN_TIMESTAMP_CHECK_WINDOW               60

// MONEY_SUPPLY — OVNEX: 100,000,000 OVNX × 10^8 atomic units
// 10,000,000,000,000,000 = 10^16 atomic units total
#define MONEY_SUPPLY                                    ((uint64_t)10000000000000000ULL)
#define EMISSION_SPEED_FACTOR_PER_MINUTE                (21)
// Tail emission: ~0.00001 OVNX per minute after main emission ends
#define FINAL_SUBSIDY_PER_MINUTE                        ((uint64_t)1000000) // 0.00001 OVNX (10^6 atomic)

#define CRYPTONOTE_REWARD_BLOCKS_WINDOW                 100
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2    60000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V1    20000
#define CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5    300000
#define CRYPTONOTE_LONG_TERM_BLOCK_WEIGHT_WINDOW_SIZE   100000
#define CRYPTONOTE_SHORT_TERM_BLOCK_WEIGHT_SURGE_FACTOR 50
#define CRYPTONOTE_COINBASE_BLOB_RESERVED_SIZE          600
// OVNEX uses 8 decimal places (1 OVNX = 10^8 atomic units)
#define CRYPTONOTE_DISPLAY_DECIMAL_POINT                8
// COIN = 10^8 atomic units = 1 OVNX
#define COIN                                            ((uint64_t)100000000ULL)

#define FEE_PER_KB_OLD                                  ((uint64_t)10000000) // 0.1 OVNX
#define FEE_PER_KB                                      ((uint64_t)2000000)  // 0.02 OVNX
#define FEE_PER_BYTE                                    ((uint64_t)300)
#define DYNAMIC_FEE_PER_KB_BASE_FEE                     ((uint64_t)2000000)
#define DYNAMIC_FEE_PER_KB_BASE_BLOCK_REWARD            ((uint64_t)1000000000000) // 10000 OVNX
#define DYNAMIC_FEE_PER_KB_BASE_FEE_V5                  ((uint64_t)2000000 * (uint64_t)CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V2 / CRYPTONOTE_BLOCK_GRANTED_FULL_REWARD_ZONE_V5)
#define DYNAMIC_FEE_REFERENCE_TRANSACTION_WEIGHT         ((uint64_t)3000)

#define ORPHANED_BLOCKS_MAX_COUNT                       100

// OVNEX block target: 60 seconds
#define DIFFICULTY_TARGET_V2                            60   // seconds (OVNEX mainnet)
#define DIFFICULTY_TARGET_V1                            60   // seconds
#define DIFFICULTY_WINDOW                               720  // blocks
#define DIFFICULTY_WINDOW_V2                            70   // blocks
#define DIFFICULTY_LAG                                  15
#define DIFFICULTY_CUT                                  60
#define DIFFICULTY_BLOCKS_COUNT                         DIFFICULTY_WINDOW + DIFFICULTY_LAG
#define DIFFICULTY_BLOCKS_COUNT_V2                      DIFFICULTY_WINDOW_V2

#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V1   DIFFICULTY_TARGET_V1 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_SECONDS_V2   DIFFICULTY_TARGET_V2 * CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS
#define CRYPTONOTE_LOCKED_TX_ALLOWED_DELTA_BLOCKS       1

#define DIFFICULTY_BLOCKS_ESTIMATE_TIMESPAN             DIFFICULTY_TARGET_V1

#define BLOCKS_IDS_SYNCHRONIZING_DEFAULT_COUNT          10000
#define BLOCKS_IDS_SYNCHRONIZING_MAX_COUNT              25000
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT_PRE_V4       100
#define BLOCKS_SYNCHRONIZING_DEFAULT_COUNT              20
#define BLOCKS_SYNCHRONIZING_MAX_COUNT                  2048

#define CRYPTONOTE_MEMPOOL_TX_LIVETIME                    (86400*3)
#define CRYPTONOTE_MEMPOOL_TX_FROM_ALT_BLOCK_LIVETIME     604800

#define CRYPTONOTE_DANDELIONPP_STEMS              2
#define CRYPTONOTE_DANDELIONPP_FLUFF_PROBABILITY 20
#define CRYPTONOTE_DANDELIONPP_MIN_EPOCH         10
#define CRYPTONOTE_DANDELIONPP_EPOCH_RANGE       30
#define CRYPTONOTE_DANDELIONPP_FLUSH_AVERAGE      5
#define CRYPTONOTE_DANDELIONPP_EMBARGO_AVERAGE   39

#define CRYPTONOTE_NOISE_MIN_EPOCH                      5
#define CRYPTONOTE_NOISE_EPOCH_RANGE                    30
#define CRYPTONOTE_NOISE_MIN_DELAY                      10
#define CRYPTONOTE_NOISE_DELAY_RANGE                    5
#define CRYPTONOTE_NOISE_BYTES                          3*1024
#define CRYPTONOTE_NOISE_CHANNELS                       2

#define CRYPTONOTE_FORWARD_DELAY_BASE (CRYPTONOTE_NOISE_MIN_DELAY + CRYPTONOTE_NOISE_DELAY_RANGE)
#define CRYPTONOTE_FORWARD_DELAY_AVERAGE (CRYPTONOTE_FORWARD_DELAY_BASE + (CRYPTONOTE_FORWARD_DELAY_BASE / 2))

#define CRYPTONOTE_MAX_FRAGMENTS                        20

#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_BLOCK_COUNT     1000
#define COMMAND_RPC_GET_BLOCKS_FAST_MAX_TX_COUNT        20000
#define MAX_RPC_CONTENT_LENGTH                          1048576

#define P2P_LOCAL_WHITE_PEERLIST_LIMIT                  1000
#define P2P_LOCAL_GRAY_PEERLIST_LIMIT                   5000

#define P2P_DEFAULT_CONNECTIONS_COUNT                   12
#define P2P_DEFAULT_HANDSHAKE_INTERVAL                  60
#define P2P_DEFAULT_PACKET_MAX_SIZE                     50000000
#define P2P_DEFAULT_PEERS_IN_HANDSHAKE                  250
#define P2P_MAX_PEERS_IN_HANDSHAKE                      250
#define P2P_DEFAULT_CONNECTION_TIMEOUT                  5000
#define P2P_DEFAULT_SOCKS_CONNECT_TIMEOUT               45
#define P2P_DEFAULT_PING_CONNECTION_TIMEOUT             2000
#define P2P_DEFAULT_INVOKE_TIMEOUT                      60*2*1000
#define P2P_DEFAULT_HANDSHAKE_INVOKE_TIMEOUT            5000
#define P2P_DEFAULT_WHITELIST_CONNECTIONS_PERCENT       70
#define P2P_DEFAULT_ANCHOR_CONNECTIONS_COUNT            2
#define P2P_DEFAULT_SYNC_SEARCH_CONNECTIONS_COUNT       2
#define P2P_DEFAULT_LIMIT_RATE_UP                       2048
#define P2P_DEFAULT_LIMIT_RATE_DOWN                     8192

#define P2P_FAILED_ADDR_FORGET_SECONDS                  (60*60)
#define P2P_IP_BLOCKTIME                                (60*60*24)
#define P2P_IP_FAILS_BEFORE_BLOCK                       10
#define P2P_IDLE_CONNECTION_KILL_INTERVAL               (5*60)

#define P2P_SUPPORT_FLAG_FLUFFY_BLOCKS                  0x01
#define P2P_SUPPORT_FLAGS                               P2P_SUPPORT_FLAG_FLUFFY_BLOCKS

#define RPC_IP_FAILS_BEFORE_BLOCK                       3

// OVNEX coin identity
#define CRYPTONOTE_NAME                         "ovnex"
#define CRYPTONOTE_BLOCKCHAINDATA_FILENAME      "data.mdb"
#define CRYPTONOTE_BLOCKCHAINDATA_LOCK_FILENAME "lock.mdb"
#define P2P_NET_DATA_FILENAME                   "p2pstate.bin"
#define RPC_PAYMENTS_DATA_FILENAME              "rpcpayments.bin"
#define MINER_CONFIG_FILE_NAME                  "miner_conf.json"

#define THREAD_STACK_SIZE                       5 * 1024 * 1024

// ============================================================
// OVNEX HARDFORK SCHEDULE
// All Zephyr stablecoin/oracle/Djed hardforks are set to
// block 99,999,999 — effectively NEVER activated.
// OVNEX runs as a pure CryptoNote coin from block 0.
// When a real OVNX wallet address is available, DEV_FEE
// hardfork (HF_VERSION_DEV_FEE = 1) activates immediately.
// ============================================================
#define HF_VERSION_DEV_FEE                      1   // Dev fee active from block 1
#define HF_VERSION_DJED                         99  // DISABLED — never activates
#define HF_VERSION_PR_UPDATE                    99  // DISABLED
#define HF_VERSION_V5                           99  // DISABLED
#define HF_VERSION_V6                           99  // DISABLED
#define HF_VERSION_V7                           99  // DISABLED
#define HF_VERSION_AUDIT                        99  // DISABLED
#define HF_VERSION_PAUSE                        99  // DISABLED
#define HF_VERSION_AUDIT_EXTENSION              99  // DISABLED
#define HF_VERSION_V11                          99  // DISABLED

// These Zephyr fork heights are set to unreachable block numbers
#define YIELD_FORK_HEIGHT                       99999999
#define AUDIT_FORK_HEIGHT                       99999999
#define HF_VERSION_V11_FORK_HEIGHT              99999999

// OVNEX Dev Fee: 5% of every block reward goes to DEV_FUND_ADDRESS
// This is enforced at protocol level in construct_miner_tx().
// PLACEHOLDER: Replace with real OVNX wallet address after first build.
// Address must be a valid OVNEX mainnet address (ovnx... prefix).
#define OVNEX_DEV_FEE_PERCENT                   5
#define OVNEX_DEV_FEE_DENOMINATOR               100

// OVNEX Premine: 3% of total supply in genesis block
#define OVNEX_PREMINE_AMOUNT                    ((uint64_t)300000000000000ULL) // 3,000,000 OVNX in atomic units

// Unauditable Zeph amount — set to 0 since we never reach HF_VERSION_V11
#define UNAUDITABLE_ZEPH_AMOUNT                ((uint64_t)0)

#define PER_KB_FEE_QUANTIZATION_DECIMALS        8
#define CRYPTONOTE_SCALING_2021_FEE_ROUNDING_PLACES 2

#define HASH_OF_HASHES_STEP                     512

#define DEFAULT_TXPOOL_MAX_WEIGHT               648000000ull

#define BULLETPROOF_MAX_OUTPUTS                 16
#define BULLETPROOF_PLUS_MAX_OUTPUTS            16

#define CRYPTONOTE_PRUNING_STRIPE_SIZE          4096
#define CRYPTONOTE_PRUNING_LOG_STRIPES          3
#define CRYPTONOTE_PRUNING_TIP_BLOCKS           5500

#define RPC_CREDITS_PER_HASH_SCALE ((float)(1<<24))

#define DNS_BLOCKLIST_LIFETIME (86400 * 8)

// PRICING_RECORD constants kept for compile compatibility only.
// Oracle/pricing record logic is never reached (HF_VERSION_DJED = 99).
#define PRICING_RECORD_VALID_BLOCKS                     10
#define PRICING_RECORD_VALID_TIME_DIFF_FROM_BLOCK       120

#define MAX_TX_EXTRA_SIZE                       1060

// New constants are intended to go here
namespace config
{
  uint64_t const DEFAULT_FEE_ATOMIC_XMR_PER_KB = 500;
  uint8_t const FEE_CALCULATION_MAX_RETRIES = 10;
  uint64_t const DEFAULT_DUST_THRESHOLD = ((uint64_t)2000000000);
  uint64_t const BASE_REWARD_CLAMP_THRESHOLD = ((uint64_t)100000);

  // OVNEX mainnet address prefix.
  // Base58 prefix 0x1D7B2 encodes to "ovnx" at the start of a standard
  // CryptoNote address. This will be verified/adjusted after the first build.
  // Prefix calculation: "ovnx" target → numeric value 0x1D7B2 (120754)
  uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x1D7B2;         // "ovnx"
  uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x11D7B2; // "ovnxi"
  uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x21D7B2;        // "ovnxs"

  // OVNEX network ports (from ovnex_config.json — DO NOT CHANGE)
  uint16_t const P2P_DEFAULT_PORT = 28080;
  uint16_t const RPC_DEFAULT_PORT = 28081;
  uint16_t const ZMQ_RPC_DEFAULT_PORT = 28082;

  // OVNEX Network ID — unique UUID for OVNEX mainnet
  // Differs from Zephyr's UUID to prevent cross-chain peer confusion
  boost::uuids::uuid const NETWORK_ID = { {
      0x4F, 0x56, 0x4E, 0x45, 0x58, 0x01, 0x00, 0x00,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01
    } }; // "OVNEX" + version bytes

  // GENESIS_TX: placeholder — regenerate with --print-genesis-tx after parameter finalization
  // This is the encoded genesis coinbase transaction (premine output will be in genesis block)
  // TODO: Replace with real genesis tx after wallet address is available
    std::string const GENESIS_TX = "023c01ff00018080c89d9deb96f80602afbc283f3741ebd2435b7970adb061409fa01db0973bb30dc96bbab43ffa20e9045a455048df21011d4eeaac524223701c570651663e7e4f13b1c304c476927f19d6c3de217dcfc300000000";
  uint32_t const GENESIS_NONCE = 10000;

  // Hash domain separators (unchanged from Monero lineage)
  const char HASH_KEY_BULLETPROOF_EXPONENT[] = "bulletproof";
  const char HASH_KEY_BULLETPROOF_PLUS_EXPONENT[] = "bulletproof_plus";
  const char HASH_KEY_BULLETPROOF_PLUS_TRANSCRIPT[] = "bulletproof_plus_transcript";
  const char HASH_KEY_RINGDB[] = "ringdsb";
  const char HASH_KEY_SUBADDRESS[] = "SubAddr";
  const unsigned char HASH_KEY_ENCRYPTED_PAYMENT_ID = 0x8d;
  const unsigned char HASH_KEY_WALLET = 0x8c;
  const unsigned char HASH_KEY_WALLET_CACHE = 0x8d;
  const unsigned char HASH_KEY_RPC_PAYMENT_NONCE = 0x58;
  const unsigned char HASH_KEY_MEMORY = 'k';
  const unsigned char HASH_KEY_MULTISIG[] = {'M', 'u', 'l', 't' , 'i', 's', 'i', 'g', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  const unsigned char HASH_KEY_MULTISIG_KEY_AGGREGATION[] = "Multisig_key_agg";
  const unsigned char HASH_KEY_CLSAG_ROUND_MULTISIG[] = "CLSAG_round_ms_merge_factor";
  const unsigned char HASH_KEY_TXPROOF_V2[] = "TXPROOF_V2";
  const unsigned char HASH_KEY_CLSAG_ROUND[] = "CLSAG_round";
  const unsigned char HASH_KEY_CLSAG_AGG_0[] = "CLSAG_agg_0";
  const unsigned char HASH_KEY_CLSAG_AGG_1[] = "CLSAG_agg_1";
  const char HASH_KEY_MESSAGE_SIGNING[] = "OVNEXMessageSignature";
  const unsigned char HASH_KEY_MM_SLOT = 'm';
  const constexpr char HASH_KEY_MULTISIG_TX_PRIVKEYS_SEED[] = "multisig_tx_privkeys_seed";
  const constexpr char HASH_KEY_MULTISIG_TX_PRIVKEYS[] = "multisig_tx_privkeys";
  const constexpr char HASH_KEY_TXHASH_AND_MIXRING[] = "txhash_and_mixring";

  // Multisig
  const uint32_t MULTISIG_MAX_SIGNERS{16};

  // OVNEX Dev Fund Address (Protocol-Level 5% Dev Fee)
  // PLACEHOLDER — replace with real OVNEX wallet address after first build.
  // Format: valid OVNEX mainnet address starting with "ovnx"
  // The governance mechanism is REPURPOSED as OVNEX Dev Fee.
  std::string const GOVERNANCE_WALLET_ADDRESS = "WtTSWhEYRkhMtke2ZgvYEn6HuDDPy33C1NCs3R9xxjx2KyNP2HNsk8w4T1AvV2AGbvRbmEUdFaoSvBvGsehieLA821Qd2KsEHn";
  std::string const GOV_WALLET_ADDRESS_2 = "WtTSWhEYRkhMtke2ZgvYEn6HuDDPy33C1NCs3R9xxjx2KyNP2HNsk8w4T1AvV2AGbvRbmEUdFaoSvBvGsehieLA821Qd2KsEHn";

  // ORACLE DISABLED — OVNEX has no external oracle dependency.
  // These fields are kept for compile compatibility only.
  // HF_VERSION_DJED = 99 means oracle code is never reached.
  std::array<std::string, 3> const ORACLE_URLS = {{"disabled.ovnex.network:443", "disabled.ovnex.network:443", "disabled.ovnex.network:443"}};
  std::string const ORACLE_PUBLIC_KEY = ""; // Oracle disabled in OVNEX

  namespace testnet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x2D7B2;         // testnet prefix
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x12D7B2;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x22D7B2;
    uint16_t const P2P_DEFAULT_PORT = 38080;
    uint16_t const RPC_DEFAULT_PORT = 38081;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 38082;
    boost::uuids::uuid const NETWORK_ID = { {
        0x4F, 0x56, 0x4E, 0x45, 0x58, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02
      } }; // OVNEX testnet
      std::string const GENESIS_TX = "023c01ff00018080c89d9deb96f80602afbc283f3741ebd2435b7970adb061409fa01db0973bb30dc96bbab43ffa20e9045a455048df21011d4eeaac524223701c570651663e7e4f13b1c304c476927f19d6c3de217dcfc300000000";
  uint32_t const GENESIS_NONCE = 10001;
    std::string const GOVERNANCE_WALLET_ADDRESS = "PLACEHOLDER_REPLACE_WITH_REAL_OVNX_TESTNET_ADDRESS";
    std::string const GOV_WALLET_ADDRESS_2 = "PLACEHOLDER_REPLACE_WITH_REAL_OVNX_TESTNET_ADDRESS";
    std::array<std::string, 3> const ORACLE_URLS = {{"disabled.ovnex.network:443", "disabled.ovnex.network:443", "disabled.ovnex.network:443"}};
    std::string const ORACLE_PUBLIC_KEY = "";
  }

  namespace stagenet
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX = 0x3D7B2;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX = 0x13D7B2;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX = 0x23D7B2;
    uint16_t const P2P_DEFAULT_PORT = 48080;
    uint16_t const RPC_DEFAULT_PORT = 48081;
    uint16_t const ZMQ_RPC_DEFAULT_PORT = 48082;
    boost::uuids::uuid const NETWORK_ID = { {
        0x4F, 0x56, 0x4E, 0x45, 0x58, 0x01, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03
      } }; // OVNEX stagenet
      std::string const GENESIS_TX = "023c01ff00018080c89d9deb96f80602afbc283f3741ebd2435b7970adb061409fa01db0973bb30dc96bbab43ffa20e9045a455048df21011d4eeaac524223701c570651663e7e4f13b1c304c476927f19d6c3de217dcfc300000000";
  uint32_t const GENESIS_NONCE = 10002;
    std::string const GOVERNANCE_WALLET_ADDRESS = "PLACEHOLDER_REPLACE_WITH_REAL_OVNX_STAGENET_ADDRESS";
    std::string const GOV_WALLET_ADDRESS_2 = "PLACEHOLDER_REPLACE_WITH_REAL_OVNX_STAGENET_ADDRESS";
    std::array<std::string, 3> const ORACLE_URLS = {{"disabled.ovnex.network:443", "disabled.ovnex.network:443", "disabled.ovnex.network:443"}};
    std::string const ORACLE_PUBLIC_KEY = "";
  }
}

namespace cryptonote
{
  enum network_type : uint8_t
  {
    MAINNET = 0,
    TESTNET,
    STAGENET,
    FAKECHAIN,
    UNDEFINED = 255
  };
  struct config_t
  {
    uint64_t const CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX;
    uint64_t const CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX;
    uint64_t const CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX;
    uint16_t const P2P_DEFAULT_PORT;
    uint16_t const RPC_DEFAULT_PORT;
    uint16_t const ZMQ_RPC_DEFAULT_PORT;
    boost::uuids::uuid const NETWORK_ID;
    std::string const GENESIS_TX;
    uint32_t const GENESIS_NONCE;
    std::array<std::string, 3> const ORACLE_URLS;
    std::string const ORACLE_PUBLIC_KEY;
  };
  inline const config_t& get_config(network_type nettype)
  {
    static const config_t mainnet = {
      ::config::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::P2P_DEFAULT_PORT,
      ::config::RPC_DEFAULT_PORT,
      ::config::ZMQ_RPC_DEFAULT_PORT,
      ::config::NETWORK_ID,
      ::config::GENESIS_TX,
      ::config::GENESIS_NONCE,
      ::config::ORACLE_URLS,
      ::config::ORACLE_PUBLIC_KEY
    };
    static const config_t testnet = {
      ::config::testnet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::testnet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::testnet::P2P_DEFAULT_PORT,
      ::config::testnet::RPC_DEFAULT_PORT,
      ::config::testnet::ZMQ_RPC_DEFAULT_PORT,
      ::config::testnet::NETWORK_ID,
      ::config::testnet::GENESIS_TX,
      ::config::testnet::GENESIS_NONCE,
      ::config::testnet::ORACLE_URLS,
      ::config::testnet::ORACLE_PUBLIC_KEY
    };
    static const config_t stagenet = {
      ::config::stagenet::CRYPTONOTE_PUBLIC_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_INTEGRATED_ADDRESS_BASE58_PREFIX,
      ::config::stagenet::CRYPTONOTE_PUBLIC_SUBADDRESS_BASE58_PREFIX,
      ::config::stagenet::P2P_DEFAULT_PORT,
      ::config::stagenet::RPC_DEFAULT_PORT,
      ::config::stagenet::ZMQ_RPC_DEFAULT_PORT,
      ::config::stagenet::NETWORK_ID,
      ::config::stagenet::GENESIS_TX,
      ::config::stagenet::GENESIS_NONCE,
      ::config::stagenet::ORACLE_URLS,
      ::config::stagenet::ORACLE_PUBLIC_KEY
    };
    switch (nettype)
    {
      case MAINNET: return mainnet;
      case TESTNET: return testnet;
      case STAGENET: return stagenet;
      case FAKECHAIN: return mainnet;
      default: throw std::runtime_error("Invalid network type");
    }
  };
}
