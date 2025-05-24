#include "EBook.h"
#include <iostream>
using namespace std;

EBook::EBook(int bookID, const string& title, const string& author,
             const string& publisher, int year, int copiesAvailable,
             const string& fileFormat, double fileSizeMB, const string& downloadLink)
    : Book(bookID, title, author, publisher, year, copiesAvailable),
      fileFormat(fileFormat), fileSizeMB(fileSizeMB), downloadLink(downloadLink) {}

void EBook::displayDetails() const {
    Book::displayDetails();
    cout << "File Format: " << fileFormat << "\nFile Size (MB): " << fileSizeMB
         << "\nDownload Link: " << downloadLink << "\n";
}
