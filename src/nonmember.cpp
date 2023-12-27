#include "../include/NonMember.h"
#include "../include/Member.h" 
#include "../include/Supporter.h"
#include <string>
#include <iostream>
#include <map>
#include <typeinfo>
 
NonMember::NonMember(std::vector<Member>& membersList) : members(membersList) {}

void NonMember::registerMember() {
    std::string username, fullName, email, homeAddress, password, skillName, skillLevel;
    int phoneNumber;
    std::map<std::string, vector<int>> skills;
    char addMoreSkills = 'y';

    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter full name: ";
    std::cin.ignore();  // To handle newline characters
    std::getline(std::cin, fullName);
    std::cout << "Enter phone number: ";
    std::cin >> phoneNumber;
    std::cout << "Enter email: ";
    std::cin >> email;
    std::cout << "Enter home address: ";
    std::cin.ignore();
    std::getline(std::cin, homeAddress);

    while (addMoreSkills == 'y' || addMoreSkills == 'Y') {
        std::cout << "Enter skill name: ";
        std::cin >> skillName;
        std::cout << "Enter skill level (as an integer): ";
        int skillLevelInt;
        std::cin >> skillLevelInt;
        skills[skillName].push_back(skillLevelInt);

        std::cout << "Add more skills? (y/n): ";
        std::cin >> addMoreSkills;
    }

    std::cout << "Enter password: ";
    std::cin >> password;

    // Process payment of $20 entry fee (placeholder)
    std::cout << "Processing $20 entry fee...\n";

    // Placeholder data for Supporter and Host attributes
    vector<int> emptyRatings;
    vector<Review*> emptyReviews;

    // Constructing new Member object with the provided details
    members.push_back(Member(username, fullName, phoneNumber, email, password, homeAddress, 20,  // Starting with 20 credit points
                             emptyRatings, skills, emptyReviews,  // Supporter details
                             emptyRatings, emptyReviews));        // Host details

    std::cout << "Registration successful. 20 credit points added.\n";
}

void NonMember::viewSupporterDetail(const std::string& memberUsername) const {
    for (const Member& member : members) {
        if (member.getUsername() == memberUsername) {
            // Check if the member is a Supporter
            const Supporter* supporter = dynamic_cast<const Supporter*>(&member);
            if (supporter != nullptr) {
                std::cout << "Supporter Details:\n";
                // Assuming Supporter has methods to access these details
                std::cout << "Full Name: " << supporter->getFullName() << std::endl;
                std::cout << "Phone Number: " << supporter->getPhoneNumber() << std::endl;
                std::cout << "Email: " << supporter->getEmail() << std::endl;
                std::cout << "Home Address: " << supporter->getHomeAddress() << std::endl;
                return;
            } else {
                std::cout << "The specified member is not a Supporter." << std::endl;
                return;
            }
        }
    }
    std::cout << "Member not found." << std::endl;
}
