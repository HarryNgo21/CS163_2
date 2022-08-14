#include "search_history.h"

search_history::search_history() : hist_head(nullptr) {}

bool check_empty_file(string dir) {
	bool check = false;
	ifstream fin;
	fin.open(dir);
	if (fin.peek() == EOF) check = true;
	fin.close();
	return check;
}

string search_history::Dist(string def_dir) {
	if (def_dir == "database\\eng-vie\\def.bin") return "database\\eng-vie\\search_history.txt";
	if (def_dir == "database\\eng-eng\\def.bin") return "database\\eng-eng\\search_history.txt";
	if (def_dir == "database\\vie-eng\\def.bin") return "database\\vie-eng\\search_history.txt";
	if (def_dir == "database\\slang\\def.bin") return "database\\slang\\search_history.txt";
	if (def_dir == "database\\emotional\\def.bin") return "database\\emotional\\search_history.txt";
}


Node<wstring>* search_history::Load(string history_dir)
{
	if (!check_empty_file(history_dir)) {
		wifstream fin;
		fin.open(history_dir);

		wstring word;
		while (!fin.eof()) {
			fin >> word;
			hist_head = new Node<wstring>(word, hist_head);
		}
		fin.close();
		Node<wstring>* temp = hist_head;
		hist_head = hist_head->next;
		delete temp;
	}
	return hist_head;
}
int search_history::count()
{
	if (!hist_head) return 0;
	int count = 0;
	Node<wstring>* temp = hist_head;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return count;
}
Node<wstring>* search_history::Find(int num)
{
	int count = 1;
	Node<wstring>* temp = hist_head;
	while (count < num)
	{
		count++;
		temp = temp->next;
	}
	return temp;
}
Node<wstring>* search_history::Add(wstring word, string history_dist)
{
	hist_head = new Node<wstring>(word, hist_head);
	wofstream fout;
	fout.open(history_dist, ios::app);
	fout << word << endl;
	fout.close();
	return hist_head;
}

void search_history::View()
{
	if (!hist_head) {
		wcout << L"No history." << endl;
		return;
	}
	int count = 1;
	Node<wstring>* temp = hist_head;
	while (temp) {
		wcout <<L"["<<count<<"]."<< temp->data << endl;
		count++;
		temp = temp->next;
	}
}

Node<wstring>* search_history::Delete(string history_dir) {
	ofstream fout(history_dir, ios::trunc);
	fout.close();
	if (hist_head) hist_head->clear();
	hist_head = nullptr;
	return hist_head;
}