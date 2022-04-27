//contains function definitions of dataset class

#include <filesystem>
#include "dataset.h"



//address of data values in main dataset
map<string, student*>* dataset::addressOfStudents() {
    return &students;
}
map<string, section*>* dataset::addressOfCourses() {
    return &courses;
}
map<string, instructor*>* dataset::addressOfInstructors() {
    return &instructors;
}
map<string, term*>* dataset::addressOfTerms() {
    return &terms;
}


//accessors for retrieving data values
student* dataset::studentAccessor(string studentID) {
        return students[studentID];
}

section* dataset::sectionAccessor(string classID) {
    return courses[classID];
}

instructor* dataset::instructorAccessor(string instructorID) {
    return instructors[instructorID];
}

term* dataset::termAccessor(string termID) {
    return terms[termID];
}

// method to add new students
void dataset::addStudent(string studentID, string course, string letterGrade) {

    //only adds new students into dataset
    if (!students.count(studentID)) {
        student* s = new student(studentID, course, letterGrade);
        students[studentID] = s;
    } else {
        students[studentID]->addCourse(course, letterGrade);
    }
}

// method to add instructor
void dataset::addInstructor(string instructorID, string course) {

    //only adds new instructors to dataset
    if (!instructors.count(instructorID)) {
        instructor* s = new instructor(instructorID, course);
        instructors[instructorID] = s;
    } else {
        instructors[instructorID]->addCourse(course);
    }
}

// method to add course and term
void dataset::addCourse(string course, section* isSection) {

    courses[course] = isSection;
}

void dataset::addTerm(string termID, term* term) {

    terms[termID] = term;
}

// locates files with .csv extension in data subdirectory
using std::__fs::filesystem::directory_iterator;
vector<string> findCSV() {

    vector<string> csvFiles;
    string fileExtension = ".csv";
    for (const auto& file : directory_iterator("../data/")) {

        if (file.path().extension().string() == fileExtension)

            csvFiles.push_back(file.path());
    }
    return csvFiles;
}
