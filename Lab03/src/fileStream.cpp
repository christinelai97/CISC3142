//contains functions for reading and writing input and output files

#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <stdio.h>
#include <map>
#include <set>
#include <ctime>
#include <sstream>

#include "dataset.cpp"

using namespace std;

//read function reads in files and produces dataset from collected data
dataset read() {

    ifstream inputFileStream;

    //vector of files to be read
    vector<string> files = findCSV();

    //initializes dataset
    dataset newDataset;

    //loops through files length
    for (string file : files) {

        inputFileStream.open(file);

        if (inputFileStream.good()) {
            string fileField;
            inputFileStream >> fileField;
            stringstream field (fileField);
            string fieldItem;

            //initializes number of fields to 0
            int numOfFields = 0;

            while (getline(field, fieldItem, ',')) {
                numOfFields++;
            }

            //throws runtime error is number of fields is not equal to 6
            if (numOfFields != 6) {
                throw runtime_error ("Error: An Error Occured with the input files");
            }

            string lines;
            string studentID;
            string courseNum;
            string instructorID;
            string termID;
            string sectionID;
            string letterGrade;

            while (inputFileStream >> lines) {

                //each line's delimited contents are streamed to appropriate var
                stringstream line (lines);
                getline(line, studentID, ',');
                getline(line, courseNum, ',');
                getline(line, instructorID, ',');
                getline(line, termID, ',');
                getline(line, sectionID, ',');
                getline(line, letterGrade);


                string classID = termID + '.' + courseNum + '.' + sectionID;

                //fetches data from dataset
                section* isSection = newDataset.sectionAccessor(classID);
                term* isTerm = newDataset.termAccessor(termID);

                set<string> spring_terms = {"T04", "T07", "T09", "T12", "T15", "T17"};

                //only adds new sections from dataset
                if(!isSection) {
                    isSection = new section (classID, courseNum, sectionID, instructorID, termID);
                    newDataset.addCourse(classID, isSection);
                }

                //only adds new terms from dataset
                if(!isTerm) {
                    isTerm = new term(termID, classID, spring_terms.count(termID));
                    newDataset.addTerm(termID, isTerm);
                }

                //adds studentID from section
                isSection->addStudent(studentID);
                isTerm->addCourse(classID);

                //adds student and instructor to dataset
                newDataset.addStudent(studentID, classID, letterGrade);
                newDataset.addInstructor(instructorID, classID);
            }
        }
        //closes input file stream
        inputFileStream.close();
    }

    //returns the new dataset
    return newDataset;
}

//writing functions follow:
FILE* outputFile;
ofstream outputFileStream;

//function returns current timestamp
string timestamp() {

   time_t givemetime = time(NULL);

    //currentime() returns given time
    string currentTime = ctime(&givemetime);
   return currentTime;
}

//writing function for instructor pass rate
void printInstructorePassRate(map<string, vector<double>>* instructorPassRate) {

    string outputFilePath = "../output/instructor-passing-rate( " + timestamp() + ").txt";

    const char * fileName = outputFilePath.c_str();
    outputFile = fopen(fileName, "w");

    // outputfile formatting
    fprintf(outputFile, "Instructor Passing Rate: \n\n");
    fprintf(outputFile, "%10s: %13s Count / (Total):          Pass Rate:\n", "Instructor ID", "Passing");
    for (const auto& i : *instructorPassRate) {

        float ratio = (i.second[0]/i.second[1]*100); // calculation for rate to be printed

        fprintf(outputFile, "%s %20d           / %5d %19.2f %% \n",
        i.first.c_str(), int (i.second[0]), int (i.second[1]), ratio); // data is listed accordinglyß
    }
    fclose(outputFile);
}

// writing function for instructor withdrawal rate
void printInstructoreWithdrawalRate(map<string, vector<double>>* instructorWithdrawalRate) {

    string outputFilePath = "../output/instructor-withdrawal-rate( " + timestamp() + ").txt";

    const char * fileName = outputFilePath.c_str();
    outputFile = fopen(fileName, "w");

    // outputfile formatting
    fprintf(outputFile, "Instructor Withdrawal Rate: \n\n");
    fprintf(outputFile, "%10s: %13s Count / (Total):          Pass Rate:\n", "Instructor ID", "Withdrawal");
    for (const auto& i : *instructorWithdrawalRate) {


        float ratio = (i.second[0]/i.second[1]*100); // calculation for rateto be printed

        fprintf(outputFile, "%s %20d           / %5d %19.2f %% \n",
        i.first.c_str(), int (i.second[0]), int (i.second[1]), ratio); // data is listed accordinglyß
    }
    fclose(outputFile);
}

// writing function for course pass rate
void printCoursePassRate(map<string, vector<double>>* coursePassRate) {

    string outputFilePath = "../output/course-passing-rate( " + timestamp() + ").txt";

    const char * fileName = outputFilePath.c_str(); // back to C string
    outputFile = fopen(fileName, "w"); // open new file for writing

    // outputfile formatting
    fprintf(outputFile, "Course Passing Rate: \n\n");
    fprintf(outputFile, "%10s: %13s Count / (Total):          Pass Rate:\n", "Instructor ID", "Passing");
    for (const auto& i : *coursePassRate) {

        float ratio = (i.second[0]/i.second[1]*100); // calculation for rate to be printed

        fprintf(outputFile, "%s %20d          / %5d %19.2f %% \n",
        i.first.c_str(), int (i.second[0]), int (i.second[1]), ratio); // data is listed accordinglyß
    }
    fclose(outputFile);
}

// writing function for course withdrawal rate
void printCourseWithdrawalRate(map<string, vector<double>>* courseWithdrawalRate) {

    string outputFilePath = "../output/course-withdrawal-rate( " + timestamp() + ").txt";

    const char * fileName = outputFilePath.c_str(); // back to C string
    outputFile = fopen(fileName, "w"); // open new file for writing

    // outputfile formatting
    fprintf(outputFile, "Course Withdrawal Rate: \n\n");
    fprintf(outputFile, "%10s: %13s Count / (Total):          Pass Rate:\n", "Instructor ID", "Withdrawal");
    for (const auto& i : *courseWithdrawalRate) {

        float ratio = (i.second[0]/i.second[1]*100); // calculation for rate to be printed

        fprintf(outputFile, "%s %20d          / %5d %19.2f %% \n",
        i.first.c_str(), int (i.second[0]), int (i.second[1]), ratio); // data is listed accordinglyß
    }
    fclose(outputFile);
}

// writing function for spring vs fall
void printTermComparison(map<string, vector<double>>* termComparison) {

    string outputFilePath = "../output/spring-vs-fall( " + timestamp() + ").txt";

    const char * fileName = outputFilePath.c_str(); // back to C string
    outputFile = fopen(fileName, "w"); // open new file for writing

    // outputfile formatting
    fprintf(outputFile, "Spring vs Fall Semester: \n\n");
    fprintf(outputFile, "%s: %13s Count / (Total):          Pass Rate:\n", "Term", "Passing");
    for (const auto& i : *termComparison) {

        float ratio = (i.second[0]/i.second[1]*100); // calculation for rate to be printed

        fprintf(outputFile, "%2s %13d          / %5d %19.2f %% \n",
        i.first.c_str(), int (i.second[0]), int (i.second[1]), ratio); // data is listed accordinglyß
    }
    fclose(outputFile);
}
