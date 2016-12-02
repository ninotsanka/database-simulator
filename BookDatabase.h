#ifndef BOOK_DATABASE_H
#define BOOK_DATABASE_H

#include "Book.h"
#include <map>
#include <set>
#include <iostream>
#include <iterator>

using namespace std;

class BookDatabase{
private:
    map<string, Book> bookData;

public:
    Book searchByTitle(const string& title);
    set<Book> searchByAuthor(const string& author);
    set<Book> publishedBefore(int year);
    set<Book> searchByPublisher(const string& publisher);
    void addBook(Book& book);
    void removeBook(const string& title);

    friend ostream& operator <<(ostream& os, BookDatabase& bookDatabase);

};
#endif //BOOK_DATABASE_H