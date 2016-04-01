#include<iostream>
#include<vector>
using namespace std;

class Sudoku{
	public:
		void giveQuestion();
		void readIn();
		void solve();
		int checkRow(int num,int n);
		int checkCol(int num,int n);
		int checkBlock(int num,int n);
		void changeNum(int a,int b);
		void changeRow(int a,int b);
		void changeCol(int a,int b);
		void rotate(int n);
		void flip(int n);
		void transform();
		void change();
		void printOut();

	private:
		int ques[82];
		int in[82];
		int fp[82];
		int map[82];
};
