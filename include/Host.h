#ifndef HOST_H
#define HOST_H

#include "Member.h"
#include <vector>
#include <string>


class Review {
    // Review class implementation
};

class Host {
private:
    std::vector<int> hostRatingScore;
    std::vector<Review*> allHostReviews;

public:
    double getAverageHostRating() {
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

    bool bookAvailability() {
        // Check for availability logic
        return true; // Placeholder return value
    }

    void showAllAvailableSupporters(const std::string& fromTime, const std::string& toTime) {
        // Show available supporters logic
    }
};

#endif