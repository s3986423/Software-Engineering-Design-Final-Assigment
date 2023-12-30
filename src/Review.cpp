#include <iostream>
#include "../include/Review.h"

using std::string;
using std::cout;

//Review constructor
Review::Review(string commentInput = "", string reviewerInput = "", string revieweeInput = "")
: comment(commentInput), reviewer(reviewerInput), reviewee(revieweeInput){};

Review::~Review(){};

//Host's reviews constructor
HostReview::HostReview(int hostScoreInput = 0,
                    string commentInput = "",
                    string reviewerInput = "",
                    string revieweeInput = "")
: hostScore(hostScoreInput), 
Review(commentInput, reviewerInput, revieweeInput){};

HostReview::~HostReview(){};

//Host's showReview() method
void HostReview::showReview() {
    cout << "-----Host Review-----" << '\n';
    cout << "Host score: " << this->hostScore << '\n';
    cout << "Reviewer comment: " << this->comment << '\n';
    cout << "Reviewer: " << this->reviewer << '\n';
    cout << "Reviewee: " << this->reviewee << '\n';
}

//Supporter's reviews constructor
SupporterReview::SupporterReview(int supporterScoreInput = 0,
                                string skillNameInput = "",
                                int skillScoreInput = 0,
                                string commentInput = "",
                                string reviewerInput = "",
                                string revieweeInput = "")
: supporterScore(supporterScoreInput), 
skillName(skillNameInput), 
skillScore(skillScoreInput), 
Review(commentInput, reviewerInput, revieweeInput){};

SupporterReview::~SupporterReview(){};

//Supporter's showReview() method
void SupporterReview::showReview() {
    cout << "-----Supporter Review-----" << '\n';
    cout << "Supporter score: " << this->supporterScore << '\n';
    cout << "Skill performed: " << this->skillName << '\n';
    cout << "Skill score: " << this->skillScore << '\n';
    cout << "Reviewer comment: " << this->comment << '\n';
    cout << "Reviewer: " << this->reviewer << '\n';
    cout << "Reviewee: " << this->reviewee << '\n';
}