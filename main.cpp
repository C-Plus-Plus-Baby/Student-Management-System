#include <iostream>
#include <curses.h>
#include <unistd.h>

#include "student.h"
#include "teacher.h"
#include "class.h"
#include "studentclass.h"
#include "classteacher.h"
#include "studentmarks.h"


using namespace std;

// GLOBAL FUNCTION
void mainMenu();
void welcomeScreen();
void studentManage();
void teacherManage();
void classManage();
void resultsManage();

int main()
{
    system("clear");
    usleep(1000000);

    string root_pass = "";
    string ch;

    cout << "\t\tEnter Master Password:-> ";
    cin>>ch;
    if (ch == "123")
    {
        welcomeScreen();
    }
    else
    {
        system("clear");
        cout << "\n\n\n\t\t\tAccess Denied...!!!\n\n";
        usleep(1000000);
        main();
    }
    return 0;
}
//  WELCOME SCREEN FUNCTION
void welcomeScreen()
{
    system("clear");

    cout << "\n\n\n\n\n\n\n\n\n\n";
    cout << "\t\t\t ================================================\n";
    cout << "\t\t\t ||                  WELCOME TO                ||\n";
    cout << "\t\t\t ||                                            ||\n";
    cout << "\t\t\t ||         STUDENT MANAGEMENT SYSTEM          ||\n";
    cout << "\t\t\t ||                                            ||\n";
    cout << "\t\t\t ||                    PROJECT                 ||\n";
    cout << "\t\t\t ================================================\n\n\n";

    cout << "\t\t\t-------------------------------------------------\n";
    cout << "\t\t\t  Developed By:-           \t\n";
    cout << "\t\t\t                           \t\n";
    cout << "\t\t\t  ------ -----             \t\n";
    cout << "\t\t\t-------------------------------------------------\n\n";

    usleep(1000000);
    mainMenu();
}

// MAIN MENU FUNCTION
void mainMenu()
{
    int choice;

    while (1)
    {
        system("clear");
        //system("cls");

        // MENU ITEMS
        cout << "\n\n\n\n";
        cout << "\t\t\t ================================================\n";
        cout << "\t\t\t #################::MAIN MENU::##################\n";
        cout << "\t\t\t ================================================\n\n\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t1. Student Management \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t2. Teacher Management \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t3. Class Management \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t4. Results Management\t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t5. EXIT \t\t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n\n";

        cout << "\n\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)

        {

        case 1:
            studentManage();
            break;

        case 2:
            teacherManage();
            break;

        case 3:
            classManage();
            break;
        
        case 4:
            resultsManage();
            break;

        case 5:
            system("clear");
            cout << "\n\n\n\n\t\t\t  Thanks for using our project...!!! \t\t\t\n";
            cout << "\n\n\t\t\t\t\t          Have a nice day...!!!      \t\t\t\n\n";
            exit(0);

        default:
            cout << "\n\n\t\t\t  Choose valid option!!! \t\t\t\n";
            usleep(1000000);
            mainMenu();
        }
    }
}

void studentManage()
{
    Student student;

    int choice;

    while (1)
    {
        system("clear");

        // MENU ITEMS
        cout << "\n\n\n";
        cout << "\t\t\t ================================================\n";
        cout << "\t\t\t ###############::STUDENT MANAGE::###############\n";
        cout << "\t\t\t ================================================\n\n\n";

        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t1. Add Student            \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t2. View All Student         \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t3. Delete Student      \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t4. Update Student      \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t5. View Student by Id     \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t6. BACK               \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n\n";

        cout << "\n\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)

        {

        case 1:
            student.add();
            //system("pause");
             usleep(1000000);
            break;

        case 2:
            student.readAll();
            cout << "\n\n";
           // system("pause");
            usleep(1000000);
            break;

        case 3:
            student.remove();
            //system("pause");
             usleep(1000000);
            break;

        case 4:
            student.update();
           // system("pause");
            usleep(1000000);
            break;

        case 5:
            student.readByID();
            break;

        case 6:
            system("clear");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t  Choose valid option!!! \t\t\t\n";
            //system("pause");
             usleep(1000000);
            studentManage();
        }
    }
}


void teacherManage()
{
    Teacher teacher;

    int choice;

    while (1)
    {
         system("clear");

        // MENU ITEMS
        cout << "\n\n\n";
        cout << "\t\t\t ================================================\n";
        cout << "\t\t\t ###############::TEACHER MANAGE::###############\n";
        cout << "\t\t\t ================================================\n\n\n";

        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t1. Add Teacher            \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t2. View All Teaecher         \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t3. Delete Teacher      \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t4. Update Teacher     \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t5. View Teacher by Id     \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t6. Assign Teacher to Class    \t\t\t|\n";
        cout << "\t\t\tt-------------------------------------------------\n";
        cout << "\t\t\t|\t7. Re-Assign Teacher to Class    \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t8. Remove Teacher from Assigned Class     \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t9. Show Teacher of Class by Teacher ID    \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t10. BACK               \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n\n";

        cout << "\n\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)

        {

        case 1:
            teacher.add();
            //system("pause");
             usleep(1000000);
            break;

        case 2:
            teacher.readAll();
            cout << "\n\n";
           // system("pause");
            usleep(1000000);
            break;

        case 3:
            teacher.remove();
            //system("pause");
             usleep(1000000);
            break;

        case 4:
            teacher.update();
           // system("pause");
            usleep(1000000);
            break;

        case 5:
            teacher.readByID();
            break;

        case 6:
            teacher.assignTeacherToClass();
            break;
        
        case 7:
            teacher.reAssignTeacherToClass();
            break;
        
        case 8:
            teacher.removeTeacherFromAssignedClass();
            break;
        
        case 9:
            teacher.showparticularTeacherByID();
            break;

        case 10:
            system("clear");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            //system("pause");
             usleep(1000000);
            teacherManage();
        }
    }
}

void classManage()
{
    Class clas;

    int choice;

    while (1)
    {
       system("clear");

        // MENU ITEMS
        cout << "\n\n\n";
        cout << "\t\t\t ================================================\n";
        cout << "\t\t\t ###############::CLASS MANAGE::###############\n";
        cout << "\t\t\t ================================================\n\n\n";

        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t1. Add Class            \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t2. View All Class         \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t3. Delete Class      \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t4. Update Class    \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t5. View Class by Id     \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\tt|\t6. Admit A Student     \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t7. Struck OFF A Student     \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t8. Show Students in Class     \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t9. BACK               \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n\n";

        cout << "\n\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)

        {

        case 1:
            clas.add();
            //system("pause");
             usleep(1000000);
            break;

        case 2:
            clas.readAll();
            cout << "\n\n";
           // system("pause");
            usleep(1000000);
            break;

        case 3:
            clas.remove();
            //system("pause");
             usleep(1000000);
            break;

        case 4:
            clas.update();
           // system("pause");
            usleep(1000000);
            break;

        case 5:
            clas.readByID();
            break;
        
        case 6:
            clas.admitStudentInClass();
            break;

        case 7:
            clas.struckOffStudent();
            break;

        case 8:
            clas.showallstudentsinclass();
            break;

        case 9:
            system("clear");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            //system("pause");
            usleep(1000000);
            classManage();
        }
    }
}

void resultsManage()
{
    StudentMarks sm;

    int choice;

    while (1)
    {
        system("clear");

        // MENU ITEMS
        cout << "\n\n\n";
        cout << "\t\t\t ================================================\n";
        cout << "\t\t\t ###############::RESULTS::###############\n";
        cout << "\t\t\t ================================================\n\n\n";

        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t1. Add Student Marks            \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t2. View All Student Marks            \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n";
        cout << "\t\t\t|\t3. BACK               \t\t\t|\n";
        cout << "\t\t\t-------------------------------------------------\n\n";

        cout << "\n\t\t\tEnter your choice:-> ";

        cin >> choice;

        switch (choice)

        {

        case 1:
            sm.add();
            //system("pause");
             usleep(1000000);
            break;

        case 2:
            sm.readAll();
            cout << "\n\n";
           // system("pause");
            usleep(1000000);
            break;

        case 3:
            system("clear");
            mainMenu();
            break;

        default:
            cout << "\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            //system("pause");
            usleep(1000000);
            resultsManage();
        }
    }
}
