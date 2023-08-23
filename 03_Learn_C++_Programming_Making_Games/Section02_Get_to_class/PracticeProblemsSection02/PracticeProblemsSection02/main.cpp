#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;

class Time
{
public:
    Time() : mHours(0), mMinutes(0), mSeconds(0) {}
    ~Time();
    void Init(uint16_t hr, uint16_t min, uint16_t sec);
    void Display24Hour(void);
    void Display12Hour(void);
    bool checkMinSec(const uint16_t& tVal);
    bool checkHour(const uint16_t& tVal);
    uint16_t getStdTime(const uint16_t& sHours);
    string formatTime(const uint16_t& iTime);
    vector<std::string> getAmPm(const uint16_t& sHours);
private:
    uint16_t mHours;
    uint16_t mMinutes;
    uint16_t mSeconds;
};
Time::~Time()
{
    //cout << "Default destructor!" << endl;
}

void Time::Init(uint16_t hr, uint16_t min, uint16_t sec)
{
    mHours = hr;
    mMinutes = min;
    mSeconds = sec;
}

bool Time::checkMinSec(const uint16_t& tVal)
{
    if (tVal <= 59)
        return true;
    else 
        return false;
}

bool Time::checkHour(const uint16_t& tVal)
{
    if (tVal <= 23)
        return true;
    else 
        return false;
}

vector<string> Time::getAmPm(const uint16_t& sHours)
{
    vector<string> dayState;
    if (mHours > 12)
    {
        dayState.push_back("pm");
        dayState.push_back("evening");
    }
    else {
        dayState.push_back("am");
        dayState.push_back("morning");
    }
    return dayState;
}

string Time::formatTime(const uint16_t& iTime)
{
    stringstream ssTime;
    ssTime << std::setw(2) << std::setfill('0') << iTime << ":"
        << std::setw(2) << std::setfill('0') << mMinutes << ":"
        << std::setw(2) << std::setfill('0') << mSeconds;

    return ssTime.str();
}

uint16_t Time::getStdTime(const uint16_t& sHours)
{
    if (sHours > 12)
        return (mHours - 12);
    else 
        return mHours;
}

void Time::Display24Hour(void)
{
    std::vector<std::string> amPM;
    amPM = getAmPm(mHours);

    if (checkHour(mHours) && checkMinSec(mMinutes) && checkMinSec(mSeconds))
    {
        cout << formatTime(mHours) << " ";
        cout << "- this is " << formatTime(getStdTime(mHours)) << " " << amPM[0] << " in 12 hour time " << endl;
    }
    else {
        cout << "Invalid Time!" << endl;
    }
}

void Time::Display12Hour(void)
{
    std::vector<std::string> amPM;
    amPM = getAmPm(mHours);

    if (checkHour(mHours) && checkMinSec(mMinutes) && checkMinSec(mSeconds))
    {

        cout << formatTime(getStdTime(mHours)) << " " << amPM[0] << " - " << getStdTime(mHours) 
            << " hours, " << mMinutes << " minutes and " << mSeconds << " second in the " 
            << amPM[1] << endl;
    }
    else 
        cout << "Invalid Time!" << endl;
}

int main()
{
    Time myTime;
    myTime.Init(11, 45, 22);
    myTime.Display24Hour();
    myTime.Display12Hour();

    cout << endl << endl;

    myTime.Init(22, 34, 8);
    myTime.Display24Hour();
    myTime.Display12Hour();

    cout << endl << endl;

    myTime.Init(24, 45, 22);
    myTime.Display24Hour();
    myTime.Display12Hour();

    cout << endl;
    system("Pause");
    return 0;
}


