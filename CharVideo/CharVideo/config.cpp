#include "main.h"

extern Config config;
extern vector<Cs> cs_k;

vector<string> GetLineFromFile(string path) {
	ifstream fin(path);
	vector<string> res;
	while (!fin.eof()) {
		string s;
		getline(fin, s);
		res.push_back(s);
	}
	return res;
}

vector<string> SplitByChar(string s, char c) {
	string::size_type pos1, pos2;
	pos2 = s.find(c);
	pos1 = 0;
	vector<string> res;
	while (string::npos != pos2) {
		res.push_back(s.substr(pos1, pos2 - pos1));
		pos1 = pos2 + sizeof(c);
		pos2 = s.find(c, pos1);
	}
	if (pos1 != s.length())
		res.push_back(s.substr(pos1));
	return res;
}

vector<string> RemoveNote(vector<string> k) {
	for (int i = 0; i < k.size();i++) {
		if (k.at(i).at(0) == '#') {
			k.erase(k.begin() + i, k.end());
			break;
		}
	}
	return k;
}

int GetNumFromString(string s) {
	int n = 0;
	for (auto i : config.configs) {
		if (i.name.compare(s) == 0) {
			return n;
		}
		n++;
	}
	return -1;
}

int Config::WriteIn(vector<string> k) {
	if (k.size() != 2) return -1;
	configs.at(GetNumFromString(k.at(0))).value = atoi(k.at(1).c_str());
	return 0;
}

int init() {
	setFont(8, 18);
	vector<string> config_0 = GetLineFromFile("../config.txt");
	for (auto config_1 : config_0) {
		if (config.WriteIn(RemoveNote(SplitByChar(config_1, ' '))) != 0) {
			cout << "Config Error.\n";
			return -1;
		};
	}
	vector<string> video_0 = GetLineFromFile("../video.txt");
	for (auto video_1 : video_0) {
		Cs new_cs;
		if (new_cs.WriteIn(RemoveNote(SplitByChar(video_1, ' ')))) {
			cout << "Video Error.\n";
			return -1;
		}
		cs_k.push_back(new_cs);
	}
	return 0;
}
