#include <iostream>
#include "Library.h"
#include "Book.h"
#include "EBook.h"
#include "ResearchJournal.h"
#include "Member.h"
#include "Librarian.h"
using namespace std;


int main() {
    try {
        // Create a librarian
        Librarian librarian(101, "Alice Smith", "alice@library.com");

        // Create library with the librarian
        Library library(librarian);

        // Add some books
        Book* book1 = new Book(1, "C++ Programming", "Bjarne Stroustrup", "Pearson", 2013, 5);
        EBook* ebook1 = new EBook(2, "Learn STL", "John Doe", "TechPress", 2020, 3, "PDF", 2.5, "http://downloadlink.com/stl.pdf");
        ResearchJournal* journal1 = new ResearchJournal(3, "Quantum Computing", "Jane Roe", "SciencePub", 2021, 2, 10, 3, "Physics");

        library.addBook(book1);
        library.addBook(ebook1);
        library.addBook(journal1);

        // Add some members
        Member* member1 = new Member(201, "Khushi Mittal", "khushi@example.com", "1234567890");
        Member* member2 = new Member(202, "Plaksha Goel", "plaksha@example.com", "0987654321");

        library.addMember(member1);
        library.addMember(member2);

        // Issue a book to Khushi
        library.issueBook(1, 201, "2025-05-20");

        // Issue an ebook to Plaksha
        library.issueBook(2, 202, "2025-05-21");

        // Try to issue a non-existing book (to test exception handling)
        try {
            library.issueBook(10, 201, "2025-05-22");  // BookID 10 doesn't exist
        } catch (const exception& e) {
            cerr << "Exception caught: " << e.what() << "\n";
        }

        // Return a book from Khushi
        library.returnBook(1, 201, "2025-05-25");

        // Calculate fine for Khushi as of a date (should be zero if returned on time)
        double fine = library.calculateFine(201, "2025-05-25");
        cout << "Fine for member 201: $" << fine << "\n";

        // Generate report to show current state
        library.generateReport();

    } catch (const exception& e) {
        cerr << "Fatal error: " << e.what() << "\n";
    }

    return 0;
}
