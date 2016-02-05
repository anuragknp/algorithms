#include<iostream>
using namespace std;


void print_m(int m[][3], int row, int col) {
 int k = 0;

 for(int i =0; i < min(row, col); i=i+2) {
  for (int j=k; j<col-k;j++) {
   cout<<m[k][j]<<endl;
  }
  for (int j=k;j<row-k;j++) {
   cout<<m[j][col-k]<<endl;
  }
  for(int j=col-k;j>k;j--) {
    cout<<m[row-k][j]<<endl;}
  for(int j=row-k;j>k;j--) {
    cout<<m[j][k]<<endl;}
  k++;
 }
 if (row==col && row%2==0) 
  cout<<m[k][k]<<endl;

}

int main() {
 int m[3][3]={{1,1,1},{1,2,7},{3,4,8}};
 print_m(m, 2, 2);
 return 0;
}
