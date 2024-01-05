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
class Member : public Supporter, public Host
{
private:
    string userName;
    string fullName;
    string phoneNumber;
    string email;
    string password;
    string homeAddress;
    int creditPoint;
    vector<string> blockedMember;
public:
    /*Orignal Constructor*/
    Member(string userName, string fullName, string phoneNumber, string email, string password, string homeAddress, int creditPoint, vector<string> blockedMember,
    vector<int> supporterRatingScore, map<string, vector<int>> skills, vector<Review*> allSupporterReviews,  //inherit from Supporter
    vector<int> hostRatingScore, vector<Review*> allHostReviews); //inherit from Host
    
    /*Overloading Constructors*/
    Member(string userName, 
        string fullName, 
        string phoneNumber, 
        string email, 
        string password, 
        string homeAddress, 
        int creditPoint); //7 Member attributes

    Member(string userName, 
        string fullName, 
        string phoneNumber, 
        string email, 
        string password, 
        string homeAddress, 
        int creditPoint,
        map<string, vector<int>> skills); //7 Member attributes and supporter skills

    /*Destructor*/
    ~Member();
    Member(/* parameters */);

    string getUsername() const { return userName; }
    int getCreditPoint() const { return creditPoint; }
    void addPoints(int points);
    void deductPoints(int points);
    int getcreditPoint() const;

    void performTopUp();
    void showSupporterAllReviews(Supporter* supporter);
    void showHostAllReviews(Host* host);
    void blockMember(Member* member);
};




