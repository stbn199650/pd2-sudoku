#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
#include"lab2.h"

int main(){

	int cm,kg;
	data dt;

	ifstream inFile("file.in",ios::in);		//read file
	ofstream outFile("file.out",ios::out);		//write file
	if(!inFile || !outFile){
		cerr << "open file failed" << endl;
		exit(1);
	}

	while(inFile >> cm >> kg){
		
		outFile << dt.BMI(cm,kg) << "\t" << dt.category(dt.BMI(cm,kg)) << endl;
	}
	
	


return 0;
}
