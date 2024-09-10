#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int CNT = 9;

void solution(vector<int> &arr){
    int sum = 0;
    for (int i=0; i<CNT;i++){
        sum += arr[i];
    }

    for (int i=0; i<CNT;i++){
        for (int j=i+1; j < CNT; j++){
            if (sum - arr[i] - arr[j]== 100) {
                arr.erase(arr.begin() + j); //i는 j보다 항상 작기 때문에 i를 먼저 지우면 값의 인덱스들이 바뀌게 됨.
                arr.erase(arr.begin() + i);
                
                return;

            }
    }
    }
}

int main(){
    vector<int> arr(CNT);
    for (int i = 0; i<CNT; i++){
        cin >> arr[i];
    }

    solution(arr);
    sort(arr.begin(), arr.end());


    for (auto it: arr){
        cout << it <<"\n";
    }

    return 0;
}