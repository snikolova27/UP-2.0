#include <iostream>

struct Domino
{
    int left;
    int right;
};

//Array of dominos-related functions

/**
     * @brief Function to create a Domino and input its elements
     * @return Domino with the input guven
     */
Domino createDomino()
{
    Domino result;
    do
    {
        std::cout << "Enter number for the left side of the tile: ";
        std::cin >> result.left;

        if (result.left <= 0)
        {
            std::cout << "Number should be > 0. Try again." << std::endl;
            std::cout << "Left number: ";
            std::cin >> result.left;
        }
    } while (result.left <= 0);

    do
    {
        std::cout << "Enter number for  the right side of the tile: ";
        std::cin >> result.right;

        if (result.right <= 0)
        {
            std::cout << "Number should be > 0. Try again." << std::endl;
            std::cout << "Right number: ";
            std::cin >> result.right;
        }
    } while (result.right <= 0);

    return result;
}

/**
     * @brief Function to allocate an array of Dominos with given size
     * @param size: Size of array
     * @return Array of Dominos with given size
     */
Domino *allocateArray(int size)
{
    Domino *result = new (std::nothrow) Domino[size];
    if (!result)
    {
        return nullptr;
    }
    return result;
}
/**
     * @brief Function to input an array of Dominos
     * @param array: Array to fill
     * @param size: Size of array
     */
void input(Domino *array, int size)
{
    std::cout << "Enter your array tiles" << std::endl;
    for (int i = 0; i < size; i++)
    {
        std::cout << "Tile #" << i + 1 << std::endl;
        array[i] = createDomino();
        std::cout << std::endl;
    }
}

/**
     * @brief Function to print array of Dominos
     * @param array: Array to print
     * @param size: Size of array
     */
void print(Domino *array, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i].left << "-" << array[i].right << " ";
    }
    std::cout << std::endl;
}

/**
     * @brief Function to  deallocate dynamically allocated array of Dominos
     * @param array: Array to deallocate
     */
void clear(Domino *array)
{
    delete[] array;
}

/**
     * @brief Function to  deallocate dynamically allocated array of ints
     * @param array: Array to deallocate
     */
void clear(int *array)
{
    delete[] array;
}

//Function to solve the task

/**
     * @brief Function to find the longest row of Dominos
     * @param array: Array of dominos to search for the answer in
     * @param size: Size of array
     * @param maxCnt: Max count of domino tiles in a row
     * @param maxRow: Row with max count of dominos
     * @param currentCnt: Current count of domino tiles in a row
     * @param currentRow: Current row of dominos
     * @param usedTiles: Array to store which domino tiles have already been used while searching for the answer
     */
void findLongestRowOfDominos(Domino *array, int size, int &maxCnt, Domino *maxRow, int currentCnt, Domino *currentRow, int *usedTiles)
{
    if (currentCnt > size)
    {
        return;
    }

    if (currentCnt > maxCnt)
    {
        maxCnt = currentCnt;
        for (int i = 0; i < maxCnt; i++)
        {
            maxRow[i] = currentRow[i];
        }
    }

    for (int i = 0; i < size; i++)
    {
        bool used = false;

        for (int j = 0; j < currentCnt; j++)
        {
            if (i == usedTiles[j])
            {
                used = true;
                break;
            }
        }

        if (!used)
        {
            if (currentRow[currentCnt - 1].right == array[i].left)
            {
                currentRow[currentCnt].left = array[i].left;
                currentRow[currentCnt].right = array[i].right;
                usedTiles[currentCnt] = i;
                findLongestRowOfDominos(array, size, maxCnt, maxRow, currentCnt + 1, currentRow, usedTiles);
            }
            if (currentRow[currentCnt - 1].right == array[i].right)
            {
                currentRow[currentCnt].left = array[i].right;
                currentRow[currentCnt].right = array[i].left;
                usedTiles[currentCnt] = i;
                findLongestRowOfDominos(array, size, maxCnt, maxRow, currentCnt + 1, currentRow, usedTiles);
            }
        }
    }
}

int main()
{
    int tiles;
    Domino *dominos;

    std::cout << "Enter amount of tiles you'll enter: ";
    std::cin >> tiles;

    if (!std::cin)
    {
        std::cout << "Invalid user input. You should enter a number." << std::endl;
        return -2;
    }
    do
    {
        if (tiles <= 0)
        {
            std::cout << "Tiles should be > 0. Try again." << std::endl;
            std::cout << "Til:s ";
            std::cin >> tiles;
        }

    } while (tiles <= 0);

    dominos = allocateArray(tiles);
    if (!dominos)
    {
        std::cout << "Memory problem while allocating memory for the array of dominos" << std::endl;
        return -1;
    }

    input(dominos, tiles);

    std::cout << "Entered domino tiles: ";
    print(dominos, tiles);

    Domino *currentRow = new (std::nothrow) Domino[tiles];
    if (!currentRow)
    {
        std::cout << "Problem while allocating memory for the current row" << std::endl;
        return -1;
    }

    Domino *maxRow = new (std::nothrow) Domino[tiles];
    if (!maxRow)
    {
        std::cout << "Problem while allocating memory for the max row" << std::endl;
        return -1;
    }

    int *usedTiles = new (std::nothrow) int[tiles];
    if (!usedTiles)
    {
        std::cout << "Problem while allocating memory for the used tiles" << std::endl;
        return -1;
    }

    int maxCnt = 1;

    for (int i = 0; i < tiles; i++)
    {
        currentRow[0].left = dominos[i].left;
        currentRow[0].right = dominos[i].right;
        usedTiles[0] = i;
        findLongestRowOfDominos(dominos, tiles, maxCnt, maxRow, 1, currentRow, usedTiles);

        currentRow[0].left = dominos[i].right;
        currentRow[0].right = dominos[i].left;
        usedTiles[0] = i;
        findLongestRowOfDominos(dominos, tiles, maxCnt, maxRow, 1, currentRow, usedTiles);
    }

    Domino *result = new (std::nothrow) Domino[maxCnt];

    if (!result)
    {

        std::cout << "Problem while allocating memory for the result" << std::endl;
        return -1;
    }

    for (int i = 0; i < maxCnt; i++)
    {
        result[i] = maxRow[i];
    }

    std::cout << "Result: ";
    print(result, maxCnt);

    clear(dominos);
    clear(currentRow);
    clear(maxRow);
    clear(result);
    clear(usedTiles);

    return 0;
}