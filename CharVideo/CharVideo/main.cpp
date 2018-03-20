//¿ØÖÆÌ¨ÉèÖÃ£º·ÂËÎ5ºÅ×Ö£¬F11È«ÆÁ
#include "main.h"

using namespace std;


int main() {
	if (init() != 0) {
		system("pause");
		return 0;
	}

	string s;
	cin >> s;

	Video video(s);
	video.play();
	
	system("pause");

	return 0;
}
