#include <iostream>

const int MAX_ARRAY_SIZE = 1000;
const int ALPHABET = 26;

int strlen(const char *str)
{
    int len = 0;
    while (str[len])
    {
        len++;
    }
    return len;
}

void strcopy(const char *src, char *dest)
{
    int pos = 0;
    while (src[pos])
    {
        dest[pos] = src[pos];
        pos++;
    }
    dest[pos] = '\0';
}

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isLowerCase(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

void crypt(char *string, int len)
{

    char smallLettersEncrypted[ALPHABET] = {};
    char capitalLetterEncrypted[ALPHABET] = {};

    for (int i = 0; i < ALPHABET; i++)
    {
        smallLettersEncrypted[i] = 'z' - i;
        capitalLetterEncrypted[i] = 'Z' - i;
    }

    for (int i = 0; i < len; i++)
    {
        if (isLetter(string[i]))
        {
            if (isLowerCase(string[i]))
            {
                string[i] = smallLettersEncrypted[(int)string[i] - 'a'];
            }
            else
            {
                string[i] = capitalLetterEncrypted[(int)string[i] - 'A'];
            }
        }
    }
}

int main()
{
    char buffer[MAX_ARRAY_SIZE] = {};
    std::cout << "enter string: ";
    std::cin >> buffer;

    int len = strlen(buffer) + 1;

    char *string = new (std::nothrow) char[len];
    if (!string)
    {
        std::cout << "Memory allocation problem" << std::endl;
        return -1;
    }

    else
    {
        strcopy(buffer, string);
        crypt(string, len);
        std::cout << string << std::endl;

        delete[] string;
    }
    return 0;
}