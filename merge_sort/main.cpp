//
//  main.cpp
//  merge_sort
//
//  Created by Saloxiddin Sayfuddinov on 14/10/24.
//

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> & arr, int left, int right, int mid) {
    int n1 = mid - left + 1; // chap
    int n2 = right - mid; // o'ng
    
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);
    
    // left
    for(int i = 0; i<n1; i++) {
        leftArr[i] = arr[left+i];
    }
    
    // o'ng
    for(int j = 0; j<n2; j++) {
        rightArr[j] = arr[mid + 1 + j];
    }
    
    // 2ta massivni birlashtirish
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }
    
    // qolgan elementlarni qo'shish
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
};

void mergeSort(vector<int> & arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid); // chap yarim
        mergeSort(arr, mid + 1, right); // o'ng yarim
        
        merge(arr, left, right, mid); // birlashtirish
        
        cout<<"chap: ";
        for (int i = left; i<=mid; i++) {
            cout<<" "<<arr[i];
        }
        cout<<endl;
        
        /*cout<<"o'ng: ";
        for (int i = mid; i<=right; i++) {
            cout<<" "<<arr[i];
        }
        cout<<endl; */
    }
};

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    auto arrSize = arr.size();

    mergeSort(arr, 0, arrSize - 1);
    
    cout<<"Saralangan massiv: ";
    for (int i: arr) {
        cout<< i << " ";
    }
    cout<<endl;
    return 0;
}
