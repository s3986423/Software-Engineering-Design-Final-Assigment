#include <iostream>

using std::string;
using std::cout;

class Review
{
private:
    string comment;
    //The username of the reviewer and reviewee
    string reviewer;
    string reviewee;

public:
    Review(string comment, string reviewer, string reviewee);
    ~Review();

    void showReview();

friend class HostReview;
friend class SupporterReview;
};

class HostReview : public Review 
{
private:
    int hostScore;
public:
    HostReview(int HostScore, string comment, string reviewer, string reviewee);
    ~HostReview();

    void showReview();
};

class SupporterReview : public Review
{
private:
    int supporterScore;
    string skillName;
    int skillScore;
public:
    SupporterReview(int supporterScore, string skillName, int skillScore, string comment, string reviewer, string reviewee);
    ~SupporterReview();

    void showReview();
};


