// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <Windows.h>
#include <barrier>
#include <secp256k1.h>
#include <stdio.h>
#pragma warning(suppress : 4996)
#pragma warning(disable : 4996)
secp256k1_context* ctx = NULL;
#define export_dll __declspec(dllexport)
EXTERN_C
{
    export_dll int __cdecl GenerateBitcoinAddress() 
    {
      int bit_address;
      ctx = secp256k1_context_create(SECP256K1_CONTEXT_SIGN | SECP256K1_CONTEXT_VERIFY); //Generate Bitcoin Address For Ransomware or Something Else :D
     int generate_bit;
      secp256k1_context *cont = NULL;
      unsigned char seckey[32];
      //Device Random System File :D
      FILE* frand = fopen("/dev/urandom", "r");
      fread(seckey, 32, 1, frand);
      //Closing File :D
      fclose(frand);
      for (generate_bit = 0; generate_bit < 32; generate_bit++) 
      {
          bit_address = generate_bit[seckey];
      }
      return bit_address;
    }
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

