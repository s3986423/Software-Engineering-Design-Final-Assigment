#ifndef REQUEST_H
#define REQUEST_H

#include <string>
#include <ctime>

class Request {
private:
    time_t startTime;
    time_t endTime;
    std::string skill;
    std::string hostName; 

public:
    Request(time_t start, time_t end, const std::string& skill, const std::string& host);
    void showRequestDetails() const;
    
};

#endif
