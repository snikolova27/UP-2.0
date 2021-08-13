#include <iostream>

const int MAX_STR_LEN = 1024 * 1024;
const int MAX_WORD_CNT = 1024;
const int MAX_WORD_LEN = 64;

bool isLetter(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || ch == '-';
}

int strlen(const char *str)
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch += 'a' - 'A';
    }
    return ch;
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
int strcomp(const char *str1, const char *str2)
{
    while (*str1 && *str1 == *str2)
    {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

bool areEqual(const char *str1, const char *str2)
{
    int len1 = strlen(str1) + 1;
    int len2 = strlen(str2) + 1;
    if (len1 != len2)
    {
        return false;
    }
    for (int i = 0; i < len1; i++)
    {
        if (str1[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}
int countWords(const char *string, char words[][MAX_WORD_LEN])
{
    int cnt = 0;
    while (*string)
    {
        while (*string && !isLetter(*string))
        {
            string++;
        }
        if (*string)
        {
            cnt++;
        }
        const char *start = string;
        while (isLetter(*string))
        {
            string++;
        }
        int len = string - start;

        for (int i = 0; i < len; i++)
        {
            words[cnt - 1][i] = toLower(*start);
            start++;
        }
    }
    return cnt;
}

int min(char distinct[][MAX_WORD_LEN], int from, int to, int cntIdx[])
{
    int pos = from;
    for (int j = from + 1; j < to; j++)
    {
        if ((cntIdx[j] > cntIdx[pos]))
        {
            pos = j;
        }
        else if (cntIdx[pos] == cntIdx[j] && strcomp(distinct[j], distinct[pos]) < 0)
        {
            pos = j;
        }
    }
    return pos;
}

void selectionSort(char distinct[][MAX_WORD_LEN], int cnt, int cntIdx[])
{
    for (int i = 0; i < cnt - 1; i++)
    {
        int minIdx = min(distinct, i, cnt, cntIdx);
        if (minIdx != i)
        {
            char buff[MAX_WORD_LEN] = {};
            strcopy(distinct[i], buff);
            strcopy(distinct[minIdx], distinct[i]);
            strcopy(buff, distinct[minIdx]);
            int temp = cntIdx[i];
            cntIdx[i] = cntIdx[minIdx];
            cntIdx[minIdx] = temp;
        }
    }
}

int cntDistinctWords(const char words[][MAX_WORD_LEN], int cntAll, int cntIdx[], char distinct[][MAX_WORD_LEN])
{
    int cnt = 0;

    for (int i = 0; i < cntAll; i++)
    {
        bool found = false;

        for (int j = i + 1; j < cntAll; j++)
        {
            if (areEqual(words[i], words[j]))
            {
                found = true;
            }
        }
        if (!found)
        {
            strcopy(words[i], distinct[cnt]);
            ++cnt;
        }
    }

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 0; j < cntAll; j++)
        {
            if (areEqual(distinct[i], words[j]))
            {
                ++cntIdx[i];
            }
        }
    }
    selectionSort(distinct, cnt, cntIdx);
    
    return cnt;
}
int main()
{
    char buffer[MAX_STR_LEN] = {};
    char words[MAX_WORD_CNT][MAX_WORD_LEN] = {};
    int countIndex[MAX_WORD_CNT] = {};
    char distinct[MAX_WORD_CNT][MAX_WORD_LEN] = {};

    std::cout << "Enter string:";
    std::cin.getline(buffer, MAX_STR_LEN, '#');

    int cntWords = countWords(buffer, words);
    std::cout << "All words: " << cntWords << std::endl;

    int distinctCount = cntDistinctWords(words, cntWords, countIndex, distinct);
    std::cout << "Distinct words: " << distinctCount << std::endl;

    for (int i = 0; i < distinctCount; i++)
    {
        std::cout << distinct[i] << " - " << countIndex[i] << std::endl;
    }

    return 0;
}