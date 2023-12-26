#include <iostream>
#include <vector>
#include <map>
#include "Member.h"
#include "Review.h"

using std::string;
using std::cout;
using std::vector;
using std::map;

Member::Member(/*Member attributes*/
            string userNameInput = "", 
            string fullNameInput = "", 
            int phoneNumberInput = 0, 
            string emailInput = "", 
            string passwordInput = "", 
            string homeAddressInput = "",
            int creditPointInput = 0,

            /*Supporter attributes*/
            vector<int> supporterRatingScore,
            map<string, vector<int>> skills,
            vector<Review*> allSupporterReviews,
            
            /*Host attributes*/
            vector<int> hostRatingScore,
            vector<Review*> allHostReviews)
            
            /*Member's*/
            : userName(userNameInput), fullName(fullNameInput), 
            phoneNumber(phoneNumberInput), email(emailInput), 
            password(passwordInput), homeAddress(homeAddressInput), creditPoint(creditPointInput)
            /*Supporter's*/
            Supporter(supporterRatingScore, skills, allSupporterReviews),
            /*Host's*/
            Host(hostRatingScore, allHostReviews){};
{
}

Member::~Member()
{
}
