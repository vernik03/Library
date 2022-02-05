#include "Book.h"

Book::Book(string new_id, string new_title, string new_description, string new_num_of_pages, string new_authors_name, string new_authors_surname, string new_date){
    SetTitle(new_title);
    SetDescription(new_description);
    SetName(new_authors_name);
    SetSurname(new_authors_surname);
    SetNumOfPages(new_num_of_pages);
    SetDate(new_date);
}

string Book::GetTitle() {
    return title;
}

string Book::GetDescription() {
    return description;
}

string Book::GetName() {
    return authors_name;
}

string Book::GetSurname() {
    return authors_surname;
}

int Book::GetNumOfPages() {
    return num_of_pages;
}

string Book::GetDate() {
    return to_string(date.day) + '.' + to_string(date.month) + '.' + to_string(date.year);
}

void Book::GetDateStream(ofstream& out)
{
    out << setfill('0');
    out << setw(2) << date.day << "." << setw(2) << date.month << "." << setw(4) << date.year;
}

Date Book::GetDateStruct() {
    return date;
}

string Book::GetCharacterLevel(string ch_id) {
    switch (characters.at(ch_id))
    {
    case Level::MAIN:
        return "Main";
    case Level::SECONDARY:
        return "Secondary";
    case Level::EPISODIC:
        return "Episodic";
    default:
        break;
    }
}

ostream& operator<< (ostream& out, const Level& date) {
    switch (date)
    {
    case Level::MAIN:
        out << "main";
        return out;
    case Level::SECONDARY:
        out << "secondary";
        return out;
    case Level::EPISODIC:
        out << "episodic";
        return out;
    }
}

int Book::GetCharacterLevelInt(string ch_id) {
    return static_cast<int>(characters.at(ch_id));
}

int Book::GetNumOfCharacters() {
    return characters.size();
}

map<string, Level> Book::GetAllCharacters() {
    return characters;
}

void Book::SetTitle(string str) {
    title = str;
}

void Book::SetDescription(string str) {
    description = str;
}

void Book::SetName(string str) {
    authors_name = str;
}

void Book::SetSurname(string str) {
    authors_surname = str;
}

void Book::SetNumOfPages(string str) {
    num_of_pages = stoi(str);
}

void Book::SetDate(string str) {
    if (str.size() != 10)
    {
        throw invalid_argument("Wrong DATE input.");
    }
    date.day = stoi(str.substr(0, 2));
    date.month = stoi(str.substr(3, 2));
    date.year = stoi(str.substr(6));
    if (!CheckDay())
    {
        throw invalid_argument("Wrong DATE values.");
    }
}

bool Book::CheckDay() {
    return (date.day > 0 && date.day <= 31 && (date.month == 1 || date.month == 3 || date.month == 5 || date.month == 7 || date.month == 8 || date.month == 10 || date.month == 12))
        || (date.day > 0 && date.day <= 30 && (date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11))
        || (date.day > 0 && date.day <= 29 && date.month == 2 && date.year % 4 == 0)
        || (date.day > 0 && date.day <= 28 && date.month == 2);
}

void Book::SetCharacter(string name_str, string lvl_str) {
    characters[name_str] = Level(stoi(lvl_str));
}

void Book::SetCharacter(string name_str, int lvl_str) {

    characters[name_str] = Level(lvl_str);
}

bool operator< (const Book& b1, const Book& b2) {
    if (b1.authors_surname == b2.authors_surname)
    {
        if (b1.authors_name == b2.authors_name)
        {
            if (b1.date.year == b2.date.year)
            {
                if (b1.date.month == b2.date.month)
                {
                    return b1.date.day < b2.date.day;
                }
                else
                {
                    return b1.date.month < b2.date.month;
                }
            }
            else
            {
                return b1.date.year < b2.date.year;
            }
        }
        else
        {
            return b1.authors_name < b2.authors_name;
        }
    }
    else
    {
        return b1.authors_surname < b2.authors_surname;
    }
}

ostream& operator<< (ostream& out, const Date& date) {
    out << right << setfill('0') << setw(2) << date.day << "." << setfill('0') << setw(2) << date.month << "." << setfill('0') << setw(4) << date.year;
    return out;
}

void Book::PrintBook(vector<string> to_print) {
    cout << endl;
    if (find(to_print.begin(), to_print.end(), "title") != to_print.end())
    {
        cout << title << endl << endl;
    }
    if (find(to_print.begin(), to_print.end(), "name") != to_print.end())
    {
        cout << "\t" << setfill(' ') << setw(18) << left << "Author:" << authors_name << " " << authors_surname << endl << endl;
    }
    if (find(to_print.begin(), to_print.end(), "pages") != to_print.end())
    {
        cout << "\t" << setfill(' ') << setw(18) << left << "Number of pages:" << num_of_pages << " pages" << endl << endl;
    }
    if (find(to_print.begin(), to_print.end(), "date") != to_print.end())
    {
        cout << "\t" << setfill(' ') << setw(18) << left << "First publicated:" << date << endl << endl;
    }
    if (find(to_print.begin(), to_print.end(), "description") != to_print.end())
    {
        cout << "Description:" << "\n\n" << description << endl << endl;
    }    
    if (find(to_print.begin(), to_print.end(), "characters") != to_print.end())
    {
        cout << "Characters: " << endl << endl;
        for (auto [name, lvl] : characters) {
            cout << "\t" << setfill('.') << setw(40) << left << name << lvl << " character" << endl;

        }
    }
    cout << endl;
}

void Book::Update(char to_update, string value) {
    string lvl;
    switch (to_update)
    {
    case '0':
        SetName(value);
        break;
    case '1':
        SetSurname(value);
        break;
    case '2':
        SetDescription(value);
        break;
    case '3':
        SetNumOfPages(value);
        break;
    case '4':
        SetDate(value);
        break;
    case '5':
        cout << "Enter the level of character in this book: ";
        getline(cin, lvl);
        SetCharacter(value, lvl);
        break;
    case '6':
        characters.erase(value);
        break;
    default:
        break;
    }
}
