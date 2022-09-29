#include <fstream>
#include <iostream>
#include <string>
#include "AES.h"

int wordLength;
std::string originalText;
std::string symmetricKey;
std::string encrytedText;

char GetRandomChar()
{
	return 'a' + (rand() % 26);
}

std::string GenerateSymmetricKey(int length)
{
    std::string key = "";
	srand((unsigned int)time(0));
	for (int i = 0; i < length; i++) key += GetRandomChar();
    return key;
}

void LoadTextFile()
{
	std::ifstream file("File.txt");
	if(file.is_open())
    {
        while(!file.eof()) getline(file, originalText);
        wordLength = originalText.length();
        file.close();
	}
}

void SaveEncryptedTextFile()
{
    std::ofstream file("EncryptedFile.txt");
    if(file.is_open())
    {
        file << encrytedText;
        file.close();
    }
}

void SaveSymmetricKey()
{
    std::ofstream file("SymmetricKey.txt");
    if(file.is_open())
    {
        file << symmetricKey;
        file.close();
    }    
}

int main()
{
    // 데이터 불러오기 및 문자열 개수 추출
    LoadTextFile();
    std::cout << "Original Text : ";
    std::cout << originalText << std::endl;

    // 대칭키 생성 (문자열 개수 만큼 대칭키의 길이가 결정된다.)
    symmetricKey = GenerateSymmetricKey(wordLength);
    std::cout << "Generated Key : ";
    std::cout << symmetricKey << std::endl;

    // 데이터 암호화 + Base64 인코딩
    encrytedText = Encrypt(originalText, symmetricKey);
    std::cout << encrytedText << std::endl;

    // 대칭키 저장 (KSS에 대칭키 보내기)
    SaveSymmetricKey();

    // 암호화된 데이터 저장 (DSS에 암호화된 데이터 보내기)
    SaveEncryptedTextFile();
    
    return 0;
}