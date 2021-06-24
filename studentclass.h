#ifndef STUDENTCLASS_H
#define STUDENTCLASS_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class StudentClass {       // The class
  public:             // Access specifier
    int classId;        // Attribute (int variable)
    int studentId;
    char admit[50];
    char struckoff[50];

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