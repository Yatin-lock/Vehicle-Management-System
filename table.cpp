#include "table.h"
#include<bits/stdc++.h>
using namespace std;

template<typename T>
Table<T> ::Table(string filename) throw (MemoryError){
    this->filename = filename;
    if(!this->records){
        throw MemoryError();
    }
}
template<typename T>
long Table<T>::getNextRecordId() const{
    return this->records.size()+1;
}

template<typename T>
const T* const Table<T>::addNewRecord(T record) throw (MemoryError, IOError){
    T *newRecord = new T(record);
    if(!newRecord){
        throw new MemoryError();
    }
    newRecord->recordId = this->getNextRecordId();
    this->records.push_back(newRecord);//must check for reference after
    try{
        this->writeToFile();
    } catch(IOerror error){
        this->records.pop_back();
        delete newRecord;
        throw;
    }
    return newRecord;
}

template<typename T>
void Table<T>::updateRecord(T updatedRecord) throw (IOError,NoSuchRecordError){
    for(auto &record: *this->records){
        if(record->getRecord()==updateRecord.getRecord())
    }
}