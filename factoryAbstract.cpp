#include <iostream>
#include <vector>

using namespace std;


class stooze {
	public:
		static stooze * make_stooge(int kk);
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

stooze * stooze::make_stooge(int xx) {
	switch (xx) {
		case 1:
			return new moe();
			break;
		case 2:
			return new joe();
			break;
		case 3:
			return new ram();
			break;
		default:
			return NULL;
			break;
	}

}

int main (void) {
	int input = 0;
	vector<stooze *> ll;
	cout << "enter choice, enter 0 to finish \n";
	while (true) {
		cin >> input; 

		switch (input) {
			case 1:
			case 2:
			case 3:
				ll.push_back(stooze::make_stooge(input));
				break;
			default:
				cout << "wrong entry \n";
		}
				
		if (input == 0) break ;
	}

	for (int i = 0; i < ll.size(); i++) 
		ll[i]->action();

	return 0;
}
