//Member.h
#include <vector>
#include <map>
#include <string>
#include "Review.h"
#include "Availability.h"

class Supporter {
private:
    std::vector<int> supporterRatingScore;
    std::map<std::string, std::vector<int>> skills;
    std::vector<Review*> allSupporterReviews;

public:

    Supporter(vector<int> supporterRatingScore, 
            map<std::string, std::vector<int>> skills, 
            vector<Review*> allSupporterReviews);

    double getAverageSkillRating(std::string skillName);

    double getAverageSupporterRating();

    Availability listAvailability();

    Availability unlistAvailability();

friend class Member;
};
