#include <iostream>
using namespace std;

class SingleTon {
	private:
		SingleTon(); 
		unsigned short xx;
		static SingleTon * instance; 
		static bool createdFlag; 

	public:
		inline void incrementNum(void) { xx += 1; }
		inline void decrementNum(void){ xx -= 1;}
		inline void printNumber(void) { cout << "number is : " << xx << "\n"; }
		static SingleTon * getInstance();
};

SingleTon::SingleTon() {
	xx = 0;
}

SingleTon * SingleTon::getInstance() {
	if (SingleTon::instance == NULL) {
		cout << " no object instance creating one \n";
		SingleTon::instance = new SingleTon();
	}
	
	return SingleTon::instance;
}

bool SingleTon::createdFlag = false;
SingleTon * SingleTon::instance = NULL;

int main () {
	SingleTon *tt = SingleTon::getInstance();
	SingleTon *xx = SingleTon::getInstance();

	tt->printNumber();
	xx->printNumber();

	xx->incrementNum();
	xx->incrementNum();
	tt->decrementNum();
	
	tt->printNumber();

	delete(tt);

	
	
	return 0;
}


