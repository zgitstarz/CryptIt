#ifndef KEYS
#define KEYS
#endif

#include <QString>

struct rsa_keys{
    std::string priv;
    std::string pub;
};





void get_rsa_keys(rsa_keys*, int);
void get_aes_key(std::string& key_holder, int size, int encoding);
