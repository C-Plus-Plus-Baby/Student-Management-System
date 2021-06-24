#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <vector> 
#include <sstream> 
#include "student.h"
#include "studentclass.h"


using namespace std;

class Class {       
  public:             
    int Id;        
    char name[50];  
    char description[50];

 public:              
    void add() {

        system("clear");
        Class c;

        cout << "\n\n\n\n";
        cout << "\t\t\t ================================================\n";
        cout << "\t\t\t ###################::ADD CLASS::##################\n";
        cout << "\t\t\t ================================================\n\n\n";

        cout << "\n\t\t\tEnter Class ID:-> ";
        cin.ignore();
        cin >> c.Id;
        cout << "\n\t\t\tEnter Class Name:-> ";
        cin.ignore();
        cin.getline(c.name,50);
        cout << "\n\t\t\tEnter Class Description:-> ";
        cin.getline(c.description,50);

        std::ofstream myfile;
        myfile.open("classes.txt", std::ios_base::app);
        if (myfile.is_open())
        {
            myfile << c.Id<<","<<c.name<<","<<c.description<<"\n";
            myfile.close();
            cout << "\n\t\t\tClass Added Successfully...!!!:-> \n";
        }
        else cout << "Unable to open file";
        
    }

    void update() {  
        system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::UPDATE CLASS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter Class ID \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("classes.txt");
        std::vector<std::string> vectorString;

        string khatam;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string ID, fname, lname;
                std::getline(ss,ID,',');    
                std::getline(ss,fname,','); 
                std::getline(ss,lname,','); 
                if(id==ID){
                    cout<<"\n\n\t\t\t\tRecord Founded, Lets Update A Record";
                    Class c;
                    cout << "\n\t\t\tEnter Class ID:-> ";
                    cin.ignore();
                    cin >> c.Id;
                    cout << "\n\t\t\tEnter Class Name:-> ";
                    cin.ignore();
                    cin.getline(c.name,50);
                    cout << "\n\t\t\tEnter Class Description:-> ";
                    cin.getline(c.description,50);

                    string new_record = std::to_string(c.Id) + ","+std::string(c.name) + ","+std::string(c.description) + "\n";
                    khatam.append(new_record);
                    cout << "\n\t\t\tClass Updated Successfully...!!!:-> \n";
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
            ofstream MyFile("classes.txt");
            MyFile << khatam;
            MyFile.close();
        }

        else cout << "Unable to open file"; 
    }
    void remove() {  
        system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::DELETE CLASS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter Class ID \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("classes.txt");
        std::vector<std::string> vectorString;

        string khatam;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string ID, fname, lname;
                std::getline(ss,ID,',');    
                std::getline(ss,fname,','); 
                std::getline(ss,lname,','); 
                if(id==ID){
                    cout<<"\n\n\n\t\t\tRecord Founded and Deleted Successfully";
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
            ofstream MyFile("classes.txt");
            MyFile << khatam;
            MyFile.close();
        }

        else cout << "Unable to open file"; 

        
    }

    void readByID() {  
        system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::FIND CLASS BY ID::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter Class ID \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("classes.txt");
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
                if(id==ID){
                    cout << "\n\n";
                    cout << "\t===================================================================================================================\n";
                    cout << "\t                                                     ::CLASSES DETAILS::                                             \n\n";
                    cout << "\t===================================================================================================================\n";
                    cout << "\t"
                        << "  Class ID" << setw(22) << "Class Name" << setw(22) << "Class Description" 
                        << "\n";
                    cout << "\t===================================================================================================================\n";

                    cout << "\n\t    " << ID << setw(20) << fname << setw(22) << lname << "\n";

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
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::CLASSES DETAILS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t"
             << "  Class ID" << setw(22) << "Class Name" << setw(22) << "Class Description" 
             << "\n";
        cout << "\t===================================================================================================================\n";

        string line;
        ifstream myfile ("classes.txt");
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
    string getAllClassesIds(){
        string ids;
        string line;
        ifstream myfile ("classes.txt");
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
    
    void admitStudentInClass(){
        Student s;
        system("clear");
        cout << "\n\n";
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::ADMIT STUDENT IN CLASS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\t All Student Ids are -->"<<s.getAllStudentsID();
        cout<<"\n\n\t\t\t All Classes Ids are -->"<<getAllClassesIds();

        StudentClass sc;
        cout<<"\n\t\t\t Enter Student Id ->";
        cin>>sc.studentId;
        cout<<"\n\t\t\t Enter Class Id ->";
        cin>>sc.classId;
        cout<<"\n\t\t\t Enter Admit (Y/N) ->";
        cin>>sc.admit;
        cout<<"\n\t\t\t Enter Struck OFF  (Y/N)->";
        cin>>sc.struckoff;

        std::ofstream myfile;
        myfile.open("studentclass.txt", std::ios_base::app);
        if (myfile.is_open())
        {
            myfile << sc.studentId<<","<<sc.classId<<","<<sc.admit<<","<<sc.struckoff<<"\n";
            myfile.close();
            cout << "\n\t\t\tStudent Admitted Successfully...!!!:-> \n";
        }
        else cout << "Unable to open file";  
    }
    void struckOffStudent(){
        Student s;
        string khatam;
        system("clear");
        cout << "\n\n";
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::STRUCK OFF STUDENT FROM CLASS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        alladmittedstudents();
        cout<<"\n\n\t\t\tEnter Student ID to Struckoff \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("studentclass.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string ID, classid, admit,struckoff;
                std::getline(ss,ID,',');    
                std::getline(ss,classid,','); 
                std::getline(ss,admit,','); 
                std::getline(ss,struckoff,','); 

                if(id==ID){
                    khatam.append(ID+","+classid+","+admit+","+"Y\n");
                    cout << "\n\t\t\tStudent Struck OFF Successfully...!!!:-> \n";
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
            ofstream MyFile("studentclass.txt");
            MyFile << khatam;
            MyFile.close();
        }

        else cout << "Unable to open file"; 
    }
    void alladmittedstudents(){
        cout << "\t"
             << "  Student ID" << setw(22) << "Class ID" << setw(22) << "Admitted" << setw(22) << "Struck-off" 
             << "\n";
        cout << "\t===================================================================================================================\n";
        string line;
        ifstream myfile ("studentclass.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {

                std::stringstream ss(line);

                std::string ID, classid, admit,struckoff;
                std::getline(ss,ID,',');    
                std::getline(ss,classid,','); 
                std::getline(ss,admit,','); 
                std::getline(ss,struckoff,','); 

                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
                std::cout<<"\n";
                
                cout << "\n\t    " << ID << setw(22) << classid << setw(22) << admit << setw(22) << struckoff<< "\n";
                //cout<<line<<"\n";
            }
            myfile.close();
        }

        else cout << "Unable to open file"; 
    }
    void showallstudentsinclass(){
        Student s;
        string khatam;
        system("clear");
        cout << "\n\n";
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::STUDENT BY CLASS ID::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t"
             << "  Student ID/RollNo" << setw(22) << "Class ID" << setw(22) << "Admitted" << setw(22) << "Struck-off" 
             << "\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter Class ID to View Students \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("studentclass.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {

                std::stringstream ss(line);

                std::string ID, classid, admit,struckoff;
                std::getline(ss,ID,',');    
                std::getline(ss,classid,','); 
                std::getline(ss,admit,','); 
                std::getline(ss,struckoff,','); 
                if(id==classid){
                
                cout << "\n\t    " << ID << setw(22) << classid << setw(22) << admit << setw(22) << struckoff<< "\n";

                }
                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
                std::cout<<"\n";
                
                //cout<<line<<"\n";
            }
            myfile.close();
        }

        else cout << "Unable to open file";
    }
};
#endif