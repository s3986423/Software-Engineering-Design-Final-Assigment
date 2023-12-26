#include "admin.h"
#include <iostream>

Admin::Admin(std::vector<Member>& membersVector) : members(membersVector) {}

bool Admin::resetPassword(const std::string& memberUsername, const std::string& newPassword) {
    for (Member& member : members) {
        if (member.getUsername() == memberUsername) {
            member.setPassword(newPassword);
            return true;
        }
    }
    return false;  // Member not found
}

void Admin::viewAllMember() const {
    std::cout << "Members List:\n";
    for (const Member& member : members) {
        std::cout << member.getUsername() << std::endl;
    }
}
