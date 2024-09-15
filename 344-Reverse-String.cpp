class Solution {
public:
    void reverseString(vector<char>& s) {
        int st , end ;
        st = 0;
        
        end = (s.size()-1);
        while (st<end){
            
            swap (s.at(st),s.at(end));
            st++;
            end--;
        }
        
    }
};