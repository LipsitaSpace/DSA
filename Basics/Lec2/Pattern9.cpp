#include<iostream>
using namespace std;

void pyramid(int n) {
     for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < n-i-1 ; j++) {
            cout << " ";
        }
        for (int j = 0; j < (2*i)+1 ; j++) {
            cout << "*";
        }
        for (int j = 0; j < n-i-1 ; j++) {
            cout << " ";
        } 
        cout << endl;
    }
}
void invertedpyramid(int n) {
    for (int i = 0 ; i < n; i++) {
        for (int j = 0; j < i ; j++) {
            cout << " ";
        }
        for (int j = 0; j < 2*n - (2*i+1) ; j++) {
            cout << "*";
        }
        for (int j = 0; j < i ; j++) {
            cout << " ";
        } 
        cout << endl;
    }
}

int main() {
    int n = 5;
    pyramid(n);
    invertedpyramid(n);
}