#include "Base64.h"
#include "Vigenere.h"

std::string Encrypt(std::string& msg, std::string& key) 
{
	std::string b64_str = Base64Encode(msg);
	return encrypt_vigenere(b64_str, key);
}