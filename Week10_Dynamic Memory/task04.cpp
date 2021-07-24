#include <iostream>

void input(char *str, int size)
{
    std::cout << " Enter string: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> str[i];
    }
}

void print(char *str, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << str[i];
    }
}

char *concatenate(char *str1, int size1, char *str2, int size2)
{
    int size = size1 + size2;
    char *res = new (std::nothrow) char[size + 1];
    if (res)
    {
        for (int i = 0; i < size1; i++)
        {
            res[i] = str1[i];
        }

        for (int j = size1, k = 0; j < size; j++, k++)
        {
            res[j] = str2[k];
        }
        res[size] = '\0';
    }
    else
    {
        std::cout << "Problem allocating memory for contatenated string :(" << std::endl;
        return nullptr;
    }

    return res;
}
int main()
{
    int size1;
    std::cout << "Enter size of first string ";
    std::cin >> size1;

    if (size1)
    {
        char *str1 = new (std::nothrow) char[size1];
        if (str1)
        {
            input(str1, size1);

            int size2;
            std::cout << "Enter size of string to concatenate the first with: ";
            std::cin >> size2;

            if (size2)
            {
                char *str2 = new (std::nothrow) char[size2];
                if (str2)
                {
                    input(str2, size2);
                    char *concatenated = concatenate(str1, size1, str2, size2);
                    if (concatenated)
                    {
                        print(concatenated, size1 + size2);
                    }
                    delete[] concatenated;
                }

                else
                {
                    std::cout << "Problem allocating memory for string 2 :(" << std::endl;
                }

                delete[] str2;
            }

            else
            {
                std::cout << "Size should be more than 0!" << std::endl;
            }

            delete[] str1;
        }

        else
        {
            std::cout << "Problem allocating memory for string 1 :(" << std::endl;
        }
    }
    
    else
    {
        std::cout << "Size should be more than 0!" << std::endl;
    }

    return 0;
}