#include <iostream>

const int MAX_CRYPTED_WORD_LEN = 10;
const int MAX_LINE_LEN = 1000;

//Helper functions
void clear(char **str, int len)
{
    for (int i = 0; i < len; i++)
    {
        delete[] str[i];
    }
    delete[] str;
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

bool strcomp(const char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

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

void strcopy(const char *src, char *dest)
{
    int idx = 0;
    while (src[idx])
    {
        dest[idx] = src[idx];
        idx++;
    }

    dest[idx] = '\0';
}

char *strconcat(char *str1, const char *str2)
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int newLen = len1 + len2 + 1;

    char *res = new (std::nothrow) char[newLen];
    if (!res)
    {
        std::cout << "Memory problem while allocating memory for the concatenated string" << std::endl;
        return nullptr;
    }

    for (int i = 0; i < len1; i++)
    {
        res[i] = str1[i];
    }

    for (int k = 0; k < len2; k++)
    {
        res[len1] = str2[k];
        len1++;
    }
    res[newLen - 1] = '\0';

    return res;
}

bool isLetter(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

char toLower(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
    {
        ch += 'a' - 'A';
    }
    return ch;
}

char *toLowerString(char *string, int len)
{
    char *result = new (std::nothrow) char[len + 1];
    if (!result)
    {
        std::cout << "Memory problem" << std::endl;
        return nullptr;
    }
    for (int i = 0; i < len; i++)
    {
        result[i] = toLower(string[i]);
    }
    result[len] = '\0';

    return result;
}

bool containsOnlyLetters(const char *string, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (!isLetter(string[i]))
        {
            return false;
        }
    }

    return true;
}

bool readDictionary(int size, char *&letters, char **&cryptedWords)
{
    //Allocating memory for the letters of the dictionary
    letters = new (std::nothrow) char[size];
    if (!letters)
    {
        std::cout << "Memory problem while allocating memory for letters" << std::endl;
        return false;
    }

    //Allocating memory for the crypted words of the dictionary
    cryptedWords = new (std::nothrow) char *[size];
    if (!cryptedWords)
    {
        std::cout << "Memory problem while allocating memory for crypted words" << std::endl;
        return false;
    }

    //Reading the dictionary
    char letter;
    char bufferCrypted[MAX_CRYPTED_WORD_LEN] = {};

    int cnt = 0;

    do
    {
        std::cout << "Enter normal letter and corresponding crypted word #" << cnt + 1 << ": ";
        std::cin >> letter;
        std::cin >> bufferCrypted;

        if (!isLetter(letter))
        {
            do
            {
                std::cout << "Not a letter. Try again." << std::endl;
                std::cout << "Letter: ";
                std::cin >> letter;
            } while (!isLetter(letter));
        }

        letters[cnt] = letter;

        int lenCrypt = strlen(bufferCrypted);
        if (!containsOnlyLetters(bufferCrypted, lenCrypt))
        {
            do
            {
                std::cout << "Crypted word should contain only letters. Try again." << std::endl;
                std::cout << "Crypted word: ";
                std::cin >> bufferCrypted;
                lenCrypt = strlen(bufferCrypted);
            } while (!containsOnlyLetters(bufferCrypted, lenCrypt));
        }

        cryptedWords[cnt] = new (std::nothrow) char[lenCrypt + 1];
        if (!cryptedWords[cnt])
        {
            return false;
        }
        strcopy(bufferCrypted, cryptedWords[cnt]);

        cnt++;

    } while (cnt < size);

    return true;
}

void clearDictionary(char *letters, char **cryptedWords, int size)
{
    delete[] letters;

    for (int i = 0; i < size; i++)
    {
        delete[] cryptedWords[i];
    }
    delete[] cryptedWords;
}

void printDic(char *letters, char **cryptedWords, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << letters[i] << " " << cryptedWords[i] << std::endl;
    }
}

int findLetterInDict(char toFind, char *letters, int size) //returns index of correspondindg crypted word
{
    for (int i = 0; i < size; i++)
    {
        if (toLower(toFind) == letters[i])
        {
            return i;
        }
    }
    return -1;
}

int findWordInDict(char *toFind, char **cryptedWords, int size) //returns index of corresponding letter
{
    int len = strlen(toFind);
    for (int i = 0; i < size; i++)
    {

        if (strcomp(toLowerString(toFind, len), cryptedWords[i]))
        {
            return i;
        }
    }

    return -1;
}

int cntWords(const char *str, int len)
{
    int cnt = 1;
    for (int i = 0; i < len; i++)
    {
        if ((str[i] == ' ' || str[i] == '\t') && str[i + 1] != ' ' && str[i + 2] != ' ' && str[i + 1] != '\t' && str[i + 2] != '\t')
        {
            cnt++;
        }
    }

    return cnt;
}

char **readSentence(int cnt, int &words)
{
    char **string;
    char buffer[MAX_LINE_LEN] = {};
    if (cnt == 0)
    {
        std::cin.ignore();
    }

    std::cin.getline(buffer, MAX_LINE_LEN);
    int len = strlen(buffer) + 1;

    words = cntWords(buffer, len);

    string = new (std::nothrow) char *[words];

    if (!string)
    {
        std::cout << "Memory problem while allocating string" << std::endl;
        return nullptr;
    }

    int startIdx = 0;
    int endIdx = 0;
    int cntSpaces = 0;
    for (int i = 0; i < words; i++)
    {
        // last word
        if (cntSpaces == words - 1)
        {
            int lenght = len - startIdx + 1;
            char *temp = new (std::nothrow) char[lenght];
            if (!temp)
            {
                return nullptr;
            }

            for (int k = startIdx, t = 0; k < len, t < lenght; k++, t++)
            {
                temp[t] = buffer[k];
            }
            temp[lenght - 1] = '\0';

            string[i] = nullptr;
            int len = strlen(temp) + 1;
            string[i] = new (std::nothrow) char[len];
            if (!string[i])
            {
                std::cout << "Memory problem while allocating string" << std::endl;
                return nullptr;
            }
            strcopy(temp, string[i]);
            //std::cout << "Word #" << i + 1 << " " << string[i] << std::endl;
            delete[] temp;
            break;
        }

        for (int j = startIdx; j < len; j++)
        {
            // first word
            if (buffer[j] == ' ' && cntSpaces == 0)
            {
                // std::cout << "start idx:" << startIdx << std::endl;
                endIdx = j;
                // std::cout << "end idx: " << endIdx << std::endl;
                char *temp = new (std::nothrow) char[j + 1 - startIdx];
                if (!temp)
                {
                    return nullptr;
                }

                for (int k = startIdx, l = 0; k < j + 1 - startIdx; k++, l++)
                {
                    temp[l] = buffer[k];
                }
                temp[j - startIdx] = '\0';

                int len = strlen(temp) + 1;
                string[i] = new (std::nothrow) char[len];
                if (!string[i])
                {
                    std::cout << "Memory problem while allocating string" << std::endl;
                    return nullptr;
                }
                strcopy(temp, string[i]);
                // std::cout << "Word #" << i + 1 << " " << string[i] << std::endl;
                startIdx = endIdx + 1;
                // std::cout << " next start idx:" << startIdx << std::endl;
                cntSpaces++;
                delete[] temp;
                break;
            }

            else if (startIdx != 0)
            {
                //find next space
                //  std::cout << "current start idx: " << startIdx << std::endl;
                for (int h = startIdx; h < len; h++)
                {
                    if (buffer[h] == ' ')
                    {
                        endIdx = h;
                        //  std::cout << "next end idx: " << endIdx << std::endl;
                        break;
                    }
                }

                char *temp = new (std::nothrow) char[endIdx - startIdx + 1];
                if (!temp)
                {
                    return nullptr;
                }

                for (int k = startIdx, l = 0; l < endIdx - startIdx + 1, k < endIdx; k++, l++)
                {
                    temp[l] = buffer[k];
                }
                temp[endIdx - startIdx] = '\0';

                int len = strlen(temp) + 1;
                string[i] = new (std::nothrow) char[len];
                if (!string[i])
                {
                    std::cout << "Memory problem while allocating string" << std::endl;
                    return nullptr;
                }
                strcopy(temp, string[i]);

                // std::cout << "Word #" << i + 1 << " " << string[i] << std::endl;
                startIdx = endIdx + 1;
                cntSpaces++;
                delete[] temp;
                break;
            }
        }
    }

    return string;
}

void printSentence(char **sentence, int words)
{
    for (int i = 0; i < words; i++)
    {
        std::cout << sentence[i] << " ";
    }
    std::cout << std::endl;
}

char *getSubstring(char *string, int startingPos, int endingPos)
{
    if (startingPos < 0 || endingPos > strlen(string))
    {
        return nullptr;
    }

    int len = endingPos - startingPos + 1;
    char *result = new (std::nothrow) char[len];
    if (!result)
    {
        return nullptr;
    }
    for (int i = 0, j = startingPos; i < len, j < endingPos; i++, j++)
    {
        result[i] = string[j];
    }
    result[len - 1] = '\0';

    return result;
}

//Required functions
char **encrypt(char **toEncrypt, int cntWords, char *letters, char **cryptedWords, int sizeDict)
{
    char **result = new (std::nothrow) char *[cntWords];
    if (!result)
    {
        std::cout << "Memory allocation problem while allocating memory for result" << std::endl;
        return nullptr;
    }

    for (int i = 0; i < cntWords; i++)
    {
        int currentLen = strlen(toEncrypt[i]);

        //If the word consists only of 1 letter
        if (currentLen == 1)
        {
            int idx = findLetterInDict(toEncrypt[i][0], letters, sizeDict);

            //if there is no corresponing letter in the dictionary
            if (idx < 0)
            {
                result[i] = new (std::nothrow) char[2];
                if (!result[i])
                {
                    std::cout << "Memory allocation problem while allocating for crypting word" << std::endl;
                    return nullptr;
                }
                result[i][0] = toEncrypt[i][0];
                result[i][1] = '\0';
            }

            //There is a corresponding letter and we encrypt it
            else
            {
                int newLen = strlen(cryptedWords[idx]) + 1;

                result[i] = new (std::nothrow) char[newLen];
                if (!result[i])
                {
                    std::cout << "Memory allocation problem while allocating for crypting word" << std::endl;
                    return nullptr;
                }
                strcopy(cryptedWords[idx], result[i]);
            }

            //std::cout << result[i] << " Line 447 " << std::endl;
        }
        //The word consists of more than 1 letter
        else
        {
            for (int j = 0; j < currentLen; j++)
            {
                int idx = findLetterInDict(toEncrypt[i][j], letters, sizeDict);

                //If there is a corresponding letter
                if (idx >= 0)
                {
                    if (j == 0)
                    {

                        int newLen = strlen(cryptedWords[idx]) + 1;

                        result[i] = new (std::nothrow) char[newLen];
                        if (!result[i])
                        {
                            std::cout << "Memory allocation problem while allocating for crypting word" << std::endl;
                            return nullptr;
                        }
                        strcopy(cryptedWords[idx], result[i]);
                    }

                    else
                    {
                        int newLen = 1 + strlen(result[i]);
                        //  std::cout << "New len: " << newLen << std::endl;
                        char *temp1 = new (std::nothrow) char[newLen];
                        if (!temp1)
                        {
                            return nullptr;
                        }
                        strcopy(result[i], temp1);

                        char *temp = strconcat(temp1, cryptedWords[idx]);

                        newLen = strlen(temp);

                        result[i] = new (std::nothrow) char[newLen];
                        if (!result[i])
                        {
                            std::cout << "Memory allocation problem while allocating for crypting word" << std::endl;
                            return nullptr;
                        }
                        strcopy(temp, result[i]);

                        delete[] temp1;
                        delete[] temp;
                    }
                }
                else
                {
                    //if the current word in the result is still empty
                    if (result[i] == nullptr)
                    {
                        result[i] = new (std::nothrow) char[2];
                        if (!result[i])
                        {
                            std::cout << "Memory allocation problem while allocating for crypting word" << std::endl;
                            return nullptr;
                        }

                        result[i][0] = toEncrypt[i][j];
                        result[i][1] = '\0';
                    }
                    else
                    {

                        int newLen = 1 + strlen(result[i]);
                        char *temp1 = new (std::nothrow) char[newLen];
                        if (!temp1)
                        {
                            return nullptr;
                        }
                        strcopy(result[i], temp1);

                        result[i] = new (std::nothrow) char[newLen + 2];
                        if (!result[i])
                        {
                            std::cout << "Memory allocation problem while allocating for crypting word" << std::endl;
                            return nullptr;
                        }
                        //putting ## so the lenght increases and then we can change them into the symbol that we need
                        result[i] = {};
                        result[i] = strconcat(temp1, "##");

                        newLen = strlen(result[i]);
                        result[i][newLen - 2] = toEncrypt[i][j];
                        result[i][newLen - 1] = '\0';

                        delete[] temp1;
                    }
                }
            }
        }
    }

    return result;
}

char **decrypt(char **toDecrypt, int cntWords, char *letters, char **cryptedWords, int sizeDict)
{

    char **result = new (std::nothrow) char *[cntWords];
    if (!result)
    {
        std::cout << "Memory problem while allocating memory for the decrypted string" << std::endl;
        return nullptr;
    }
    for (int i = 0; i < cntWords; i++)
    {
        //len of current word for decryption
        int len = strlen(toDecrypt[i]);

        int startIdx = 0;
        int endIdx, idxInDict;
        int currentLen = 0;

        for (startIdx; startIdx < len; startIdx++)
        {
            bool subStrWithCurrentLetter = false;

            for (endIdx = startIdx + 1; endIdx <= len; endIdx++)
            {
                // std::cout << "Start idx: " << startIdx << std::endl;
                // std::cout << "end idx: " << endIdx << std::endl;

                char *current = getSubstring(toDecrypt[i], startIdx, endIdx);

                if (!current)
                {
                    return nullptr;
                }
                idxInDict = findWordInDict(current, cryptedWords, sizeDict);

                if (idxInDict >= 0)
                {

                    subStrWithCurrentLetter = true;

                    //if the current word in the result is still empty
                    if (result[i] == nullptr)
                    {
                        result[i] = new (std::nothrow) char[2];
                        if (!result[i])
                        {
                            return nullptr;
                        }
                        result[i][0] = letters[idxInDict];
                        result[i][1] = '\0';
                        currentLen++;
                    }

                    //if the current word in the result already has letters, keep them and add the new ones
                    else
                    {
                        char *temp1 = result[i];
                        result[i] = nullptr;
                        result[i] = new (std::nothrow) char[currentLen + 1];
                        if (!result[i])
                        {
                            return nullptr;
                        }
                        strcopy(temp1, result[i]);
                        result[i][currentLen] = letters[idxInDict];
                        result[i][currentLen + 1] = '\0';
                        currentLen++;

                        delete[] temp1;
                    }
                    startIdx += strlen(current) - 1;

                    break;
                }
            }
            //if no substring with the letter at startindIdx has been found in the dictionary
            if (!subStrWithCurrentLetter)
            {
                //if the current word in the result is still empty
                if (result[i] == nullptr)
                {
                    result[i] = new (std::nothrow) char[2];
                    if (!result[i])
                    {
                        return nullptr;
                    }
                    result[i][0] = toDecrypt[i][startIdx];
                    result[i][1] = '\0';
                    currentLen++;
                }

                //if the current word in the result already has letters, keep them and add the new ones
                else
                {
                    char *temp1 = result[i];
                    result[i] = nullptr;
                    result[i] = new (std::nothrow) char[currentLen + 1];
                    if (!result[i])
                    {
                        return nullptr;
                    }
                    strcopy(temp1, result[i]);
                    result[i][currentLen] = toDecrypt[i][startIdx];
                    result[i][currentLen + 1] = '\0';
                    currentLen++;

                    delete[] temp1;
                }
            }
        }
    }

    return result;
}

int main()
{
    char *letters;
    char **crypted;
    int n, size;
    do
    {
        std::cout << "Enter size of dictionary: ";
        std::cin >> n;

        if (n <= 0)
        {
            std::cout << "Size should be > 0. Try again." << std::endl;
            std::cout << "Size: ";
            std::cin >> n;
        }

    } while (n <= 0);

    size = n;

    bool isDictionaryValid = readDictionary(size, letters, crypted);

    do
    {
        if (!isDictionaryValid)
        {
            std::cout << "Invalid dictionary. Try again." << std::endl;
            clearDictionary(letters, crypted, size);
            isDictionaryValid = readDictionary(size, letters, crypted);
        }

    } while (!isDictionaryValid);

    std::cout << std::boolalpha << isDictionaryValid << std::endl;
    printDic(letters, crypted, size);

    int cntToCrypt, cntToDecrypt;

    do
    {
        std::cout << "Enter how many strings you'll enter for encryption: ";
        std::cin >> cntToCrypt;
        if (cntToCrypt <= 0)
        {
            std::cout << "Count of strings to crypt should be > 0. Try again." << std::endl;
            std::cout << "Count of strings to crypt: ";
            std::cin >> cntToCrypt;
        }
    } while (cntToCrypt <= 0);

    int cntEncrypt = 0;
    for (int i = 0; i < cntToCrypt; i++)
    {

        int words;
        std::cout << "Enter string #" << i + 1 << " to encrypt: ";
        char **string = readSentence(cntEncrypt, words);
        if (!string)
        {
            return -1;
        }

        std::cout << "You have entered: ";
        printSentence(string, words);

        char **res = encrypt(string, words, letters, crypted, size);
        if (!res)
        {
            return -1;
        }
        std::cout << "Encrypted sentence #" << i + 1 << ": ";
        printSentence(res, words);

        clear(string, words);
        clear(res, words);
        std::cin.clear();
        cntEncrypt++;
    }

    do
    {
        std::cout << "Enter how many strings you'll enter for decryption: ";
        std::cin >> cntToDecrypt;
        if (cntToDecrypt <= 0)
        {
            std::cout << "Count of strings to decrypt should be > 0. Try again." << std::endl;
            std::cout << "Count of strings to decrypt: ";
            std::cin >> cntToDecrypt;
        }
    } while (cntToDecrypt <= 0);

    int cntDecrypt = 0;
    for (int i = 0; i < cntToDecrypt; i++)
    {
        int words;
        std::cout << "Enter string #" << i + 1 << " to decrypt: ";
        char **string = readSentence(cntDecrypt, words);
        if (!string)
        {
            return -1;
        }
        std::cout << "You have entered: ";
        printSentence(string, words);

        char **res = decrypt(string, words, letters, crypted, size);
        if (!res)
        {
            return -1;
        }

        std::cout << "Decrypted string #" << i + 1 << ": ";
        printSentence(res, words);

        clear(string, words);
        clear(res, words);
        std::cin.clear();
        cntDecrypt++;
    }

    clearDictionary(letters, crypted, size);

    return 0;
}