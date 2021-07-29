#include <iostream>

void mostEncountered(char *array, int size)
{
    char res = array[0];
    int cntMax = 1;

    for (int i = 0; i < size; i++)
    {
        res = array[i];

        int cnt = 1;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] == res)
            {
                cnt++;
            }
        }

        if (cnt > cntMax)
        {
            res = array[i];
            cntMax = cnt;
        }
    }

    std::cout << "Most encountered: " << res << " " << cntMax << " times" << std::endl;
}

void print(char *array, int size)
{
    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << array[i];
    }

    std::cout << std::endl;
}

int main()
{
    int lenght;
    char *word;
    std::cout << "Enter lenght of word: ";
    std::cin >> lenght;

    if (lenght && lenght < 1000)
    {
        word = new (std::nothrow) char[lenght];
        if (!word)
        {
            std::cout << "Memory allocation problem" << std::endl;
        }
        
        else
        {
            char ch;
            int cnt = 0;
            std::cin >> ch;

            while (ch >= 'a' && ch <= 'z' && cnt < lenght)
            {
                word[cnt] = ch;
                std::cin >> ch;
                cnt++;
            }
            word[lenght] = '\0';

            print(word, lenght);
            mostEncountered(word, lenght);
        }
        delete[] word;
    }

    else
    {
        std::cout << "Lenght should be in the interval [1,1000]" << std::endl;
    }

    return 0;
}