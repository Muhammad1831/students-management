#include <iostream>
#include "student.h"
using namespace std;

Student::Student()
{
}
void Student ::set_ID(Student s[], int count)
{
    long long int id;
    cin >> id;
    if (id < 0)//آیدی داده شده را چک می کند که منفی نباشد
    {
        cout << "\n\033[1;31m ID is not correct choose again \033[0m \n"
             << endl;
        set_ID(s, count);
    }

    for (size_t i = 0; i < 200; i++)//آیدی داده شده را چک می کند که تکراری نباشد
    {
        if (id == s[i].ID)
        {
            cout << "\n\033[1;31m the ID is duplicated choose again \033[0m \n"
                 << endl;
            set_ID(s, count);
        }
    }

    s[count].ID = id;
}

void Student ::set_name(Student s[], int count)
{
    cout << "\033[1;37m Enter the first_name ---> \033[0m";
    cin >> s[count].first_name;
    cout << "\033[1;37m Enter the last_name ---> \033[0m";
    cin >> s[count].last_name;
}

void Student ::set_score(Student s[], int count)
{
    for (size_t i = 0; i < 5; i++)//پنج تا نمره رو مقدار دهی می کنه
    {
        cout << "\033[1;37m Enter the Score \033[1;31m"
             << i + 1 << "\033[0m"
             << "\033[1;37m ---> \033[0m";
        cin >> s[count].score[i];

        if (s[count].score[i] < 0 || s[count].score[i] > 20)//چک میکنه خارج از 0 تا 20 نباشه نمره
        {
            cout << "\033[1;31m the Entered Score is not correct" 
                 << " choose again \033[0m";
            getchar();
            getchar();
            system("cls");
            --i;
        }
    }
}

void Student ::set_avrage(Student s[], int count)
{
    for (size_t i = 0; i < 5; i++)//میانگین پنج تا نمره رو حساب و در اوریج می ریزه
    {
        s[count].avrage = s[count].avrage + s[count].score[i];
    }
    s[count].avrage = s[count].avrage / 5;
}

int Student ::Edit(Student s[], long long int id)
{
    bool check = true;
    int i;
    for (i = 0; i < 200; i++)//چک می کنه آیدی وارد شده وجود داره بین آیدی ها یا نه
    {
        if (id == s[i].ID)
        {
            check = false;
            break;
        }
    }
    if (check)//اگه آیدی وجود نداشت پیام خطا می دهد
    {
        cout << "\033[1;31m the Entered id does not exist \033[0m";
        getchar();
        return 0;
    }

    cout << "\033[1;37m Enter the\033[1;31m New\033[1;37m ID ---> \033[0m";
    set_ID(s, i);
    set_name(s, i);
    set_score(s, i);
    set_avrage(s, i);
}

void Student ::Print(Student s[], long long int id)
{
    bool available = true;
    for (size_t i = 0; i < 200; i++)
    {
        if (id == s[i].ID)
        {
            cout << "\033[1;33m ID Is : \033[0m" << s[i].ID << endl;
            cout << "\033[1;32m firsrt_name Is : \033[0m" << s[i].first_name << endl
                 << "\033[1;31m last_name   Is : \033[0m" << s[i].last_name << endl;
            for (size_t j = 0; j < 5; j++)
            {
                cout << "\033[1;34m Score \033[0m" << j + 1
                     << "\033[1;34m Is : \033[0m" << s[i].score[j] << endl;
            }

            cout << "\033[1;35m avrage Is  : \033[0m" << s[i].avrage << endl;
            available = false;
        }
    }

    if (available)
    {
        cout << "\033[1;31m The entered ID is not available \033[0m" << endl;
    }
}

void Student ::Delete(Student s[], long long int id)
{
    int i;
    for (i = 0; i < 200; i++)
    {
        if (id == s[i].ID)
        {
            break;
        }
    }
    for ( ; i < 199 ; i++)
    {
        s[i].ID = s[i + 1].ID;
        s[i].first_name = s[i + 1].first_name;
        s[i].last_name = s[i + 1].last_name;
        for (size_t j = 0; j < 5; j++)
        {
            s[i].score[j] = s[i + 1].score[j];
        }
        s[i].avrage = s[i + 1].avrage;  
    }
}
