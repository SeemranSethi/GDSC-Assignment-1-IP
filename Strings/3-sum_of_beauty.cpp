class Solution {
public:
    int beautySum(string s) {
        int n=s.size(), ans=0, mn=INT_MAX, mx=0;
        for(int i=0;i<n;i++)
        {
            map<char, int> m;
            for(int j=i;j<n;j++)
            {
                m[s[j]]++;
                for(auto& it: m)
                {
                    mn=min(mn, it.second);
                    mx=max(mx, it.second);
                }
                ans+=(mx-mn);
                mn=INT_MAX;
                mx=0;
            }
            m.clear();
        }
        return ans;
    }
};
