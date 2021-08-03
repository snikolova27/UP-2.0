#include <iostream>

struct Kontrolni
{
    double first;
    double second;
};

struct Homework
{
    double first;
    double second;
    double third;
};

struct Exam
{
    double tasks;
    double theory;
};

struct Grades
{
    Kontrolni kontrolni;
    Homework hw;
    Exam exams;
};

double finalGrade(Grades grades)
{
    double TK = (grades.kontrolni.first + grades.kontrolni.second + (grades.hw.first + grades.hw.second + grades.hw.second) / 3) / 3;
    double E = (grades.exams.tasks + grades.exams.theory) / 2;
    return TK * 0.5 + E * 0.5;
}

Grades inputGrades()
{
    Grades grades;
    Exam e;
    Kontrolni k;
    Homework hws;

    std::cout << "Please insert result from test #1: ";
    std::cin >> k.first;

    std::cout << "Please insert result from test #2: ";
    std::cin >> k.second;

    std::cout << "Please insert result from homework #1: ";
    std::cin >> hws.first;

    std::cout << "Please insert result from homework #2: ";
    std::cin >> hws.second;

    std::cout << "Please insert result from homework #3: ";
    std::cin >> hws.third;

    std::cout << "Please insert result from the written exam: ";
    std::cin >> e.tasks;

    std::cout << "Please insert result from the oral exam: ";
    std::cin >> e.theory;

    grades.exams = e;
    grades.hw = hws;
    grades.kontrolni = k;

    return grades;
}

int main()
{

    Grades grades;
    grades = inputGrades();
    std::cout << finalGrade(grades) << std::endl;
    return 0;
}