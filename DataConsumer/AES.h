#include "Base64.h"
#include "Vigenere.h"

std::string Decrypt(std::string& encrypted_msg, std::string& key) {
	std::string newKey = extend_key(encrypted_msg, key);
	std::string b64_encoded_str = decrypt_vigenere(encrypted_msg, newKey);
	std::string b64_decode_str = Base64Decode(b64_encoded_str);
	return b64_decode_str;
}