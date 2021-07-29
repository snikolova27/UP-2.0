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
    int len = strlen(src) + 1;
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
        if (string[cnt][0] == '#' && strlen(string[cnt]) == 1)
        {
            break;
        }
        cnt++;
    }
    return cnt;
}

int find(const char str[][MAX_LETTERS_WORD], const char word[], int cntWords)
{
    for (int i = 0; i < cntWords; i++)
    {
        if (strcomp(str[i], word))
        {
            return i;
            break;
        }
    }

    return -1;
}

int removeAt(char str[][MAX_LETTERS_WORD], int cntWords, int pos, const char *toRemove) //return cnt oc words left in string after removaL
{
    int cnt = cntWords;
    for (int i = pos; i < cntWords; i++)
    {
        strcopy(str[i + 1], str[i]);
    }
    cnt--;

    return cnt;
}

int main()
{
    char string[MAX_WORDS][MAX_LETTERS_WORD] = {};
    std::cout << "Enter string: ";
    int cntWords = input(string);

    char toRemove[MAX_LETTERS_WORD] = {};
    std::cout << "Enter word to remove from string: ";
    std::cin >> toRemove;

    if (find(string, toRemove, cntWords) >= 0)
    {
        int pos = find(string, toRemove, cntWords);
        int cnt = removeAt(string, cntWords, pos, toRemove);

        for (int i = 0; i < cnt; i++)
        {
            if (find(string, toRemove, cntWords) >= 0)
            {
                pos = find(string, toRemove, cntWords);
                cnt = removeAt(string, cnt, pos, toRemove);
            }
        }
        for (int i = 0; i < cnt; i++)
        {
            std::cout << string[i] << " ";
        }
    }
    return 0;
}