// This file shows basic functions of reading in a CSV file using C++98
//Christine Lai

/* Homework Objective: fix this program to match the requirements listed:
  1. successfully reads all lines of the input file
  2. calculate the average price per brand, average price per category
  3. writes to an output file
  4. for each unique year, list the count of skus and also print out the skus as a list i.e. 2000 (3): 111, 211, 311 and make a new line per year.
All programs must be able to compile in C++98 standard (the default version on Linux Machine). That means you cannot use the new features of C++11! :(
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <iterator>
#include <map>
#include <numeric>

using namespace std;

int main() {

    //vector variables
    vector<int>vSKU;
    vector<string>vBrand;
    vector<string>vCategory;
    vector<int>vYear;
    vector<float>vPrice;

    //variables for reading & writing data from file
    ifstream in_stream;
    ofstream out_stream;

    //openign the input and output files
    in_stream.open("data.csv");
    out_stream.open("file_out.txt");


    if (!in_stream.fail()) {


        string line; //variable for current line being read


        getline(in_stream,line);


        while (getline(in_stream, line)) { //loops until the end of file


            //loop removes commas from the current line
            for(int i = 0; i < line.length(); i++)  {

                if(line[i] == ',')    {
                    line[i] = ' ';
                }
            }

            //stores information from line into dataLine
            stringstream dataLine(line);


            //declaring variables for storing values from each line
            int iSKU;
            dataLine >> iSKU; //stored in dataline
            vSKU.push_back(iSKU); //value is stored in vector

            string brand;
            dataLine >> brand;
            vBrand.push_back(brand); //value stored in vector

            string category;
            dataLine >> category;
            vCategory.push_back(category); //stored in vector

            int iYear;
            dataLine >> iYear;
            vYear.push_back(iYear); //stored in vector

            float fPrice;
            dataLine >> fPrice;
            vPrice.push_back(fPrice); //stored in vector
        }


        //input file is closed
        in_stream.close();
    }

    else {

        out_stream << "Unable to open file";
    }

    //output values
    cout << "SKU" << "\t" << "Brand" << "\t" << "Year" << endl;

    for (int j = 0; j < vSKU.size(); j++) {
    cout << vSKU[j] << "\t" << vBrand[j] << "\t" << vYear[j] << endl;
  }

  cout << endl;

    //writing output file
    out_stream << "SKU" << "\t" << "Brand" << "\t" << "Category" << "\t" << "Year" << "\t" << "Price" << endl;

    //loops through rows and writes to output file
    for (int j = 0; j < vSKU.size(); j++) {
            out_stream << vSKU[j] << "\t" << vBrand[j] << "\t   " << vCategory[j] << "\t\t\t\t" << vYear[j] << "\t" << vPrice[j] << endl;
    }

    out_stream << endl;

    map<string,vector<float> > brand_mapping; //declaring map for brand price

    // loop for storing brand price into map
    for(int i = 0; i < vBrand.size(); i++)  {
        brand_mapping[vBrand[i]].push_back(vPrice[i]);
    }

    //output file header
    out_stream << "Brand\tAverage\n";

    //map iterator for brand
    map<string,vector<float> >::iterator i;

    //loops through map  in order to find average price per brand
    for(i = brand_mapping.begin(); i != brand_mapping.end(); ++i)  {

        string brandCurrent = i->first; //current brand

        vector<float> priceCurrent = i->second; //current price

        float sum = accumulate(priceCurrent.begin(), priceCurrent.end(),0.0); //calculating brand sum by price

        float brandAverage = sum / priceCurrent.size(); //calculating average per brand

        //prints information onto output file
        out_stream << brandCurrent << "\t\t" << brandAverage << "\n";
    }
    out_stream << endl; //newline on output file

    map<string,vector<float> > category_mapping; //declaring map for category price

    //loop for storing category price in map
    for(int i = 0; i < vCategory.size(); i++) {
        category_mapping[vCategory[i]].push_back(vPrice[i]);
    }

    //Output file headers
    out_stream << "Category\tAverage\n";

    //map iterator for category
    map<string,vector<float> >::iterator j;

    //loops through category map in order to find average price per category
    for(j = category_mapping.begin(); j != category_mapping.end(); j++)  {

        string curCategory = j->first; //current category

        vector<float> curPrices = j->second; //current price for category

        float brandSum = accumulate(curPrices.begin(), curPrices.end(),0.0); //calculating category sum by price

        float average = brandSum / curPrices.size(); //calculating average price  per category

        //prints information onto output file
        out_stream << curCategory << "\t\t\t\t\t" << average << "\n";
    }
    out_stream << endl; //newline on output file

    map<int,vector<int> > year_mapping; //declaring map for year and skus

    for(int i = 0; i < vYear.size(); i++) {
        year_mapping[vYear[i]].push_back(vSKU[i]);
    }

    //output file header for SKUs
    out_stream << "Year\tSKU's\n";

    // Declaring map iterator for year
    map<int,vector<int> >::iterator k;

    // Iterating over the map
    for(k = year_mapping.begin(); k != year_mapping.end(); k++) {

        // Writing the year to the output file
        out_stream << k->first << "\t";

        // iterator for the vector of the current year
        vector<int>::iterator sku_k;

        //loops through SKUS for a given year
        for(sku_k = k->second.begin(); sku_k != k->second.end(); sku_k++) {

            //Prints the sku to output file
            out_stream << *sku_k;

            //provides space if a year has more SKUS
            if(sku_k != k->second.end()) {
                out_stream << " ";
            }

            else {
                out_stream << "\t";
            }
        }
        //Prints the total number of SKUS each year
        out_stream << "| Total: " << k->second.size() << endl;
    }

    //closing output file
    out_stream.close();
}

