#include <iostream>
#include <vector>
#include "../include/Host.h"

int main() {
    // Test the Host class
    Host host;

    // Call the methods
    double averageRating = host.getAverageHostRating();
    bool isAvailable = host.bookAvailability();
    host.showAllAvailableSupporters("", "");

    return 0;
}