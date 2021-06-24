#ifndef CLASSTEACHER_H
#define CLASSTEACHER_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class ClassTeacher {       // The class
  public:             // Access specifier
    int teacherId;        // Attribute (int variable)
    int classId;
    char status[50];

  public:              // Access specifier
    void add() {  // Method/function defined inside the class
        cout<< "Add";
    }
    void update() {  // Method/function defined inside the class
        cout<< "Update";
    }
    void remove() {  // Method/function defined inside the class
        cout<< "Hello World!";
    }
    void read() {  // Method/function defined inside the class
        cout<< "Hello World!";
    }
};
#endif