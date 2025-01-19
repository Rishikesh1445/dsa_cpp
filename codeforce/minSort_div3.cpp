#include <bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int size;
        cin >> size;
        int nums[size];
        int i = 0;
        while(i<size){
            cin >> nums[i];
            i++;
        }
        if (size == 1){
            cout << "YES" << "\n";
            continue;
        }
        if(nums[0]>nums[1]){
            cout << "NO" << "\n";
            continue;
        }
        int zero = -1;
        for(i = 1; i<size-1; i++){
            if(nums[i] > nums[i+1]){
                for(int j = zero+2; j<=i; j++){
                    nums[j] = nums[j] - nums[j-1];
                    nums[j-1]=0;
                }
                zero = i-1;
            }
            if((nums[i] < 0 )or (nums[i] > nums[i+1])){
                cout << "NO" << "\n";
                break;
            }
        }
        if(i == (size-1)) cout << "YES" << "\n";
    }
}