#ifndef AVAILABILITY_H
#define AVAILABILITY_H

#include "Member.h"
#include <vector>
#include <ctime>
#include <string>

class Availability {
private:
    time_t startTime;
    time_t endTime;
    int consumingPointerPerHour;
    std::vector<std::string> skills;
    Member* supporter;  // Pointer to a Member (Supporter)
    int minimumRequiredHostScore;

public:
    Availability(time_t start, time_t end, int pointerPerHour, const std::vector<std::string>& skillSet, Member* supp, int minHostScore);
    void showInfo() const;

    // Getter methods
    time_t getStartTime() const { return startTime; }
    time_t getEndTime() const { return endTime; }
    Member* getSupporter() const { return supporter; }
    int getConsumingPointerPerHour() const { return consumingPointerPerHour; }
    const std::vector<std::string>& getSkills() const { return skills; }
};

#endif
