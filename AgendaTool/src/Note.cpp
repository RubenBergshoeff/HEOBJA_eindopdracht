//
//  Note.cpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#include "Note.hpp"

Note::Note () {
    this->date = DateAndTime::Today();
}

Note::Note (std::string content){
    this->content = content;
    this->date = DateAndTime::Today();
}
