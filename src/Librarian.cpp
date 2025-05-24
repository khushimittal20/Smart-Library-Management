#include "Librarian.h"
#include <iostream>

Librarian::Librarian(int employeeID, const std::string& name, const std::string& contact)
    : employeeID(employeeID), name(name), contact(contact) {}

void Librarian::addBook(Book* book) {
    
    std::cout << "Librarian: Add book request received for book ID " << book->getBookID() << "\n";
}

void Librarian::removeBook(int bookID) {
    std::cout << "Librarian: Remove book request received for book ID " << bookID << "\n";
}

void Librarian::addMember(Member* member) {
    std::cout << "Librarian: Add member request received for member ID " << member->getMemberID() << "\n";
}

void Librarian::removeMember(int memberID) {
    std::cout << "Librarian: Remove member request received for member ID " << memberID << "\n";
}

void Librarian::generateReport() {
    std::cout << "Librarian: Generating report...\n";
    // Implementation in Library class
}

void Librarian::displayDetails() const {
    std::cout << "Librarian ID: " << employeeID << "\nName: " << name << "\nContact: " << contact << "\n";
}
