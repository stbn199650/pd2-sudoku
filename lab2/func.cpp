#include<iostream>
#include<string>
#include"lab2.h"

void data::setCm(int height){cm=height;}
void data::setKg(int mass){kg=mass;}
int data::getCm(){return cm;}
int data::getKg(){return kg;}
float data::BMI(int x,int y){

	float BMI_value;

	BMI_value=y/(x*0.01)/(x*0.01);

return BMI_value;
}
string data::category(int BMI_value){

	string k;

	if(BMI_value<15)
		k="very severely underweight";
	else if(BMI_value<16)
		k="severely underweight";
	else if(BMI_value<18.5)
		k="underweight";
	else if(BMI_value<25)
		k="normal";
	else if(BMI_value<30)
		k="overweight";
	else if(BMI_value<35)
		k="moderately obese";
	else if(BMI_value<40)
		k="severely obese";
	else if(BMI_value>=40)
		k="very severely obese";

return k;
}
