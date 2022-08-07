#include "edit_definition.h"

void edit_definition(bNode* word, int def_order, wstring edited_def, vector<wstring>& definitions, string def_dir) 
{
	definitions[def_order] = edited_def;
	//remove_def_from_file(word->d, def_dir);

	ofstream fout;
	fout.open(def_dir, ios::binary | ios::out | ios::app | ios::ate);
	word->d = fout.tellp();
	int n = definitions.size() - 1;
	fout.write((char*)&n, sizeof(int));
	for (int i = 0; i < n; ++i) 
	{	
		int length = definitions[i].length() + 1;
		fout.write((char*)&length, sizeof(int));
		fout.write((char*)&definitions[i][0], length * sizeof(wchar_t));
	}
	fout.close();
}