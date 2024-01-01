// System.h
#include <vector>
#include "Member.h"
#include "Admin.h"
#include "Availability.h"

class System {
private:
    std::vector<Member> members;
    std::vector<Admin> admins;
    std::vector<Availability> availabilities;

public:
    void saveData();
    void loadData();
};
