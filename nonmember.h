#ifndef NONMEMBER_H
#define NONMEMBER_H

#include "Member.h"  // Include the Member class and its subclasses
#include <vector>
#include <string>

class NonMember {
private:
    const std::vector<Member>& members; // Reference to the list of members

public:
    NonMember(const std::vector<Member>& membersList);
    void registerMember(); // Simulates a registration process
    void viewSupporterDetail(const std::string& memberUsername) const; // Function to view supporter details
};

#endif
