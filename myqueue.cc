#include<iostream>
using namespace std;

template <typename T>
class MyQueue {
  T stack1[50];
  T stack2[50];
  public:
  int idxs1;
  int idxs2;

  public: 
  void push(T val) {
    if (idxs1 == 50) {
      cout<<"Stack limit reached"<<endl;
      return;
    }
    stack1[++idxs1] = val;
  }
  
  void PushInStack2() {
    while(idxs1 > -1) {
     stack2[++idxs2] = stack1[idxs1--];
    }
  }

  T pop() {
    if (idxs2 == -1) {
      PushInStack2();
    }
    if (idxs2 == -1)
      return T(-1);

    return stack2[idxs2--];
  }

  void PrintQueue() {
    PushInStack2();
    for (int i = idxs2; i >=0; i--) {
      cout<<stack2[i]<<endl;
    }
  }

  public:
  MyQueue() {
    idxs1 = -1;
    idxs2 = -1;
  }
};

int main() {
  MyQueue<int> q;
  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  cout<<q.pop()<<endl;
  cout<<"left"<<endl;
  q.push(6);
  q.PrintQueue();
}
