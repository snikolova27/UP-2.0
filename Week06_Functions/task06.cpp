#include <iostream>

int main()
{
    int n;
    std::cout << "Enter count of participants: ";
    std::cin >> n;

    if (n > 50)
    {
        std::cout << "Number should not be greater than 50. \n";
        return -1;
    }

    int result, winnerIdx = 1;
    double weight;

    std::cout << "Enter result and weight of participant: ";
    std::cin >> result >> weight;

    int maxResult = result, minWeight = weight;

    for (int i = 2; i <= n; i++)
    {
        std::cin >> result >> weight;
        if( result > maxResult || (result == maxResult && weight < minWeight))
        {
            maxResult = result;
            minWeight = weight;
            winnerIdx = i;
        }
    }

    std::cout << winnerIdx << std::endl;
    
    return 0;
}