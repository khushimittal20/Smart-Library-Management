#include "ResearchJournal.h"
#include <iostream>

ResearchJournal::ResearchJournal(int bookID, const std::string& title, const std::string& author,
                                 const std::string& publisher, int year, int copiesAvailable,
                                 int volume, int issueNumber, const std::string& researchField)
    : Book(bookID, title, author, publisher, year, copiesAvailable),
      volume(volume), issueNumber(issueNumber), researchField(researchField) {}

void ResearchJournal::displayDetails() const {
    Book::displayDetails();
    std::cout << "Volume: " << volume << "\nIssue Number: " << issueNumber
              << "\nResearch Field: " << researchField << "\n";
}
