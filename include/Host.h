#ifndef HOST_H
#define HOST_H

#include "Member.h"
#include "Review.h"
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
    double getAverageHostRating();
    bool bookAvailability();
    void showAllAvailableSupporters(int fromTime, int toTime);

friend class Member;
};

#endif