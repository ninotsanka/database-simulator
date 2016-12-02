#include "BookDatabase.h"

using namespace std;

Book BookDatabase::searchByTitle(const string& title) {
    map<string, Book>::iterator it = bookData.find(title);
    if(it == bookData.end()) {//if the title isn't found
        cout << "\nNo Books By The Title " << title << "\n";
        return Book();//returns empty Book object
    }
    else
        return it->second;
}

set<Book> BookDatabase::searchByAuthor(const string& author) {
    set<Book> temp;
    for(map<string, Book>::iterator it = bookData.begin(); it != bookData.end(); it++){//loops through the map
        vector<string> authors = it->second.getAuthors();//creates a new vector from map's value Book -> authors vector
        for(int i = 0; i < authors.size(); i++){//loops through the vector
            if(authors[i] == author)//checks if any of the entries are equal to passed parameter author
                temp.insert(it->second);//if so adds it to the temporary set
        }
    }
    return  temp;
}
//loops through the map, if the yearOfPublication is less than the passed year, adds it to the temporary set
set<Book> BookDatabase::publishedBefore(int year) {
    set<Book> temp;
    for(map<string, Book>::iterator it = bookData.begin(); it != bookData.end(); it++) {
        if (it->second.getYearOfPublication() < year)
            temp.insert(it->second);

    }
    return  temp;
}

//loops through the map, if the publishers are the same, adds it to the temporary set
set<Book> BookDatabase::searchByPublisher(const string& publisher) {
    set<Book> temp;
    for(map<string, Book>::iterator it = bookData.begin(); it != bookData.end(); it++) {
        if (it->second.getPublisher() == publisher)
            temp.insert(it->second);
    }
    return  temp;
}

void BookDatabase::addBook(Book& book) {
    pair<string, Book> newBook(book.getTitle(), book);//creates a new pair with Book object and its title
    bookData.insert(newBook);//adds the pair to the map
}

void BookDatabase::removeBook(const string& title) {
    bool wasRemoved = (bool)bookData.erase(title);
    cout << title << " was" <<(wasRemoved? "": " NOT")<<" removed successfully.\n";
}

//goes through the map and prints out its value member
ostream &operator<<(ostream &os, BookDatabase& bookDatabase) {
    for ( map<string, Book>::iterator it = bookDatabase.bookData.begin(); it != bookDatabase.bookData.end(); it++)
        os << it->second  << "\n";
    return os;
}