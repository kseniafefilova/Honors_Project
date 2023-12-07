#include "book.h"
#include <iostream>
using namespace std;
 
bool Book::operator==( const Book& other ) const {
    return ( title  == other.title  &&
             author == other.author &&
             subject == other.subject );
}