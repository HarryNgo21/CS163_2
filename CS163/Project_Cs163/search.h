#ifndef search_h
#define search_h


#endif /* search_h */
#include "AVL.h"
#include "LL.h"
#include <cstring>
#include <vector>
#include <iostream>
#include <ctime>
#include <locale.h>
using namespace std;

vector<wstring> search_for_def(bNode* root, string dir);
vector<bNode*> random_take(bNode* root, vector<int> lists);
vector<vector<wstring>> random_word(AVL& tree, string dir, int n);
bool random_game(vector<vector<wstring>> lists);
bool random_def_game(vector<vector<wstring>> lists);
void random_keywords(vector<vector<wstring>> lists);
wstring modify_input(wstring& str);

