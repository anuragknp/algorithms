#include <vector>
#include<iostream>
#include <algorithm>
#include <unordered_map>

using std::vector;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      int j=0;
      std::vector<int> m;
      std::unordered_map<int, int> h;
      for (int i=0;i<nums.size();i++) {
        int a=nums[i];
        int b=target-a;
        if (h.find(b) != h.end()) {
          m.push_back(h[b]);
          m.push_back(j+1);
          return m;
        }
        h.insert({nums[i], i});
      }
  }

  int maxProfit(vector<int>& nums) {
        int m=0;
        int c=0;
        for (int i=0;i<nums.size()-1;i++) {
            c=nums[i+1]-nums[i];
            if (c>0) {
                m+=c;
            }
        }
        return m;
    }
};

int main() {
  Solution a;
  int ss[] = {0};
  std::vector<int> myints(&ss[0], &ss[0]);
  int y = a.maxProfit(myints);
  std::cout<<y<<std::endl;
  return 1;
}
