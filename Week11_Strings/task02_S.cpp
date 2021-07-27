#include <iostream>

const int MAX_LEN = 1000;

int strlen(const char str[])
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

bool isWhiteSpace(char ch)
{
    return ch == ' ';
}

void removeWhiteSpace(char str[], int len)
{
    int pos = 0;
    for (int i = 0; i < len; i++)
    {
        if (isWhiteSpace(str[i]))
        {
            bool isFirstSymbolSpace = false;
            if (i == 0)
            {
                isFirstSymbolSpace = true;
            }

            while (isWhiteSpace(str[i + 1])) //skip white spaces
            {
                i++;
            }

            if (isFirstSymbolSpace)
            {
                i++;
            }
        }

        str[pos++] = str[i];
    }
    str[pos++] = '\0';
}
int main()
{
    char string[MAX_LEN] = {};
    std::cout << "Enter string: ";
    std::cin.getline(string, MAX_LEN);

    int len = strlen(string);

    removeWhiteSpace(string, len);
    std::cout << string << std::endl;

    return 0;
}