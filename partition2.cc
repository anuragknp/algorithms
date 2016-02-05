#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
  public:

bool isPalindrome(string &s, int i, int j, vector<vector<int>> &p) {
  //cout<<s<<" "<<i<<" "<<j<<endl;
  if (p[i][j] == 1) return true;
  if (p[i][j] == 0) return false;

  int mid = (i+j)/2;
  p[mid][mid] = 1;
  bool palin = true;
  int x= i, y = j;
  bool ispalin = true;
  while(x<y) {
   if (s[x] != s[y]) ispalin = false;
   if (p[x][y] != -1) {
     p[i][j] = p[x][y];
     break;
   }
   if (!ispalin) {
    p[x][y] = 0;
    p[i][j] = 0;
    break;
   }
   x++;
   y--;
  }
  if (x>=y) {
   p[i][j] = 1;
  }
  cout<<s<<" "<<i<<" "<<j<<" "<<p[i][j]<<endl;
  return p[i][j]==1;
}

int findPath(string &s, int i, vector<vector<int>> &p, vector<int> &o) {
 if (isPalindrome(s, 0, i, p)) {
  return 0;
 }
 int m = i;
 for (int j = 1; j <= i; j++) {
   cout<<"is palin"<<isPalindrome(s, j, i, p)<<endl;
   if (isPalindrome(s, j, i, p)) {
     m = min(o[j-1] + 1, m);
   }
 }
 return m;
}

int minCut(string &s) {
 vector<vector<int>> p(s.length(), vector<int>(s.length(), -1));
 vector<int> o;

 for (int i=0;i<s.length(); i++) {
  o.push_back(i);
  o[i] = min(o[i], findPath(s, i, p, o));
  cout<<i<<" "<<o[i]<<endl;
 }
 return o[s.length()-1];
}
};

int main() {
 Solution s;
 string a("leet");
 cout<<"Min cut"<<s.minCut(a)<<endl;;
 return 1;
}
