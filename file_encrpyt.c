#include <stdio.h>
#include <string.h>
#include "header.h"

void file_encryption(char key[])
{
    FILE *f1 = fopen("plaintext.txt", "r");

    if (f1 == NULL)
        printf("error in opening the file");

    else
    {
        char ch;
        int keyLen = strlen(key), i, j;

        int ciphertext_len = 0;
        for (int i = 0; (ch = fgetc(f1)) != EOF; i++)
        {
            if (((ch >= 'A') && (ch <= 'Z')) || (ch==' '))
                ciphertext_len++;
        }
        //printf("cipher text length: %d\n", ciphertext_len);

        char newKey[ciphertext_len];

        //generating new key
        for (i = 0, j = 0; i < ciphertext_len; ++i, ++j)
        {
            if (j == keyLen)
                j = 0;

            newKey[i] = key[j];
        }
        newKey[i] = '\0';
        printf("\nNew Generated Key: %s\n", newKey);

        char encryptedmsg[ciphertext_len];
        char text[ciphertext_len];
        fseek(f1, 0, SEEK_SET);
        fscanf(f1, "%[^\n]", text);
        //converting text to cipher text using vigenere cipher algorithm
        for(i = 0; i < ciphertext_len; ++i)
            encryptedmsg[i] = ((text[i] + newKey[i]) % 26) + 'A';
        encryptedmsg[i] = '\0'; //denote the end of the string
        printf("Encrypted Message: %s",encryptedmsg);
    }
    fclose(f1);
}
