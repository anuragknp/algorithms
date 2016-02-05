
#include<iostream>
#include<string>
#include<vector>
#include<climits>
using namespace std;

class Solution {
public:

   bool isPalindrome(string s) {
     int i=0;
     int j=s.length()-1;
     while(i<j){
       if (s[i]!=s[j]) return false;
       i++;
       j--;
     }
     return true;
   }

    void backtrack(int i, string s, vector<string> &path, vector<vector<string>> &result) {
      if (i == s.length()) {
        result.push_back(path);
        return;
      }
      for (int j=i+1; j <= s.length(); j++) {
        if (isPalindrome(s.substr(i, j-i))) {
         path.push_back(s.substr(i, j-i));
         backtrack(j, s, path, result);
         path.pop_back();
        }
      }
    }

    vector<vector<string>> partition(string s) {
      vector<vector<string>> result;
      vector<string> path;
      if (s.length() == 0)
        return result;

      backtrack(0, s, path, result);
      return result;
    }

   bool isPalin(string x, int g, int h, vector<vector<int>> &a) {
     cout<<x<<" "<<g<<" "<<h<<endl;
     string s1(x.substr(g, h));
     int i=0;
     int j=s1.length()-1;
     while(i<j){
       if(a[i][j] == 1) break;
       if(a[i][j] == 0) {
        if (g!=h)
          a[g][g+h-1] = 0;
        return false;
       }
       if (s1[i]!=s1[j]) {
          if (g!=h)
           a[g][g+h-1] = 0;
         return false;
       }
       i++;
       j--;
     }
     a[g][g+h-1] = 1;
     return true;
   }

   int minCut(const string s) {
     if (s.length() == 0)
       return 0;
    
    vector<vector<int>> p(s.length(), vector<int>(s.length(), -1));
    vector<int> o;
    for (int i=0; i<=s.length(); i++) {
      cout<<i<<" "<<s<<endl;
      o.push_back(i-1);
      if (isPalin(s, 0, i, p)) {
        o[i] = 0;
        continue;
      }
      for (int j = 1; j< i; j++) {
        if (o[j]!=INT_MAX && isPalin(s, j, i-j, p)) {
           o[i] = min(o[i], o[j]+1);
        }
      }
      cout<<i<<" "<<s<<endl;
    }
    return o[s.length()];
   }
};

int main() {
 string a = "cdd";
 Solution s;
 /*vector<vector<string>> v = s.partition(a);
 cout<<"done"<<endl;
 for (int i=0;i<v.size(); i++) {
   for (int j=0; j<v[i].size();j++) {
     cout<<v[i][j]<<" ";
   }
   cout<<endl;
 }*/
 cout<<"Mincut: "<<s.minCut(a)<<endl;
}
	
