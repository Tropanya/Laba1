#include "Laba1Sourse.h"

int main()
{
	setlocale(LC_CTYPE, "rus");

	Encryptor encr("TextForEncr.txt", "��������������������������������");
	encr.Encryption("TextForEncr.txt");

	Decryptor decr("out_TextForEncr.txt", "TextForIP.txt", 32);
	decr.Decryption("TextForDecr.txt");

	return 0;
}