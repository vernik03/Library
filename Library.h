#pragma once
#include <iostream>
#include <windows.h>
#include <regex>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include "Book.h"

using namespace std;

class Library {
public:
    Library(string file_books = "data/book.txt", string file_characters = "data/character.txt");
    void ReadBooks(string file);
    void ReadCharacters(string file);
    void WriteBooks(string file = "data/book.txt");
    void WriteCharacters(string file = "data/character.txt");
    void SetBook(Book new_book);
    void SetCharacter(string new_character);

    void PrintAll() {
        for (auto book : books) {
            book.PrintBook();
        }
    }
    void AddBook();
    void Sort();

    void FindByCharacter(string in_name, bool& flag) {
        for(auto character : characters)
        if (in_name.find(character) != string::npos || character.find(in_name) != string::npos)
        {     
            for (Book book : books)
            {
                for (auto [ch_name, ch_lvl] : book.GetAllCharacters())
                {
                    if (ch_name == in_name)
                    {
                        book.PrintBook({ "title", "name", "date" });
                        flag = true;
                    }
                }
            }
        }
    }


    bool Find(string find_text)
    {
        bool flag = false;
        for (Book book : books)
        {        
            if (find_text.find(book.GetName()) != string::npos || find_text.find(book.GetSurname()) != string::npos || find_text.find(book.GetTitle()) != string::npos ||
                book.GetName().find(find_text) != string::npos || book.GetSurname().find(find_text) != string::npos || book.GetTitle().find(find_text) != string::npos)
            {                
                book.PrintBook({ "title", "name", "date" });
                flag = true;
            }            
        }
        if (!flag)
        {
            FindByCharacter(find_text, flag);
        }
        return flag;
    }


private:
    vector<Book> books;
    set<string> characters;
};