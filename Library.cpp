#include "Library.h"

Library::Library(string file_books, string file_characters) {
    ReadBooks(file_books);
}

Library::~Library() {
    WriteBooks();
}

void Library::ReadBooks(string file) {
    ifstream in(file);
    string temp;
    if (in)
    {
        while (!in.eof())
        {
            Book new_book;
            getline(in, temp);
            if (temp == "")
            {
                break;
            }
            new_book.SetTitle(temp);
            getline(in, temp);
            new_book.SetName(temp);
            getline(in, temp);
            new_book.SetSurname(temp);
            getline(in, temp);
            new_book.SetDescription(temp);
            getline(in, temp);
            new_book.SetDate(temp);
            getline(in, temp);
            new_book.SetNumOfPages(temp);
            getline(in, temp);
            while (temp[0] != '@')
            {
                string ch_id = temp;
                getline(in, temp);
                new_book.SetCharacter(ch_id, temp);
                getline(in, temp);
            }
            SetBook(new_book);
        }
    }
    else
    {
        throw invalid_argument("Wrong filename.");
    }
}

void Library::WriteBooks(string file) {
    ofstream out(file);
    if (out)
    {
        for(auto book : books)
        {
            out << book.GetTitle() << endl;
            out << book.GetName() << endl;
            out << book.GetSurname() << endl;
            out << book.GetDescription() << endl;
            book.GetDateStream(out); out << endl;
            out << book.GetNumOfPages() << endl;
            for (auto [ch_name, level] : book.GetAllCharacters()) {
                out << ch_name << endl;
                out << book.GetCharacterLevelInt(ch_name) << endl;
            }
            out << '@' << endl;
        }
    }
    else
    {
        throw invalid_argument("Wrong filename.");
    }
}

void Library::SetBook(Book new_book) {
    books.push_back(new_book);
    Sort();
}

void Library::Sort() {
   sort(books.begin(), books.end());
}

void Library::AddBook()
{
    unsigned int id = 0;
    Book new_book;
    string str_in;
    cout << "Enter book title: ";
    getline(cin, str_in);
    new_book.SetTitle(str_in);
    cout << "Enter author`s name: ";
    getline(cin, str_in);
    new_book.SetName(str_in);
    cout << "Enter author`s surname: ";
    getline(cin, str_in);
    new_book.SetSurname(str_in);
    cout << "Enter date of publication: ";
    getline(cin, str_in);
    regex rx(R"(\d\d(.)\d\d(.)\d\d\d\d)");
    while (!regex_match(str_in, rx))
    {
        cout << "Invalod date input. Try again: ";
        getline(cin, str_in);

    }
    new_book.SetDate(str_in);
    cout << "Enter book description: ";
    getline(cin, str_in);
    new_book.SetDescription(str_in);
    cout << "Enter number of pages: ";
    getline(cin, str_in);
    new_book.SetNumOfPages(str_in);
    cout << "Enter name of main character: ";
    getline(cin, str_in);
    new_book.SetCharacter(str_in, 1);

    cout << "Add more characters?" << endl;
    cout << "'Y' or 'N'" << endl;
    getline(cin, str_in);

    while (str_in[0] == 'Y' || str_in[0] == 'y')
    {
        cout << "Enter name of character: ";
        getline(cin, str_in);
        string lvl;
        cout << "Enter the level of character in this book: ";
        getline(cin, lvl);
        new_book.SetCharacter(str_in, lvl);
        cout << "Add more characters?" << endl;
        cout << "'Y' or 'N'" << endl;
        getline(cin, str_in);
    }
    SetBook(new_book);
}

void Library::PrintAll() {
    for (auto book : books) {
        book.PrintBook();
    }
}

void Library::FindByCharacter(string in_name, bool& flag) {
    for (Book book : books)
    {
        for (auto [ch_name, ch_lvl] : book.GetAllCharacters())
        {
            if (in_name.find(ch_name) != string::npos || ch_name.find(in_name) != string::npos)
            {
                book.PrintBook({ "title", "name", "date" });
                flag = true;
            }
        }
    }
}

void Library::DeleteBook(string in_name, bool& flag) {
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].GetTitle() == in_name)
        {
            books.erase(books.begin() + i);
        }
    }
}

void Library::UpdateBook(string in_name, bool& flag, char to_update, string value) {
    for (int i = 0; i < books.size(); i++)
    {
        if (books[i].GetTitle() == in_name)
        {
            books[i].Update(to_update, value);
        }
    }
}

bool Library::Find(string find_text, char to_do, char to_update, string value)
{
    bool flag = false;
    for (Book book : books)
    {
        if (find_text.find(book.GetName()) != string::npos || find_text.find(book.GetSurname()) != string::npos || find_text.find(book.GetTitle()) != string::npos ||
            book.GetName().find(find_text) != string::npos || book.GetSurname().find(find_text) != string::npos || book.GetTitle().find(find_text) != string::npos)
        {
            switch (to_do)
            {
            case 'f':
                book.PrintBook({ "title", "name", "date" });
                flag = true;
                break;
            case 'i':
                book.PrintBook();
                flag = true;
                break;
            case 'd':
                DeleteBook(find_text, flag);
                break;
            case 'u':
                UpdateBook(find_text, flag, to_update, value);
                break;
            default:
                break;
            }
        }
    }
    if (to_do == 'f')
    {
        if (!flag)
        {
            FindByCharacter(find_text, flag);
        }
    }
    return flag;
}