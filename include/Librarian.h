#ifndef LIBRARIAN_H
#define LIBRARIAN_H

#include <string>
#include "Book.h"
#include "Member.h"
using namespace std;

class Librarian {
private:
    int employeeID;
    string name;
    string contact;

public:
    Librarian(int employeeID, const string& name, const string& contact);

    void addBook(Book* book);         
    void removeBook(int bookID);

    void addMember(Member* member);    
    void removeMember(int memberID);

    void generateReport();             
    void displayDetails() const;
};

#endif
