#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <map>
using namespace std;

class Library {
private:
    multimap <string, Book> books;
    // This is used if the library has several copies of the same book
    // that have the same ID in the multimap above.
    map <string, int> inventory; 

public:
    
    void addBook( const string& id, Book& book );
    void removeBook( const string& id );
    void removeBook( Book& book );

    Book* findBook( const string& id );
    Book* findBook( Book& book );

    size_t totalBooks() const;
    size_t totalUniqueBooks() const;

    // Three different ways to return the library back to user
    multimap<string, Book> mapOfBooks() const;

};

void displayLibrary( const Library& library );

#endif // LIBRARY_H