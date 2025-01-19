#include <bits/stdc++.h>
using namespace std;

int solution(int arr[], int brr[], int n, int m){
    if(n > m) return solution(brr, arr, m, n);
    int low = 0, high = n;
    while(low <= high){
        int cut1 = low + (high - low) / 2;
        int cut2 = (n + m + 1) / 2 - cut1;
        int left1 = cut1 == 0 ? INT_MIN : arr[cut1 - 1];
        int left2 = cut2 == 0 ? INT_MIN : brr[cut2 - 1];
        int right1 = cut1 == n ? INT_MAX : arr[cut1];
        int right2 = cut2 == m ? INT_MAX : brr[cut2];
        if(left1 <= right2 && left2 <= right1){
            if((n + m) % 2 == 0){
                return (max(left1, left2) + min(right1, right2)) / 2;
            }else{
                return max(left1, left2);
            }
        }else if(left1 > right2){
            high = cut1 - 1;
        }else{
            low = cut1 + 1;
        }
    }
    return 0;
}

int main(){
    int arr[] = {2,4,6};
    int brr[] = {1,3,5};

    cout << solution(arr , brr, 3, 3) << endl;
}