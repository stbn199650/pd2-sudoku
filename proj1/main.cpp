#include<iostream>
#include"Sudoku.h"
using namespace std;

int main(){
	Sudoku ss;
//	ss.giveQuestion();
	ss.readIn();
	ss.solve();
//	ss.changeRow(1,2);
//	ss.changeCol(1,2);
//	ss.flip(1);
//	ss.rotate(3);
//	ss.changeNum(2,6);

	return 0;
}
