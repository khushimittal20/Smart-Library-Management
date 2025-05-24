#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include "Book.h"
#include "Member.h"
#include "Librarian.h"
#include "Transaction.h"

class Library {
private:
    std::vector<Book*> books;
    Member* membersHead;   // linked list head for members
    Librarian librarian;
    std::vector<Transaction*> transactions;

    std::stack<Transaction*> recentIssues;
    std::queue<Transaction*> recentReturns;

    int nextTransactionID;

public:
    Library(const Librarian& librarian);

    ~Library();  

    void addBook(Book* book);
    void removeBook(int bookID);

    void addMember(Member* member);
    void removeMember(int memberID);

    Book* searchBookByID(int bookID);
    Member* searchMemberByID(int memberID);

    void issueBook(int bookID, int memberID, const std::string& issueDate);
    void returnBook(int bookID, int memberID, const std::string& returnDate);

    double calculateFine(int memberID, const std::string& currentDate);

    void generateReport();

    // Template function for searching book by any key 
    template<typename T>
    Book* searchBook(T key);

    // Template function for sorting books by a criteria 
    template<typename Comparator>
    void sortBooks(Comparator comp);

private:
    
    void deleteMembersList();
};

#endif
