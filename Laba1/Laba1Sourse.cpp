#include "Laba1Sourse.h"

void Encryptor::_copyAlphToArr(int* alphArray, const std::string& alphabet)
{
	for (int i = 0; i < alphabet.size(); ++i)
		alphArray[i] = unsigned char(alphabet[i] - 'À');
}

Encryptor::Encryptor(const std::string& inFile, const std::string& alphabet)
{
	_aphSize = alphabet.size();
	_alphArr = new int[_aphSize];
	_fileSourse = ReadFile(inFile);

	_copyAlphToArr(this->_alphArr, alphabet);
}

Encryptor::~Encryptor()
{
	delete[] this->_alphArr;
	_alphArr = nullptr;
}

void Encryptor::Encryption(const std::string& outFile)
{
	unsigned char current;
	std::string output;

	std::string sourse(this->_fileSourse);

	for (int i = 0; sourse[i] != '\0'; ++i)
	{
		current = sourse[i];

		if (isalpha(current) && (current >= (unsigned char)('À')))
		{
			int letter = current - (unsigned char)('À');

			if (letter >= _aphSize)
				letter %= _aphSize;

			output += (_alphArr[letter] + (unsigned char)('À'));
		}
		else
			output += sourse[i];
	}

	WriteFile(outFile, output);
}

void Decryptor::_scanFile(const std::string& filePath, int* alphArray, int alphSize)
{
	int numOfLetter(0);
	unsigned char current;
	double* freqArray = new double[alphSize];
	memset(freqArray, 0, alphSize * sizeof(double));

	std::string sourse = ReadFile(filePath);

	for (int i = 0; sourse[i] != '\0'; ++i)
	{
		current = sourse[i];

		if (isalpha(current) && (current >= (unsigned char)'À'))
		{
			int freq = current - (unsigned char)'À';

			if (freq >= alphSize)
				freq %= alphSize;

			numOfLetter++;
			freqArray[freq]++;
		}
	}

	for (int i = 0; i < alphSize; ++i)
		freqArray[i] /= numOfLetter;

	_sort(freqArray, alphArray, alphSize);

	delete[] freqArray;
	freqArray = nullptr;
}

void Decryptor::_sort(double* freqArray, int* alphArray, int arrSize)
{
	for (int i = 0; i < arrSize - 1; ++i)
		for (int j = 0; j < arrSize - i - 1; ++j)
		{
			if (freqArray[j] < freqArray[j + 1])
			{
				double tmpFreq = freqArray[j];
				freqArray[j] = freqArray[j + 1];
				freqArray[j + 1] = tmpFreq;

				int tmpAlp = alphArray[j];
				alphArray[j] = alphArray[j + 1];
				alphArray[j + 1] = tmpAlp;
			}
		}
}

void Decryptor::_fillArray(int* array, int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
		array[i] = i;
}

int Decryptor::_search(int* array, int key, int arrSize)
{
	for (int i = 0; i < arrSize; ++i)
		if (array[i] == key)
			return i;
}

Decryptor::Decryptor(const std::string& inFile, const std::string& sourseFile, int alphSize)
{
	_fileSourse = ReadFile(inFile);
	_alphSize = alphSize;

	_inAlphArr = new int[_alphSize];
	_sourseAlphArr = new int[_alphSize];

	_fillArray(_inAlphArr, alphSize);
	_fillArray(_sourseAlphArr, alphSize);

	_scanFile(inFile, _inAlphArr, alphSize);
	_scanFile(sourseFile, _sourseAlphArr, alphSize);
}

Decryptor::~Decryptor()
{
	delete[] this->_sourseAlphArr;
	delete[] this->_inAlphArr;

	_sourseAlphArr = nullptr;
	_inAlphArr = nullptr;
}

void Decryptor::Decryption(const std::string& outFile)
{
	unsigned char current;
	std::string output;

	for (int i = 0; _fileSourse[i] != '\0'; ++i)
	{
		current = _fileSourse[i];

		if (isalpha(current) && (current >= (unsigned char)'À'))
		{
			int letter = current - (unsigned char)'À';

			if (letter >= _alphSize)
				letter %= _alphSize;

			int posInSourArr = _search(_inAlphArr, letter, _alphSize);

			output += (_sourseAlphArr[posInSourArr] + (unsigned char)'À');
		}
		else
			output += _fileSourse[i];
	}

	WriteFile(outFile, output);
}