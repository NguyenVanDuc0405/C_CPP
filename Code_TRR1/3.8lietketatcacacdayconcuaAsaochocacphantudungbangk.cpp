#include<bits/stdc++.h>
using namespace std;
int m,n;
int a[10009];
void Input(){
    cin >> m >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
}
void Solve(){
    int dem = n;
    for(int i = dem; i <=n; i++){
        vector<int>res;
        vector<int>ok;
        res.push_back(a[i]);
        ok.push_back(a[i]);
        for(int j = i+1; j <= n; j++){
            res.push_back(a[j]);
            ok.push_back(a[j]);
        }
        for(int j = 1; j < res.size()-1; j++){
            for(int k = j+1; k < res.size(); k++){
                if(res[j] < res[k]){
                    swap(res[j],res[k]);
                }
            }
        }
        int sum = 0;
        vector<int>in;
        for(int j = 0; j < res.size(); j++){
            sum = sum + res[j];
            in.push_back(res[j]);
            if(sum == m){
                for(int k = 0; k < ok.size();k++){
                    for(int h = 0; h < in.size(); h++){
                        if(ok[k] == in[h]){
                            cout << ok[k] << " ";
                            break;
                        }
                    }
                }
                cout << endl;
            }
            else if(sum > m){
                sum = sum - res[j];
                in.pop_back();
            }
        }
        dem--;
        i = i-2;
        if(dem == 0){
            break;
        }
    }
}
int main(){
    Input();
    Solve();
    return 0;
}

