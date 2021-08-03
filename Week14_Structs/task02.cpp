#include <iostream>

const int MAX_STRING_LEN = 150;
struct Student
{
    char name[MAX_STRING_LEN];
    unsigned fn;
    unsigned course;
    unsigned short group;
};

Student createStudent()
{
    Student result;

    //used in order to input the name correctly
    std::cin.get();

    std::cout << "Enter a name: ";
    std::cin.getline(result.name, MAX_STRING_LEN);

    std::cout << "Enter a faculty number: ";
    std::cin >> result.fn;

    std::cout << "Enter a course: ";
    std::cin >> result.course;

    std::cout << "Enter a group: ";
    std::cin >> result.group;

    return result;
}

Student *createStudentsArray(int cnt)
{
    Student *students = new (std::nothrow) Student[cnt];
    if (!students)
    {
        return nullptr;
    }

    for (int i = 0; i < cnt; i++)
    {
        students[i] = createStudent();
    }
    return students;
}

void printStudent(Student *students, int cnt, unsigned fn)
{
    int idx = -1;
    for (int i = 0; i < cnt; i++)
    {
        if (students[i].fn == fn)
        {
            idx = i;
        }
    }

    if (idx)
    {
        Student current = students[idx];
        std::cout << current.name << std::endl;
        std::cout << current.fn << std::endl;
        std::cout << current.course << std::endl;
        std::cout << current.group << std::endl;
    }
    else
    {
        std::cout << "No such student" << std::endl;
    }
}

int main()
{
    int cntStudent;
    std::cout << "Enter how many students you will enter: ";
    std::cin >> cntStudent;

    if (!cntStudent)
    {
        return -1;
    }

    Student *students = createStudentsArray(cntStudent);
    if (!students)
    {
        return -2;
    }

    unsigned fnToFind;
    std::cout << "Enter faculty number of student to find: ";
    std::cin >> fnToFind;
    if (!fnToFind)
    {
        return -3;
    }
    printStudent(students, cntStudent, fnToFind);
    delete[] students;
    return 0;
}