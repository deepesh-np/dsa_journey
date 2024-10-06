//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template in C++

class Solution {
public:
    long long findPages(int n, int arr[], int m) {
        if (m > n) return -1; // If students are more than books, return -1.

        int st = *max_element(arr, arr + n); // Start with the maximum element
        int sum = accumulate(arr, arr + n, 0); // Sum of all elements
        long long ans = sum;

        int end = sum;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isValid(arr, n, m, mid)) {
                ans = mid;
                end = mid - 1;
            } else {
                st = mid + 1;
            }
        }

        return ans;
    }

    bool isValid(int arr[], int n, int m, int maxAllowed) {
        int studentsRequired = 1;
        int pages = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] > maxAllowed) {
                return false;
            }
            if (pages + arr[i] > maxAllowed) {
                studentsRequired++;
                pages = arr[i];
                if (studentsRequired > m) {
                    return false;
                }
            } else {
                pages += arr[i];
            }
        }

        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        Solution ob;
        cout << ob.findPages(n, A, m) << endl;
    }
    return 0;
}

// } Driver Code Ends