#include <iostream>
#include <vector>
#include "../include/Host.h"

double Host::getAverageHostRating() {
        double average = 0.0;
        if (!hostRatingScore.empty()) {
            int sum = 0;
            for (int rating : hostRatingScore) {
                sum += rating;
            }
            average = static_cast<double>(sum) / hostRatingScore.size();
        }
        return average;
    }

bool Host::bookAvailability() {
        // Check for availability logic
        return true; // Placeholder return value
    }

void showAllAvailableSupporters(const std::string& fromTime, const std::string& toTime) {
        // Show available supporters logic
    }
