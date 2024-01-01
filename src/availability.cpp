#include "../include/Availability.h"
#include <iostream>
#include <iomanip>

Availability::Availability(time_t start, time_t end, int pointerPerHour, const std::vector<std::string>& skillSet, Member* supp, int minHostScore)
    : startTime(start), endTime(end), consumingPointerPerHour(pointerPerHour), skills(skillSet), supporter(supp), minimumRequiredHostScore(minHostScore) {}

void Availability::showInfo() const {
    std::cout << "Availability Information:\n";
    std::cout << "Start Time: " << std::asctime(std::localtime(&startTime));
    std::cout << "End Time: " << std::asctime(std::localtime(&endTime));
    std::cout << "Pointer Per Hour: " << consumingPointerPerHour << "\n";
    std::cout << "Skills Required: ";
    for (const auto& skill : skills) {
        std::cout << skill << " ";
    }
    std::cout << "\nSupporter: " << (supporter ? supporter->getUsername() : "None") << "\n";
    std::cout << "Minimum Required Host Score: " << minimumRequiredHostScore << "\n";
}

bool Availability::operator==(const Availability& other) const {
    // Compare the relevant attributes
    return startTime == other.startTime
        && endTime == other.endTime
        && consumingPointerPerHour == other.consumingPointerPerHour
        && skills == other.skills
        && supporter == other.supporter
        && minimumRequiredHostScore == other.minimumRequiredHostScore;
}