#ifndef FACTORY_ABSTRACT
#define FACTORY_ABSTRACT
#include <iostream>
#include <vector>

using namespace std;

class stooze {
	public:
		static stooze* make_stooge(int kk);
		virtual void action() = 0;
};

class moe : public stooze {
	public:
		inline void action() {
			cout << "roll eyes \n";
		}
};

class joe : public stooze {
	public:
		inline void action() {
			cout << "raise hand \n";
		}
};

class ram : public stooze {
	public:
		inline void action() {
			cout << "raise leg \n";
		}
};
#endif
