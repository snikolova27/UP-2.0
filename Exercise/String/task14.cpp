#include <iostream>

const int MAX_WORDS = 100;
const int MAX_LETTERS_IN_WORD = 50;

int strlen(char *str)
{
    int len = 0;
    while (str[len])
    {
        len++;
    }

    return len;
}

int input(char sentence[MAX_WORDS][MAX_LETTERS_IN_WORD])
{
    int cnt = 0;
    std::cin >> sentence[cnt];

    while (true)
    {

        if ((strlen(sentence[cnt]) == 1 && sentence[cnt][0] == '.'))
        {
            break;
        }
        if (sentence[cnt][strlen(sentence[cnt]) - 1] == '.')
        {
            cnt++;
            sentence[cnt][strlen(sentence[cnt]) - 1] = ' ';
            break;
        }
        cnt++;
        std::cin >> sentence[cnt];
    }

    return cnt;
}

int main()
{
    char sentence[MAX_WORDS][MAX_LETTERS_IN_WORD] = {};
    int cntWords = input(sentence);
    std::cout << cntWords << std::endl;
    for (int i = cntWords - 1; i >= 0; i--)
    {
        std::cout << sentence[i] << " ";
    }

    return 0;
}