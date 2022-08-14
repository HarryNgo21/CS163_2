
#include "remove_a_word.h"

//bool remove_def_from_file(int d, string def_dir) {
//	ifstream fin;
//	fin.open(def_dir, ios::binary | ios::in);
//	if (!fin.is_open()) {
//		return false;
//	}
//	fin.seekg(d);
//	int n;
//	fin.read((char*)&n, sizeof(int));
//	int* len = new int[n];
//	int size_delete = n;
//	for (int i = 0; i < n; ++i) {
//		fin.read((char*)&len[i], sizeof(int));
//		fin.seekg(len[i]);
//		size_delete = size_delete + sizeof(int) + len[i];
//	}
//	fin.close();
//
//	ofstream fout;
//	fout.open(def_dir, ios::binary | ios::out);
//	if (!fout.is_open()) {
//		return false;
//	}
//	fout.seekp(d);
//	for (int i = 0; i < size_delete; ++i) {
//		char del = ' ';
//		fout.write((char*)&del, sizeof(char));
//	}
//	fout.close();
//	return true;
//}

bool remove_a_word(wstring word, AVL& tree, string def_dir) {
	//int d = word->d;
	//remove_def_from_file(d, def_dir);
	return tree.remove(word);
}