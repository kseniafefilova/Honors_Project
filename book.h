//Header for the book class
#ifndef BOOK_H
#define BOOK_H

#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
  string title;
  string author;
  string subject;
  string imageName;

public:
  Book(const string title, const string author, const string subject,
       const string imageName) {
    this->title = title;
    this->author = author;
    this->subject = subject;
    this->imageName = imageName;
  }

  string GetTitle() const { return title; }
  string GetAuthor() const { return author; }
  string GetSubject() const { return subject; }
  string GetImageName() { return imageName; }

  bool operator==(const Book &other) const;
};

#endif 