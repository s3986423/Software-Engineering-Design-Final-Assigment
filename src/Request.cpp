#include "../include/Request.h"
#include <iostream>

Request::Request(time_t start, time_t end, const std::string& skill, const std::string& host)
    : startTime(start), endTime(end), skill(skill), hostName(host) {}

void Request::showRequestDetails() const {
    std::cout << "Request from Host: " << hostName << "\n";
    std::cout << "Start Time: " << std::asctime(std::localtime(&startTime));
    std::cout << "End Time: " << std::asctime(std::localtime(&endTime));
    std::cout << "Required Skill: " << skill << "\n";
}
