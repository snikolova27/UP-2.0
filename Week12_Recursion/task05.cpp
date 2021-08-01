#include <iostream>

const int MAX_WORD_LEN = 1000;

int strlen(const char *str, int len)
{
    if (!str[len])
    {
        return len;
    }
    return strlen(str, len + 1);
}

bool isPalindrome(char *str, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    if (str[start] != str[end])
    {
        return false;
    }
    else
    {
        return isPalindrome(str, start + 1, end - 1);
    }
}

int main()
{
    char word[MAX_WORD_LEN] = {};
    std::cout << "Enter word: ";
    std::cin >> word;

    int len = strlen(word, 0);
    std::cout << "Is word palindrome: " << std::boolalpha << isPalindrome(word, 0, len - 1) << std::endl;
    return 0;
}