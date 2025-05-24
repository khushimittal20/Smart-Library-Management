#include "Member.h"

Member::Member(int memberID, const std::string& name, const std::string& email, const std::string& phoneNumber)
    : memberID(memberID), name(name), email(email), phoneNumber(phoneNumber),
      maxBooksAllowed(3), booksIssuedCount(0), next(nullptr) {}

int Member::getMemberID() const {
    return memberID;
}

bool Member::canIssueMoreBooks() const {
    return booksIssuedCount < maxBooksAllowed;
}

void Member::issueBook() {
    if (canIssueMoreBooks()) {
        ++booksIssuedCount;
    } else {
        throw std::runtime_error("Maximum issue limit reached for member ID: " + std::to_string(memberID));
    }
}

void Member::returnBook() {
    if (booksIssuedCount > 0) {
        --booksIssuedCount;
    }
}

void Member::displayDetails() const {
    std::cout << "Member ID: " << memberID << "\nName: " << name
              << "\nEmail: " << email << "\nPhone: " << phoneNumber
              << "\nBooks Issued: " << booksIssuedCount << "/" << maxBooksAllowed << "\n";
}

void Member::setNext(Member* nextMember) {
    next = nextMember;
}

Member* Member::getNext() const {
    return next;
}
