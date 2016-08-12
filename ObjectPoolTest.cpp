#include <iostream>
#include <vector>
#include "ObjectPool.h"
#include <map>

using namespace std;

int main (void) {
	int input = 0;
	vector<stooze &> ll;
	ObjectPool op;
	cout << "enter choice, enter 0 to finish \n";
	while (true) {
		cin >> input; 

		switch (input) {
			case 1:
			case 2:
			case 3:
				ll.push_back(op.getObject(input));
				break;
			default:
				cout << "wrong entry \n";
		}
				
		if (input == 0) break ;
	}

	for (int i = 0; i < ll.size(); i++){ 
		ll[i].action();
		op.releaseObject(ll[i]);
	}

	return 0;
}
