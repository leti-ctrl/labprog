#include "Date.h"

#include <ctime>
#include <string>
using namespace std;

Date::Date() {
//COSTRUTTORE DI DEFAULT: restituisce data e ora corrente presa dalla macchina
    currentDate = new char [25];

    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);

    strftime(currentDate, 25, " %m/%d/%Y at %H:%M:%S ", localTime);
}

Date::~Date() {
    delete currentDate;
}

char *Date::getCurrentDate() const {
    return currentDate;
}
