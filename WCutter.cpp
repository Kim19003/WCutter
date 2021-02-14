// WCutter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>>
#include <string>
#include <vector>

using namespace std;

int main()
{
    fstream to_read, to_write;
    string path, n;
    vector<string> words;
    int i = 0;

    cout << "###############\n### WCutter ###\n###############" << endl;

    while (true)
    {
        cout << "\nInsert file path:";
        getline(cin, path);

        to_read.open(path, ios_base::in);

        if (to_read)
        {
            break;
        }
        else
        {
            cout << "\nBad file path.";
            continue;
        }
    }

    while (getline(to_read, n))
    {
        words.push_back(n);
    }
    to_read.close();

    to_write.open(path, ios_base::out);

    if (to_write)
    {
        for (int i = 0; i < words.size(); i++)
        {
            to_write << words[i] << endl;
        }
    }
    to_write.close();

    return 0;
}