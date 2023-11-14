class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==1)
        {
            return intervals;
        }

        vector<vector<int>> v;
        for(int i=0;i<intervals.size();i++)
        {
            v.push_back(intervals[i]);
        }
        sort(v.begin(),v.end());

        vector<vector<int>> ans;
        int f=v[0][0], s=v[0][1];
        for(int i=0;i<v.size()-1;i++)
        {
            vector<int> a(2);
            if(s>=v[i+1][0])
            {
                s=max(s,v[i+1][1]);
            }
            else
            {
                a[0]=f;
                a[1]=s;
                f=v[i+1][0];
                s=v[i+1][1];
                ans.push_back(a);
            }
        }
        ans.push_back({f,s});
        return ans;
    }
};
