#ifndef KEYEDFREQ_H
#define KEYEDFREQ_H

using namespace std;

typedef int Freq;

class KeyedFreq
{
public:
   KeyedFreq() {}
   KeyedFreq(const Freq& freq) { searchFreq = freq; }
   Freq getKeyFreq() const // returns search key
   {  return searchFreq;
   }  // end getKey
private:
   Freq searchFreq;
}; // end KeyedItem

#endif