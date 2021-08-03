#include <iostream>

const int MAX_STRING = 100;
const int ISBN = 13;

struct Book
{
    char title[MAX_STRING];
    char author[MAX_STRING];
    char genre[MAX_STRING];
    char isbn[ISBN];
    double price;
    long sales;
};

void initialize(Book &b)
{
    std::cout << "Book title:" << std::endl;
    std::cin.ignore();
    std::cin.getline(b.title, MAX_STRING);

    std::cout << "Book author:" << std::endl;
    std::cin.ignore();
    std::cin.getline(b.author, MAX_STRING);

    std::cout << "Book genre: " << std::endl;
    std::cin >> b.genre;

    std::cout << "Book ISBN:" << std::endl;
    std::cin >> b.isbn;

    std::cout << "Book price: " << std::endl;
    std::cin >> b.price;

    std::cout << "Book sales: " << std::endl;
    std::cin >> b.sales;
}

void print(Book &b)
{
    std::cout << "Book title:" << b.title << std::endl;

    std::cout << "Book author:" << b.author << std::endl;

    std::cout << "Book genre: " << b.genre << std::endl;

    std::cout << "Book ISBN:" << b.isbn << std::endl;

    std::cout << "Book price: " << b.price << std::endl;

    std::cout << "Book sales: " << b.sales << std::endl;
}
int main()
{
    return 0;
}