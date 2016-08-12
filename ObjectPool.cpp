#include <iostream> 
#include "factoryAbstract.h"
#include "ObjectPool.h"

using namespace std;

stooze * ObjectPool::getObject(int xx) {
	map<stooze *,bool>::iterator it = pool.begin();
	for (; it!=pool.end(); ++it) {
		if (it->second == false) {
			it->second = true;
			return it->first;
		}
		else {
			cout << "no object in pool, creating one \n";
			stooze& temp = stooze::make_stooge(xx);
			pool.insert(temp, true);
			return temp;
		}
	return NULL; //code should never come here 
}


int ObjectPool::releaseObject(stooze * _ptr) {
	if (_ptr == NULL) {
		cout << "trying to release NULL pointer\n"
		return -1;
	}
		
	pool[_ptr] = false;
	return 0;
}
