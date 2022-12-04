#include <iostream>
#include "student.h"
using namespace std;

void menu()
{
    cout << "\033[1;32m 1. Add Student \033[1;33m \n 2. Edit Student"
         << "\033[1;34m \n 3. Print Information"
         << "\033[1;37m \n 4. Delete Student \033[1;31m \n 5. Exit\n\033[0m";
}

void run()
{
    Student s[200];
    int choice;
    int count = 0;// اندیس ارایه است و با هر بار ورود به اَد یکی اضافه می شود تا اطلاعات دانشجوی جدید در خانه بعد قرار گیرد
    do
    {
        menu();
        long long int id = 0;
        cout << "\033[1;37m chose a number ---> \033[0m";
        cin >> choice;
        system("cls");

        if (choice < 1 || choice > 5)//چک می کند عدد داده شده خارج از عدد گزینه های منو نباشد
        {
            cout << "\033[1;31m The selected number is wrong."
                 << " Enter the correct number \033[0m";
            getchar();
            getchar();
            system("cls");
            continue;
        }

        if (choice == 1)//Add student
        {
            cout << "\033[1;37m Enter the ID ---> \033[0m";
            s->set_ID(s, count);
            s->set_name(s, count);
            s->set_score(s, count);
            s->set_avrage(s, count);
            getchar();
            system("cls");
            count++;
        }

        else if (choice == 2)//Edit student
        {
            cout << "\033[1;37m Enter the\033[1;31m Old\033[1;37m ID ---> \033[0m";
            cin >> id;//آیدیی که کاربر می خواد ادیت کنه
            s->Edit(s, id);
            getchar();
            system("cls");
        }

        else if (choice == 3)//Print student
        {
            cout << "\033[1;37m Enter the desired ID ---> \033[0m";
            cin >> id;
            s->Print(s, id);
            getchar();
            getchar();
            system("cls");
        }

        else if (choice == 4)
        {
            cout << "\033[1;37m Enter the ID ---> \033[0m";
            cin >> id;//آیدیی که کاربر می خواد دیلیت کنه
            s->Delete(s, id);
        }
    } while (choice != 5);
}

int main()
{
    run();
}