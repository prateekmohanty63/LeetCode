#include <iostream>
#include<stack>
using namespace std;

int main() {

    string str="a ";
    string s="";
     int index=0;


       for(int i = str.size()-1;i>=0;i--) {
         if(str[i] != ' '){
         index = i;
       break;
          }
      }

        for(int i=0;i<=index;i++)
            s+=str[i];


        int len=0;

        for (int i = 0; i < s.length(); i++)
    {
        if (str.at(i) == ' ')
            len = 0;
        else
            len++;
    }


    cout<<len;

}
