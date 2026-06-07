#include <iostream>
#include "../headers/HashTable.h"
#include "../headers/AVLTree.h"
#include "../headers/Graph.h"
#include "../headers/Stack.h"

using namespace std;

int main() {

    HashTable hashTable;
    AVLTree avl;
    Graph graph;
    Stack history;

    hashTable.loadCSV("dataset/estudiantes.csv");

    int option;

    do {

        cout << "\n===== MENU =====\n"
             << "1. Mostrar Hash\n"
             << "2. Buscar estudiante\n"
             << "3. Mostrar AVL\n"
             << "4. Mostrar Grafo\n"
             << "5. BFS\n"
             << "6. DFS\n"
             << "7. Agregar estudiante\n"
             << "8. Eliminar estudiante\n"
             << "9. Total estudiantes\n"
             << "10. Promedio GPA\n"
             << "11. Mejor estudiante\n"
             << "12. Peor estudiante\n"
             << "13. Benchmark Hash vs AVL\n"
             << "14. Actualizar estudiante\n"
             << "15. Agregar proyecto\n"
             << "16. Mostrar proyectos\n"
             << "17. Mostrar historial\n"
             << "18. Generar benchmark CSV\n"
             << "19. Estadisticas\n"
             << "20. Salir\n"
             << "Seleccione opcion: ";

        cin >> option;

        switch(option) {

            case 1: {

                hashTable.display();
                break;
            }

            case 2: {

                int id;

                cout << "\nIngrese ID: ";
                cin >> id;

                hashTable.search(id);

                break;
            }

            case 3: {

                avl.inorder();
                break;
            }

            case 4: {

                graph.display();
                break;
            }

            case 5: {

                int start;

                cout << "\nNodo inicial BFS: ";
                cin >> start;

                graph.BFS(start);

                break;
            }

            case 6: {

                int start;

                cout << "\nNodo inicial DFS: ";
                cin >> start;

                graph.DFS(start);

                break;
            }

            case 7: {

                int id;
                string name;
                string career;
                int semester;
                float gpa;
                int skill;

                cout << "\nID: ";
                cin >> id;

                cin.ignore();

                cout << "Nombre: ";
                getline(cin, name);

                cout << "Carrera: ";
                getline(cin, career);

                cout << "Semestre: ";
                cin >> semester;

                cout << "GPA: ";
                cin >> gpa;

                cout << "Skill Score: ";
                cin >> skill;

                Student s(
                    id,
                    name,
                    career,
                    semester,
                    gpa,
                    skill
                );

                hashTable.insert(s);
                avl.insert(s);

                history.push("Estudiante agregado");

                cout << "\nEstudiante agregado\n";

                break;
            }

            case 8: {

                int id;

                cout << "\nID a eliminar: ";
                cin >> id;

                hashTable.remove(id);

                history.push("Estudiante eliminado");

                break;
            }

            case 9: {

                cout << "\nTotal estudiantes: "
                     << hashTable.countStudents()
                     << endl;

                break;
            }

            case 10: {

                cout << "\nPromedio GPA: "
                     << hashTable.averageGPA()
                     << endl;

                break;
            }

            case 11: {

                Student* best = hashTable.getBestStudent();

                if(best != nullptr) {

                    cout << "\nMejor estudiante:\n";
                    cout << best->full_name << endl;
                    cout << "GPA: " << best->gpa << endl;
                }

                break;
            }

            case 12: {

                Student* worst = hashTable.getWorstStudent();

                if(worst != nullptr) {

                    cout << "\nPeor estudiante:\n";
                    cout << worst->full_name << endl;
                    cout << "GPA: " << worst->gpa << endl;
                }

                break;
            }

            case 13: {

                hashTable.benchmark();
                break;
            }

            case 14: {

                int id;
                string name;
                string career;
                int semester;
                float gpa;
                int skill;

                cout << "\nID: ";
                cin >> id;

                cin.ignore();

                cout << "Nuevo nombre: ";
                getline(cin, name);

                cout << "Nueva carrera: ";
                getline(cin, career);

                cout << "Nuevo semestre: ";
                cin >> semester;

                cout << "Nuevo GPA: ";
                cin >> gpa;

                cout << "Nuevo Skill Score: ";
                cin >> skill;

                hashTable.update(
                    id,
                    name,
                    career,
                    semester,
                    gpa,
                    skill
                );

                history.push("Estudiante actualizado");

                break;
            }

            case 15: {

                int student_id;
                int project_id;
                string title;
                string description;
                int year;

                cout << "\nID estudiante: ";
                cin >> student_id;

                cout << "ID proyecto: ";
                cin >> project_id;

                cin.ignore();

                cout << "Titulo: ";
                getline(cin, title);

                cout << "Descripcion: ";
                getline(cin, description);

                cout << "Anio: ";
                cin >> year;

                hashTable.addProject(
                    student_id,
                    project_id,
                    title,
                    description,
                    year
                );

                history.push("Proyecto agregado");

                break;
            }

            case 16: {

                int id;

                cout << "\nID estudiante: ";
                cin >> id;

                hashTable.showProjects(id);

                break;
            }

            case 17: {

                history.display();
                break;
            }

            case 18: {

                hashTable.generateCSVBenchmark();

                break;
            }

            case 19: {

                cout << "\n===== ESTADISTICAS =====\n";

                cout << "Total estudiantes: "
                     << hashTable.countStudents()
                     << endl;

                cout << "Colisiones hash: "
                     << hashTable.getCollisions()
                     << endl;

                cout << "Factor carga: "
                     << hashTable.getLoadFactor()
                     << endl;

                break;
            }

            case 20: {

                cout << "\nSaliendo...\n";
                break;
            }

            default: {

                cout << "\nOpcion invalida\n";
            }
        }

    } while(option != 20);

    return 0;
}