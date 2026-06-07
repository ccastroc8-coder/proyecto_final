public class Student {

    int student_id;

    String full_name;

    String career;

    int semester;

    float gpa;

    int skill_score;

    public Student(int student_id,
                   String full_name,
                   String career,
                   int semester,
                   float gpa,
                   int skill_score) {

        this.student_id = student_id;

        this.full_name = full_name;

        this.career = career;

        this.semester = semester;

        this.gpa = gpa;

        this.skill_score = skill_score;
    }
}