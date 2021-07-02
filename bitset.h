// Author :: Sravan Kumar

#ifndef BITSET_H
#define BITSET_H

bool oppositeSigns(int num1, int num2) {
         return ((num1 ^ num2) < 0); 
    }

int countSetBits(int num)
{
    int count = 0;
    while (num)
    {
        num &= (num-1);
        count++;
    }
    return count;
}
int isPowerof2(int num)
{
    return (num && !(num & num-1));
}

void setBit(int &num,int pos){
  num |=(1<<pos);
}

void unsetBit(int &num,int pos){
    num &=(~(1<<pos));
}
void flipBit(int &num,int pos){
    num ^=(1<<pos);
}
bool getBit(int &num,int pos){
    bool res= num&(1<<pos);
    return res;
}


#endif