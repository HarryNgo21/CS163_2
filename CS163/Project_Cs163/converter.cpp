#include "converter.h"
void convert_txt(string dir)
{
    string tmp1, tmp2;
    bool isfist = false, iskey = false;
    ofstream fout;
    ifstream fin;
    fin.open(dir);
    fout.open("output1.txt");
    while (fin.eof() == false)
    {
        tmp2.clear();
        isfist = false;
        iskey = false;
        getline(fin, tmp1);
        if (!tmp1.empty())
        {
            for (int i = 0; i < tmp1.length(); i++)
            {
                if (tmp1[i] == '(' && isfist == false)
                {
                    while (tmp1[i] != ')')
                    {
                        i++;
                    }
                    i += 2;
                    isfist = true;
                }
                tmp2.push_back(tmp1[i]);
                if (tmp1[i + 1] == ' ' && iskey == false)
                {
                    tmp2.push_back(':');
                    iskey = true;
                }
            }
            //cout << tmp2 <<endl;
            fout << tmp2 << endl;
        }
    }
    fout.close();
    fin.close();
}
void ignore_blank(string dir)
{
    int i = 0;
    string tmp;
    ifstream fin(dir);
    ofstream fout("output.txt");
    while (fin.eof() == false)
    {
        getline(fin, tmp);
        if (i % 2 == 0)
            fout << tmp << endl;
        i++;
    }
    fin.close();
    fout.close();
}

void lower_key()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    while (!fin.eof())
    {
        string tmp;
        getline(fin, tmp, '\t');
        transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
        fout << tmp << '\t';
        getline(fin, tmp);
        fout << tmp << endl;
    }
    fin.close();
    fout.close();
}

void convert_single_quote(string dir)
{
    char t;
    string tmp1, tmp2;
    bool isfirst = false, iskey = false;
    ofstream fout;
    ifstream fin;
    fin.open(dir);
    fout.open("output.txt");
    while (!fin.eof())
    {
        tmp1.clear();
        getline(fin, tmp1, '`');
        fout << tmp1 << '\t';
        getline(fin, tmp1);
        fout << tmp1 << endl;
    }
    fout.close();
    fin.close();
}