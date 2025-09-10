/* psoc6_crypto.h
 *
 * Copyright (C) 2006-2025 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

#ifndef _PSOC6_CRYPTO_PORT_H_
#define _PSOC6_CRYPTO_PORT_H_

#include <wolfssl/wolfcrypt/settings.h>
#include <wolfssl/wolfcrypt/types.h> /* for MATH_INT_T */
#include <wolfssl/wolfcrypt/wc_port.h>

#include "cy_pdl.h"

#if !defined(NO_WOLFSSL_PSOC_HASH)
#define PSOC_HASH_SHA1
#define PSOC_HASH_SHA2
#define PSOC_HASH_SHA3

typedef enum
{
    WC_PSOC_SHA1        = 0,
    WC_PSOC_SHA224      = 1,
    WC_PSOC_SHA256      = 2,
    WC_PSOC_SHA384      = 3,
    WC_PSOC_SHA512      = 4,
    WC_PSOC_SHA512_224  = 5,
    WC_PSOC_SHA512_256  = 6,
} wc_psoc_hash_sha1_sha2_t;
#endif /* NO_WOLFSSL_PSOC_HASH */

#if defined(PSOC_HASH_SHA1) || defined(PSOC_HASH_SHA2)
int wc_Psoc_Sha1_Sha2_Init(void *sha, wc_psoc_hash_sha1_sha2_t hash_mode, int init_hash);
#endif

#if defined(PSOC_HASH_SHA1) || defined(PSOC_HASH_SHA2) || defined(PSOC_HASH_SHA3)
void wc_Psoc_Sha_Free(void);
#endif

#if defined(WOLFSSL_SHA3) && defined(PSOC_HASH_SHA3)

int wc_Psoc_Sha3_Init(void* sha3);
int wc_Psoc_Sha3_Update(void *sha3, const byte* data, word32 len, byte p);
int wc_Psoc_Sha3_Final(void* sha3, byte padChar, byte* hash, byte p, word32 l);
int wc_Psoc_Shake_SqueezeBlocks(void *shake, byte* out, word32 blockCnt);
#endif /* WOLFSSL_SHA3 && PSOC_HASH_SHA3 */

#ifdef HAVE_ECC
/* Forward declaration of ecc_key structure, defined in wolfssl/wolfcrypt/ecc.h */
struct ecc_key;

int psoc6_ecc_verify_hash_ex(MATH_INT_T *r, MATH_INT_T *s, const byte* hash,
                    word32 hashlen, int* verif_res, struct ecc_key* key);
#endif /* HAVE_ECC */

#define PSOC6_CRYPTO_BASE ((CRYPTO_Type*) CRYPTO_BASE)

/* Crypto HW engine initialization */
int psoc6_crypto_port_init(void);

#endif /* _PSOC6_CRYPTO_PORT_H_ */
