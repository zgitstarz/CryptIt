#include <QString>
#include "keys.h"

#include <cryptopp/aes.h>
#include <cryptopp/base64.h>
#include <cryptopp/hex.h>
#include <filter.h>
#include <cryptopp/secblock.h>
#include <cryptopp/osrng.h>


void get_aes_key(std::string& key_holder, int size, int encoding)
{
    CryptoPP::StringSink kh(key_holder);

    CryptoPP::SecByteBlock key((unsigned int)size);

    CryptoPP::AutoSeededRandomPool prng;

    prng.GenerateBlock(key, size);

    if(encoding == 0)
    {
        CryptoPP::StringSource(key, size, true, new CryptoPP::Base64Encoder(&kh));
    }
    else if(encoding == 1)
    {
        CryptoPP::StringSource(key, size, true, new CryptoPP::HexEncoder(&kh));
    }

}
