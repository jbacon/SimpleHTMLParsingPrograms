#ifndef KEYEDITEM_H
#define KEYEDITEM_H

#include <string>
#include <cstring>
using namespace std;

typedef string KeyType;

class KeyedItem
{
public:
   KeyedItem() {}
   KeyedItem(const KeyType& keyValue) { searchKey = keyValue; }
   KeyType getKey() const // returns search key
   {  return searchKey;
   }  // end getKey
private:
   KeyType searchKey;
}; // end KeyedItem

#endif