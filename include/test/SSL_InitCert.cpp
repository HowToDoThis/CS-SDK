#include <Windows.h>

#include "../openssl/ssl.h"

STACK *SSL_InitCert()
{
  STACK *v1; // edi
  X509_INFO *x509; // edi
  int v3; // esi
  char *szCertType; // eax
  int v6; // esi
  unsigned __int8 *dst; // esi
  int (__cdecl *v11)(void *, unsigned __int8 **, int); // esi
  void *p_crl; // ebx
  char *v14; // ecx
  char *v15; // eax
  bool v16; // cf
  unsigned __int8 v17; // dl
  EVP_PKEY *v19; // eax
  char *v20; // ecx
  char *v21; // edx
  unsigned int v22; // ecx
  const char *v23; // eax
  char *v24; // ecx
  bool v25; // cf
  unsigned __int8 v26; // dl
  int v27; // eax
  EVP_PKEY *v28; // eax
  char *v29; // ecx
  int v30; // eax
  STACK *v31; // esi
  int v32; // eax
  int EVP_CIPHER_INFO; // eax
  unsigned __int8 *v34; // esi
  int i; // esi
  X509_INFO *v36; // eax
  size_t v38; // [esp-10h] [ebp-5Ch]
  char *szCertEncrypt; // [esp-8h] [ebp-54h]
  unsigned __int8 *v40; // [esp+Ch] [ebp-40h] BYREF
  int v41; // [esp+10h] [ebp-3Ch]
  int v42; // [esp+14h] [ebp-38h]
  char *Src; // [esp+18h] [ebp-34h]
  long len; // [esp+1Ch] [ebp-30h] BYREF
  int v45; // [esp+20h] [ebp-2Ch]
  unsigned __int8 *data; // [esp+2Ch] [ebp-20h]
  STACK *v49; // [esp+30h] [ebp-1Ch]
  EVP_CIPHER_INFO cipher; // [esp+34h] [ebp-18h] BYREF

  data = 0;
  v41 = 0;
  v1 = (STACK *)sk_new_null();
  v49 = v1;
  if ( !v1 )
  {
LABEL_81:
    for ( i = 0; i < sk_num(v1); ++i )
    {
      v36 = (X509_INFO *)sk_value(v1, i);
      CRYPTO_FREE(v36);
    }
    if ( v1 )
      sk_free(v1);
    v31 = 0;
    goto LABEL_86;
  }

  x509 = (X509_INFO *)X509_INFO_new();
  if ( !x509 )
    goto LABEL_80;

  Src = byte_3765D2A8;
  v3 = 0;
  v45 = 0;
  v42 = 0;

  do
  {
    szCertType    = _strdup(*(char **)((char *)oCertType + v3));
    szCertEncrypt = _strdup(*(char **)((char *)oCertEncrypt + v3));
    v6 = *(int *)((char *)dword_3765D2A0 + v3);
    len = v6;
    v38 = v6;
    dst = (unsigned __int8 *)malloc(v6 + 1);
    data = dst;
    memmove(dst, Src, v38);
    v42 += 4;
    Src += 0x34D;
    dst[len] = 0;

    while ( 1 )
    {
      if ( !strcmp(szCertType, "CERTIFICATE") || !strcmp(szCertType, "X509 CERTIFICATE") )
      {
        v11 = (int (__cdecl *)(void *, unsigned __int8 **, int))d2i_X509;

        if ( !x509->x509 )
        {
          p_crl = x509;
          goto LABEL_50;
        }

        v31 = v49;
        if ( !sk_push(v49, x509) )
            goto LABEL_77;

        x509 = (X509_INFO *)X509_INFO_new();
        if ( !x509 )
        {
            v1 = v31;
            goto LABEL_81;
        }
      }
    }

    if ( !strcmp(szCertType, "RSA PRIVATE KEY") )
    {
      v11 = (int (__cdecl *)(void *, unsigned __int8 **, int))d2i_RSAPrivateKey;
      if ( x509->x_pkey )
      {
        v31 = v49;

        if ( !sk_push(v49, x509) )
            goto LABEL_77;

        x509 = (X509_INFO *)X509_INFO_new();
        if ( !x509 )
        {
            v1 = v31;
            goto LABEL_81;
        }
      }

      x509->enc_data = 0;
      x509->enc_len = 0;
      x509->x_pkey = (X509_PKEY *)X509_PKEY_new(v14);
      v19 = (EVP_PKEY *)EVP_PKEY_new();
      x509->x_pkey->dec_pkey = v19;

      if ( v19 )
      {
        v20 = szCertEncrypt;
        v21 = szCertEncrypt + 1;
        x509->x_pkey->dec_pkey->type = 6;
        p_crl = &x509->x_pkey->dec_pkey->pkey;
        v22 = (unsigned int)&v20[strlen(v20) + 1];
        if ( (v22 - v21) > 10 )
        {
            v30 = 1;
            goto LABEL_51;
        }
      }

LABEL_76:
      v31 = v49;
      goto LABEL_77;
    }

LABEL_50:
    v30 = v45;

LABEL_51:
    if ( !v11 )
      goto LABEL_60;

    if ( v30 )
    {
      if ( PEM_get_EVP_CIPHER_INFO(szCertEncrypt, &x509->enc_cipher) )
      {
        v34 = 0;
        x509->enc_data = (char *)data;
        x509->enc_len = len;
        goto LABEL_61;
      }

      goto LABEL_76;
    }

    if ( !PEM_get_EVP_CIPHER_INFO(szCertEncrypt, &cipher) || !PEM_do_header(&cipher, data, &len, 0, 0) )
      goto LABEL_76;

    v40 = data;
    v32 = v11(p_crl, &v40, len);
    
    if ( !v32 )
      goto LABEL_76;

LABEL_60:
    v34 = data;
LABEL_61:
    if ( szCertType )
      free(szCertType);
    if ( szCertEncrypt )
      free(szCertEncrypt);
    if ( v34 )
      free(v34);

    v3 = v42;
    szCertType = 0;
    szCertEncrypt = 0;
    data = 0;
    v45 = 0;
  } while ( Src < &unk_3765D942 );

  ERR_clear_error();

  if ( x509->x509 || x509->crl || x509->x_pkey || x509->enc_data )
  {
    v31 = v49;
    if ( sk_push(v49, x509) )
    {
      x509 = 0;
      v41 = 1;
    }
  }
  else
  {
    v31 = v49;
    v41 = 1;
  }

LABEL_77:
  if ( x509 )
    CRYPTO_FREE(x509);

  if ( !v41 )
  {
LABEL_80:
    v1 = v49;
    goto LABEL_81;
  }

LABEL_86:
  if ( szCertType )
    free(szCertType);
  if ( szCertEncrypt )
    free(szCertEncrypt);
  if ( data )
    free(data);

  return v31;
}