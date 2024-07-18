class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        stack<char> st1, st2;
        unordered_map<char, int> mp;
        int lastIndex[26] = {0};
        for(int i=n-1; i>=0; i--)
        {
            if(mp[s[i]] == 0)
            {
                lastIndex[s[i]-'a'] = i;
                mp[s[i]] = 1;
            }
        }
        mp.clear();
        for(int i=0; i<n; i++)
        {
            if(mp[s[i]] != 0)
                continue;
            if(st1.empty())
            {
                st1.push(s[i]);
                mp[s[i]] = 1;
            }
            else
            {
                while(!st1.empty() && s[i] < st1.top())
                {
                    if(lastIndex[st1.top()-'a'] > i)
                    {
                        mp[st1.top()] = 0;
                        st1.pop();
                    }
                    else break;
                }
                st1.push(s[i]);
                mp[s[i]] = 1;
            }
        }
        
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        string result;
        while(!st2.empty())
        {
            result.push_back(st2.top());
            st2.pop();
        }
        return result;
    }
};
