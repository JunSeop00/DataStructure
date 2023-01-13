#include "logbook.h"

Logbook::Logbook(int month, int year)
{
	logMonth = month;
	logYear = year;
	for (int i = 0; i < 31; i++) {
		entries[i] = 0;
	}
}

void Logbook::putEntry(int day, int value)
{
	entries[day - 1] = value;
}

int Logbook::getEntry(int day) const
{
	return entries[day - 1];
}

int Logbook::getMonth() const
{
	return logMonth;
}

int Logbook::getYear() const
{
	return logYear;
}

int Logbook::getDaysInMonth() const
{
	if (logMonth == 1 || logMonth == 3 || logMonth == 5 || logMonth == 7 || logMonth == 8 || logMonth == 10 || logMonth == 12) {
		return 31;
	}
	else if (logMonth == 4 || logMonth == 6 || logMonth == 9 || logMonth == 11) {
		return 30;
	}
	else if(logMonth == 2) {
		if (this->isLeapYear()) {
			return 29;
		}
		else {
			return 28;
		}
	}
}

bool Logbook::isLeapYear() const
{
	if ((logYear % 4 == 0) && (logYear % 100 != 0) || (logYear % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}

// In-lab operations
void Logbook::displayCalendar() const
{
	int day;
	int cnt = 0;
	cnt += this->getDayOfWeek(1);
	cout << '\t' << '\t' << '\t' << this->getMonth() << " " << " / " << " " << this->getYear() << endl;
	cout << "Sun" << '\t' << "Mon" << '\t' << "Tue" << '\t' << "Wed" << '\t' << "Thu" << '\t' << "Fri" << '\t' << "Sat" << endl;
	for (int i = 0; i < this->getDayOfWeek(1); i++) {
		cout << "\t";
	}
	for (day = 1; day <= this->getDaysInMonth(); day++) {
		cout  << day << " " << entries[day - 1] << '\t';
		cnt++;
		if (cnt % 7 == 0) {
			cout << endl;
		}
	}
}

int Logbook::getDayOfWeek(int day) const
{
	int nDaystoMonth = 0;
	int nLeapYears = 0;
	int nYears = 0;

	if (this->getMonth() == 3 || this->getMonth() == 5 || this->getMonth() == 7 || this->getMonth() == 8 || this->getMonth() == 10 || this->getMonth() == 12) {
		if (this->isLeapYear()) {
			nDaystoMonth = (this->getMonth() / 2) * 31 + (this->getMonth() - 1) / 2 * 30 - 1;
		}
		else {
		nDaystoMonth = (this->getMonth() / 2) * 31 + (this->getMonth() - 1) / 2 * 30 - 2;
		}
	}	
	else if (this->getMonth() == 4 || this->getMonth() == 6 || this->getMonth() == 9 || this->getMonth() == 11) {
		if (this->isLeapYear()) {
			nDaystoMonth = (this->getMonth() + 1) / 2 * 31 + (this->getMonth() - 2) / 2 * 30 - 1;
		}
		else {
			nDaystoMonth = (this->getMonth() + 1) / 2 * 31 + (this->getMonth() - 2) / 2 * 30 - 2;
		}
	}
	else if (this->getMonth() == 1) {
		nDaystoMonth = 0;
	}
	else if (this->getMonth() == 2) {
		nDaystoMonth = 31;
	}

	nYears = this->getYear() - 1901;
	for (int i = 1901; i < this->getYear(); i++) {
		if ((i % 4 == 0) && (i % 100 != 0) || (i % 400 == 0)) {
			nLeapYears++;
		}
	}

	return  (1 + nYears + nLeapYears + nDaystoMonth + day ) % 7 ;
}
