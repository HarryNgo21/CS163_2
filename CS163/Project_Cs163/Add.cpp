#include "AVL.h"
#include<string>
#include<iostream>
using namespace std;
int AVL::Add(AVL& tree, wstring key, string def_dir,int numb)
{
	wstring def;
	ofstream fout(def_dir, ios_base::binary | ios_base::app | ios_base::ate);
	if (!fout.is_open()) return -2;
	int d = fout.tellp();
	fout.write((char*)&numb, sizeof(int));
	for (int i = 0; i < numb; i++)
	{
		wcout << L"Please input definition of word that you want to add to dictionary : ";
		getline(wcin, def);
		int l = def.length() + 1;
		fout.write((char*)&l, sizeof(int));
		fout.write((char*)&def[0], l * sizeof(wchar_t));
	}
	fout.close();
	tree.insert(key, d);
	return d;
}