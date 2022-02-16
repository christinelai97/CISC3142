lab1:
	 cd Lab1 && g++ file_in.cpp -o file_in.o -std=c++98 && ./file_in
clean: 
	cd Lab1 && rm output.txt
