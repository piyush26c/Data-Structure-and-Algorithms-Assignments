/* 
 * File:   SortingAlgorithms.cpp
 * Author: Piyush
 *
 * Created on September 10, 2018, 6:49 PM
 */
#include<bits/stdc++.h>
using namespace std;
//function Definition

void selectionSort(float e[], int size) {
    int i;

    int j, min;
    int temp;
    for (i = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (e[min] > e[j]) {
                min = j;
            }
        }

        temp = e[i];
        e[i] = e[min];
        e[min] = temp;
    }
    cout << "\nSorting By Selection Sort " << endl;
    for (i = 0; i < size; i++) {
        cout << e[i] << "\t";
    }
}

void bubbleSort(float r[], int size) {
    for (int pass = 1; pass < size; pass++) {
        for (int i = 0; i < size - pass; i++) {
            if (r[i] > r[i + 1]) {
                int temp;
                temp = r[i];
                r[i + 1] = r[i];
                r[i] = temp;
            }

        }
    }
    cout << "\nSorting By Bubble Sort" << endl;
    for (int i = 0; i < size; i++) {
        cout << r[i] << "\t";
    }
}

int main() {
    int noe;
    cout << "\nEnter The Total Number of First Year Students :" << endl;
    cin>>noe;
    float a[noe];
    cout << "\nEnter The First Year Percentage :" << endl;
    cout << "\t";
    for (int i = 0; i < noe; i++) {

        cin >> a[i];
        cout << "\t";
    }

    selectionSort(a, noe); // selection function call
    bubbleSort(a, noe); // Bubble function call
    cout << "\nDisplaying top five scores :";
    for (int i = noe - 1; i >= noe - 5; i--)
        cout << a[i] << "\t";
    cout << "\n";
}

