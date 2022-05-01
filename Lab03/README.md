This program is designed to read in files from the data subdirectory
and generate a report that shows for each instructor, course, and term;
which will be posted onto the output directory with a given timestamp
The program contains user-defined structs(student, instructor, term, section) in structures.h
for each field in CSV files (emplid,courseno,instructorid,termid,sectionid),
fileStream.cpp is used for reading and writing the input and output files,
while dataset.cpp contains the function definitions for the dataset class.

