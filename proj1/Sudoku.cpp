#include<iostream>
#include<cstdlib>
#include<ctime>
#include"Sudoku.h"
using namespace std;

void Sudoku::giveQuestion(){
	
	int n;
	int hole[60];
	int ques[82]={8,4,2,1,3,5,6,7,9,6,1,9,2,7,8,4,3,5,
		7,3,5,4,6,9,1,8,2,1,2,4,6,5,7,8,9,3,5,7,8,3,9,4,2,6,1,
		3,9,6,8,2,1,5,4,7,4,5,1,7,8,3,9,2,6,2,8,3,9,1,6,7,5,4,
		9,6,7,5,4,2,3,1,8};

	srand(time(NULL));
	n=rand()%11+40;		//the amounts of the hole
	count=81-n;		//how many zero
	for(int i=0;i<n;i++){
		hole[i]=rand()%81;		//decide which number of the hole is 0
		for(int j=0;j<i;j++){
			if(hole[i]==hole[j]){i--;break;}	//if the number same,reproduce
		}
	}
	for(int i=0;i<n;i++){	//dig hole
		ques[hole[i]]=0;
	}
	for(int i=0;i<81;i++){
		cout << ques[i];
		(i%9)==8?cout<<endl:cout<<' ';
	}
}
void Sudoku::readIn(){
	for(int i=0;i<81;i++)
		cin>>in[i];
}
void Sudoku::solve(){
	int num[82];
	for(int i=0;i<81;i++){map[i]=in[i];}
	for(int i=0;i<81;i++){num[i]=1;}
	for(int i=0;i<81;i++){
		if(in[i]==0){
			for(int k=num[i];k<10;k++){
				if(checkRow(k)==true && checkCol(k)==true && checkBlock(k)==true){
					in[i]=k;
					num[i]=k+1;	//若此格須重填，從k+1開始
					break;
				}

				while(map[i-1]!=0){i-=1;}	//回到上一個原本是0的地方
					i-=2;	//因為for會再+1
					in[i+1]=0;
			}
		}
	}
	for(int i=0;i<81;i++){
		cout<<in[i];
		(i%9)==8?cout<<'\n':cout<<' ';
	}


	
	return;
}
bool Sudoku::checkRow(int n){
	int row=n/9;
	for(int i=0;i<9;i++){
		if(map[row*9+i]==n)
			return false;
	}
	return true;
}
bool Sudoku::checkCol(int n){
	int col=n%9;
	for(int i=0;i<9;i++){
		if(map[i*9+col]==n)
			return false;
	}
	return true;
}
bool Sudoku::checkBlock(int n){
	int row=n/9,col=n%9;
	int k,l,m;
	if(row<=2){l=0;}
	else if(row<=5){l=1;}
	else{l=2;}

	if(col<=2){m=0;}
	else if(col<=5){m=1;}
	else{m=2;}

	k=9*l+m;	//block 左上角的數字
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if((in[k+9*i+j]==in[n]) && ((k+9*i+j)!=n)){
				return false;
			}
		}
	}

	return true;
}
void Sudoku::changeNum(int a,int b){
	int x,y;
	for(int i=0;i<81;i+=9){		//remember the array address to exchange
		for(int j=0;j<9;j++){
			if(in[i+j]==a){x=i+j;}
			if(in[i+j]==b){y=i+j;}
		}
		swap(in[x],in[y]);
	}
}
void Sudoku::changeRow(int a,int b){
	int temp;
	int x=27*a,y=27*b;
	if(a != b){
		for(int i=x;i<x+27;i++){
			temp=in[i];
			in[i]=in[y];
			in[y]=temp;
			y++;
		}
	}
}
void Sudoku::changeCol(int a,int b){
	int temp;
	if(a != b){
		for(int i=a;i<81;i+=9){
			temp=in[i];
			in[i]=in[b];
			in[b]=temp;
			b+=9;
		}
	}
}
void Sudoku::rotate(int n){

	int k;
	if(n%4 == 1){
		for(int i=0;i<81;i++){
			if(i/9 == 0){k=9*(i+1)-1;  fp[k]=in[i];}
			else if(i/9 == 1){k=9*(i-8)-2;  fp[k]=in[i];}
			else if(i/9 == 2){k=9*(i-17)-3; fp[k]=in[i];}
			else if(i/9 == 3){k=9*(i-26)-4; fp[k]=in[i];}
			else if(i/9 == 4){k=9*(i-35)-5; fp[k]=in[i];}
			else if(i/9 == 5){k=9*(i-44)-6; fp[k]=in[i];}
			else if(i/9 == 6){k=9*(i-53)-7; fp[k]=in[i];}
			else if(i/9 == 7){k=9*(i-62)-8; fp[k]=in[i];}
			else if(i/9 == 8){k=9*(i-72);   fp[k]=in[i];}
		}
	}
	else if(n%4 == 2){
		for(int i=0;i<81;i++){
			fp[i]=in[80-i];
		}
	}
	else if(n%4 == 3){
		for(int i=0;i<81;i++){
			if(i/9 == 0){fp[72-i*9]=in[i];}
			if(i/9 == 1){fp[154-i*9]=in[i];}
			if(i/9 == 2){fp[236-i*9]=in[i];}
			if(i/9 == 3){fp[318-i*9]=in[i];}
			if(i/9 == 4){fp[400-i*9]=in[i];}
			if(i/9 == 5){fp[482-i*9]=in[i];}
			if(i/9 == 6){fp[564-i*9]=in[i];}
			if(i/9 == 7){fp[646-i*9]=in[i];}
			if(i/9 == 8){fp[728-i*9]=in[i];}
		}
	}
	for(int i=0;i<81;i++){in[i]=fp[i];}
}
void Sudoku::flip(int n){

	int k;
	if(n==0){
		for(int i=0;i<81;i++){
			if(i/9 == 0){k=9*(i+1)-1;  fp[k]=in[i];}
			else if(i/9 == 1){k=9*(i-8)-2;  fp[k]=in[i];}
			else if(i/9 == 2){k=9*(i-17)-3; fp[k]=in[i];}
			else if(i/9 == 3){k=9*(i-26)-4; fp[k]=in[i];}
			else if(i/9 == 4){k=9*(i-35)-5; fp[k]=in[i];}
			else if(i/9 == 5){k=9*(i-44)-6; fp[k]=in[i];}
			else if(i/9 == 6){k=9*(i-53)-7; fp[k]=in[i];}
			else if(i/9 == 7){k=9*(i-62)-8; fp[k]=in[i];}
			else if(i/9 == 8){k=9*(i-72);   fp[k]=in[i];}
		}
	}
	if(n == 1){
		for(int i=0;i<81;i++){
			if(i%9 == 0){fp[i+8]=in[i];}
			if(i%9 == 1){fp[i+6]=in[i];}
			if(i%9 == 2){fp[i+4]=in[i];}
			if(i%9 == 3){fp[i+2]=in[i];}
			if(i%9 == 4){fp[i] = in[i];}
			if(i%9 == 5){fp[i-2]=in[i];}
			if(i%9 == 6){fp[i-4]=in[i];}
			if(i%9 == 7){fp[i-6]=in[i];}
			if(i%9 == 8){fp[i-8]=in[i];}
		}
	}
	for(int i=0;i<81;i++){in[i]=fp[i];}
}
void Sudoku::transform(){
	readIn();
	change();
	printOut();
}
void Sudoku::change(){
	srand(time(NULL));
	changeNum(rand()%9+1,rand()%9+1);
	changeRow(rand()%3,rand()%3);
	changeCol(rand()%3,rand()%3);
	rotate(rand()%101);
	flip(rand()%2);
}
void Sudoku::printOut(){
	for(int i=0;i<81;i++){
		cout << in[i];
		(i%9)==8?cout<<endl:cout<<' ';
	}
}
