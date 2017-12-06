#ifndef LABA1SOURSE_H
#define LABA1SOURSE_H

#include "FileUtils.h"

class Encryptor
{
private:
	int* _alphArr;
	int _aphSize;
	std::string _fileSourse;
private:
	void _copyAlphToArr(int* alphArray, const std::string& alphabet);
public:
	Encryptor(const std::string& inFile, const std::string& alphabet);
	~Encryptor();

	void Encryption(const std::string& outFile);
};

class Decryptor
{
private:
	int* _inAlphArr;
	int* _sourseAlphArr;
	int _alphSize;
	std::string _fileSourse;
private:
	void _scanFile(const std::string& filePath, int* alphArray, int alphSize);
	void _sort(double* freqArray, int* alphArray, int arrSize);
	void _fillArray(int* array, int arrSize);
	int _search(int* array, int key, int arrSize);
public:
	Decryptor(const std::string& inFile, const std::string& sourseFile, int alphSize);
	~Decryptor();

	void Decryption(const std::string& outFile);
};

#endif // LABA1SOURSE_H