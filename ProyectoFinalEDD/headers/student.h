#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include "Project.h"

using namespace std;

struct Student {

    int student_id;

    string full_name;

    string career;

    int semester;

    float gpa;

    int skill_score;

    Project* projects;

    Student() {

        projects = nullptr;
    }

    Student(
        int id,
        string name,
        string car,
        int sem,
        float avg,
        int skill
    ) {

        student_id = id;

        full_name = name;

        career = car;

        semester = sem;

        gpa = avg;

        skill_score = skill;

        projects = nullptr;
    }
};

#endif