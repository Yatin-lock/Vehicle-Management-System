#ifndef table_h
#define table_h
#include "storable.cpp"
#include "error.cpp"
#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Table{

    string fileName;
    fstream fileStream;
    vector<Storable*> records = nullptr;

    T *getReferenceOfRecordForId(long recordId) const throw (NoSuchRecordError);
    void writeToFile() throw (IOError);
    const T* const addNewRecord(T data) throw (MemoryError, IOError);
    void updateRecord(T updatedRecord) throw (IOError, NoSuchRecordError);
public:
    Table(string filename) throw    ;
    ~Table();
    long getNextRecordId() const;
    const T *const  getRecordForId(long recordId) const throw (NoSuchRecordError);
    friend class Database;
};

#endif