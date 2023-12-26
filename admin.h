#ifndef ADMIN_H
#define ADMIN_H

#include "Member.h"
#include <string>
#include <vector>

class Admin {
private:
    std::vector<Member>& members;  // Reference to a vector of Member objects

public:
    Admin(std::vector<Member>& membersVector);
    bool resetPassword(const std::string& memberUsername, const std::string& newPassword);
    void viewAllMember() const;  // Function to view all members
};

#endif
