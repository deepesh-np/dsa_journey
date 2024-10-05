class Solution {
public:
    int singleNonDuplicate(vector<int>& a) {
        int s = 0;
        int e = a.size() - 1;
        
        while (s < e) {
            int m = s + (e - s) / 2;
            
            // Ensure m is not at the boundaries to avoid out-of-bounds
            if (m > 0 && m < a.size() - 1) {
                if (a[m] == a[m + 1]) {
                    if (m % 2 == 0) {
                        s = m + 2;
                    } else {
                        e = m - 1;
                    }
                } else if (a[m] == a[m - 1]) {
                    if (m % 2 == 0) {
                        e = m - 2;
                    } else {
                        s = m + 1;
                    }
                } else {
                    return a[m];
                }
            } else {
                return a[m];
            }
        }
        
        return a[s];
    }
};
