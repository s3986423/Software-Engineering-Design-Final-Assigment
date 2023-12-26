#include <iostream>
#include <vector>
#include <map>
#include "Review.h"
#include "Host.h"
#include "Supporter.h"

using std::string;
using std::cout;
using std::vector;
using std::map;

//Member constructor
class Member : public Supporter, Host
{
private:
    string userName;
    string fullName;
    int phoneNumber;
    string email;
    string password;
    string homeAddress;
    int creditPoint;
public:
    Member(string userName, string fullName, int phoneNumber, string email, string password, string homeAddress, int creditPoint,
    vector<int> supporterRatingScore, map<string, vector<int>> skills, vector<Review*> allSupporterReviews,  //inherit from Supporter
    vector<int> hostRatingScore, vector<Review*> allHostReviews); //inherit from Host
    ~Member();

    void performTopUp(int amount);
    void showSupporterAllReviews(Supporter* supporter);
    void showHostAllReviews(Host* host);
    void blockMember(Member* member);
};




