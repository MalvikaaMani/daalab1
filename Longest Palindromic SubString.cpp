class Solution {
public:
    string longestPalindrome(string s) {
         int l,r,start=0,len=1;
        int n=s.length();
        if(n<=1) return s;
        for(int i=0;i<n && 2*(n-i)>len;i++){
            l=r=i;
            for(;r+1<n && s[r]==s[r+1];r++) i=r+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if(len<r-l+1){
                    len=r-l+1;
                    start=l;
                }
                l--;
                r++;
            }
        } 
        return s.substr(start,len);
    }
};
        
    
