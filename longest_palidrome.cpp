
/// first approach
O(n^3)
class Solution {
    bool pali(string a){
        string b=a;
         reverse(b.begin(),b.end());
        if(a==b)
            return true;
        return false;
    }
public:
    string longestPalindrome(string s) {
        string res;
        int max=-1;

        // string b;
        // b="aba";
        // if(pali(b))
        //     cout<<"IN";
        // cout<<b;

        for(int i=0;i<s.length()-1;i++){
            string a;
            a=s[i];
            for(int j=i+1;j<s.length();j++){
                if(pali(a)==true && a.size()>max){
                    res=a;
                    max=a.size();
                    cout<<"IN"<<" ";
                }
                a+=s[j];
            }
            cout<<res<<" ";
        }
        return res;
    }
};


/// second approach
