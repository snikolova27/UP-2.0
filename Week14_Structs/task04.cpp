#include <iostream>

const int MAX_BOOKS = 1000;
const int MAX_STR_LEN = 100;
const int ISBN = 13;

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

struct Book
{
    char title[MAX_STR_LEN];
    char author[MAX_STR_LEN];
    char ISBN[ISBN];

    void read()
    {
        std::cout << "Book title:" << std::endl;
        std::cin.ignore();
        std::cin.getline(title, MAX_STR_LEN);
        std::cout << "Book author:" << std::endl;
        std::cin.ignore();
        std::cin.getline(author, MAX_STR_LEN);
        std::cout << "Book ISBN:" << std::endl;
        std::cin >> ISBN;
    }
};

struct Library
{
    Book books[MAX_BOOKS];
    int number_of_books = 0;

    void addBookFromConsole()
    {
        if (number_of_books < MAX_BOOKS)
        {
            Book newBook;
            newBook.read();
            books[number_of_books++] = newBook;
        }
        else
        {
            std::cout << "NO MORE CAPACITY" << std::endl;
        }
    }

    void removeBook()
    {
        char isbn[ISBN];
         std::cout << "ISBN of Book for deletion:" <<  std::endl;
         std::cin >> isbn;

        bool foundBook = false;
        for (int i = 0; i < number_of_books; i++)
        {
            if (strcomp(books[i].ISBN, isbn) == 0)
            {
                foundBook = true;
                number_of_books--;
            }

            if (foundBook)
            {
                books[i] = books[i + 1];
            }
        }
    }

    int numberOfBooks()
    {
        return number_of_books;
    }
};

void printMenu()
{
    std::cout << "Choose option:\n";
    std::cout << "1 - Add Book to Library\n";
    std::cout << "2 - Remove Book from Library\n";
    std::cout << "3 - Get size of Library\n";
    std::cout << "0 - Exit\n";
}

int main()
{
    int option;
    Library myLibrary;

    do
    {
        printMenu();

        std::cin >> option;

        switch (option)
        {
        case 1:
            myLibrary.addBookFromConsole();
            break;
        case 2:
            myLibrary.removeBook();
            break;
        case 3:
            std::cout << myLibrary.numberOfBooks() <<  std::endl;
            break;
        }
    } while (option);

    return 0;
}