#include "Book.h"
#include <iostream>
using namespace std;

Book::Book(int bookID, const string& title, const string& author,
           const string& publisher, int year, int copiesAvailable)
    : bookID(bookID), title(title), author(author), publisher(publisher),
      year(year), copiesAvailable(copiesAvailable) {}

int Book::getBookID() const {
    return bookID;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

int Book::getCopiesAvailable() const {
    return copiesAvailable;
}

void Book::issueCopy() {
    if (copiesAvailable > 0) {
        --copiesAvailable;
    } else {
        throw runtime_error("Book not available for issue.");
    }
}

void Book::returnCopy() {
    ++copiesAvailable;
}

void Book::displayDetails() const {
    cout << "Book ID: " << bookID << "\nTitle: " << title
         << "\nAuthor: " << author << "\nPublisher: " << publisher
         << "\nYear: " << year << "\nCopies Available: " << copiesAvailable << "\n";
}
