#include <iostream>

const int MAX_WORD_LEN = 100;
const int MAX_WORDS = 1000;
const char *TERMINATING_WORD = "stop";

bool isLetter(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}
bool containsOnlyLetters(const char *str)
{
    int pos = 0;
    while (str[pos])
    {
        if (!isLetter(str[pos]))
        {
            return false;
        }
        pos++;
    }
    return true;
}

bool isLowerCase(char ch)
{
    return ch >= 'a' && ch <= 'z';
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

void strcopy(const char *src, char *dest)
{
    while (*src)
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest = '\0';
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

bool isTerminatingWord(const char *str)
{
    int lenstr = strlen(str) + 1;
    int lenterminating = strlen(TERMINATING_WORD) + 1;
    if (lenstr != lenterminating)
    {
        return false;
    }
    for (int i = 0; i < lenstr; i++)
    {
        if (str[i] != TERMINATING_WORD[i])
        {
            return false;
        }
    }

    return true;
}
char **read(int &cntWords)
{
    char **result = new (std::nothrow) char *[MAX_WORDS];
    if (!result)
    {
        return nullptr;
    }

    int cnt = 0;
    char buffer[MAX_WORD_LEN];
    do
    {
        std::cin >> buffer;
        if (containsOnlyLetters(buffer))
        {
            if (!isTerminatingWord(buffer))
            {
                int len = strlen(buffer) + 1;
                result[cnt] = new (std::nothrow) char[len];
                if (!result[cnt])
                {
                    return nullptr;
                }
                strcopy(buffer, result[cnt]);
                cnt++;
            }
        }
    } while (!isTerminatingWord(buffer));
    cntWords = cnt;
    return result;
}

void clear(char **str, int size)
{
    for (int i = 0; i < size; i++)
    {
        delete[] str[i];
    }
    delete[] str;
}

void print(char **str, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << "Word #" << i + 1 << " " << str[i] << std::endl;
    }
}

int findOrder(char **words, int cnt, int *order)
{

    int cnt1s = 0;
    int cnt0s = 0;
    for (int i = 0; i < cnt - 1; i++)
    {

        for (int j = i + 1; j < cnt; j++)
        {

            if (strcomp(words[i], words[j]) < 0) //ascending ->mark with a zero
            {
                cnt1s++;
                i++;
                j++;
            }
            else if (strcomp(words[i], words[j]) > 0) //descending ->mark with a 1
            {
                cnt0s++;
                i++;
                j++;
            }
        }
    }

    if (cnt0s == cnt) //ascending
    {
        return 1;
    }
    if (cnt1s == cnt) //descending
    {
        return 2;
    }
    return 3; //no order
}

int minFrom(char **words, int from, int to)
{
    int min = from;
    for (int i = from + 1; i < to; i++)
    {
        if (strcomp(words[min], words[i]) > 0)
        {
            min = i;
        }
    }

    return min;
}

void selectionSort(char **words, int cnt)
{
    int minIdx = 0;
    for (int i = 0; i < cnt - 1; i++)
    {
        minIdx = minFrom(words, i, cnt);
        if (minIdx != i)
        {
            char buff[MAX_WORD_LEN];
            strcopy(words[i], buff);
            strcopy(words[minIdx], words[i]);
            strcopy(buff, words[minIdx]);
        }
    }
}

void cntLetters(char *word, int &cntCapitals, int &cntLower)
{
    int len = strlen(word) + 1;
    for (int i = 0; i < len; i++)
    {
        if (isLowerCase(word[i]))
        {
            cntLower++;
        }
        else
        {
            cntCapitals++;
        }
    }
}

int cntMoreCapitals(char **words, int cnt)
{
    int res = 0;
    for (int i = 0; i < cnt; i++)
    {
        int cntCapitals = 0;
        int cntLower = 0;
        cntLetters(words[i], cntCapitals, cntLower);
        if (cntCapitals > cntLower)
        {
            res++;
        }
    }

    return res;
}
int main()
{
    int cntWords = 0;
    char **words = read(cntWords);
    if (!words)
    {
        return -1;
    }
    // int order = findOrder(words, cntWords, orderWords);
    // std::cout << order << std::endl;
    // int *orderWords = new (std::nothrow) int[cntWords];
    // if (!orderWords)
    // {
    //     return -1;
    // }

    selectionSort(words, cntWords);
    std::cout << "Lenght of smallest word: " << strlen(words[0]) << std::endl;
    std::cout << "More capitals than lowercase count: " << cntMoreCapitals(words, cntWords) << std::endl;
    print(words, cntWords);
    clear(words, cntWords);

    return 0;
}