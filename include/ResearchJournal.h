#ifndef RESEARCHJOURNAL_H
#define RESEARCHJOURNAL_H

#include "Book.h"
#include <string>

class ResearchJournal : public Book {
private:
    int volume;
    int issueNumber;
    std::string researchField;

public:
    ResearchJournal(int bookID, const std::string& title, const std::string& author,
                    const std::string& publisher, int year, int copiesAvailable,
                    int volume, int issueNumber, const std::string& researchField);

    void displayDetails() const override;
};

#endif
