#include<unordered_map>
#include<iostream>
#include<vector>
#include <stdlib.h>
#include<climits>
using namespace std;

bool containsDuplicate(vector<int>& nums, int k, int t) {
  if (k <= 0 || t<0) {
    return false;
  }
  unordered_map<int, int> m;
  for (int i = 0; i < nums.size(); i++) {
    int bucket_num = nums[i]/(t+1);
    if (nums[i] < 0) {
      bucket_num += -1;
    }
    //cout << nums[i] << bucket_num << endl;
    if (m.find(bucket_num)!=m.end()) {
      if (nums[i] < 0 and m.find(bucket_num)->second > 0) {
        if (m.find(bucket_num)->second < INT_MAX+nums[i] and abs(m.find(bucket_num)->second - nums[i]) <= t) {
          return true;
        }
      }
      else if (nums[i] > 0 and m.find(bucket_num)->second < 0) {
        if (nums[i] < INT_MAX+m.find(bucket_num)->second and abs(m.find(bucket_num)->second - nums[i]) <= t) {
          return true;
        }
      } else {
        if (abs(m.find(bucket_num)->second - nums[i]) <= t) {
          return true;
        }
      }
    }
    if (m.find(bucket_num-1)!=m.end()) {
      if (nums[i] < 0 and m.find(bucket_num-1)->second > 0) {
        if (m.find(bucket_num-1)->second < INT_MAX+nums[i] and abs(m.find(bucket_num-1)->second - nums[i]) <= t) {
          return true;
        }
      }
      else if (nums[i] > 0 and m.find(bucket_num-1)->second < 0) {
        if (nums[i] < INT_MAX+m.find(bucket_num-1)->second and abs(m.find(bucket_num-1)->second - nums[i]) <= t) {
          return true;
        }
      } else {
        if (abs(m.find(bucket_num-1)->second - nums[i]) <= t) {
          return true;
        }
      }
    }

    if (m.find(bucket_num+1)!=m.end()) {
      if (nums[i] < 0 and m.find(bucket_num+1)->second > 0) {
        if (m.find(bucket_num+1)->second < INT_MAX+nums[i] and abs(m.find(bucket_num+1)->second - nums[i]) <= t) {
          return true;
        }
      }
      else if (nums[i] > 0 and m.find(bucket_num+1)->second < 0) {
        if (nums[i] < INT_MAX+m.find(bucket_num+1)->second and abs(m.find(bucket_num+1)->second - nums[i]) <= t) {
          return true;
        }
      }
      else {
        if (abs(m.find(bucket_num+1)->second - nums[i]) <= t) {
          return true;
        }
      }
    }
    m[bucket_num] = nums[i];
    if (i>=k) {
      int bucket = nums[i-k]/(t+1);
      m.erase(bucket);
    }
  }
  return false;
}

int main() {
  int a[] = {-1, INT_MAX};
  vector<int> v(a, a+(sizeof(a)/sizeof(int)));
  if (containsDuplicate(v, 1, INT_MAX)) {
    cout<<"found"<<endl;
  } else {
    cout<<"not found"<<endl;
  }
  return 0;
}
