//--------------------------------------------------------------------
//
//  Laboratory 1                                           logbook.h
//
//  Class declaration for the Logbook ADT
//
//--------------------------------------------------------------------
#include <iostream>

using namespace std;

class Logbook
{
  public:

    // Constructor
    Logbook(int month, int year);         // Create a logbook

    // Logbook marking operations
    void putEntry(int day, int value);   // Store entry for day
    int getEntry(int day) const;         // Return entry for day

    // General operations
    int getMonth() const;                  // Return the month
    int getYear() const;                   // Return the year
    int getDaysInMonth() const;            // Number of days in month

    // In-lab operations
    void displayCalendar() const;          // Display as calendar

  private:

    // Facilitator (helper) function
    bool isLeapYear() const;               // Leap year?

    // In-lab facilitator function
    int getDayOfWeek(int day) const;     // Return day of the week

    // Data members
    int logMonth,      // Month covered by logbook
        logYear,       // Year for this logbook
        entries[31];   // Logbook entries
};
