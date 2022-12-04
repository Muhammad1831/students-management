#ifndef STUDENT
#define STUDENT
#include <string>

class Student
{
private:
    long long int ID = 0;
    std::string first_name;
    std::string last_name;

    float score[5];
    float avrage = 0;

public:
    void set_ID(Student[], int);
    void set_name(Student[], int);
    void set_score(Student[], int);
    void set_avrage(Student[], int);
    int Edit(Student[], long long int);
    void Print(Student[], long long int);
    void Delete(Student[], long long int);
    Student();
};
#endif