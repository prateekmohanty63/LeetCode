#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;



class Solution {
public:

  bool isPali(string a)
  {
      int start=0;
      int end=a.length()-1;
      while(start<=end)
      {
          if(a[start]!=a[end])return false;

          start++;
          end--;
      }
      return true;
  }
//    int palindrome(string mask1,string mask2)
//    {
//        // checking for common indexes
//        unordered_map<int,bool>mp;

//        string pali1,pali2;

//        for(int i=0;i<mask1.length();i++)
//        {
//            if(mask1[i]=='1'){
//                mp[i]=true;
//                pali1+=s[i];
//            }
//        }

    
//        int flag=0;

//        for(int i=0;i<mask2.length();i++)
//        {
//            if(mask2[i]=='1' && mp.find(i)!=mp.end())
//            {
//                flag=1;
//            }
//            if(mask2[i]=='1')
//            pali2+=s[i];
//        }
      
//       if(flag==1)return false;

//       int start=0;
//       int end=pali1.length()-1;

//       while(start<=end)
//       {
//           if(pali1[start]!=pali1[end])return false;

//           start++;
//           end--;
//       }

//       start=0;
//       end=pali2.length()-1;

//       while(start<=end)
//       {
//           if(pali2[start]!=pali2[end])return false;

//           start++;
//           end--;
//       }
//     //  cout<<pali1.length()<<" "<<pali2.length()<<endl;
     
//      int n=pali1.length();
//      int m=pali2.length();

//      return n*m;
//    }
   int solve(string &s,int ind,string pali1,string pali2)
   {
         // base case
         int n=s.length();
        int ans=0;

         if(ind>=n)
         {  
            if(isPali(pali1) && isPali(pali2))return pali1.length()*pali2.length();

             return 0;
         }
    

         // we have the option of either taking this 
         // character for mask1 or mask 2 or none of these

        
         ans=max({ans,solve(s,ind+1,pali1+s[ind],pali2)});
         pali1[ind]='0';

         pali2[ind]='1';
         ans=max({ans,solve(s,ind+1,pali1,pali2+s[ind])});
         pali2[ind]='0';
       
         ans=max({ans,solve(s,ind+1,pali1,pali2)});

         return ans;
   }
    int maxProduct(string s) {
        
       string a;
       int res=solve(s,0,a,a);

        return res;
    }
};

// T(N)=O(3^n)


class Solution {
public:
   int palindrome(string s,string mask1,string mask2)
   {
       // checking for common indexes
       unordered_map<int,bool>mp;

       string pali1,pali2;

       for(int i=0;i<mask1.length();i++)
       {
           if(mask1[i]=='1'){
               mp[i]=true;
               pali1+=s[i];
           }
       }

    
       int flag=0;

       for(int i=0;i<mask2.length();i++)
       {
           if(mask2[i]=='1' && mp.find(i)!=mp.end())
           {
               flag=1;
           }
           if(mask2[i]=='1')
           pali2+=s[i];
       }
      
      if(flag==1)return false;

      int start=0;
      int end=pali1.length()-1;

      while(start<=end)
      {
          if(pali1[start]!=pali1[end])return false;

          start++;
          end--;
      }

      start=0;
      end=pali2.length()-1;

      while(start<=end)
      {
          if(pali2[start]!=pali2[end])return false;

          start++;
          end--;
      }
      cout<<pali1.length()<<" "<<pali2.length()<<endl;
     
     int n=pali1.length();
     int m=pali2.length();

     return n*m;
   }
   void solve(string s,int ind,string pali1,string pali2,int &maxim)
   {
         // base case
         int n=s.length();

         //  cout<<pali1<<" "<<pali2<<endl;
         maxim=max(maxim,palindrome(s,pali1,pali2));

         if(ind>=n)return ;
    

         // we have the option of either taking this 
         // character for mask1 or mask 2 or none of these

         string temp1=pali1;
         temp1[ind]='1';
         string temp2=pali2;
         temp2[ind]='1';
         solve(s,ind+1,temp1,pali2,maxim);
         solve(s,ind+1,pali1,temp2,maxim);
         solve(s,ind+1,pali1,pali2,maxim);
   }
    int maxProduct(string s) {
        
        int maxim=0;
        string a;
        for(int i=0;i<s.length();i++)a+='0';

        solve(s,0,a,a,maxim);

        return maxim;
    }
};

int main()
{
    
    return 0;
}