//bankDate.h is the Date class specification file
#ifndef bankDate_H
#define bankDate_H

//class declaration
class Date
{
private:
	int yearDate, monthDate, dayDate;
public:
	Date() {
		setYear(1);
		setMonth(1);
		setDay(1);
	}
	// setters
	void setYear(int Year) {
		yearDate = Year;
	}
	void setMonth(int Month) {
		monthDate = Month;
	}
	void setDay(int Day) {
		dayDate = Day;
	}
	void setDate(int Year, int Month, int Day) {
		yearDate = Year;
		monthDate = Month;
		dayDate = Day;
	}
	//getters
	int getYear() {
		return yearDate;
	}
	int getMonth() {
		return monthDate;
	}
	int getDay() {
		return dayDate;
	}
	~Date() {}
};
#endif