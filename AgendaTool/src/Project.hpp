//
//  Project.hpp
//  AgendaTool
//
//  Created by Ruben Bergshoeff on 1/9/18.
//

#ifndef Project_hpp
#define Project_hpp

#include <stdio.h>
#include <string>

//TODO: start and end date

struct Project {
    Project ();
    Project (std::string name);
    Project (std::string name, std::string description);
    std::string name;
    std::string description;
};


#endif /* Project_hpp */
