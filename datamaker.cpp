#include<bits/stdc++.h>
#define pb push_back
#define is insert
#define fi first
#define se second
#define bg begin
#define INF INT_MAX
#define Mod(a,m) (((a)%(m)+(m))%(m))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
int n;
mt19937_64 rnd(time(0));
ll rand(ll l,ll r){return rnd()%(r-l+1)+l;} 
int main(int argc,char* argv[]){
	n=atoi(argv[1]);
	cout<<n<<endl;
	for(int i=1;i<=n;i++){
		cout<<rand(1,1e9)<<'\n';
	}
	return 0;
}

