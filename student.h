#ifndef STUDENT_H
#define STUDENT_H


#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <vector> 
#include <sstream> 
using namespace std;

class Student {       
  public:             
    int rollno;        
    char name[50];  
    int age;
    char address[100];

  public:              
    void add() {  
        system("clear");
        
        Student s;

        cout << "\n\n\n\n";
        cout << "\t\t\t ================================================\n";
        cout << "\t\t\t ###################::ADD STUDENT::##################\n";
        cout << "\t\t\t ================================================\n\n\n";

        cout << "\n\t\t\tEnter Student Roll No:-> ";
        cin.ignore();
        cin >> s.rollno;
        cout << "\n\t\t\tEnter Student Name:-> ";
        cin.ignore();
        cin.getline(s.name,50);
        cout << "\n\t\t\tEnter Student Age:-> ";
        cin.ignore();
        cin >> s.age;
        cout << "\n\t\t\tEnter Student Address:-> ";
        cin.ignore();
        cin.getline(s.address,50);

        std::ofstream myfile;
        myfile.open("students.txt", std::ios_base::app);
        if (myfile.is_open())
        {
            myfile << s.rollno<<","<<s.name<<","<<s.age<<","<<s.address<<"\n";
            myfile.close();
            cout << "\n\t\t\tStudent Added Successfully...!!!:-> \n";
        }
        else cout << "Unable to open file";  
    }


    void update() {  system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::UPDATE STUDENT::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter STUDENT ROLL NO \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("students.txt");
        std::vector<std::string> vectorString;

        string khatam;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string rollno, name, age,address;
                std::getline(ss,rollno,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,address,',');

                if(id==rollno){

                    Student s;
                    cout<<"\n\n\t\t\t\tRecord Founded, Lets Update A Record";
                    cout << "\n\t\t\tEnter Student Roll No:-> ";
                    cin.ignore();
                    cin >> s.rollno;
                    cout << "\n\t\t\tEnter Student Name:-> ";
                    cin.ignore();
                    cin.getline(s.name,50);
                    cout << "\n\t\t\tEnter Student Age:-> ";
                    cin.ignore();
                    cin >> s.age;
                    cout << "\n\t\t\tEnter Student Address:-> ";
                    cin.ignore();
                    cin.getline(s.address,50);

                    string new_record =std::to_string(s.rollno) + ","+std::string(s.name) + ","+ std::to_string(s.age) +","+std::string(s.address)+ "\n";
                    khatam.append(new_record);
                    cout << "\n\t\t\tStudent Updated Successfully...!!!:-> \n";
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
            ofstream MyFile("students.txt");
            MyFile << khatam;
            MyFile.close();
        }

        else cout << "Unable to open file"; 
    }

    void remove() {  
        system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::DELETE STUDENT:                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter STUDENT ROLL NO \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("students.txt");
        std::vector<std::string> vectorString;

        string khatam;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string rollno, name, age,address;
                std::getline(ss,rollno,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,address,',');

                if(id==rollno){
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
            ofstream MyFile("students.txt");
            MyFile << khatam;
            MyFile.close();
        }

        else cout << "Unable to open file"; 
    }
    void readByID() {  
        system("clear");
        cout << "\n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t                                                     ::FIND STUDENT BY ID::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout<<"\n\n\t\t\tEnter STUDENT ROLL NO \t --> ";
        string id;
        cin>>id;
        string line;
        ifstream myfile ("students.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                std::stringstream ss(line);

                std::string rollno, name, age,address;
                std::getline(ss,rollno,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,address,',');

                if(id==rollno){
                    cout << "\n\n";
                    cout << "\t===================================================================================================================\n";
                    cout << "\t                                                     ::STUDENT DETAILS::                                             \n\n";
                    cout << "\t===================================================================================================================\n";
                    cout << "\t"
                        << "  Student Roll No" << setw(22) << "Student Name" << setw(22) << "Student Age" <<setw(22) << "Student Address"
                        << "\n";
                    cout << "\t===================================================================================================================\n";

                    cout << "\n\t    " << rollno << setw(22) << name << setw(22) << age << setw(22)<< address << setw(22)<< "\n";

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
        cout << "\t                                                     ::STUDENT DETAILS::                                             \n\n";
        cout << "\t===================================================================================================================\n";
        cout << "\t"
            << "  Student Roll No" << setw(22) << "Student Name" << setw(22) << "Student Age" <<setw(22) << "Student Address"
            << "\n";
        cout << "\t===================================================================================================================\n";

        string line;
        ifstream myfile ("students.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {

                std::stringstream ss(line);

                std::string rollno, name, age,address;
                std::getline(ss,rollno,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,address,',');

                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
                std::cout<<"\n";
                
                cout << "\n\t    " << rollno << setw(20) << name << setw(22) << age << setw(22)<< address << setw(22)<< "\n";
                //cout<<line<<"\n";
            }
            myfile.close();
        }

        else cout << "Unable to open file"; 
    }
    string getAllStudentsID(){
        string res;
        string line;
        ifstream myfile ("students.txt");
        std::vector<std::string> vectorString;
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {

                std::stringstream ss(line);

                std::string rollno, name, age,address;
                std::getline(ss,rollno,',');    
                std::getline(ss,name,','); 
                std::getline(ss,age,',');
                std::getline(ss,address,',');

                res.append(rollno);
                res.append(" , ");

                std::vector<std::string> enrolled;
                std::string course;
                while( std::getline(ss,course,',') )
                {
                    enrolled.push_back(course); std::cout<<", \""<<course<<"\"";
                }
            }
            myfile.close();
            return res;
        }

        else cout << "Unable to open file";
        return "null";
    }
};
#endif