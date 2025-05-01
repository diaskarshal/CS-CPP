#include "phonebook.h"

void PhoneEntry::print( std::ostream& out ) const{
    out << firstname << " " << secondname << " " << number;
}

void PhoneEntry::read( std::istream& in ){
    in >> firstname >> secondname >> number;
}

void PhoneBook::read( std::istream& in ){
    PhoneEntry pe;
    while(in >> pe){
        entries.push_back(pe);
    }
}

void PhoneBook::print( std::ostream& out ) const{
    for(size_t i = 0; i < entries.size(); i++){
        out << entries[i] << "\n";
    }
}

void PhoneBook::checkandnormalize( std::ostream& err ){
    for(size_t i = 0; i < entries.size(); i++){
        entries[i].firstname.normalize();
        entries[i].secondname.normalize();
        if(!entries[i].number.iswellformed())
            err << "It must print warnings for phone numbers that are not well-formed: " << entries[i].number << "\n";
    }
}