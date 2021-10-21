#ifndef storable_cpp
#define storable_cpp

// #include "serializable.cpp"
class Serializable{
    
};

#include<string>
#include<iostream>

using namespace std;

class Storable: public Serializable{
protected:
    long recordId;
public:
    Storable(long recordId){
        this->recordId = recordId;
    }
    long getRecord() const{
        return this->recordId;
    }
    virtual void setDataFrom(Storable *s) = 0;
    template<typename T> friend class Table;
    friend class Database;
};

#endif

