/* 7zCrc.h -- CRC32 calculation
2009-11-21 : Igor Pavlov : Public domain */

#ifndef __7Z_CRC_H
#define __7Z_CRC_H

#include "Types.h"

EXTERN_C_BEGIN

/* Call CrcGenerateTable one time before other CRC functions */
STATIC void MY_FAST_CALL CrcGenerateTable(void);

#define CRC_INIT_VAL 0xFFFFFFFF
#define CRC_GET_DIGEST(crc) ((crc) ^ CRC_INIT_VAL)
#define CRC_UPDATE_BYTE(crc, b) (g_CrcTable[((crc) ^ (b)) & 0xFF] ^ ((crc) >> 8))

STATIC UInt32 MY_FAST_CALL CrcCalc(const void *data, size_t size);

EXTERN_C_END

#endif
