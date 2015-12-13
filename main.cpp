#include <iostream>
#include <fstream>
#include <string>
#include "Pythagorean.h"
int main(){
	Pythagorean py;
	std::string fileName;
	int maxSideLen;
	std::cout << "Max side length: ";
	// enter maxSideLen
	if((std::cin >> maxSideLen)){
		//std::cin.get();
		// save to file or not
		std::cout << "Save to file (*.txt)?\n"
			<< "Enter a filename(no spaces) to save\n"
            << "Or input \"no\" to display on the screen: ";
        std::cin >> fileName;   // get fileName
        if(fileName.length() != 0 && fileName != "no" && fileName != "n"){ // succeed to open fileName, save
			fileName += ".txt";
			std::fstream fout(fileName.c_str(), std::ios_base::in|std::ios_base::out|std::ios_base::trunc);
			if(fout.is_open()){
				py(maxSideLen, fout);
				std::cout << "Save to file. Please check " << fileName << "\n";
			}
			else{   // fail to open fileName, display on the screen
				py(maxSideLen);
				std::cout << "fail to open " << fileName << "\n";
				std::cout << "Display on the screen.\n";
			}
		}
		else{   // if no fileName input
			py(maxSideLen);
			std::cout << "Display on the screen.\n";
		}
	}
	else{   // error in inputing MaxSideLen
		std::cin.clear();
		py(100, std::cout);
		std::cout << "Error. Display sample. MaxSideLen = 100\n";
	}
	
	std::cout << "bye!\n";
	return 0;
}
