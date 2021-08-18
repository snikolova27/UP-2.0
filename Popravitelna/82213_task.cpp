//
// СУ "Св. Климент Охридски"
// Факултет по математика и информатика
// Курс Увод в Програмирането 2020/21
// Поправителен изпит - първа част
// 2021-08-16
//
// Име: Соня Николова Николова
// ФН:  82213
// Специалност: Компютърни науки
// Курс: 1
// Административна група: 4
// Използван компилатор:    GCC
//

#include <iostream>
#include <new>

const int MAX_STRING_LEN = 1000000;

bool isLetter(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

bool isSymbol(char ch)
{
    return ch == '!' || ch == '?' || ch == '.' || ch == ' ' || ch == ',' || ch == ';';
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

char *allocateString(int len)
{
    char *result = new (std::nothrow) char[len];
    if (!result)
    {
        std::cout << "Problem allocating memory for string" << std::endl;
        return nullptr;
    }
    return result;
}

int *allocateArray(int size)
{
    int *result = new (std::nothrow) int[len];
    if (!result)
    {
        std::cout << "Problem allocating memory for array of ints" << std::endl;
        return nullptr;
    }
    return result;
}
int *symbolsIdx(char *str, int len, int &cntSymbols) //save the indexes of symbols so we can check for validity later
{
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (isSymbol(str[i]))
        {
            cnt++;
        }
    }
    cntSymbols = cnt;
    if (cnt > 0)
    {
        int result = allocateArray(cnt);
        if (!result)
        {
            return nullptr;
        }

        int idx = 0;
        for (int i = 0; i < len; i++)
        {
            if (isSymbol(str[i]))
            {
                result[idx] = i;
                idx++;
            }
        }
    }
    else
    {
        return nullptr;
    }

    return result;
}

bool symbolsValidation(char *str, int len, int *symbolsIdx, int cntSymbols)
{
    for (int i = 0; i < cntSymbols; i++)
    {
        if (!isLetter(str[symbolsIdx[i] - 1]) || !isLetter(str[symbolsIdx[i] + 1])) //check if there is a letter on both sides of a symbol
        {
            return false;
        }
    }

    return true;
}

int cntLetters(char *str, int len)
{
    int cnt = 0;
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (isLetter(str[i]))
        {
            cnt++;
        }
    }
    return cnt;
}

bool isLastLetterValid(char *str, int len) //check if the last letter is followed by . or ? or !
{
    int lastLetteridx = 0;
    for (int i = 0; i < len; i++)
    {
        if (isLetter(str[i]))
        {
            lastLetteridx = i;
        }
    }

    if (lastLetteridx < len)
    {
        if (str[lastLetteridx + 1] != '.' || str[lastLetteridx + 1] != '?' || str[lastLetteridx] != '!')
        {
            return false;
        }
    }

    return true;
}

bool isInputValid(char *str, int len)
{
    if (len < 0)
    {
        return false;
    }
    for (int i = 0; i < len; i++)
    {
        if (!isLetter(str[i]) && !isSymbol(str[i]))
        {
            return false;
        }

        int cntSymbols = 0;
        int *symbols = symbolsIdx(str, len, cntSymbols);
        if (symbols && !symbolsValidation(str, len, symbols, cntSymbols) && cntSymbols >= 1)
        {
            return false;
        }

        int cntLetter = cntLetters(str, len);
        if (cntLetter >= 1 && !isLastLetterValid(str, len))
        {
            return false;
        }
    }

    return true;
}
void clearString(char *str)
{
    delete[] str;
}

void clearArray(int *array)
{
    delete[] array;
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
void removeExtraIntervals(char *str, int len, int *symbolsIdx, int cntSym)
{
    for (int i = 0; i < cntSym; i++)
    {
        if (str[symbolsIdx[i]] == ' ')
        {
            if (str[symbolsIdx])
        }
    }
}

void toUpper(char &ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        ch += 'A' - 'a';
    }
}
void capitalizeFirstLetter(char *str)
{
    if (isLetter(str[0]))
    {
        toUpper(str[0]);
    }
}

void afterSymbols(char* str, int len)
{
    
}
char *normalizeString(const char *originalString, int len)
{
    char *result = allocateString(len + 1);
    if (!result)
    {
        return nullptr;
    }

    strcopy(originalString, result);
    removeExtraIntervals(result, len + 1);
    capitalizeFirstLetter(result);

    return result;
}

int main(char **argv, char argc)
{
    if (argc != 1)
    {
        std::cout << "Program only accepts one parameter" << std::endl;
    }
    char buffer[MAX_STRING_LEN] = {};

    return 0;
}