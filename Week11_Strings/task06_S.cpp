#include <iostream>

const int MAX_WORDS = 1000;
const int MAX_LETTERS_WORD = 60;

int strlen(const char str[])
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

bool strcomp(const char *str1, const char *str2)
{
    if (strlen(str1) != strlen(str2))
    {
        return false;
    }

    int len = strlen(str1);
    for (int i = 0; i < len; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }

    return true;
}

void strcopy(const char *src, char *dest)
{
    int len = strlen(src);
    for (int i = 0; i < len; i++)
    {
        dest[i] = src[i];
    }
    dest[len] = '\0';
}

int input(char string[][MAX_LETTERS_WORD])
{
    int cnt = 0;
    while (true)
    {
        std::cin >> string[cnt];
        if (strlen(string[cnt]) == 2 && string[cnt][0] == '#' && string[cnt][1] == '#')
        {
            break;
        }
        cnt++;
    }
    return cnt;
}

int cntDistinct(const char str[][MAX_LETTERS_WORD], int cntWords)
{
    int cnt = 0;

    for (int i = 0; i < cntWords; i++)
    {
        bool distinct = false;
        int distinctCnt = 1;

        for (int j = i + 1; j < cntWords; j++)
        {
            if (strcomp(str[i], str[j]))
            {
                distinctCnt++;
            }
        }
        if (distinctCnt == 1)
        {
            distinct = true;
        }
        if (distinct)
        {
            cnt++;
        }
    }

    return cnt;
}
char **distinctWords(const char str[][MAX_LETTERS_WORD], int cntWords)
{
    int cnt = 0;
    char **words = new (std::nothrow) char *[MAX_WORDS];
    if (!words)
    {
        std::cout << "Memory allocation problem! " << std::endl;
    }

    else
    {
        for (int i = 0; i < MAX_WORDS; i++)
        {
            words[i] = new (std::nothrow) char[MAX_LETTERS_WORD];
            if (!words[i])
            {
                std::cout << "Memory allocation problem! " << std::endl;
                delete[] words;
            }
        }

        // for (int i = 0; i < cntWords; i++)
        // {
        //     if (!strcomp(str[i], str[i + 1]))
        //     {
        //         strcopy(str[i], words[cnt]);
        //         cnt++;
        //     }
        // }

        for (int i = 0; i < cntWords; i++)
        {
            bool distinct = false;
            int distinctCnt = 1;

            for (int j = i + 1; j < cntWords; j++)
            {
                if (strcomp(str[i], str[j]))
                {
                    distinctCnt++;
                }
            }
            if (distinctCnt == 1)
            {
                distinct = true;
            }
            if (distinct)
            {

                strcopy(str[i], words[cnt]);
                cnt++;
            }
        }
    }

    return words;
}

int main()
{
    char string[MAX_WORDS][MAX_LETTERS_WORD] = {};
    int cntWords = input(string);

    char **words = distinctWords(string, cntWords);

    int distinct = cntDistinct(string, cntWords);

    std::cout << distinct << " distinct words in string" << std::endl;

    for (int i = 0; i < distinct; i++)
    {

        std::cout << "Word №" << i + 1 << " " << words[i] << std::endl;
    }

    for (int i = 0; i < cntWords; i++)
    {
        delete[] words[i];
    }
    delete[] words;

    return 0;
}