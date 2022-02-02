#pragma once
#include <iostream>
#include <windows.h>
#include <regex>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <map>
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
    unsigned int GetId();
    string GetTitle();
    string GetDescription();
    string GetName();
    string GetSurname();
    int GetNumOfPages();
    string GetDate();
    Date GetDateStruct();
    void GetDateStream(std::ofstream& out);
    //template <typename ch_id>
    //string GetCharacterLevel(typename ch_id);
    string GetCharacterLevel(string ch_name);
    int GetCharacterLevelInt(string ch_name);
    int GetNumOfCharacters();
    map<string, Level> GetAllCharacters();
    void SetId(string str);
    void SetId(int str);
    void SetTitle(string str);
    void SetDescription(string str);
    void SetName(string str);
    void SetSurname(string str);
    void SetNumOfPages(string str);
    void SetDate(string str);
    void SetCharacter(string name_str, string lvl_str);
    void SetCharacter(string name_str, int lvl_str);

    friend bool operator< (const Book& b1, const Book& b2);

private:
    unsigned int id;
    string title;
    string description;
    int num_of_pages;
    string authors_name;
    string authors_surname;
    Date date;
    map<string, Level> characters;

    bool CheckDay();
};

