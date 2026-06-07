#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "Student.h"

using namespace std;

const int TABLE_SIZE = 10;

struct Node {

    Student data;
    Node* next;

    Node(Student s) {

        data = s;
        next = nullptr;
    }
};

class HashTable {

private:

    Node* table[TABLE_SIZE];
    int collisions;

public:

    HashTable();

    int hashFunction(int id);

    bool exists(int id);

    void insert(Student student);

    void display();

    void search(int id);

    void remove(int id);

    void loadCSV(string filename);

    int countStudents();

    float averageGPA();

    Student* getBestStudent();

    Student* getWorstStudent();

    void benchmark();

    void update(
        int id,
        string name,
        string career,
        int semester,
        float gpa,
        int skill
    );

    void addProject(
        int student_id,
        int project_id,
        string title,
        string description,
        int year
    );

    void showProjects(int student_id);

    int getCollisions();

    float getLoadFactor();

    void generateCSVBenchmark();
};

#endif