
/// approach 1
class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s==goal)
            return true;
        if(s.size()!=goal.size())
            return false;

        map<char,int>map1,res;

        for(int  i=0;i<s.size();i++){
            map1.insert({s[i],i});
        }
        for(int i=0;i<goal.size();i++){
             for (auto itr = map.find(goal[i]); itr != map.end(); itr++)
             {
                 res.insert({itr->first,abs(itr->second-i)});
             }
        }

    }
};



/// approach 2

class Solution {
public:
    bool rotateString(string s, string goal) {

        vector<int>vec1;
        if(s.size()!=goal.size())
            return false;
        if(s==goal)
            return true;

        int a=s.size();
        //int move=-1;
        for(int i=0;i<a;i++){
            for(int j=0;j<a;j++){
                if(s[i]==goal[j]){
                   vec1.push_back(abs(j-i));
                }
            }
        }
        sort(vec1.begin(),vec1.end());
        for(int i=0;i<vec1.size();i++)
            cout<<vec1[i]<<" ";
        int move=vec1[0];

        string res,res1;

        /// left shift
        for(int i=move;i<s.size();i++){
            res+=s[i];
        }
        for(int i=0;i<move;i++)
            res+=s[i];

        /// right shift
        for(int i=s.size()-move;i<s.size();i++)
            res1+=s[i];
        for(int i=0;i<s.size()-move;i++)
            res1+=s[i];

        cout<<res<<" "<<goal<<" "<<res1;
        if(res==goal || res1==goal)
            return true;
        return false;

    }
};


/// Rotate string correct approach

class Solution {
    string shift(string a){
        string res;
        res=a[a.size()-1];
        for(int i=0;i<a.size()-1;i++){
            res+=a[i];
        }
        return res;
    }
public:
    bool rotateString(string s, string goal) {

        if(s.size()!=goal.size())
            return false;
        if(s==goal)
            return true;

        int count=0;
        string res1=s;
        while(s!=goal){
            res1=shift(res1);
             count++;
            if(res1==goal)
                return true;
            if(count>=s.size())
                return false;
            cout<<res1<<" ";

        }
        return true;
    }
};
