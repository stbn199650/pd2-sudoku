#include<iostream>
#include<ctime>
#include<cstdlib>
#include"Sudoku.h"
using namespace std;

void Sudoku::readIn(){
	for(int i=0;i<81;i++){
		cin>>in[i];
	}
}
void Sudoku::solve(){

	int out[82]={0};
	solve1();
	if(add==2){goto print;}
	if(out[0]==0){
		cout<<endl<<"0"<<endl<<endl;
		goto print;
	}
print:
	if(add==1){cout<<endl<<"1"<<endl;
		for(int i=0;i<81;i++){
				cout<<out[i];
				(i%9)==8?cout<<endl:cout<<' ';
			}
		}
}
void Sudoku::solve1(){
	int count=0;
	for(int i=0;i<81;i++){
		if(in[i]==0){count++;}
	}
	if(count==0){
		add++;
		if(add>=2){
			cout<<"2.many answer"<<endl;
			return;
		}
		for(int i=0;i<81;i++){out[i]=in[i];}
		return;
	}
	for(int i=0;i<81;i++){
		if(in[i]==0){
			for(int k=1;k<10;k++)
				if(checkRow(i,k)==1 && checkCol(i,k)==1 && checkBlock(i,k)==1){
					in[i]=k;
					solve1();
					in[i]=0;
				}if(add==2){return;}
		}return;
	}
}

int Sudoku::findzero(int n){
	for(int i=0;i<81;i++)
		if(in[i]==0)
			return 1;
	return 0;
}
int Sudoku::checkRow(int num,int n){    //num:第幾個  n:1~9
	int k=num/9,row=9*k;
	for(int i=0;i<9;i++){
		if((in[row+i]==n) && ((row+i)!=num))
			return 0;
	}
	return 1;
}
int Sudoku::checkCol(int num,int n){
	int col=num%9,k;
	for(int i=0;i<9;i++){
		k=i*9+col;
		if((in[k]==n) && (k!=num))
			return 0;
	}
	return 1;
}
int Sudoku::checkBlock(int num,int n){
	int row=num/9,col=num%9;
	int k,l,m,p;
		if(row<=2){l=0;}
		else if(row<=5){l=1;}
		else{l=2;}

		if(col<=2){m=0;}
        else if(col<=5){m=1;}
        else{m=2;}

		k=27*l+3*m;     //block 左上角的數字

		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				p=k+9*i+j;
				if(in[p]==n && p!=num){
					return 0;
				}
			}
		}
	return 1;

}

