//
//  DateAndTime.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#ifndef DateAndTime_hpp
#define DateAndTime_hpp

#include <stdio.h>
#include <string>

typedef char byte;

struct DateAndTime {
    byte hour;
    byte minute;
    byte second;
    byte day;
    byte month;
    short year;
    std::string dateAsString();
    DateAndTime ();
    DateAndTime (byte day, byte month, short year);
    DateAndTime (byte hour, byte minute, byte second, byte day, byte month, short year);
    bool operator ==(const DateAndTime & rhs) const;
    bool operator >(const DateAndTime & rhs) const;
    bool operator <(const DateAndTime & rhs) const;
    static DateAndTime Today ();
};

#endif /* DateAndTime_hpp */
