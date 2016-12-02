#ifndef BOOKDATABASE_BOOK_H
#define BOOKDATABASE_BOOK_H

#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Book {
private:
    string title;
    string publisher;
    int yearOfPublication = 0;
    vector<string> authors;
public:
    Book();
    Book(const string& title, int numAuthors, vector<string>& authors, const string& publisher, int yearOfPublication);

    string getTitle()const;
    string getPublisher()const ;
    int getYearOfPublication()const;
    vector<string> getAuthors();

    bool operator==(const Book& book) const;
    bool operator<(const Book& book1)const;

    friend ostream& operator << (ostream& os, const Book& book);

};

#endif //BOOKDATABASE_BOOK_H
