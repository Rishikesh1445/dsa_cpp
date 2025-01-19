#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    
    while(tc--){
        int ans = 1;
        int num[4];
        int i = 0;
        while(i<4){
            cin >> num[i];
            i++;
        }
        if(num[2] == (num[0] + 2*num[1])){
            ans++;
            if(num[3] == (2*num[0] + 3*num[1])){
                ans++;
            }
        }else{
            int third = num[2] - num[1];
            if(num[3] == (third + num[2])){
                ans++;
            }else{
                third = num[3] - num[2];
                if(third == (num[0] + num[1])){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
}