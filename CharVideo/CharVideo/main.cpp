#include "main.h"
using namespace std;

int main() {
	if (init() != 0) {
		system("pause");
		return 1;
	}

	string s;
	cin >> s;

	play(s);

	system("pause");
	return 0;
}
