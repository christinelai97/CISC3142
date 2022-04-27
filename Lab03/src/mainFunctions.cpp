// contains function definitions used in main.cpp

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <map>

#include "fileStream.cpp"

using namespace std;


  // function returns the passing rate of instructor
   map<string, vector<double>> instructorRate(dataset* csCourse, bool (*criterion)(string)) {
       double counter;
       double sum;
       double studentSum = 0;
       vector<double> passingRate;

       map<string, vector<double>> instructorPassingRate;
       map<string, section*>* courses = (*csCourse).addressOfCourses();
       map<string, student*>* students = (*csCourse).addressOfStudents();
       map<string, instructor*>* instructors = (*csCourse).addressOfInstructors();

       for(const auto& i : *instructors) {
           counter = 0;
           sum = 0;
           passingRate = {};
           for (const auto& c : i.second->classes) {
               for(string s : courses->at(c)->students) {
                   counter += criterion(students->at(s)->classes[c]);
                   sum++;
               }
           }
           passingRate.push_back(counter);
           passingRate.push_back(sum);
           passingRate.push_back(double (counter)/sum);
           instructorPassingRate[i.first] = passingRate;
           studentSum += sum;
       }
       return instructorPassingRate;
   }

//function returns the passing rate of course
map<string, vector<double>> courseRate(dataset* csCourse, bool (*criterion)(string)) {
    double counter;
    double sum;
    double studentSum = 0;
    string courseNum;
    vector<double> counter_rate;

    map<string, vector<double>> coursePassingRate;
    map<string, section*>* courses = (*csCourse).addressOfCourses();
    map<string, student*>* students = (*csCourse).addressOfStudents();

    // computes the number of students who passed or withdrawn from the course
    for(const auto& c : *courses) {
        counter = 0;
        sum = 0;
        counter_rate = {};
        courseNum = c.second->courseNum;
        for (const auto& s : c.second->students) {
            counter += criterion(students->at(s)->classes.at(c.first));
            sum++;
        }

        if(coursePassingRate.count(courseNum)) {
            coursePassingRate[courseNum][0] += counter;
            coursePassingRate[courseNum][1] += sum;
        } else {
            counter_rate.push_back(counter);
            counter_rate.push_back(sum);
            coursePassingRate[courseNum] = counter_rate;
        }
        studentSum += sum;
    }

    // contains course numbers
    vector<string> courseNums = {"1115", "3115", "3130"};

    for (string s : courseNums) {
        coursePassingRate[s].push_back(coursePassingRate[s][0] / coursePassingRate[s][1]);
    }

    return coursePassingRate;
}



// function returns the passing rate of each term
map<string, vector<double>> termRate (dataset* csCourse, bool (*criterion)(string)) {
    double springCounter = 0;
    double springSum = 0;
    double fallCounter = 0;
    double fallSum = 0;
    double studentSum = 0;
    vector<double> passingRate;
    map<string, vector<double>> termPassingRate = {
        {"Spring", {0, 0, 0}},
        {"Fall", {0, 0, 0}}
    };

    // vector<string> courseNums = {"1115", "3115", "3130"};

    map<string, section*>* courses = (*csCourse).addressOfCourses();
    map<string, student*>* students = (*csCourse).addressOfStudents();
    map<string, term*>* terms = (*csCourse).addressOfTerms();

    for(const auto& i : *terms) {
        passingRate = {};
        for (string c : i.second->courses) {
            for(string s : courses->at(c)->students) {
                if (i.second->isSpring) {
                    springCounter += criterion(students->at(s)->classes[c]);
                    springSum++;
                } else {
                    fallCounter += criterion(students->at(s)->classes[c]);
                    fallSum++;
                }
                studentSum++;
            }
        }
    }

    //assigns values to designated place in map
    termPassingRate["Spring"][0] = springCounter;
    termPassingRate["Spring"][1] = springSum;
    termPassingRate["Spring"][2] = springCounter/springSum;

    termPassingRate["Fall"][0] = fallCounter;
    termPassingRate["Fall"][1] = fallSum;
    termPassingRate["Fall"][2] = fallCounter/fallSum;

    return termPassingRate;
}

// boolean for passing letter grade
bool isPassingLetterGrade(string letterGrade) {
    set<string> passing = {"A+", "A", "A-", "B+", "B", "B-", "C+", "C", "CR", "C-", "D+", "D", "D-", "P"};
    return passing.count(letterGrade);
}
// boolean for withdrawn letter grade
bool isWithdrawnLetterGRade(string letterGrade) {
    set<string> withdrawals = {"W", "WN", "WD", "WU"};
    return withdrawals.count(letterGrade);
}
