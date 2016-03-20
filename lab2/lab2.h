#include<string>
using namespace std;

class data{

	private:
		int cm;
		int kg;

	public:
		void setCm(int height);
		void setKg(int mass);
		int getCm();
		int getKg();

		float BMI(int x,int y);
		string category(int z);

};

