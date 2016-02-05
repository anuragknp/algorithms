#include<iostream>
#include <string.h>
#include<string>
using namespace std;

int main() {
 string input;
 char a[1024] = {0};
 cin>>input;
 strcpy(a, input.c_str());
 for (int i=0; i<input.length()/2; i++) {
  char t = a[i];
  a[i] = a[input.length() - i-1];
  a[input.length() - i-1] = t;
 }
 cout<<a;
 return 0;
}
