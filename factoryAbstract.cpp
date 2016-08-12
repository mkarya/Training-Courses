#include <iostream>
#include <vector>
#include "factoryAbstract.h"


stooze* stooze::make_stooge(int xx) {
	stooze * _ptr;
	switch (xx) {
		case 1:
			_ptr = new moe();
			return _ptr;
			break;
		case 2:
			_ptr = new joe();
			return _ptr;
			break;
		case 3:
			_ptr = new ram();
			return _ptr;
			break;
		default:
			return NULL;
			break;
	}

}

