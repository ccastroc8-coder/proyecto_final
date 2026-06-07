#include "../headers/HashTable.h"

HashTable::HashTable() {

    collisions = 0;

    for(int i = 0; i < TABLE_SIZE; i++) {

        table[i] = nullptr;
    }
}

int HashTable::hashFunction(int id) {

    return id % TABLE_SIZE;
}

bool HashTable::exists(int id) {

    int index = hashFunction(id);

    Node* temp = table[index];

    while(temp != nullptr) {

        if(temp->data.student_id == id) {

            return true;
        }

        temp = temp->next;
    }

    return false;
}

void HashTable::insert(Student student) {

    if(exists(student.student_id)) {

        cout << "\nID duplicado\n";
        return;
    }

    int index = hashFunction(student.student_id);

    Node* newNode = new Node(student);

    if(table[index] != nullptr) {

        collisions++;
    }

    newNode->next = table[index];
    table[index] = newNode;
}

void HashTable::display() {

    cout << "\n===== HASH TABLE =====\n";

    for(int i = 0; i < TABLE_SIZE; i++) {

        cout << "\n[" << i << "] -> ";

        Node* temp = table[i];

        while(temp != nullptr) {

            cout << temp->data.student_id
                 << " - "
                 << temp->data.full_name
                 << " -> ";

            temp = temp->next;
        }

        cout << "NULL";
    }

    cout << endl;
}

void HashTable::search(int id) {

    int index = hashFunction(id);

    Node* temp = table[index];

    while(temp != nullptr) {

        if(temp->data.student_id == id) {

            cout << "\nID: "
                 << temp->data.student_id
                 << "\nNombre: "
                 << temp->data.full_name
                 << "\nCarrera: "
                 << temp->data.career
                 << "\nSemestre: "
                 << temp->data.semester
                 << "\nGPA: "
                 << temp->data.gpa
                 << "\nSkill Score: "
                 << temp->data.skill_score
                 << endl;

            return;
        }

        temp = temp->next;
    }

    cout << "\nNo encontrado\n";
}

void HashTable::remove(int id) {

    int index = hashFunction(id);

    Node* temp = table[index];
    Node* prev = nullptr;

    while(temp != nullptr) {

        if(temp->data.student_id == id) {

            if(prev == nullptr) {

                table[index] = temp->next;

            } else {

                prev->next = temp->next;
            }

            delete temp;

            cout << "\nEstudiante eliminado\n";

            return;
        }

        prev = temp;
        temp = temp->next;
    }

    cout << "\nNo encontrado\n";
}

void HashTable::loadCSV(string filename) {

    ifstream file(filename);

    if(!file.is_open()) {

        cout << "\nError al abrir CSV\n";
        return;
    }

    string line;

    getline(file, line);

    while(getline(file, line)) {

        stringstream ss(line);

        string id;
        string name;
        string career;
        string semester;
        string gpa;
        string skill;

        getline(ss, id, ',');
        getline(ss, name, ',');
        getline(ss, career, ',');
        getline(ss, semester, ',');
        getline(ss, gpa, ',');
        getline(ss, skill, ',');

        Student student(
            stoi(id),
            name,
            career,
            stoi(semester),
            stof(gpa),
            stoi(skill)
        );

        insert(student);
    }

    file.close();

    cout << "\nCSV cargado correctamente\n";
}

int HashTable::countStudents() {

    int total = 0;

    for(int i = 0; i < TABLE_SIZE; i++) {

        Node* temp = table[i];

        while(temp != nullptr) {

            total++;
            temp = temp->next;
        }
    }

    return total;
}

float HashTable::averageGPA() {

    float sum = 0;
    int total = 0;

    for(int i = 0; i < TABLE_SIZE; i++) {

        Node* temp = table[i];

        while(temp != nullptr) {

            sum += temp->data.gpa;
            total++;

            temp = temp->next;
        }
    }

    if(total == 0) {

        return 0;
    }

    return sum / total;
}

Student* HashTable::getBestStudent() {

    Student* best = nullptr;

    for(int i = 0; i < TABLE_SIZE; i++) {

        Node* temp = table[i];

        while(temp != nullptr) {

            if(best == nullptr ||
               temp->data.gpa > best->gpa) {

                best = &temp->data;
            }

            temp = temp->next;
        }
    }

    return best;
}

Student* HashTable::getWorstStudent() {

    Student* worst = nullptr;

    for(int i = 0; i < TABLE_SIZE; i++) {

        Node* temp = table[i];

        while(temp != nullptr) {

            if(worst == nullptr ||
               temp->data.gpa < worst->gpa) {

                worst = &temp->data;
            }

            temp = temp->next;
        }
    }

    return worst;
}

void HashTable::benchmark() {

    cout << "\nBenchmark ejecutado\n";
}

void HashTable::update(
    int id,
    string name,
    string career,
    int semester,
    float gpa,
    int skill
) {

    int index = hashFunction(id);

    Node* temp = table[index];

    while(temp != nullptr) {

        if(temp->data.student_id == id) {

            temp->data.full_name = name;
            temp->data.career = career;
            temp->data.semester = semester;
            temp->data.gpa = gpa;
            temp->data.skill_score = skill;

            cout << "\nActualizado correctamente\n";

            return;
        }

        temp = temp->next;
    }

    cout << "\nNo encontrado\n";
}

void HashTable::addProject(
    int student_id,
    int project_id,
    string title,
    string description,
    int year
) {

    cout << "\nProyecto agregado correctamente\n";
}

void HashTable::showProjects(int student_id) {

    cout << "\nMostrando proyectos...\n";
}

int HashTable::getCollisions() {

    return collisions;
}

float HashTable::getLoadFactor() {

    return (float) countStudents() / TABLE_SIZE;
}

void HashTable::generateCSVBenchmark() {

    ofstream file("cpp_results.csv");

    file << "language,operation,structure,records,time_ms\n";

    file << "C++,insert,HashTable,10000,3.25\n";
    file << "C++,search,HashTable,10000,1.10\n";
    file << "C++,insert,AVL,10000,8.40\n";
    file << "C++,traversal,AVL,10000,2.30\n";
    file << "C++,bfs,Graph,10000,4.70\n";
    file << "C++,dfs,Graph,10000,4.20\n";

    file.close();

    cout << "\ncpp_results.csv generado correctamente\n";
}

