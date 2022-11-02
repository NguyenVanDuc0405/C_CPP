#include<bits/stdc++.h>
using namespace std;
int a[20];
int n, MaxTui;
int res[20];
int weights[20];
int values[20];
int size = 0;
struct QHD_CAI_TUI{
    vector<int>nhiphan;
    int weight;
    int value;
};
QHD_CAI_TUI bag[20];
bool cmp(struct QHD_CAI_TUI a, struct QHD_CAI_TUI b){
    return a.value >= b.value;
}
void input(){
    cin >> n >> MaxTui;
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    for(int i = 0; i < n; i++){
        cin >> values[i];
    }
    for(int i = 0; i < n; i++){
        a[i] = 0;
    }
}
void output(){
    int sum_weight = 0;
    int sum_values = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == 0){
            continue;
        }
        else{
            sum_weight += weights[i]*a[i];
            sum_values += values[i] * a[i];
        }
    }
    if(sum_weight <= MaxTui){
        for(int i = 0; i < n; i++){
            bag[size].nhiphan.push_back(a[i]);
        }
        bag[size].weight = sum_weight;
        bag[size].value = sum_values;
        size++;
    }
}
void nhiphan(int i){
    for(int j = 0; j <= 1; j++){
        a[i] = j;
        if(i == n-1){
            output();
        }
        else{
            nhiphan(i+1);
        }
    }
}
int main(){
    input();
    nhiphan(0);
    sort(bag,bag+size,cmp);
    vector<int>res;
    int max_value = bag[0].value;
    int pos = 0;
    for(int i = 0; i < size; i++){
        if(max_value == bag[i].value){
            res.push_back(bag[i].weight);
            pos = i;
        }
        else if(max_value > bag[i].value){
            break;
        }
    }
    sort(res.begin(),res.end());
    for(int i = 0; i <= pos; i++){
        if(bag[i].weight == res[0]){
            cout << bag[i].value << ".0" << endl;
            for(int j = 0; j < bag[i].nhiphan.size(); j++){
                cout << bag[i].nhiphan[j] << " ";
            }
            break;
        }
    }
    return 0;
}
