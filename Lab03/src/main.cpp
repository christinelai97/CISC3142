// Christine Lai
//
// This program is designed to read in files from the data subdirectory
// and generate a report that shows for each instructor, course, and term;
// which will be posted onto the output directory with a given timestamp
//
// The program contains user-defined structs(student, instructor, term, section) in structures.h
// for each field in CSV files (emplid,courseno,instructorid,termid,sectionid),
// fileStream.cpp is used for reading and writing the input and output files,
// while dataset.cpp contains the function definitions for the dataset class,

#include "mainFunctions.cpp"

int main () {

   dataset csCourse = read();

    //mapping of data for the outputfile reports
    map<string, vector<double>> instructorPassingRate = instructorRate(&csCourse, &isPassingLetterGrade);
    map<string, vector<double>> instructorWithdrawalRate = instructorRate(&csCourse, &isWithdrawnLetterGRade);
    map<string, vector<double>> coursePassingRate = courseRate(&csCourse, &isPassingLetterGrade);
    map<string, vector<double>> courseWithdrawalRate = courseRate(&csCourse, &isWithdrawnLetterGRade);
    map<string, vector<double>> termComparison = termRate(&csCourse, &isPassingLetterGrade);

    //prints reports of the input files onto output directory
    printInstructorePassRate(&instructorPassingRate);
    printInstructoreWithdrawalRate(&instructorWithdrawalRate);
    printCoursePassRate(&coursePassingRate);
    printCourseWithdrawalRate(&courseWithdrawalRate);
    printTermComparison(&termComparison);
	cout << "Report successfully generated in output folder!" << endl;


    return 0;
}
