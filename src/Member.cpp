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
            vector<string> blockedMemberInput = vector<string>(),

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
            password(passwordInput), homeAddress(homeAddressInput), creditPoint(creditPointInput), blockedMember(blockedMemberInput),
            /*Supporter's*/
            Supporter(supporterRatingScoreInput, skillsInput, allSupporterReviewsInput),
            /*Host's*/
            Host(hostRatingScoreInput, allHostReviewsInput){};

Member::~Member()
{
};

/*Overloaded Constructor 1 - 7 Member attributes*/
Member::Member(string userNameInput = "", 
            string fullNameInput = "", 
            string phoneNumberInput = "", 
            string emailInput = "", 
            string passwordInput = "", 
            string homeAddressInput = "", 
            int creditPointInput = 0)
    
    /*Member's*/
    : userName(userNameInput), fullName(fullNameInput), 
    phoneNumber(phoneNumberInput), email(emailInput), 
    password(passwordInput), homeAddress(homeAddressInput), creditPoint(creditPointInput), blockedMember(vector<string>()),
    /*Supporter's*/
    Supporter(vector<int>(), map<string, vector<int>>(), vector<Review*>()),
    /*Host's*/
    Host(vector<int>(), vector<Review*>())
{
    // Initialize other attributes as needed
};

/*Overloaded Constructor 2 - 7 Member attributes and supporter skills*/
Member::Member(string userNameInput, 
            string fullNameInput = "", 
            string phoneNumberInput = "", 
            string emailInput = "", 
            string passwordInput = "", 
            string homeAddressInput = "", 
            int creditPointInput = 0,
            map<string, vector<int>> skillsInput)

    /*Member's*/
    : userName(userNameInput), fullName(fullNameInput), 
    phoneNumber(phoneNumberInput), email(emailInput), 
    password(passwordInput), homeAddress(homeAddressInput), creditPoint(creditPointInput), blockedMember(vector<string>()),
    /*Supporter's*/
    Supporter(vector<int>(), skillsInput, vector<Review*>()),
    /*Host's*/
    Host(vector<int>(), vector<Review*>())
{
    // Initialize other attributes as needed
};


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
    cout << "Top up successful! Returning...";
    return;
};

/*Show all Supporter reviews method*/
void Member::showSupporterAllReviews(Supporter* supporter){
    /*Show reviews of another supporter*/
    for (Review* review : (supporter->allSupporterReviews)) {
        review->showReview();
        cout << "End of reviews list! Returning..." << '\n';
    }

    // /*Show reviews of this supporter*/
    // for (Review* review : (this->allSupporterReviews))
    // {
    //     review->showReview();
    //     cout << "End of reviews list! Returning..." << '\n';
    // }
};

/*Show all Host reviews method*/
void Member::showHostAllReviews(Host* host){
    /*Show reviews of another host*/
    for (Review* review : (host->allHostReviews)) {
        review->showReview();
        cout << "End of reviews list! Returning..." << '\n';
    }

    // /*Show reviews of this host*/
    // for (Review* review : (this->allHostReviews)) {
    //     review->showReview();
    //     cout << "End of reviews list! Returning..." << '\n';
    // }
};

// /*Block a Member - 2 ways block*/
// void Member::blockMember(Member* member){
//     if (member->getUsername() == )
//     {
//         /* code */
//     }
    
// }