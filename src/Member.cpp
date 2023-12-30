#include <iostream>
#include <vector>
#include <map>
#include "../include/Member.h"

using std::string;
using std::cout;
using std::cin;
using std::cerr;
using std::vector;
using std::map;

/*Member Constructor*/
Member::Member(/*Member attributes*/
            string userNameInput = "", 
            string fullNameInput = "", 
            string phoneNumberInput = "", 
            string emailInput = "", 
            string passwordInput = "", 
            string homeAddressInput = "",
            int creditPointInput = 0,

            /*Supporter attributes*/
            vector<int> supporterRatingScoreInput = vector<int>(),
            map<string, vector<int>> skillsInput = map<string, vector<int>>(),
            vector<Review*> allSupporterReviewsInput = vector<Review*>(),
            
            /*Host attributes*/
            vector<int> hostRatingScoreInput = vector<int>(),
            vector<Review*> allHostReviewsInput = vector<Review*>())
            
            /*Member's*/
            : userName(userNameInput), fullName(fullNameInput), 
            phoneNumber(phoneNumberInput), email(emailInput), 
            password(passwordInput), homeAddress(homeAddressInput), creditPoint(creditPointInput),
            /*Supporter's*/
            Supporter(supporterRatingScoreInput, skillsInput, allSupporterReviewsInput),
            /*Host's*/
            Host(hostRatingScoreInput, allHostReviewsInput)
{
    // Clear the vectors and map
    this->supporterRatingScore.clear();
    this->skills.clear();
    this->allSupporterReviews.clear();
    this->hostRatingScore.clear();
    this->allHostReviews.clear();
};

Member::~Member()
{
}

/*Overloaded Constructor 1 - 7 Member attributes*/
Member::Member(string userNameInput, 
            string fullNameInput, 
            string phoneNumberInput, 
            string emailInput, 
            string passwordInput, 
            string homeAddressInput, 
            int creditPointInput)
    
    /*Member's*/
    : userName(userNameInput), fullName(fullNameInput), 
    phoneNumber(phoneNumberInput), email(emailInput), 
    password(passwordInput), homeAddress(homeAddressInput), creditPoint(creditPointInput),
    /*Supporter's*/
    Supporter(vector<int>(), map<string, vector<int>>(), vector<Review*>()),
    /*Host's*/
    Host(vector<int>(), vector<Review*>())
{
    // Initialize other attributes as needed
}

/*Overloaded Constructor 2 - 7 Member attributes and supporter skills*/
Member::Member(string userNameInput, 
            string fullNameInput, 
            string phoneNumberInput, 
            string emailInput, 
            string passwordInput, 
            string homeAddressInput, 
            int creditPointInput, 
            map<string, vector<int>> skillsInput)

    /*Member's*/
    : userName(userNameInput), fullName(fullNameInput), 
    phoneNumber(phoneNumberInput), email(emailInput), 
    password(passwordInput), homeAddress(homeAddressInput), creditPoint(creditPointInput),
    /*Supporter's*/
    Supporter(vector<int>(), skillsInput, vector<Review*>()),
    /*Host's*/
    Host(vector<int>(), vector<Review*>())
{
    // Initialize other attributes as needed
}


/*Perform top up method*/
void Member::performTopUp(){
    int amountInput; string passwordInput;
    cout << "---Performing Account Top Up---" << '\n';
    cout << "Please input your account password: ";
    cin >> passwordInput;
    while (passwordInput != this->password)
    {
        cerr << "Your input is incorrect!" << '\n' << "Try again or press 1 to exit the top up process.";
        cout << "Please input your account password: "; cin >> passwordInput;
        if (passwordInput == "1")
        {
            cout << "Exiting top up process...";
            return;
        }
    }
    cout << "Please input your top up amount in dollars: ";
    cin >> amountInput;
    this->creditPoint += amountInput;
}