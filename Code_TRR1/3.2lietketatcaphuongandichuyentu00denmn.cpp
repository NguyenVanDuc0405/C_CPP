#include<iostream>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    int a[n+m]={0};
    while(1){
        for(int i=n+m-1;i>=0;i--){
            if(a[i]==0){
                a[i]=1;
                for(int j=i+1;j<n+m;j++){
                    a[j]=0;
                }
                break;
            }
        }
        int sum=0;
        int sum1=0;
        for(int i=0;i<m+n;i++){
            if(a[i]==0) sum1++;
            sum+=a[i];
        }
        int check=0;
        if(sum1==m){
            check=1;
            for(int i=0;i<n+m;i++){
                if(a[i]==0){
                    cout<<"H"<<" ";
                } else if(a[i]==1){
                    cout<<"V"<<" ";
                } else break;
            }
        }
        if(sum==n+m) break;
        if(check==1) cout<<endl;
    }
}
