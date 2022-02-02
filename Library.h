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

    int find_by_character(string in_name) {
        for(auto character : characters)
        if (in_name.find(character) != string::npos || character.find(in_name) != string::npos)
        {     
            for (Book book : books)
            {
                for (auto [ch_name, ch_lvl] : book.GetAllCharacters())
                {
                    if (ch_name == in_name)
                    {

                    }
                }
            }
        }
    }


/*
    int find(char input[256])
    {

        ifstream in;
        in.open("../book.txt");
        char chars[50];
        in.getline(chars, 50);
        while (!in.eof())
        {
            book_info elem;


            elem.id = atoi(chars);
            in.getline(elem.title, 256);
            in.getline(elem.authors_name, 50);
            in.getline(elem.authors_surname, 50);
            in.getline(elem.description, 1024);
            in.getline(elem.date, 11);
            in.getline(chars, 50);
            elem.pages = atoi(chars);
            char check[50];
            level_of_character temp;
            in.getline(chars, 50);
            temp.character_id = atoi(chars);
            in.getline(chars, 50);
            temp.level = atoi(chars);
            elem.characters.push_back(temp);
            in.getline(chars, 50);

            while (chars[0] != '@')
            {


                temp.character_id = atoi(chars);

                in.getline(chars, 50);
                temp.level = atoi(chars);
                elem.characters.push_back(temp);
                in.getline(chars, 50);
            }


            if (string(input).find(string(elem.authors_name)) != string::npos || string(input).find(string(elem.authors_surname)) != string::npos || string(input).find(string(elem.title)) != string::npos ||
                string(elem.authors_name).find(string(input)) != string::npos || string(elem.authors_surname).find(string(input)) != string::npos || string(elem.title).find(string(input)) != string::npos)
            {

                cout << endl;
                cout << elem.title << "    " << elem.authors_name << " " << elem.authors_surname << "    " << elem.date << "    " << elem.pages << " pages" << endl;
                cout << endl;
                cout << elem.description << endl;
                cout << endl;


                //  in.close();
                  //return 0;

            }
            in.getline(chars, 50);
            if (chars[0] == NULL)
            {
                break;
            }
        }
        in.close();
        return 1;
    }

    */

private:
    vector<Book> books;
    set<string> characters;
};