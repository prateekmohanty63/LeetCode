
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& a) {

        vector<vector<int>>res;

        int n=a.size();

        unordered_map<int,vector<int>>map1;

        for(int i=0;i<n;i++){
            map1[a[i]].push_back(i);

            if(map1[a[i]].size()==a[i])
            {
                res.push_back(map1[a[i]]);
                map1[a[i]].clear();
            }


        }
        return res;
    }
};
