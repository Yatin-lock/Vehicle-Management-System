#ifndef user_h
#define user_h

#include "storable.cpp"
#include<string>

using namespace std;

class User: public Storable{
    string name;
    string contact;
    string email;
public:
    User(string name, string contact,string email, long recordId=0);
    string getName() const;
    string getContact() const;
    string getEmail() const;
    void setName(string);
    void setContact(string);
    void setEmail(string);
    void display() const;
    string toString() const;
    void setDataFrom(Storable *s);
};

#endif