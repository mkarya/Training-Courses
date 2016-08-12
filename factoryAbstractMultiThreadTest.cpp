#include <iostream>
#include <vector>
#include <iterator>
#include "factoryAbstract.h"
#include <thread>
#include <mutex>

using namespace std;
vector<stooze *> ll;
mutex mtx;

void collectInput() {
	int input;
	while (true) {
		cin >> input; 

		switch (input) {
			case 1:
			case 2:
			case 3:
			//mtx.lock();
				ll.push_back(stooze::make_stooge(input));
			//mtx.unlock();
			break;
			default:
				cout << "wrong entry \n";
		}
				
	}
	return;
}

void performAction() {
	mtx.lock();
	while(true){
		vector<stooze *>::iterator it = ll.begin();
		for (; it != ll.end(); ++it) 
			(*it)->action();
		while(!ll.empty()) {
			ll.pop_back();
		}
	mtx.unlock();
}
	return;
}


int main (void) {
	thread th01(collectInput);
	thread th02(performAction);

	th01.join();
	th02.join();

	return 0;
}
