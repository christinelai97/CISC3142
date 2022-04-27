// The program contains user-defined structs(student, instructor, term, section)

#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

// student structure
struct student {
    string studentID;
    map<string, string> classes;

    student(string studentID, string course, string letterGrade) {
        this->studentID = studentID;
        classes[course] = letterGrade;
    }

    void addCourse(string course, string letterGrade) {
        classes[course] = letterGrade;
    }
};

//instructor structure
struct instructor {

    //instructor's id
    string instructorID;
    //set of courses instructor is teaching
    set<string> classes;

    instructor (string instructorID, string course) {
        this->instructorID = instructorID;
        classes.insert(course);
    }

    void addCourse(string course) {
        classes.insert(course);
    }
};

//structure for term
struct term {

    //term's id
    string termID;
    // boolean for spring semester
    bool isSpring;
    //set of courses in that term
    set<string> courses;

    term() {}


    //points to
    term (string termID, string course, bool isSpring) {
        (*this).termID = termID;
        (*this).isSpring = isSpring;
        courses.insert(course);
    }

    void addCourse(string course) {
        courses.insert(course);
    }

};

// contains values for courseno field, sectionid field, instructorid field, termid field, and emplid field
struct section {
    string classID;
    string courseNum;
    string sectionID;
    string instructorID;
    string term;
    vector<string> students;

    section(string classID, string courseNum, string sectionID, string instructorID, string term) {
        this->classID = classID;
        this->courseNum = courseNum;
        this->sectionID = sectionID;
        this->instructorID = instructorID;
        this->term = term;
    }

    void addStudent(string studentID) {
        students.push_back(studentID);
    }
};
