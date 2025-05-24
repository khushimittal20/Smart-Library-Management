#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "Book.h"
#include "Member.h"

class Transaction {
private:
    int transactionID;
    Book* book;
    Member* member;
    std::string issueDate;
    std::string returnDate;
    bool isReturned;
    double fineAmount;

public:
    Transaction(int transactionID, Book* book, Member* member, const std::string& issueDate);

    void markReturned(const std::string& returnDate);
    double calculateFine(const std::string& currentDate) const;
    void displayTransaction() const;

    int getTransactionID() const;
    bool getIsReturned() const;
    Book* getBook() const;
    Member* getMember() const;
    void setFineAmount(double fine);
};

#endif
