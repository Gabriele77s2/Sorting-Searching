/* Binary Search
Problem: Given a sorted array arr[] of n elements, write a function to search a given element x in arr[].

Algorithm:
1. Search a sorted array by repeatedly dividing the search interval in half.
2. Begin with an interval covering the whole array.
3. If the value of the search key is less than the item in the middle of the interval, narrow the interval to the lower half.
4. Otherwise narrow it to the upper half.
5. Repeatedly check until the value is found or the interval is empty.
*/

// Recursive
#include <iostream>
using namespace std;

// A recursive binary search function.
// It returns location of x in given array arr[l..r] is present, otherwise -1
int binarySearch(int arr[], int l, int r, int x){
   if (r >= l) {
      int mid = l + (r - l) / 2;
      // If the element is present at the middle
      // itself
      if (arr[mid] == x)
         return mid;
      // If element is smaller than mid, then
      // it can only be present in left subarray
      if (arr[mid] > x)
         return binarySearch(arr, l, mid - 1, x);
      // Else the element can only be present
      // in right subarray
      return binarySearch(arr, mid + 1, r, x);
    }
    // We reach here when element is not
    // present in array
    return -1;
}

int main(void){
   int arr[] = { 2, 3, 4, 10, 40 };
   int x = 10;
   int n = sizeof(arr) / sizeof(arr[0]);
   int result = binarySearch(arr, 0, n - 1, x);
   (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
   return 0;
}


// Iterative
#include <iostream>
using namespace std;

// A iterative binary search function.
// It returns location of x in given array arr[l..r] if present, otherwise -1
int binarySearch(int arr[], int l, int r, int x){
   while (l <= r) {
      int m = l + (r - l) / 2;
      // Check if x is present at mid
      if (arr[m] == x)
         return m;
      // If x greater, ignore left half
      if (arr[m] < x) 
         l = m + 1;
       // If x is smaller, ignore right half
       else
         r = m - 1;
    }
   // if we reach here, then element was
   // not present
   return -1;
}

int main(void){
   int arr[] = { 2, 3, 4, 10, 40 };
   int x = 10;
   int n = sizeof(arr) / sizeof(arr[0]);
   int result = binarySearch(arr, 0, n - 1, x);
   (result == -1) ? cout << "Element is not present in array"
                   : cout << "Element is present at index " << result;
   return 0;
}