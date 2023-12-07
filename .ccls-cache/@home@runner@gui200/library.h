#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"
#include <map>
using namespace std;

class Library {
private:
    multimap <string, Book> books;

public:
    
    void addBook( const string& id, Book& book );
    void removeBook( const string& id );
    void removeBook( Book& book );

    Book* findBook( const string& id );
    Book* findBook( Book& book );
    
    multimap<string, Book> mapOfBooks() const;
    void displayLibrary( const Library& library );
};

#endif 