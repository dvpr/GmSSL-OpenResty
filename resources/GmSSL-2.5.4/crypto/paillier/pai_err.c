/*
 * Generated by util/mkerr.pl DO NOT EDIT
 * Copyright 1995-2019 The OpenSSL Project Authors. All Rights Reserved.
 *
 * Licensed under the OpenSSL license (the "License").  You may not use
 * this file except in compliance with the License.  You can obtain a copy
 * in the file LICENSE in the source distribution or at
 * https://www.openssl.org/source/license.html
 */

#include <stdio.h>
#include <openssl/err.h>
#include <openssl/paillier.h>

/* BEGIN ERROR CODES */
#ifndef OPENSSL_NO_ERR

# define ERR_FUNC(func) ERR_PACK(ERR_LIB_PAILLIER,func,0)
# define ERR_REASON(reason) ERR_PACK(ERR_LIB_PAILLIER,0,reason)

static ERR_STRING_DATA PAILLIER_str_functs[] = {
    {ERR_FUNC(PAILLIER_F_OLD_PAILLIER_PRIV_DECODE),
     "old_paillier_priv_decode"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_CHECK_KEY), "PAILLIER_check_key"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_CIPHERTEXT_ADD), "PAILLIER_ciphertext_add"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_CIPHERTEXT_SCALAR_MUL),
     "PAILLIER_ciphertext_scalar_mul"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_DECRYPT), "PAILLIER_decrypt"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_ENCRYPT), "PAILLIER_encrypt"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_GENERATE_KEY), "PAILLIER_generate_key"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_NEW), "PAILLIER_new"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_PLAINTEXT_SIZE), "paillier_plaintext_size"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_PRIV_DECODE), "paillier_priv_decode"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_PRIV_ENCODE), "paillier_priv_encode"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_PUB_DECODE), "paillier_pub_decode"},
    {ERR_FUNC(PAILLIER_F_PAILLIER_SIZE), "PAILLIER_size"},
    {ERR_FUNC(PAILLIER_F_PKEY_PAILLIER_CTRL), "pkey_paillier_ctrl"},
    {ERR_FUNC(PAILLIER_F_PKEY_PAILLIER_CTRL_STR), "pkey_paillier_ctrl_str"},
    {ERR_FUNC(PAILLIER_F_PKEY_PAILLIER_DECRYPT), "pkey_paillier_decrypt"},
    {ERR_FUNC(PAILLIER_F_PKEY_PAILLIER_ENCRYPT), "pkey_paillier_encrypt"},
    {ERR_FUNC(PAILLIER_F_PKEY_PAILLIER_INIT), "pkey_paillier_init"},
    {ERR_FUNC(PAILLIER_F_PKEY_PAILLIER_KEYGEN), "pkey_paillier_keygen"},
    {0, NULL}
};

static ERR_STRING_DATA PAILLIER_str_reasons[] = {
    {ERR_REASON(PAILLIER_R_BUFFER_TOO_SMALL), "buffer too small"},
    {ERR_REASON(PAILLIER_R_DECODE_ERROR), "decode error"},
    {ERR_REASON(PAILLIER_R_GENERATE_PRIME_FAILED), "generate prime failed"},
    {ERR_REASON(PAILLIER_R_INVALID_PLAINTEXT), "invalid plaintext"},
    {ERR_REASON(PAILLIER_R_KEY_SIZE_TOO_SMALL), "key size too small"},
    {ERR_REASON(PAILLIER_R_MALLOC_FAILED), "malloc failed"},
    {ERR_REASON(PAILLIER_R_NOT_IMPLEMENTED), "not implemented"},
    {ERR_REASON(PAILLIER_R_VALUE_MISSING), "value missing"},
    {0, NULL}
};

#endif

int ERR_load_PAILLIER_strings(void)
{
#ifndef OPENSSL_NO_ERR

    if (ERR_func_error_string(PAILLIER_str_functs[0].error) == NULL) {
        ERR_load_strings(0, PAILLIER_str_functs);
        ERR_load_strings(0, PAILLIER_str_reasons);
    }
#endif
    return 1;
}
