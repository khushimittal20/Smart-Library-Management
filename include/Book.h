#ifndef BOOK_H
#define BOOK_H
using namespace std;
#include <string>

class Book {
protected:
    int bookID;
    string title;
    string author;
    string publisher;
    int year;
    int copiesAvailable;

public:
    Book(int bookID, const string& title, const string& author,
         const string& publisher, int year, int copiesAvailable);

    virtual ~Book() {}

    int getBookID() const;
    string getTitle() const;
    string getAuthor() const;
    int getCopiesAvailable() const;

    virtual void issueCopy();   
    virtual void returnCopy();  
    virtual void displayDetails() const;
};

#endif
