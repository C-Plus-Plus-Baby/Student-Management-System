#ifndef STUDENTMARKS_H
#define STUDENTMARKS_H

#include <iostream>
#include <string>
#include <cstring>
#include "student.h"
using namespace std;

class StudentMarks {       
  public:             
    int studentId;        
    char subject[20];
    int marks;

  public:              
    void add() {  
        system("clear");
        StudentMarks sm;
        Student s;

        cout << "\n\n\n\n";
        cout << "\t\t\t ================================================\n";
        cout << "\t\t\t ###################::ADD STUDENT MARKS::##################\n";
        cout << "\t\t\t ================================================\n\n\n";
        cout<< "\n\n\n\t\t\t All Student IDs --> "<<s.getAllStudentsID();
        cout << "\n\t\t\tEnter Student ID:-> ";
        cin >> sm.studentId;
        cout << "\n\t\t\tEnter Subject:-> ";
        cin >> sm.subject;
        cout << "\n\t\t\tEnter Marks:-> ";
        cin>>sm.marks;

        std::ofstream myfile;
        myfile.open("studentmarks.txt", std::ios_base::app);
        if (myfile.is_open())
        {
            myfile << sm.studentId<<","<<sm.subject<<","<<sm.marks<<"\n";
            myfile.close();
            cout << "\n\t\t\tStudent Marks Added Successfully...!!!:-> \n";
        }
        else cout << "Unable to open file";
        
    }
    void update() {  
        cout<< "Update";
    }
    void remove() {  
        cout<< "Hello World!";
    }
    void readAll() {  
        system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::STUDENT MARKS DETAILS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t"
             << "  Student ID" << setw(22) << "Subject" << setw(22) << "Marks" 
             << "\n";
        cout << "\t===================================================================================================================\n";

        string line;
        ifstream myfile ("studentmarks.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {

                std::stringstream ss(line);

                std::string ID, fname, lname;
                std::getline(ss,ID,',');    
                std::getline(ss,fname,','); 
                std::getline(ss,lname,','); 

                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
                std::cout<<"\n";
                
                cout << "\n\t    " << ID << setw(20) << fname << setw(22) << lname << "\n";
                //cout<<line<<"\n";
            }
            myfile.close();
        }

        else cout << "Unable to open file"; 
    }
};
#endif