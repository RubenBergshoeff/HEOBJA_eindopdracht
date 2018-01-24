//
//  Note.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#ifndef Note_hpp
#define Note_hpp

#include <stdio.h>
#include <string>

#include "DateAndTime.hpp"

struct Note {
    Note ();
    Note (std::string content);
    DateAndTime date;
    std::string content;
};


#endif /* Note_hpp */
