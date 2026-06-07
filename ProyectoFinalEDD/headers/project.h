#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
using namespace std;

struct Project {

    int project_id;

    string title;

    string description;

    int completion_year;

    Project* next;

    Project(
        int id,
        string t,
        string d,
        int year
    ) {

        project_id = id;

        title = t;

        description = d;

        completion_year = year;

        next = nullptr;
    }
};

#endif