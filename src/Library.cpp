#include "Library.h"
#include <iostream>
#include <stdexcept>
using namespace std;

// Constructor
Library::Library(const Librarian& librarian)
    : librarian(librarian), membersHead(nullptr), nextTransactionID(1) {}

Library::~Library() {
    // Delete all books
    for (auto b : books) {
        delete b;
    }

    // Delete members linked list
    deleteMembersList();

    // Delete transactions
    for (auto t : transactions) {
        delete t;
    }
}

void Library::deleteMembersList() {
    Member* current = membersHead;
    while (current) {
        Member* toDelete = current;
        current = current->getNext();
        delete toDelete;
    }
}

// Add book to library
void Library::addBook(Book* book) {
    books.push_back(book);
    cout << "Book added: " << book->getTitle() << "\n";
}

// Remove book by ID
void Library::removeBook(int bookID) {
    auto it = remove_if(books.begin(), books.end(),
        [bookID](Book* b) { return b->getBookID() == bookID; });

    if (it != books.end()) {
        delete *it;
        books.erase(it, books.end());
        cout << "Book removed with ID: " << bookID << "\n";
    } else {
        cout << "Book ID not found: " << bookID << "\n";
    }
}

// Add member to linked list
void Library::addMember(Member* member) {
    member->setNext(membersHead);
    membersHead = member;
    cout << "Member added: " << member->getMemberID() << "\n";
}

// Remove member by ID
void Library::removeMember(int memberID) {
    Member* current = membersHead;
    Member* prev = nullptr;

    while (current) {
        if (current->getMemberID() == memberID) {
            if (prev) {
                prev->setNext(current->getNext());
            } else {
                membersHead = current->getNext();
            }
            delete current;
            cout << "Member removed: " << memberID << "\n";
            return;
        }
        prev = current;
        current = current->getNext();
    }
    cout << "Member ID not found: " << memberID << "\n";
}

// Search book by ID
Book* Library::searchBookByID(int bookID) {
    for (auto b : books) {
        if (b->getBookID() == bookID)
            return b;
    }
    return nullptr;
}

// Search member by ID
Member* Library::searchMemberByID(int memberID) {
    Member* current = membersHead;
    while (current) {
        if (current->getMemberID() == memberID)
            return current;
        current = current->getNext();
    }
    return nullptr;
}

// Issue book
void Library::issueBook(int bookID, int memberID, const string& issueDate) {
    Book* book = searchBookByID(bookID);
    if (!book) {
        throw runtime_error("Book not available with ID: " + to_string(bookID));
    }

    if (book->getCopiesAvailable() <= 0) {
        throw runtime_error("No copies available for book ID: " + to_string(bookID));
    }

    Member* member = searchMemberByID(memberID);
    if (!member) {
        throw runtime_error("Invalid member ID: " + to_string(memberID));
    }

    if (!member->canIssueMoreBooks()) {
        throw runtime_error("Maximum issue limit reached for member ID: " + to_string(memberID));
    }

    // Issue book
    book->issueCopy();
    member->issueBook();

    Transaction* transaction = new Transaction(nextTransactionID++, book, member, issueDate);
    transactions.push_back(transaction);

    recentIssues.push(transaction);

    cout << "Book issued successfully.\n";
}

// Return book
void Library::returnBook(int bookID, int memberID, const string& returnDate) {
    Member* member = searchMemberByID(memberID);
    if (!member) {
        throw runtime_error("Invalid member ID: " + to_string(memberID));
    }

    Book* book = searchBookByID(bookID);
    if (!book) {
        throw runtime_error("Book not found with ID: " + to_string(bookID));
    }

    // Find the active transaction (issued but not returned)
    Transaction* transaction = nullptr;
    for (auto t : transactions) {
        if (t->getBook()->getBookID() == bookID && t->getMember()->getMemberID() == memberID && !t->getIsReturned()) {
            transaction = t;
            break;
        }
    }

    if (!transaction) {
        throw runtime_error("No active issue transaction found for book ID " + to_string(bookID) +
                                 " and member ID " + to_string(memberID));
    }

    // Mark returned
    transaction->markReturned(returnDate);
    double fine = transaction->calculateFine(returnDate);
    // transaction->fineAmount = fine;
    transaction->setFineAmount(fine);


    book->returnCopy();
    member->returnBook();

    recentReturns.push(transaction);

    cout << "Book returned successfully. Fine: $" << fine << "\n";
}

// Calculate fine for a member
double Library::calculateFine(int memberID, const string& currentDate) {
    double totalFine = 0.0;
    for (auto t : transactions) {
        if (t->getMember()->getMemberID() == memberID && !t->getIsReturned()) {
            totalFine += t->calculateFine(currentDate);
        }
    }
    return totalFine;
}

// Generate report
void Library::generateReport() {
    cout << "----- Library Report -----\n";
    cout << "Books in library: " << books.size() << "\n";
    for (auto b : books) {
        b->displayDetails();
        cout << "-----------------------\n";
    }

    cout << "Members in library:\n";
    Member* current = membersHead;
    while (current) {
        current->displayDetails();
        cout << "-----------------------\n";
        current = current->getNext();
    }

    cout << "Transactions:\n";
    for (auto t : transactions) {
        t->displayTransaction();
        cout << "-----------------------\n";
    }
}

// Template search by key 
template<typename T>
Book* Library::searchBook(T key) {
    for (auto b : books) {
        if (b->getTitle() == key) {
            return b;
        }
    }
    return nullptr;
}

// Template sort by criteria
template<typename Comparator>
void Library::sortBooks(Comparator comp) {
    sort(books.begin(), books.end(), comp);
}
