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
void Table<T> :: updateRecord(T updatedRecord) throw (IOError,NoSuchRecordError){
    for(auto &record: *this->records){
        if(record->getRecord()==updateRecord.getRecord()){
            T *pointerToRecord = dynamic_cast<T*>(record);
            if(pointerToRecord){
                T oldRecord = T(*pointerToRecord);
                record->setDataFrom(&updatedRecord);
                try{
                    this->writeToFile();
                    return;
                }
                catch(IOError error){
                    record->setDataFrom(&oldRecord);

                    throw;
                }
            }
        }
    }
    throw NoSuchRecordError();
}

template<typename T>
void Table<T>:: writeToFile() throw(IOError){
    this->fileStream.open(fileName,ios::out|ios::trunc);
    if(!this->fileStream){
        throw IOError();
    }
    for(auto &record: *records){
        fileStream<<record->toString()<<endl;
    }
    this->fileStream.close();
}
template<typename T>
const T* const Table<T>::getRecordForId(long recordID) const throw(NoSuchRecordError){
    try{
        return this->getReferenceOfRecordForId(recordID);
    }
    catch(NoSuchRecordError err){
        throw;
    }
}

template<typename T>
T* Table<T>::getReferenceOfRecordForId(long recordId) const throw (NoSuchRecordError){
    for(auto &record: *records){
        if(record->getRecord() == recordId){
            return dynamic_cast<T*>(record);
        }
    }
    throw NoSuchRecordError();
}

template<typename T>
Table<T> :: ~Table(){
    for(auto &record: *this->records){
        delete dynamic_cast<T*>(record);
    }
    this->records->clear();
    delete this->records;
}