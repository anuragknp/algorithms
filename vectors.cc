#include<vector>
#include<iostream>
using namespace std;

//http://www.cplusplus.com/reference/vector/vector/
int main() {
 //Constructors -------------------
 vector<int> myvector1; //empty
 vector<int> myvector2(4,100);//size=4 and default value 100
 vector<int> myvector3(myvector2.begin(), myvector2.end()); //begin and end of other vector
 vector<int> myvector4(myvector3);//copy constructor
 int myarray[] = {1,2,3,4,5};
 //pointer maths starting pointer of array and ending pointer
 vector<int> myvector5(myarray, myarray+sizeof(myarray)/sizeof(int));
 
 //iterator
 vector<int> list;
 for (int i =0; i<10; i++) {list.push_back(i);}
 cout<<"Vector size: "<<list.size()<<endl;
 cout<<"Capacity(): "<<list.capacity()<<endl;
 list.reserve(2048);
 cout<<"After reserver(2048) Capacity: "<<list.capacity()<<endl;
 list.resize(12);
 cout<<"After resize(12) Capacity: "<<list.capacity()<<endl;
 for (vector<int>::iterator i = list.begin(); i != list.end(); i++) {
  cout<<*i<<endl;
 }
 //assign
 vector<int> assigntest;
 assigntest.assign(5, -1);//5 values with -1
 assigntest.assign(myvector5.begin(), myvector5.end());
 assigntest.assign({1,2,3,5});
 
 //insert
 vector<int> inserttest(assigntest);
 vector<int>::iterator it = inserttest.begin();
 inserttest.insert(it, 20);
 it = inserttest.begin();
 inserttest.insert(it, 5, -1);
 it = inserttest.begin();
 inserttest.insert(it, myvector5.begin(), myvector5.end());
 it = inserttest.begin();
 inserttest.insert(it, {1,2,3});
 //erase
 vector<int> erasetest(assigntest);
 erasetest.erase(erasetest.begin()+1);
 erasetest.erase(erasetest.begin(), erasetest.begin()+3);
 //clear
 erasetest.clear();

 return 0;
}
