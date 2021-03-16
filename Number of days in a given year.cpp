#include <iostream>
#include <string>
using namespace std;

//Function prototypes
bool leap_year(string, int&);
void number_of_days(string, int&, int&, int&, int&);

int main()
{
	string date; //01-01-2020
	int count = 0;
	int digit_day = 0;
	int digit_month = 0;
	int digit_year = 0;
	int totalDays = 0;

	cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	cout << "Enter the date in the format of mm-dd-yyyy: ";
	cin >> date;
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";
	//function call
	number_of_days(date, digit_year, digit_month, digit_day, totalDays);
	cout << ">>>  Year: " << digit_year << endl;
	cout << ">>> Month: " << digit_month << endl;
	cout << ">>>   Day: " << digit_day << endl;

	cout << "\n   Result: " << endl << endl;
	if (leap_year(date, digit_year))
		cout << ">>> " << digit_year << " is a leap year.\n";
	else
		cout << ">>> " << digit_year << " is a not leap year.\n";
	cout << ">>> " << "The number of days: " << totalDays << endl;
	cout << "\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n\n";

	return 0;
}

void number_of_days(string date, int& year_digit,
	int& month_digit, int& day_digit, int& sum_days)
{
	string day = date.substr(3, 2);
	string month = date.substr(0, 2);
	month_digit = stoi(month);
	day_digit = stoi(day);

	for (int i = 1; i < month_digit; i++)
	{
		switch (i)
		{
		case 1: case 3: case 5: case 7: case 8: case 10:
		{
			//the cases when a month has 31 days
			sum_days = sum_days + 31;
			break;
		}
		case 4: case 6: case 9: case 11:
		{
			//the cases when a month has 30 days
			sum_days = sum_days + 30;
			break;
		}
		case 2:
		{
			//the february and leap year case
			if (leap_year(date, year_digit))
				sum_days = sum_days + 29;
			else
				sum_days = sum_days + 28;
			break;
		}
		}
	}
	//finally add up the current month's days
	sum_days = sum_days + day_digit;
}

bool leap_year(string date, int& year_digit)
{
	string year = date.substr(6, 10);
	//The easiest way to convert string to int 
	//is by using the stoi() function from string library.
	year_digit = stoi(year);
	if (year_digit % 4 == 0 && year_digit % 100 != 0)
	{
		return true;
	}
	else if (year_digit % 100 == 0 && year_digit % 400 == 0)
	{
		return true;
	}
	else
		return false;
}