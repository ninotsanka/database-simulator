#include "BookDatabase.h"

using namespace std;

int main() {

    BookDatabase bookDatabase;

    string title;
    int numAuthors;
    string author;
    string publisher;
    int year;
    vector<string> authors;

    ifstream infile("books.txt");
    while (infile >> title) {
        authors.clear();//clears the vector before pushing any authors
        infile >> numAuthors;
        if(numAuthors > 1){
            for(int i = 0; i < numAuthors; i++) {
                infile >> author;
                authors.push_back(author);//adds numAuthors authors to the vector
            }
        } else{
            infile >> author;
            authors.push_back(author);//if numAuthors is 1
        }
        infile >> publisher;
        infile >> year;
        Book newBook(title, numAuthors, authors, publisher, year);//create a new Book object
        bookDatabase.addBook(newBook);//and add it to the bookDatabase map
    }
    cout << "\nOriginal Database\n\n";
    cout << bookDatabase;
    cout << "\n________________________________________\n";

    title = "Learning_Java";
    numAuthors = 2;
    authors = {"Patrick_Niemeyer", "Daniel_Leuck"};
    publisher = "Oreilly";
    year = 2013;
    Book newBook = Book(title, numAuthors, authors, publisher, year);
    bookDatabase.addBook(newBook);
    cout << "\nAdding a New Book\n\n" << newBook << "\n";
    cout << "\nNew Database\n\n";
    cout << bookDatabase;
    cout << "\n________________________________________\n";

    cout << "\nSearch By Title\n\n";
    cout << bookDatabase.searchByTitle("Case_Studies_in_Forensic_Anthropology");
    cout << bookDatabase.searchByTitle("Test_title");
    cout << "\n________________________________________\n";

    cout << "\nSearch By Author\n\n";
    set<Book> searchByAuthor = bookDatabase.searchByAuthor("McConnell");
    for(set<Book>::iterator it = searchByAuthor.begin(); it!=searchByAuthor.end(); it++)
        cout << *it <<" \n";
    cout << "\n________________________________________\n";

    cout << "\nPublished Before\n\n";
    set<Book>  publishedBefore = bookDatabase.publishedBefore(2012);
    for(set<Book>::iterator it = publishedBefore.begin(); it!=publishedBefore.end(); it++)
        cout << *it <<" \n";
    cout << "\n________________________________________\n";

    cout << "\nSearch By Publisher\n\n";
    set<Book> publishedBy = bookDatabase.searchByPublisher("Wiley_and_Sons");
    for(set<Book>::iterator it = publishedBy.begin(); it!=publishedBy.end(); it++)
        cout << *it <<" \n";
    cout << "\n________________________________________\n";

    cout << "\nRemoving a book\n\n";
    bookDatabase.removeBook("Data_Structures_with_C++_Using_STL");
    cout << "\n________________________________________\n";

    cout << "\nFinal Database\n\n";
    cout << bookDatabase;



    return 0;
}