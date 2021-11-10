class Solution {
public:
    bool isHappy(int n) {

        set<int>set1;

        int val;
        int index;

        while(1)
        {
            val=0;
            while(n)
            {
                index=n%10;
                val+=index*index;
                n/=10;
            }
            if(val==1)
                return true;
            else if(set1.find(val)!=set1.end())
                return false;

            set1.insert(val);
            n=val;
        }
        return false;
    }
};
