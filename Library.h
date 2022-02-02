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
    Library(string file_books = "book.txt", string file_characters = "character.txt");
    void ReadBooks(string file);
    void ReadCharacters(string file);
    void WriteBooks(string file = "book.txt");
    void WriteCharacters(string file = "character.txt");
    void SetBook(Book new_book);
    void SetCharacter(string new_character);

    friend istream& operator >> (istream& in, string s) {
        getline(in, s);
        return in;
    }

    void AddBook();

private:
    set<Book> books;
    set<string> characters;
};
