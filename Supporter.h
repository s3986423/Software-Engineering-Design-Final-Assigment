//Member.h
#include <vector>
#include <map>
#include <string>
#include "Review.h"
#include "Availability.h"

class Member {
private:
    std::vector<int> supporterRatingScore;
    std::map<std::string, std::vector<int>> skills;
    std::vector<Review*> allSupporterReviews;

public:
    double getAverageSkillRating(std::string skillName);

    double getAverageSupporterRating();

    Availability listAvailability();

    Availability unlistAvailability();
};
