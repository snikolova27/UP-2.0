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

bool isLowercase(char ch)
{
    return ch >= 'a' && ch <= 'z';
}

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

bool isInputValid(const char *text)
{
    int len = strlen(text);
    for (int i = 0; i < len; i++)
    {
        if (!isLowercase(text[i]) || !isLetter(text[i]))
        {
            return false;
        }
    }
    return true;
}

int getCountOfDigits(int number, int counter)
{
    if (number == 0)
    {
        return counter;
    }

    ++counter;

    return getCountOfDigits(number / 10, counter);
}

char *rleEncode(const char *text)
{
    size_t size = strlen(text);
    size_t compressedSize = size;

    for (int i = 1; i < size; ++i)
    {
        if (text[i] == text[i - 1])
        {
            int counter = 2;
            while (text[i + counter - 1] == text[i])
            {
                ++counter;
            }
            if (counter >= 4)
            {
                int digits = getCountOfDigits(counter, 0);
                compressedSize = compressedSize - counter + 3 + digits;
            }
            i += (counter - 2);
        }
    }

    char *newText = new (std::nothrow) char[compressedSize + 1];
    int currentIndex = 0;

    for (int i = 1; i < size; ++i)
    {
        if (text[i] != text[i - 1])
        {
            newText[currentIndex] = text[i - 1];
            ++currentIndex;
        }
        else
        {
            int counter = 2;
            while (text[i + counter - 1] == text[i])
            {
                ++counter;
            }
            if (counter >= 4)
            {
                newText[currentIndex] = '(';
                int digits = getCountOfDigits(counter, 0);
                int tempCounter = counter;
                for (int i = digits; i >= 1; --i)
                {
                    newText[currentIndex + i] = '0' + (tempCounter % 10);
                    tempCounter /= 10;
                }
                //newText[currentIndex+1] = '0' + counter;
                newText[currentIndex + digits + 1] = text[i];

                newText[currentIndex + digits + 2] = ')';
                currentIndex += (3 + digits);
                i += (counter - 1);
            }
            else
            {
                newText[currentIndex] = text[i - 1];
                ++currentIndex;
            }
        }
    }
    newText[currentIndex] = '\0';

    return newText;
}
int main()
{
    char buffer[MAX_ARRAY_SIZE] = {};
    std::cout << "Enter string: ";
    std::cin >> buffer;

    if (!isInputValid(buffer))
    {
        std::cout << "Invalid input!" << std::endl;
        return -1;
    }
    char *result = rleEncode(buffer);
    if (!result)
    {
        return -1;
    }
    std::cout << result << std::endl;

    delete[] result;

    return 0;
}