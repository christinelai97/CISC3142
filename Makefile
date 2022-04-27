lab1:
		cd Lab01 && g++ file_in.cpp -o file_in -std=c++98 && ./file_in

lab2:
		cd Lab02 && g++ Calculator.cpp -std=c++11 -o Calculator && ./Calculator
lab3:
		cd ./Lab03/src/ && g++ dataset.cpp -c -std=c++11
		cd ./Lab03/src/ && g++ fileStream.cpp -c -std=c++11
		cd ./Lab03/src/ && g++ mainFunctions.cpp -c -std=c++11
		cd ./Lab03/src/ && g++ main.cpp -o main -std=c++11 && ./main