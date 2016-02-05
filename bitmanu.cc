#include<iostream>
using namespace std;

bool getbit(int num, int i) {
  return (num&(1<<i)) != 0;
}

int setbit(int num, int i) {
  num = num| (1<<i);
  return num;
}

int clearbit(int num, int i) {
  num = num&(~(1<<i));
  return num;
}

int clearBitsMSBthroughI(int num, int i) {
  int mask = (1<<i) - 1;
  num = num&mask;
  return num;
}

int clearBitsIthrough0(int num, int i) {
  int mask = ~((1<<i) - 1);
  num = num&mask;
  return num;
}

int updateBit(int num, int i, int v) {
  num = clearbit(num, i);
  num = num | (v<<i);
}


int main () {
 cout<<"5: "<<getbit(5, 2)<<endl;
 cout<<"5: "<<setbit(5, 1)<<endl;
 cout<<"5: "<<clearbit(5, 0)<<endl;
 return 0;
}
