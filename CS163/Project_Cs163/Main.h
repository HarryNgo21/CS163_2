#pragma once

#include<iostream>
#include<iomanip>
#include<io.h>
#include<fcntl.h>
#include<string>
#include<codecvt>
#include"AVL.h"
#include"FL.h"
#include"Const.h"
#include"search.h"
#include"search_history.h"
#include"ViewRandomly.h"
#include"RemoveFile.h"
#include"remove_a_word.h"
#include"Keyword.h"
#include"edit_definition.h"
#include"Keyword.h"
#include"render.h"

bool load(AVL tree); // load data from file

int Init_screen(AVL&, FL&, c_hash&, string&, string&, string&);

void S_screen(AVL&, FL&, c_hash&, search_history&, string);

void F_screen(FL&, string def_dir);

void Quizz(AVL&, string);

void Add(AVL& tree, string& def_dir);

void ViewRandomWord(AVL& tree, string def_dir);

int Switch_data_set(string& struct_dir, string& def_dir, c_hash& key_hash, string& hash_dir, AVL& tree, FL& fl);

void ResetToOriginal(AVL& tree, string& struct_dir, string& def_dir, string& hash_dir, c_hash& key_hash);

void ViewSearchHistory(search_history&, AVL& root, string& def_dir);

void DeleteSearchHistory(search_history&);

void EditDefinition(AVL& tree, string def_dir);