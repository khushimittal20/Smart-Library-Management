#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <iostream>

class Member {
private:
    int memberID;
    std::string name;
    std::string email;
    std::string phoneNumber;
    int maxBooksAllowed;
    int booksIssuedCount;

    Member* next;  // For linked list node

public:
    Member(int memberID, const std::string& name, const std::string& email, const std::string& phoneNumber);

    int getMemberID() const;
    bool canIssueMoreBooks() const;
    void issueBook();
    void returnBook();
    void displayDetails() const;

    // Linked list pointers management
    void setNext(Member* nextMember);
    Member* getNext() const;
};

#endif
