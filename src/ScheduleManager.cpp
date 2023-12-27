#include "../include/ScheduleManager.h"
#include <iostream>

ScheduleManager::ScheduleManager(const std::vector<Availability>& availList) 
    : availabilities(availList) {}

void ScheduleManager::showAvailableSupporters(time_t startTime, time_t endTime) const {
    std::cout << "Available Supporters from " << std::asctime(std::localtime(&startTime))
              << " to " << std::asctime(std::localtime(&endTime)) << ":\n";

    for (const auto& avail : availabilities) {
        if (avail.getStartTime() >= startTime && avail.getEndTime() <= endTime) {
            std::cout << "Supporter: " << avail.getSupporter()->getUsername() << "\n";
            std::cout << "Required Skill Points: " << avail.getConsumingPointerPerHour() << "\n";
            std::cout << "Skills: ";
            for (const auto& skill : avail.getSkills()) {
                std::cout << skill << " ";
            }
            std::cout << "\n\n";
        }
    }
}
