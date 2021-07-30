#include <iostream>

const int NUM_SIZE = 4;
const int RES_SIZE = 5;

void input(bool num[])
{
    std::cout << "Enter bits with spaces between them: ";
    for (int i = 0; i < NUM_SIZE; i++)
    {
        std::cin >> num[i];
    }
}
void print(const bool num[], int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << num[i];
    }
    std::cout << std::endl;
}

void sum(const bool firstNum[], const bool secondNum[], bool result[])
{
    bool addition = false;

    for (int i = NUM_SIZE - 1, j = RES_SIZE - 1; i >= 0, j > 0; i--, j--)
    {

        // if  different bits
        if ((firstNum[i] && !secondNum[i]) || (!firstNum[i] && secondNum[i]))
        {
            bool newBit = firstNum[i] | secondNum[i];

            if (!addition)
            {
                result[j] = newBit;
            }
            else
            {
                result[j] = false;
                addition = true;
            }
        }
        //if equal bits
        if ((firstNum[i] && secondNum[i]) || (!firstNum[i] && !secondNum[i]))
        {
            //if bits are nulls
            if (!firstNum[i])
            {
                if (!addition)
                {
                    bool newBit = false;
                    result[j] = newBit;
                }
                else
                {
                    bool newBit = true;
                    result[j] = newBit;
                    addition = false;
                }
            }
            //if bits are 1
            else
            {
                if (!addition)
                {
                    bool newBit = false;
                    addition = true;
                    result[j] = newBit;
                }
                else
                {
                    bool newBit = true;
                    addition = true;
                    result[j] = newBit;
                }
            }
        }
    }
    if (addition)
    {
        result[0] = true;
    }
    else
    {
        result[0] = false;
    }
}
int main()
{
    bool firstNum[NUM_SIZE] = {};
    bool secondNum[NUM_SIZE] = {};
    bool result[RES_SIZE] = {};

    std::cout << "Enter first number " << std::endl;
    input(firstNum);

    std::cout << "Enter second number " << std::endl;
    input(secondNum);

    std::cout << "Result: ";
    sum(firstNum, secondNum, result);
    print(result, RES_SIZE);

    return 0;
}