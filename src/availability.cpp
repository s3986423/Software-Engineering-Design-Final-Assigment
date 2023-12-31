#include "../include/Availability.h"
#include <iostream>
#include <iomanip>

Availability::Availability(time_t start, time_t end, int pointerPerHour, const std::vector<std::string>& skillSet, Member* supp, int minHostScore)
    : startTime(start), endTime(end), consumingPointPerHour(pointerPerHour), skills(skillSet), supporter(supp), minimumRequiredHostScore(minHostScore) {}

void Availability::showInfo() const {
    std::cout << "Availability Information:\n";
    std::cout << "Start Time: " << std::asctime(std::localtime(&startTime));
    std::cout << "End Time: " << std::asctime(std::localtime(&endTime));
    std::cout << "Pointer Per Hour: " << consumingPointPerHour << "\n";
    std::cout << "Skills Required: ";
    for (const auto& skill : skills) {
        std::cout << skill << " ";
    }
    std::cout << "\nSupporter: " << (supporter ? supporter->getUsername() : "None") << "\n";
    std::cout << "Minimum Required Host Score: " << minimumRequiredHostScore << "\n";
}


bool Availability::operator==(const Availability& other) const {
    // Compare the relevant attributes
    return startTime == other.startTime
        && endTime == other.endTime
        && consumingPointPerHour == other.consumingPointPerHour
        && skills == other.skills
        && supporter == other.supporter
        && minimumRequiredHostScore == other.minimumRequiredHostScore;
}

void Availability::addRequest(const Request& request) {
    if (isAvailable) {
        requests.push_back(request);
    }
}

void Availability::showRequests() const {
    if (!isAvailable) {
        std::cout << "This availability is no longer available." << std::endl;
        return;
    }

    for (const auto& request : requests) {
        request.showRequestDetails(); 
    }
}

void Availability::acceptRequest(int requestId, Member& host) {
    if (!isAvailable || requestId < 0 || requestId >= requests.size()) {
        std::cerr << "Invalid request or availability is no longer available." << std::endl;
        return;
    }

    Request& acceptedRequest = requests[requestId];
    host.deductPoints(consumingPointPerHour);
    supporter->addPoints(consumingPointPerHour);
    isAvailable = false;  // Mark the availability as no longer available

    // Notify the host, update the system, etc.
}