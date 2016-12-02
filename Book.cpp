#include "Book.h"

using namespace std;

Book::Book() {}
Book::Book(const string &title, int numAuthors, vector<string>& authors, const string &publisher, int yearOfPublication):
        title(title), publisher(publisher), yearOfPublication(yearOfPublication) {
    for (int i = 0; i < numAuthors; i++)
        this->authors.push_back(authors[i]);//adds parameter authors[i] to private authors vector
}

string Book::getTitle()const {
    return title;
}

string Book::getPublisher()const {
    return publisher;
}

int Book::getYearOfPublication()const{
    return yearOfPublication;
}

 vector<string> Book::getAuthors() {
    return authors;
}

bool Book::operator==(const Book& book)const {
    return book.getTitle() == title;
}

bool Book::operator<(const Book& book)const{
    return book.getTitle() > title;
}

ostream& operator << (ostream& os, const Book& book) {
    os << "Title: " << book.getTitle() << "\n"
       << "Authors: ";
    for(int i = 0; i < book.authors.size(); i++){
        os << book.authors[i] << " ";
    }
    os << "\nPublisher: " << book.getPublisher() << "\n"
       << "Year: " << book.getYearOfPublication() << "\n";
    return os;

}




