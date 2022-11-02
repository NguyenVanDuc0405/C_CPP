#include<bits/stdc++.h>
#define MAX 100
using namespace std;

int n,a[MAX][MAX],f[MAX],s,b[MAX],check = 0;
void hamilton(int k){
    for(int i=1;i<=n;i++){
        if(a[b[k-1]][i]){
            if(k==n+1&&i!=b[1]){
                for(int j=1;j<=n;j++)	cout<<b[j]<<" ";
                	check = 1;
                	cout <<  endl;
                	break;
            }
            else if(i==b[1]&&k==n+1){
                for(int j=1;j<=n;j++)	cout<<b[j]<<" ";
                	cout<<s;
                	check = 1;
                	cout <<  endl;
                	break;
            }
            if(!f[i]){
                b[k]=i;
                f[i]=1;
                hamilton(k+1);
                f[i]=0;
            }
        }
    }
}
void solve(){
    cin>>n>>s;
    for(int i=1;i<=n;i++) 
		for(int j=1;j<=n;j++) cin>>a[i][j];
    		b[1]=s;
    		f[s]=1;
    hamilton(2);
    if(check == 0) cout << "No Hamiltonian path";
}
int main(){
  solve();
  return 0;
}
