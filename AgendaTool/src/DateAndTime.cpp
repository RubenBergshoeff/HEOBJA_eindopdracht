//
//  DateAndTime.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#include "DateAndTime.hpp"

std::string DateAndTime::dateAsString () {
    return std::to_string(((int) day)) + "-" + std::to_string(((int) month)) + "-" + std::to_string(year);
}

DateAndTime::DateAndTime () {
}

DateAndTime::DateAndTime (byte day, byte month, short year){
    this->hour = 8;
    this->minute = 0;
    this->second = 0;
    this->day = day;
    this->month = month;
    this->year = year;
}

DateAndTime::DateAndTime (byte hour, byte minute, byte second, byte day, byte month, short year){
    this->hour = hour;
    this->minute = minute;
    this->second = second;
    this->day = day;
    this->month = month;
    this->year = year;
}

bool DateAndTime::operator==(const DateAndTime & rhs) const{
    if (hour != rhs.hour || minute != rhs.minute || second != rhs.second || day != rhs.day || month != rhs.month || year != rhs.year) {
        return false;
    }
    return true;
}

bool DateAndTime::operator>(const DateAndTime & rhs) const{
    if (year > rhs.year) {
        return true;
    } else if (year < rhs.year) {
        return false;
    }
    if (month > rhs.month) {
        return true;
    } else if (month < rhs.month) {
        return false;
    }
    if (day > rhs.day) {
        return true;
    } else if (day < rhs.day) {
        return false;
    }
    if (hour > rhs.hour) {
        return true;
    } else if (hour < rhs.hour) {
        return false;
    }
    if (minute > rhs.minute) {
        return true;
    } else if (minute < rhs.minute) {
        return false;
    }
    if (second > rhs.second) {
        return true;
    } else if (second < rhs.second) {
        return false;
    }
    return false;
}

bool DateAndTime::operator<(const DateAndTime & rhs) const{
    if (year < rhs.year) {
        return true;
    } else if (year > rhs.year) {
        return false;
    }
    if (month < rhs.month) {
        return true;
    } else if (month > rhs.month) {
        return false;
    }
    if (day < rhs.day) {
        return true;
    } else if (day > rhs.day) {
        return false;
    }
    if (hour < rhs.hour) {
        return true;
    } else if (hour > rhs.hour) {
        return false;
    }
    if (minute < rhs.minute) {
        return true;
    } else if (minute > rhs.minute) {
        return false;
    }
    if (second < rhs.second) {
        return true;
    } else if (second > rhs.second) {
        return false;
    }
    return false;
}

DateAndTime DateAndTime::Today (){
    return DateAndTime(1,1,2018);
}
