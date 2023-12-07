#include "library.h"
#include <iostream>
using namespace std;

void Library::addBook(const string& id, Book& book) {
    books.insert(make_pair(id, book));
}

void Library::removeBook(const string& id) {
    books.erase(id);
}

void Library::removeBook(Book& book) {
 
}

Book* Library::findBook(const string& id) {
    
}

Book* Library::findBook(Book& book) {
    
}

multimap<string, Book> Library::mapOfBooks() const {
    return books;
}

void Library::displayLibrary() const {
for (const auto& [id, book] : books) {
        cout << "Book ID: " << id << ", Book Title: " << book.getTitle() << endl;
    }
}