#include "Nonmember.h"
#include <iostream>
#include <map>
#include <typeinfo>

NonMember::NonMember(std::vector<Member>& membersList) : members(membersList) {}

void NonMember::registerMember() {
    PersonalInfo pInfo;
    std::map<std::string, std::string> skills;
    std::string password, skillName, skillLevel;

    std::cout << "Enter username: ";
    std::cin >> pInfo.username;
    std::cout << "Enter full name: ";
    std::cin.ignore(); // To handle newline characters
    std::getline(std::cin, pInfo.fullName);
    std::cout << "Enter phone number: ";
    std::cin >> pInfo.phoneNumber;
    std::cout << "Enter email: ";
    std::cin >> pInfo.email;
    std::cout << "Enter home address: ";
    std::cin.ignore();
    std::getline(std::cin, pInfo.homeAddress);

    char addMoreSkills = 'y';
    while (addMoreSkills == 'y' || addMoreSkills == 'Y') {
        std::cout << "Enter skill name: ";
        std::cin >> skillName;
        std::cout << "Enter skill level: ";
        std::cin >> skillLevel;
        skills[skillName] = skillLevel;

        std::cout << "Add more skills? (y/n): ";
        std::cin >> addMoreSkills;
    }

    std::cout << "Enter password: ";
    std::cin >> password;

    // Process payment of $20 entry fee (this is a placeholder)
    std::cout << "Processing $20 entry fee...\n";

    // Add new member with 20 initial credit points
    //Cho function de push back voi 20 credit nhe
    members.push_back(Member(pInfo, skills, password));

    std::cout << "Registration successful. 20 credit points added.\n";
}

void NonMember::viewSupporterDetail(const std::string& memberUsername) const {
    for (const Member& member : members) {
        if (member.getUsername() == memberUsername) {
            // Check if the member is a Supporter
            const Supporter* supporter = dynamic_cast<const Supporter*>(&member);
            if (supporter != nullptr) {
                std::cout << "Supporter Details:\n";
                std::cout << "Full Name: " << supporter->getFullName() << std::endl;
                std::cout << "Phone Number: " << supporter->getPhoneNumber() << std::endl;
                std::cout << "Email: " << supporter->getEmail() << std::endl;
                std::cout << "Home Address: " << supporter->getHomeAddress() << std::endl;
                // Display other relevant details specific to Supporter
                return;
            } else {
                std::cout << "The specified member is not a Supporter." << std::endl;
                return;
            }
        }
    }
    std::cout << "Member not found." << std::endl;
}