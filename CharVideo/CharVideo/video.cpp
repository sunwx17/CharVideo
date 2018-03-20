#include "main.h"

char img_s[1080 * 1080];
const char gr_8[8] = { ' ', ',', '+', '1', 'n', 'D', '&', 'M' };
const char gr_16[16] = { ' ','.',';',':','!','>','7','?','C','O','$','Q','H','N','M','W' };
vector<Cs> cs_k;
Config config;

int Cs::WriteIn(vector<string> k) {
	if (k.size() != 4) return -1;
	name = k.at(0);
	beg = atoi(k.at(1).c_str());
	end = atoi(k.at(2).c_str());
	frame = atoi(k.at(3).c_str());
	return 0;
}

Video::Video(string k) {
	for (auto i : cs_k) {
		if (i.name.compare(k) == 0) {
			cs = i;
			return;
		}
	}
	cout << "No This Video.\n";
	cs.frame = -1;
}

void Video::img2str() {

	string name = cs.name;
	int beg = cs.beg;
	int end = cs.end;

	const char * gr;
	switch (config.configs.at(GetNumFromString("gradation")).value) {
	case 8: gr = gr_8; break;
	case 16: gr = gr_16; break;
	default: gr = gr_8;
	}

	for (int k = beg; k < end + 1; k++) {
		string s = to_string(k);
		string path_scr = "../resourse/" + name + "/" + name + "_r/" + s + ".jpg";
		string path_tar = "../resourse/" + name + "/" + name + "_s/" + s + ".txt";

		resetCursor();

		char pro[101];
		pro[100] = '\0';
		double process = (double)(k - beg) / (end - beg) * 100;
		for (int i = 1; i <= 100; i++) {
			if (i <= process) {
				pro[i - 1] = '#';
			}
			else {
				pro[i - 1] = '.';
			}
		}
		for (int i = 0; i < 3; i++) printf("%s\n", pro);

		ofstream fout(path_tar);

		Mat img = imread(path_scr, 0);


		int row = img.rows;
		int col = img.cols;
		uchar buffer;

		int h = config.configs.at(GetNumFromString("pxY")).value;
		int w = config.configs.at(GetNumFromString("pxX")).value;

		for (int i = 0; i < row; i += h) {
			for (int j = 0; j < col; j += w) {
				buffer = img.at<uchar>(i, j);
				fout << gr[buffer / (256 / config.configs.at(GetNumFromString("gradation")).value)];
			}
			if (i + h < row)
				fout << endl;
		}

		fout.close();
	}
}

void Video::play() {

	string name = cs.name;
	int beg = cs.beg;
	int end = cs.end;
	int frame = cs.frame;
	if (frame == -1) {
		return;
	}
	if (config.configs.at(GetNumFromString("reform")).value)
		img2str();
	setFont(config.configs.at(GetNumFromString("charsizeX")).value, config.configs.at(GetNumFromString("charsizeY")).value);
	do {
		system("cls");
		for (int k = beg; k < end + 1; k++) {
			clock_t start_time = clock();

			string s = to_string(k);
			string path = "../resourse/" + name + "/" + name + "_s/" + s + ".txt";

			ifstream is(path);
			is.seekg(0, is.end);
			int length = is.tellg();
			is.seekg(0, is.beg);
			is.read(img_s, length);

			resetCursor();

			//printf("%s", img_s);
			puts(img_s);

			clock_t end_time = clock();
			//cout << start_time << endl << end_time - start_time << endl;
			double t = ((double)(end_time - start_time) / CLOCKS_PER_SEC);
			if (t < 1.0 / frame) Sleep((1.0 / frame - t) * 1000);
		}
	} while (config.configs.at(GetNumFromString("recycle")).value);

}
