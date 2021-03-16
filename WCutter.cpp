// WCutter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>>
#include <string>
#include <vector>

using namespace std;

void Completed()
{
    cout << "\n-----------------" << endl;
    cout << "Process complete!" << endl;
    cout << "-----------------" << endl;
}

void UnexpectedError()
{
    cout << "\nAn unexpected error occurred." << endl;
}

int main()
{
    fstream to_read, to_write;
    string path, str, to_remove1, to_remove2, a, b, n, end;
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
            cout << "\nBad file path.\n";
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
        while (true)
        {
            cout << "\nWhat do you want to remove?\n1: A specific part in the text line\n2: Everything after a specific part in the text line" << endl;
            cout << "1/2: ";

            getline(cin, b);

            if (b == "1" || b == "2")
                break;
            else
                continue;
        }

        if (b == "1")
        {
            cout << "\nInsert the part to be removed: ";

            getline(cin, to_remove1);

            cout << "\nDo you also want to remove the [possible] space next to the part? (y/n): ";

            getline(cin, a);

            for (int i = 0; i < words.size(); i++)
            {
                size_t pos = words[i].find(to_remove1);

                if (pos == -1)
                {
                    cout << "\nNo match in line " << i << "..." << endl;
                    to_write << words[i] << endl;
                }
                else
                {
                    if (a == "Y" || a == "y" || a == "Yes" || a == "yes")
                    {
                        if ((int)pos - 1 >= 0)
                        {
                            str = words[i].substr(0, pos - 1);
                            str += words[i].substr(pos -1 + to_remove1.length() + 1);
                        }
                        else if ((int)pos - 1 < 0)
                        {
                            str = words[i].substr(to_remove1.length() + 1);
                        }
                    }
                    else
                    {
                        str = words[i].substr(0, pos);
                        str += words[i].substr(pos + to_remove1.length());
                    }

                    words[i] = str;

                    to_write << words[i] << endl;
                }
            }

            Completed();
        }
        else if (b == "2")
        {
            cout << "\nInsert the part to start removing from: ";

            getline(cin, to_remove2);

            for (int i = 0; i < words.size(); i++)
            {
                size_t pos = words[i].find(to_remove2);

                if (pos == -1)
                {
                    cout << "\nNo match in line " << i << "..." << endl;
                    to_write << words[i] << endl;
                }
                else
                {
                    string str = words[i].substr(0, pos);
                    words[i] = str;

                    to_write << words[i] << endl;
                }
            }

            Completed();
        }
        else
        {
            UnexpectedError();
        }
    }
    else
    {
        UnexpectedError();
    }
    to_write.close();

    getline(cin, end);

    return 0;
}