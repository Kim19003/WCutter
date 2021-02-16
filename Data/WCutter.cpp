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
    string path, to_remove, n;
    vector<string> words;

    cout << "###############\n### WCutter ###\n###############" << endl;

    while (true)
    {
        cout << "\nInsert file path (or 'file_name.txt' if in the same folder): ";
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
        cout << "\nInsert the part to remove from: ";
        getline(cin, to_remove);

        for (int i = 0; i < words.size(); i++)
        {
            size_t pos = words[i].find(to_remove);

            if (pos == -1)
            { 
                cout << "\nNo match in line " << i << "..." << endl;
            }
            else
            { 
                string str = words[i].substr(0, pos);
                words[i] = str;

                to_write << words[i] << endl;
            } 
        }

        cout << "\n-----------------" << endl;
        cout << "Process complete!" << endl;
        cout << "-----------------" << endl;
    }
    else
    {
        cout << "\nAn unexpected error occurred opening the file for writing." << endl;;
    }
    to_write.close();

    return 0;
}