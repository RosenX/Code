#include <iostream>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
        int sum=0, c=1;
        bool last=0;
        while(a||b){
            bool cur;
            if(a&b&1)cur = 0|last, last=1;
            else if((a&1)|(b&1)){
                if(last)cur=0, last=1;
                else cur=1, last=0;
            }
            else cur = 0|last, last=0;
            if(cur)sum = sum|c;
            c=c<<1;
            a=a>>1;
            b=b>>1;
        }
        if(last)sum = sum|c;
        return sum;
    }
};

int main(){
    
    return 0;
}