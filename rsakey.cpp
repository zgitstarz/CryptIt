// Sample.cpp
#include "cryptopp/pem.h"

#include "cryptopp/rsa.h"

#include "cryptopp/sha.h"

#include "cryptopp/filters.h"


#include "cryptopp/files.h"


#include "cryptopp/osrng.h"

#include "cryptopp/secblock.h"


#include "cryptopp/cryptlib.h"

#include <iostream>

#include "keys.h"



void get_rsa_keys(rsa_keys* keys, int size)
{
    keys->priv.clear();
    keys->pub.clear();


    // Generate keys
    CryptoPP::AutoSeededRandomPool rng;

    CryptoPP::InvertibleRSAFunction parameters;
    parameters.GenerateRandomWithKeySize(rng, size);

    CryptoPP::RSA::PrivateKey privateKey(parameters);
    CryptoPP::RSA::PublicKey publicKey(parameters);

    CryptoPP::StringSink pub_key(keys->pub);

    CryptoPP::PEM_Save(pub_key, publicKey);

    CryptoPP::StringSink priv_key(keys->priv);

    CryptoPP::PEM_Save(priv_key, privateKey);


}

