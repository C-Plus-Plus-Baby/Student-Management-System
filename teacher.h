#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <vector> 
#include <sstream> 
#include "classteacher.h"
using namespace std;

class Teacher {       
  public:             
    int Id;        
    char name[50];  
    int age;
    float salary;

  public:              
    public:             
    void add() {  
        system("clear");
        
        Teacher t;

        cout << "\n\n\n\n";
        cout << "\t\t\t ================================================\n";
        cout << "\t\t\t ###################::ADD TEACHER::##################\n";
        cout << "\t\t\t ================================================\n\n\n";

        cout << "\n\t\t\tEnter Teacher ID:-> ";
        cin.ignore();
        cin >> t.Id;
        cout << "\n\t\t\tEnter Teacher Name:-> ";
        cin.ignore();
        cin.getline(t.name,50);
        cout << "\n\t\t\tEnter Teacher Age:-> ";
        cin.ignore();
        cin >> t.age;
        cout << "\n\t\t\tEnter Teacher Salary:-> ";
        cin.ignore();
        cin >> t.salary;

        std::ofstream myfile;
        myfile.open("teachers.txt", std::ios_base::app);
        if (myfile.is_open())
        {
            myfile << t.Id<<","<<t.name<<","<<t.age<<","<<t.salary<<"\n";
            myfile.close();
            cout << "\n\t\t\tTeacher Added Successfully...!!!:-> \n";
        }
        else cout << "Unable to open file";  
        
    }
    void update() {  
        system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::UPDATE TEACHER::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter TEACHER ID \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("teachers.txt");
        std::vector<std::string> vectorString;

        string khatam;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string ID, name, age,salary;
                std::getline(ss,ID,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,salary,',');

                if(id==ID){
                    Teacher t;
                    cout<<"\n\n\t\t\t\tRecord Founded, Lets Update A Record";
                    cout << "\n\t\t\tEnter Teacher ID:-> ";
                    cin.ignore();
                    cin >> t.Id;
                    cout << "\n\t\t\tEnter Teacher Name:-> ";
                    cin.ignore();
                    cin.getline(t.name,50);
                    cout << "\n\t\t\tEnter Teacher Age:-> ";
                    cin.ignore();
                    cin >> t.age;
                    cout << "\n\t\t\tEnter Teacher Salary:-> ";
                    cin.ignore();
                    cin >> t.salary;

                    string new_record =std::to_string(t.Id) + ","+std::string(t.name) + ","+ std::to_string(t.age) +","+std::to_string(t.salary)+ "\n";
                    khatam.append(new_record);
                    cout << "\n\t\t\tTeacher Updated Successfully...!!!:-> \n";
                }else{
                   khatam.append(line); 
                   khatam.append("\n"); 
                }
                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
            }
            myfile.close();
            ofstream MyFile("teachers.txt");
            MyFile << khatam;
            MyFile.close();
        }

        else cout << "Unable to open file"; 
    }
    void remove() {  
        system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::DELETE TEACHER:                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter Teacher ID \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("teachers.txt");
        std::vector<std::string> vectorString;

        string khatam;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string ID, name, age,salary;
                std::getline(ss,ID,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,salary,','); 

                if(id==ID){
                    cout<<"\n\n\n\t\t\t\tRecord Founded and Deleted Successfully";
                }else{
                   khatam.append(line); 
                   khatam.append("\n"); 
                }
                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
            }
            myfile.close();
            ofstream MyFile("teachers.txt");
            MyFile << khatam;
            MyFile.close();
        }

        else cout << "Unable to open file"; 

        
    }
    void readByID() { 
        system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::FIND TEACHER BY ID::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter TEACHER ID \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("teachers.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string ID, name, age,salary;
                std::getline(ss,ID,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,salary,','); 

                if(id==ID){
                    cout << "\n\n";
                    cout << "\t===================================================================================================================\n";
                    cout << "\t                                                     ::TEACHER DETAILS::                                             \n\n";
                    cout << "\t===================================================================================================================\n";
                    cout << "\t"
                        << "  Teacher ID" << setw(22) << "Teacher Name" << setw(22) << "Teacher Age" <<setw(22) << "Teacher Salary"
                        << "\n";
                    cout << "\t===================================================================================================================\n";

                    cout << "\n\t    " << ID << setw(20) << name << setw(22) << age << setw(22)<< salary << setw(22)<< "\n";

                }
                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
            }
            myfile.close();
        }

        else cout << "Unable to open file"; 
    }

    void readAll() {  
        system("clear");
        cout << "\n\n";
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::TEACHER DETAILS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t"
            << "  Teacher ID" << setw(22) << "Teacher Name" << setw(22) << "Teacher Age" <<setw(22) << "Teacher Salary"
            << "\n";
        cout << "\t===================================================================================================================\n";

        string line;
        ifstream myfile ("teachers.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {

                std::stringstream ss(line);

                std::string ID, name, age,salary;
                std::getline(ss,ID,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,salary,','); 

                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
                std::cout<<"\n";
                
                cout << "\n\t    " << ID << setw(20) << name << setw(22) << age << setw(22)<< salary << setw(22)<< "\n";
                //cout<<line<<"\n";
            }
            myfile.close();
        }

        else cout << "Unable to open file"; 
    }
    string getAllTeacherIds(){
        string ids;
        string line;
        ifstream myfile ("teachers.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {

                std::stringstream ss(line);

                std::string ID, name, age,salary;
                std::getline(ss,ID,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,salary,','); 

                ids.append(ID);
                ids.append(" , ");
                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
               
            }
            myfile.close();
            return ids;
        }

        else cout << "Unable to open file"; 
        return "null";
    }
    void assignTeacherToClass(){
        system("clear");
        cout << "\n\n";
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::ASSIGN TEACHER TO CLASS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\t All Teacher Ids are -->"<<getAllTeacherIds();
        cout<<"\n\n\t\t\t All Classes Ids are -->"<<getAllTeacherIds();

        ClassTeacher ct;
        cout<<"\n\n\n\t\t\t Enter Teacher Id ->";
        cin>>ct.teacherId;
        cout<<"\n\t\t\t Enter Class Id ->";
        cin>>ct.classId;
        cout<<"\n\t\t\t Enter Assigned Status ->";
        cin>>ct.status;
        
        std::ofstream myfile;
        myfile.open("classteachers.txt", std::ios_base::app);
        if (myfile.is_open())
        {
            myfile << ct.teacherId<<","<<ct.classId<<","<<ct.status<<"\n";
            myfile.close();
            cout << "\n\\t\t\tTeacher Assigned Successfully...!!!:-> \n";
        }
        else cout << "Unable to open file";  

    }

    void reAssignTeacherToClass(){
        system("clear");
        cout << "\n\n";
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::RE-ASSIGN TEACHER TO CLASS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        showTeacherofClass();
        cout<<"\n\n\t\t\tEnter TEACHER ID TO Re-Assign \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("classteachers.txt");
        std::vector<std::string> vectorString;

        string khatam;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string teacherId, classId, Status;
                std::getline(ss,teacherId,',');    
                std::getline(ss,classId,','); 
                std::getline(ss,Status,',');

                if(id==teacherId){
                    cout<<"\n\n\t\t\t\tRecord Founded, Lets Update A Record";
                    ClassTeacher ct;
                    cout<<"\n\n\n\t\t\t Enter Teacher Id ->";
                    cin>>ct.teacherId;
                    cout<<"\n\t\t\t Enter Class Id ->";
                    cin>>ct.classId;
                    cout<<"\n\t\t\t Enter Assigned Status ->";
                    cin>>ct.status;

                    string new_record =std::to_string(ct.teacherId) + ","+std::to_string(ct.classId) + ","+ std::string(ct.status)+ "\n";
                    khatam.append(new_record);
                    cout << "\n\t\t\tTeacher Re-Assigned Successfully...!!!:-> \n";
                }else{
                   khatam.append(line); 
                   khatam.append("\n"); 
                }
                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
            }
            myfile.close();
            ofstream MyFile("classteachers.txt");
            MyFile << khatam;
            MyFile.close();
        }

        else cout << "Unable to open file"; 
    }
    void removeTeacherFromAssignedClass(){
        system("clear");
        cout << "\n\n";
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::REMOVE TEACHER TO CLASS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        showTeacherofClass();
        cout<<"\n\n\t\t\tEnter TEACHER ID TO Remove \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("classteachers.txt");
        std::vector<std::string> vectorString;

        string khatam;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string teacherId, classId, Status;
                std::getline(ss,teacherId,',');    
                std::getline(ss,classId,','); 
                std::getline(ss,Status,',');

                if(id==teacherId){
                    cout<<"\n\n\n\t\t\tRecord Founded and Removed Successfully";
                }else{
                   khatam.append(line); 
                   khatam.append("\n"); 
                }
                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
            }
            myfile.close();
            ofstream MyFile("classteachers.txt");
            MyFile << khatam;
            MyFile.close();
        }

        else cout << "Unable to open file"; 

    }

    void showTeacherofClass(){

        cout << "\t===================================================================================================================\n";
        cout << "\t"
            << "  Teacher ID" << setw(22) << "Class ID" << setw(22) << "Status" <<setw(22) 
            << "\n";
        cout << "\t===================================================================================================================\n";

        string line;
        ifstream myfile ("classteachers.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {


                std::stringstream ss(line);

                std::string teacherId, classId, Status;
                std::getline(ss,teacherId,',');    
                std::getline(ss,classId,','); 
                std::getline(ss,Status,','); 

                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
                std::cout<<"\n";
                
                cout << "\n\t    " << teacherId << setw(22) << classId << setw(22) << Status<< setw(22)<< "\n";
                //cout<<line<<"\n";
            }
            myfile.close();
        }

        else cout << "Unable to open file"; 
    }
    void showparticularTeacherByID(){
system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::FIND TEACHER OF CLASS BY TEACHER ID::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter TEACHER ID \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("classteachers.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string teacherId, classId, Status;
                std::getline(ss,teacherId,',');    
                std::getline(ss,classId,','); 
                std::getline(ss,Status,','); 


                if(id==teacherId){
                    cout << "\n\n";
                    cout << "\t===================================================================================================================\n";
                    cout << "\t                                                     ::TEACHER DETAILS::                                             \n\n";
                    cout << "\t===================================================================================================================\n";
                   
                    cout << "\t===================================================================================================================\n";
                    cout << "\t"
                        << "  Teacher ID" << setw(22) << "Class ID" << setw(22) << "Status" <<setw(22) 
                        << "\n";
                    cout << "\t===================================================================================================================\n";

                    cout << "\n\t    " << teacherId << setw(22) << classId << setw(22) << Status<< setw(22)<< "\n";

                }
                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
            }
            myfile.close();
        }

        else cout << "Unable to open file"; 
    }
};
#endif