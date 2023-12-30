//Member.cpp
#include "../include/Supporter.h"
#include "../include/Availability.h"
#include <iostream>
#include <numeric>

double Supporter::getAverageSkillRating(std::string skillName) {
    auto it = skills.find(skillName);
    if (it != skills.end()) {
        double sum = std::accumulate(it->second.begin(), it->second.end(), 0.0);
        return sum / it->second.size();
    } else {
        std::cerr << "Error: Skill not found.\n";
        return -1; // Indicate an error
    }
}

double Supporter::getAverageSupporterRating() {
    if (!supporterRatingScore.empty()) {
        double sum = std::accumulate(supporterRatingScore.begin(), supporterRatingScore.end(), 0.0);
        return sum / supporterRatingScore.size();
    } else {
        std::cerr << "Error: No ratings found.\n";
        return -1; // Indicate an error
    }
}

Availability Supporter::listAvailability() {
    // Implement the method here
    // For example:
    // 1. Return the supporter's availability
}

Availability Supporter::unlistAvailability() {
    // Implement the method here
    // For example:
    // 1. Remove the supporter's availability and return it
}
