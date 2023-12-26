#ifndef SCHEDULEMANAGER_H
#define SCHEDULEMANAGER_H

#include "Availability.h"
#include <vector>
#include <ctime>

class ScheduleManager {
private:
    std::vector<Availability> availabilities;

public:
    ScheduleManager(const std::vector<Availability>& availList);
    void showAvailableSupporters(time_t startTime, time_t endTime) const;
};

#endif
