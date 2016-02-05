#include <climits>
#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;

#define GET_LEAST_TIME(m, i, j) (i>=0 ? std::max(m[i], m[j]): INT_MAX)


int solution(vector<int> &A, int X, int D) {
  int m[X+1] = { INT_MAX };
  std::cout<<m[X]<<INT_MAX;
  m[X]=0;
  m[0]=0;
  for (int i=0;i<A.size();i++) {
    if (m[A[i]] == INT_MAX) {
      m[A[i]]=i;
    }
  }
  for(int i=1;i<X+1;i++) {
    int time = GET_LEAST_TIME(m, i-1, i);
    for (int j=2; j <= D; j++) {
     time = std::min(GET_LEAST_TIME(m, i - j, i), time);
    }
    m[i]=time;
  }
  if (m[X] == INT_MAX) {
    return -1;
  }
  return m[X];
}

int main() {
  int a[]={1,7,4,6};
  vector<int> vec(a, a+sizeof(a)/sizeof(a[0]));
  std::cout<<"\nAnswer: "<<solution(vec, 10, 3)<<std::endl;
  return 1;
}
