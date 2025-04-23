#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>
using namespace std;

bool isValidDateRobust(const std::string& date) {
    // First check basic format
    if (date.length() != 10 || date[2] != '-' || date[5] != '-') {
        return false;
    }
    const char *date1 = date.c_str();
    std::tm tm = {};

    if (!strptime(date1, "%d-%m-%Y", &tm))
      std::cout << "date1 isn't valid"<<endl;
    return true;


    std::istringstream ss(date);
    char dash;
    
    // Parse input with additional checks
    if (!(ss >> tm.tm_mday >> dash >> tm.tm_mon >> dash >> tm.tm_year) || dash != '-') {
        return false;
    }
    cout<<"Day - "<<tm.tm_mday<<" Month - "<<tm.tm_mon<<" Year - "<<tm.tm_year<<endl;

    // Additional range checks before mktime
    //if (tm.tm_mday < 1 || tm.tm_mday > 31) return false;
    //if (tm.tm_mon < 1 || tm.tm_mon > 12) return false;
    //if (tm.tm_year < 1900 || tm.tm_year > 2100) return false;

    //// Adjustments (tm_mon is 0-11, tm_year is years since 1900)
    //tm.tm_mon -= 1;
    //tm.tm_year -= 1900;

    // Normalize and validate
    time_t time = mktime(&tm);
    if (time == -1) return false;
    return true;

    // Check if parsed date matches input
    std::tm* check = localtime(&time);
    return (check->tm_mday == tm.tm_mday && 
            check->tm_mon == tm.tm_mon && 
            check->tm_year == tm.tm_year);
}

int main() {
    std::string dates[] = {
        "31-12-2023",  // valid
        "29-02-2020",  // valid (leap year)
        "29-02-2021",  // invalid
        "31-04-2023",  // invalid
        "00-01-2023",  // invalid
        "32-01-2023",  // invalid
        "01-13-2023",  // invalid
        "01-01-1899",  // invalid (year < 1900)
        "01-01-2101",  // invalid (year > 2100)
        "01/01/2023",  // invalid (wrong delimiter)
        "abc",        // invalid
        "01-01-20235" // invalid (wrong length)
    };

    for (const auto& date : dates) {
        std::cout << date << " : " 
                  << (isValidDateRobust(date) ? "Valid" : "Invalid") 
                  << "\n";
    }

    return 0;
}
