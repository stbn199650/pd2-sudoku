#include<iostream>
#include"Sudoku.h"
using namespace std;

int main(){
	Sudoku ss;
	ss.readIn();
//	ss.rotate(83);
//	ss.flip(1);
//	ss.changeNum(3,6);
//	ss.changeRow(0,2);
//	ss.changeCol(0,2);
	ss.solve();
	return 0;
}

