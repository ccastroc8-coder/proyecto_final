import java.io.*;

class Node {

    Student data;

    Node next;

    public Node(Student data) {

        this.data = data;

        this.next = null;
    }
}

public class HashTable {

    int SIZE = 10;

    Node[] table;

    public HashTable() {

        table = new Node[SIZE];
    }

    public int hashFunction(int id) {

        return id % SIZE;
    }

    public boolean exists(int id) {

        int index =
        hashFunction(id);

        Node temp =
        table[index];

        while(temp != null) {

            if(temp.data.student_id == id) {

                return true;
            }

            temp = temp.next;
        }

        return false;
    }

    public void insert(Student student) {

        int index =
        hashFunction(student.student_id);

        Node newNode =
        new Node(student);

        if(table[index] == null) {

            table[index] = newNode;
        }

        else {

            Node temp =
            table[index];

            while(temp.next != null) {

                temp = temp.next;
            }

            temp.next = newNode;
        }
    }

    public void loadCSV(String filename) {

        try {

            BufferedReader br =
            new BufferedReader(
            new FileReader(filename));

            String line;

            while((line = br.readLine())
                   != null) {

                String[] data =
                line.split(",");

                int id =
                Integer.parseInt(data[0]);

                String nombre =
                data[1];

                String carrera =
                data[2];

                int semestre =
                Integer.parseInt(data[3]);

                float gpa =
                Float.parseFloat(data[4]);

                int skill =
                Integer.parseInt(data[5]);

                Student student =
                new Student(
                id,
                nombre,
                carrera,
                semestre,
                gpa,
                skill);

                insert(student);
            }

            br.close();

            System.out.println(
            "\nCSV cargado correctamente");
        }

        catch(Exception e) {

            System.out.println(
            "\nERROR REAL:");

            e.printStackTrace();
        }
    }

    public void remove(int id) {

        int index =
        hashFunction(id);

        Node temp =
        table[index];

        Node prev = null;

        while(temp != null &&
              temp.data.student_id != id) {

            prev = temp;

            temp = temp.next;
        }

        if(temp == null) {

            System.out.println(
            "\nEstudiante no encontrado");

            return;
        }

        if(prev == null) {

            table[index] =
            temp.next;
        }

        else {

            prev.next =
            temp.next;
        }

        System.out.println(
        "\nEstudiante eliminado correctamente");
    }

    public void update(
        int id,
        String nombre,
        String carrera,
        int semestre,
        float gpa,
        int skill
    ) {

        int index =
        hashFunction(id);

        Node temp =
        table[index];

        while(temp != null) {

            if(temp.data.student_id == id) {

                temp.data.full_name =
                nombre;

                temp.data.career =
                carrera;

                temp.data.semester =
                semestre;

                temp.data.gpa =
                gpa;

                temp.data.skill_score =
                skill;

                System.out.println(
                "\nEstudiante actualizado");

                return;
            }

            temp = temp.next;
        }

        System.out.println(
        "\nEstudiante no encontrado");
    }

    public int countStudents() {

        int count = 0;

        for(int i = 0; i < SIZE; i++) {

            Node temp =
            table[i];

            while(temp != null) {

                count++;

                temp = temp.next;
            }
        }

        return count;
    }

    public float averageGPA() {

        float sum = 0;

        int count = 0;

        for(int i = 0; i < SIZE; i++) {

            Node temp =
            table[i];

            while(temp != null) {

                sum += temp.data.gpa;

                count++;

                temp = temp.next;
            }
        }

        if(count == 0) {

            return 0;
        }

        return sum / count;
    }

    public void display() {

        System.out.println(
        "\n===== HASH TABLE =====");

        for(int i = 0; i < SIZE; i++) {

            System.out.print(
            "\nBucket " + i + ": ");

            Node temp =
            table[i];

            while(temp != null) {

                System.out.print(
                "[" +
                temp.data.student_id +
                " - " +
                temp.data.full_name +
                "] -> ");

                temp = temp.next;
            }

            System.out.print("NULL");
        }

        System.out.println();
    }

    public void search(int id) {

        int index =
        hashFunction(id);

        Node temp =
        table[index];

        while(temp != null) {

            if(temp.data.student_id == id) {

                System.out.println(
                "\n===== ESTUDIANTE =====");

                System.out.println(
                "ID: " +
                temp.data.student_id);

                System.out.println(
                "Nombre: " +
                temp.data.full_name);

                System.out.println(
                "Carrera: " +
                temp.data.career);

                System.out.println(
                "Semestre: " +
                temp.data.semester);

                System.out.println(
                "GPA: " +
                temp.data.gpa);

                System.out.println(
                "Skill Score: " +
                temp.data.skill_score);

                return;
            }

            temp = temp.next;
        }

        System.out.println(
        "\nEstudiante no encontrado");
    }
}