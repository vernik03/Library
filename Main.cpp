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

int main() {
    Library lib;
    //read_all_books();
    string input_letter;
    cout << "Welcome to our library!" << endl;
    unsigned int id = 0;

    while (true) {
        cout << "Press press 'F' to find a book or press 'E' to edit library: ";
        getline(cin, input_letter);
        if (input_letter[0] == 'F' || input_letter[0] == 'f' || input_letter[0] == 'E' || input_letter[0] == 'e')
        {            
            break;
        }
        else {
            cout << "Invalid syntax. Try again" << endl;
        }

    }
    
  while (input_letter[0] == 'F' || input_letter[0] == 'f' || input_letter[0] == 'E' || input_letter[0] == 'e')
    {



        while (input_letter[0] == 'E' || input_letter[0] == 'e')
        {
            cout << "Press press 'A' to add a book, press 'D' to delete, press 'U' to update or press 'B' to turn back: ";
            cin >> input_letter;
            if (input_letter[0] == 'A' || input_letter[0] == 'a')
            {
                lib.AddBook();
                break;
            }
            else if (input_letter[0] == 'D' || input_letter[0] == 'd')
            {
                while (true)
                {


                    char input[256];
                    cout << "Enter a title of a book: ";
                    gets_s(input);
                    gets_s(input);
                    bool success = delete_book(input);
                    if (!success)
                    {

                        break;
                    }
                    cout << "Invalid syntax. Try again" << endl;
                }
            }
            else if (input_letter[0] == 'U' || input_letter[0] == 'u')
            {
                while (true)
                {


                    char book_title[256];
                    int item;
                    char input[1024];
                    cout << "Enter a title of a book: ";
                    gets_s(book_title);
                    gets_s(book_title);
                    cout << "What item you want to update: " << endl;
                    cout << "0 - autor`s name" << endl;
                    cout << "1 - autor`s surname" << endl;
                    cout << "2 - book description" << endl;
                    cout << "3 - number of pages" << endl;
                    cout << "4 - date of publishing" << endl;
                    cin >> item;
                    cout << "Enter new value: ";
                    gets_s(input);
                    gets_s(input);

                    cout << string(book_title) << " " << item << " " << string(input) << endl;
                    bool success = update_book(book_title, item, input);
                    if (!success)
                    {
                        break;
                    }
                    cout << "Invalid syntax. Try again" << endl;
                }
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
      if (input_letter[0] == 'F' || input_letter[0] == 'f')
        {
            char input[256];
            cout << "Enter a title of a book, an author's name or a name of a character: ";
            gets_s(input);
            gets_s(input);
            bool finder;
            finder = find(input);
            if (finder)
            {
                finder = find_by_character(input);

            }
            while (finder)
            {
                cout << "Search error. Try again?" << endl;
                cout << "Press press 'Y' or 'N'" << endl;
                cin >> input_letter;

                if (input_letter[0] == 'Y' || input_letter[0] == 'n' || input_letter[0] == 'y' || input_letter[] == 'N')
                {
                    if (input_letter[0] == 'Y' || input_letter[0] == 'y')
                    {
                        cout << "Enter a title of a book, an author's name or a name of a character: ";
                        gets_s(input);
                        gets_s(input);
                        finder = find(input);
                        if (finder)
                        {
                            finder = find_by_character(input);

                        }

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
        }

        while (true) {
            cout << "Press press 'F' to find a book, press 'E' to edit library or press 'C' to close the program: ";
            cin >> input_letter;
            if (input_letter[0] == 'F' || input_letter[0] == 'f' || input_letter[0] == 'E' || input_letter[0] == 'e')
            {
                break;
            }
            else if (input_letter[0] == 'C' || input_letter[0] == 'c')
            {
                return 0;
            }
            else {
                cout << "Invalid syntax. Try again" << endl;
            }

        }

    }
    


lib.WriteBooks();
lib.WriteCharacters();

    return 0;

}