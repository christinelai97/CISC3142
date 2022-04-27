//contains dataset class

#include <iostream>
#include "structures.h"


class dataset {

    map<string, student*> students;
    map<string, section*> courses;
    map<string, instructor*> instructors;
    map<string, term*> terms;

    public:
    dataset() {};

    // map pointing the address of data inputs
    map<string, student*>* addressOfStudents();
    map<string, section*>* addressOfCourses();
    map<string, instructor*>* addressOfInstructors();
    map<string, term*>* addressOfTerms();

    // dataset accessors
    student* studentAccessor(string studentID);
    section* sectionAccessor(string classID);
    instructor* instructorAccessor(string instructorID);
    term* termAccessor(string termID);

    // methods for adding new data inputs
    void addStudent(string studentID, string course, string letterGrade);
    void addInstructor(string instructorID, string course);
    void addCourse(string course, section* isSection);
    void addTerm(string termID, term* term);



};
