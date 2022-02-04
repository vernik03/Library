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
    ~Library();
    void ReadBooks(string file);
    void ReadCharacters(string file);
    void WriteBooks(string file = "data/book.txt");
    void WriteCharacters(string file = "data/character.txt");
    void SetBook(Book new_book);
    void SetCharacter(string new_character);

    void AddBook();
    void DeleteBook(string in_name, bool& flag);    
    void UpdateBook(string in_name, bool& flag, char to_update, string value);
    bool Find(string find_text, char to_do = 'f', char to_update = ' ', string value = "");


private:
    vector<Book> books;
    set<string> characters;
    void Sort();
    void PrintAll();
    void FindByCharacter(string in_name, bool& flag);
    void DeleteCharacter(int i);
    void CheckCharacters();
};