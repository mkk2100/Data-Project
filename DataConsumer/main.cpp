#include <fstream>
#include <iostream>
#include <string>
#include "AES.h"

std::string symmetricKey;
std::string encrytedText;

std::string GetSymmetricKey()
{
    std::string key;
	std::ifstream file("SymmetricKey.txt");
	if(file.is_open())
    {
        while(!file.eof()) getline(file, key);
        file.close();
	}
    return key;
}

std::string GetEncryptedTextFile()
{
    std::string text;
	std::ifstream file("EncryptedFile.txt");
	if(file.is_open())
    {
        while(!file.eof()) getline(file, text);
        file.close();
	}
    return text;
}

int main()
{
    // 대칭키 가져오기
    symmetricKey = GetSymmetricKey();

    // 암호화된 데이터 가져오기
    encrytedText = GetEncryptedTextFile();

    // 데이터 복호화 + Base64 디코딩
 	std::string decrypted_msg = Decrypt(encrytedText, symmetricKey);

    // 데이터 읽기
 	std::cout << "decrypted message: " << decrypted_msg << std::endl;

    return 0;
}