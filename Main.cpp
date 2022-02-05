#include <iostream>
#include <windows.h>
#include <regex>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include "Book.h"
#include "Library.h"

using namespace std;

void IsExit(string& input_letter) {
    while (true) {
        cout << "Press press 'F' to find a book, press 'E' to edit library or press 'C' to close the program: ";
        getline(cin, input_letter);
        if (input_letter[0] == 'F' || input_letter[0] == 'f' || input_letter[0] == 'E' || input_letter[0] == 'e')
        {
            break;
        }
        else if (input_letter[0] == 'C' || input_letter[0] == 'c')
        {
            exit(0);
        }
        else {
            cout << "Invalid syntax. Try again" << endl;
        }
    }
}

void Add(Library& lib, string& input_letter) {
    lib.AddBook();
}

void Delete(Library& lib, string& input_letter) {
    while (true)
    {
        string input;
        cout << "Enter a title of a book: ";
        getline(cin, input);
        bool success = lib.Find(input, 'd');
        if (!success)
        {
            cout << "Successfully deleted book " << input << "!" << endl;
            break;
        }
        cout << "Invalid syntax. Try again" << endl;
    }
}

void Update(Library& lib, string& input_letter) {
    while (true)
    {
        string input;
        string item;
        cout << "Enter a title of a book: ";
        getline(cin, input);
        cout << "What item you want to update: " << endl;
        cout << "0 - autor`s name" << endl;
        cout << "1 - autor`s surname" << endl;
        cout << "2 - book description" << endl;
        cout << "3 - number of pages" << endl;
        cout << "4 - date of publishing" << endl;
        cout << "5 - add character" << endl;
        cout << "6 - remove character" << endl;
        getline(cin, item);
        cout << "Enter value: ";
        string value;
        getline(cin, value);
        bool success = lib.Find(input, 'u', item[0], value);
        if (!success)
        {
            break;
        }
        cout << "Invalid syntax. Try again" << endl;
    }
}

void Edit(Library& lib, string& input_letter) {
    while (input_letter[0] == 'E' || input_letter[0] == 'e')
    {
        cout << "Press press 'A' to add a book, press 'D' to delete, press 'U' to update or press 'B' to turn back: ";
        getline(cin, input_letter);
        if (input_letter[0] == 'A' || input_letter[0] == 'a')
        {
            Add(lib, input_letter);
        }
        else if (input_letter[0] == 'D' || input_letter[0] == 'd')
        {
            Delete(lib, input_letter);
        }
        else if (input_letter[0] == 'U' || input_letter[0] == 'u')
        {
            Update(lib, input_letter);
        }
        else if (input_letter[0] == 'B' || input_letter[0] == 'b')
        {
            break;
        }
        else {
            input_letter = 'E';
            cout << "Invalid syntax. Try again" << endl;
        }
    }
}

void Info(Library& lib, string& input_letter, string& input, bool finder) {
    cout << "You can get more info! Press 'I' get more info or press 'C' to continue: ";
    getline(cin, input_letter);
    if (input_letter[0] == 'I' || input_letter[0] == 'i')
    {
        cout << "Enter full title of the book to get more info: ";
        getline(cin, input);
        finder = lib.Find(input, 'i');
        while (!finder)
        {
            cout << "Search error. Try again?" << endl;
            cout << "Press press 'Y' or 'N'" << endl;
            getline(cin, input_letter);

            if (input_letter[0] == 'Y' || input_letter[0] == 'n' || input_letter[0] == 'y' || input_letter[0] == 'N')
            {
                if (input_letter[0] == 'Y' || input_letter[0] == 'y')
                {
                    cout << "Enter full title of the book to get more info: ";
                    getline(cin, input);
                    finder = lib.Find(input, 'i');
                }
                else
                {
                    break;
                }
            }
            else {
                cout << "Invalid syntax. Try again" << endl;
            }
        }
    }
}

void Find(Library& lib, string& input_letter) {    
    string input;
    cout << "Enter a title of a book, an author's name or a name of a character: ";
    getline(cin, input);
    bool finder = false;
    finder = lib.Find(input);
    while (!finder)
    {
        cout << "Search error. Try again?" << endl;
        cout << "Press press 'Y' or 'N'" << endl;
        getline(cin, input_letter);

        if (input_letter[0] == 'Y' || input_letter[0] == 'n' || input_letter[0] == 'y' || input_letter[0] == 'N')
        {
            if (input_letter[0] == 'Y' || input_letter[0] == 'y')
            {
                cout << "Enter a title of a book, an author's name or a name of a character: ";
                getline(cin, input);
                finder = lib.Find(input);
            }
            else
            {
                break;
            };
        }
        else {
            cout << "Invalid syntax. Try again" << endl;
        }

    }
    if (finder)
    {
        Info(lib, input_letter, input, finder);
    }
}

void MainCycle(Library& lib, string& input_letter) {
    while (input_letter[0] == 'F' || input_letter[0] == 'f' || input_letter[0] == 'E' || input_letter[0] == 'e')
    {
        if (input_letter[0] == 'E' || input_letter[0] == 'e')
        {
            Edit(lib, input_letter);
        }        
        else if (input_letter[0] == 'F' || input_letter[0] == 'f')
        {
            Find(lib, input_letter);
        }
        IsExit(input_letter);
    }
}

int main() {
    Library lib;
    string input_letter;
    cout << "Welcome to our library!" << endl;
    IsExit(input_letter);
    MainCycle(lib, input_letter);  
    return 0;
}