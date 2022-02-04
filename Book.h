#pragma once
#include <iostream>
#include <windows.h>
#include <regex>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

enum class Level {
    MAIN = 1,
    SECONDARY = 2,
    EPISODIC = 3
};

struct Date {
    int day;
    int month;
    int year;
};

class Book
{
public:
    Book(string new_id="0", string new_title= "default", string new_description= "default", string new_num_of_pages="0", string new_authors_name= "default", string new_authors_surname= "default", string new_date= "01.01.0001");
    string GetTitle();
    string GetDescription();
    string GetName();
    string GetSurname();
    int GetNumOfPages();
    string GetDate();
    Date GetDateStruct();
    void GetDateStream(std::ofstream& out);
    string GetCharacterLevel(string ch_name);
    int GetCharacterLevelInt(string ch_name);
    int GetNumOfCharacters();
    map<string, Level> GetAllCharacters();
    void SetTitle(string str);
    void SetDescription(string str);
    void SetName(string str);
    void SetSurname(string str);
    void SetNumOfPages(string str);
    void SetDate(string str);
    void SetCharacter(string name_str, string lvl_str);
    void SetCharacter(string name_str, int lvl_str);

    friend bool operator< (const Book& b1, const Book& b2);
    friend ostream& operator<< (ostream& out, const Date& date);

    void PrintBook(vector<string> to_print = { "title", "name", "description", "pages", "date", "characters" });
    void Update(char to_update, string value);

private:
    string title;
    string description;
    int num_of_pages;
    string authors_name;
    string authors_surname;
    Date date;
    map<string, Level> characters;

    bool CheckDay();
};