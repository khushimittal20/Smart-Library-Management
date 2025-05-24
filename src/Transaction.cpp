#include "Transaction.h"
#include <iostream>
#include <cstdlib> 
#include <cmath>   // For max()

Transaction::Transaction(int transactionID, Book* book, Member* member, const std::string& issueDate)
    : transactionID(transactionID), book(book), member(member), issueDate(issueDate),
      returnDate(""), isReturned(false), fineAmount(0.0) {}

void Transaction::markReturned(const std::string& returnDate) {
    this->returnDate = returnDate;
    isReturned = true;
}

double Transaction::calculateFine(const std::string& currentDate) const {
    // fine logic: assume dates are "YYYY-MM-DD"
    // Fine = $1 per day after 14 days of issue

    int issueDay = std::stoi(issueDate.substr(8, 2));
    int returnDay = std::stoi(currentDate.substr(8, 2));

    int daysDiff = returnDay - issueDay;
    int gracePeriod = 14;

    if (daysDiff > gracePeriod) {
        return (daysDiff - gracePeriod) * 1.0;  // $1 per extra day
    }
    return 0.0;
}

void Transaction::displayTransaction() const {
    std::cout << "Transaction ID: " << transactionID << "\n"
              << "Book ID: " << book->getBookID() << "\n"
              << "Member ID: " << member->getMemberID() << "\n"
              << "Issue Date: " << issueDate << "\n"
              << "Return Date: " << (isReturned ? returnDate : "Not returned yet") << "\n"
              << "Fine: $" << fineAmount << "\n"
              << "Status: " << (isReturned ? "Returned" : "Issued") << "\n";
}

int Transaction::getTransactionID() const {
    return transactionID;
}

bool Transaction::getIsReturned() const {
    return isReturned;
}

Book* Transaction::getBook() const {
    return book;
}

Member* Transaction::getMember() const {
    return member;
}
void Transaction::setFineAmount(double fine) {
    this->fineAmount = fine;
}