/*
 * Copyright (C) OpenTX
 *
 * Based on code named
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef _GHOST_H_
#define _GHOST_H_

#include <inttypes.h>
#include "dataconstants.h"

// Device (destination) address
#define GHST_ADDR_RADIO                 0x80    // phase 1
#define GHST_ADDR_MODULE                0x81
#define GHST_ADDR_FC                    0x82
#define GHST_ADDR_GOGGLES               0x83    // phase 2
#define GHST_ADDR_5G_TXCTRL             0x84	// phase 3
#define GHST_ADDR_5G_TWRSCAN            0x85
#define GHST_ADDR_5G_RLY                0x86

#define GHST_UL_RC_CHANS_HS4_5TO8	0x10	// High Speed 4 channel (12 bits), plus CH5-8 (8 bits)
#define GHST_UL_RC_CHANS_HS4_9TO12	0x11	// High Speed 4 channel (12 bits), plus CH9-12 (8 bits)
#define GHST_UL_RC_CHANS_HS4_13TO16	0x12	// High Speed 4 channel (12 bits), plus CH13-16 (8 bits)
#define GHST_UL_RC_CHANS_SIZE           12      // 1 (type) + 10 (data) + 1 (crc)

#define GHST_DL_OPENTX_SYNC		0x20
#define GHST_DL_LINK_STAT               0x21
#define GHST_DL_VTX_STAT                0x22

#define GHST_RC_CTR_VAL_12BIT		0x7C0   // 0x3e0 << 1
#define GHST_RC_CTR_VAL_8BIT		0x7C

#define GHST_CH_BITS_12                 12
#define GHST_CH_BITS_8                  8

enum GhstPowerMode
{
  GHST_PWR_16UW =   0,
  GHST_PWR_100UW =  1,
  GHST_PWR_1MW =    2,
  GHST_PWR_25MW =   3,
  GHST_PWR_100MW =  4,
  GHST_PWR_200MW =  5,
  GHST_PWR_350MW =  6,
  GHST_PWR_500MW =  7,
  GHST_PWR_600MW =  8,
  GHST_PWR_1W =     9,
  GHST_PWR_1_5W =   10,
  GHST_PWR_2W =     11,
  GHST_PWR_3W =     12,
  GHST_PWR_4W =     13,
  GHST_PWR_COUNT
};

enum GhstRFProfile
{
  GHST_RF_PROFILE_Auto        = 0,
  GHST_RF_PROFILE_Normal      = 1,
  GHST_RF_PROFILE_Race        = 2,
  GHST_RF_PROFILE_PureRace    = 3,
  GHST_RF_PROFILE_LongRange   = 4,
  GHST_RF_PROFILE_MAX = GHST_RF_PROFILE_LongRange,
  GHST_RF_PROFILE_COUNT
};

enum GhstVtxBand
{
  GHST_VTX_BAND_Unknown     = 0,
  GHST_VTX_BAND_Irc         = 1,
  GHST_VTX_BAND_Race        = 2,
  GHST_VTX_BAND_BandE       = 3,
  GHST_VTX_BAND_BandB       = 4,
  GHST_VTX_BAND_BandA       = 5,
  GHST_VTX_BAND_MAX = GHST_VTX_BAND_BandA,
  GHST_VTX_BAND_COUNT
};

void processGhostTelemetryData(uint8_t data);
void ghostSetDefault(int index, uint8_t id, uint8_t subId);

#if SPORT_MAX_BAUDRATE < 400000
// For radios which can't support telemetry at high rates, offer baud rate choices
// (modified vs. unmodified radios)
const uint32_t GHOST_BAUDRATES[] = {
  400000,
  115200,
};
const uint8_t GHOST_PERIODS[] = {
   4,
  16,
};
#define GHOST_BAUDRATE    GHOST_BAUDRATES[g_eeGeneral.telemetryBaudrate]
#define GHOST_PERIOD      GHOST_PERIODS[g_eeGeneral.telemetryBaudrate]
#else
#define GHOST_BAUDRATE       400000
#define GHOST_PERIOD         4
#endif

#endif // _GHOST_H_
