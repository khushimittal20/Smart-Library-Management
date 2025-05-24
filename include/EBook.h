#ifndef EBOOK_H
#define EBOOK_H
using namespace std;

#include "Book.h"
#include <string>

class EBook : public Book {
private:
    string fileFormat;
    double fileSizeMB;
    string downloadLink;

public:
    EBook(int bookID, const string& title, const string& author,
          const string& publisher, int year, int copiesAvailable,
          const string& fileFormat, double fileSizeMB, const string& downloadLink);

    void displayDetails() const override;
};

#endif
