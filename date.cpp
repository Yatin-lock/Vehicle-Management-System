#include "date.h"
#include "string_helper.cpp"
const char DELIMITER = '/';

Date::Date(){
    time_t now = time(nullptr);
    this->empty = false;
    this->date = *localtime(&now);
}

Date::Date(string date){
    if(date.length()<0){
        this->empty=true;
        return;
    }
    this->empty=false;
    vector<string> dateComponents = split(date,DELIMITER);
    int day = stoi(dateComponents[0]);
    int month = stoi(dateComponents[1]);
    int year = stoi(dateComponents[2]);
    time_t now =  time(nullptr);
    this->date = *localtime(&now);
    this->date.tm_year = year-1900;
    this->date.tm_mon = month-1;
    this->date.tm_mday = day;

    mktime(&this->date);
}

bool Date::isEmpty() const{
    return this->empty;
}

string Date:: toString() const{
    if(this->empty)
        return "";
    stringstream ss;
    ss<<this->date.tm_mday<<"/"<<this->date.tm_mon+1<<"/"<<this->date.tm_year+1900;
    return ss.str();
}

Date Date::operator+(int days){
    Date newDate = *this;
    if(newDate.isEmpty()){
        return newDate;
    }
    newDate.date.tm_mday+=days; 
    time_t adjustedDate = mktime(&newDate.date);

    newDate.date = *localtime(&adjustedDate);

    return newDate;
} 

bool Date::operator>(Date date) const{
    if(this->isEmpty()|| date.isEmpty()){
        return false;
    }
    int dyear = this->date.tm_year - date.date.tm_year;
    int dmonth = this->date.tm_mon - date.date.tm_mon;
    int dday = this->date.tm_mday - this->date.tm_mday;

    if(dyear!=0){
        return dyear>0;
    }
    else if(dmonth!=0){
        return dmonth>0;
    }
    else{
        return dday>0;
    }
}

bool Date::operator>(Date date) const{
    if(this->isEmpty()|| date.isEmpty()){
        return false;
    }
    int dyear = this->date.tm_year - date.date.tm_year;
    int dmonth = this->date.tm_mon - date.date.tm_mon;
    int dday = this->date.tm_mday - this->date.tm_mday;

    if(dyear!=0){
        return dyear<0;
    }
    else if(dmonth!=0){
        return dmonth<0;
    }
    else{
        return dday<0;
    }
}

bool Date:: operator>=(Date date) const{
    return !(*this<date);
}

bool Date:: operator<=(Date date) const{
    return !(*this>date);
}


