#ifndef KEYEDITEMCOUNT_H
#define KEYEDITEMCOUNT_H

using namespace std;

typedef int KeyCount;

class KeyedItemCount
{
public:
   KeyedItemCount() {}
   KeyedItemCount(const KeyCount& count) { searchKeyCount = count; }
   KeyCount getKeyCount() const // returns search key
   {  return searchKeyCount;
   }  // end getKeyCount
private:
   KeyCount searchKeyCount;
}; // end KeyedItemCount

#endif