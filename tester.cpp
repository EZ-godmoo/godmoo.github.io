#include<bits/stdc++.h>
using namespace std;
int n,a[(int)1e7+5];
pair<int,int> p;
clock_t st,ed;
void solve(int cas){
	freopen(("IOSpeedTest"+to_string(cas)+".in").c_str(),"r",stdin);
	freopen(("IOSpeedTest"+to_string(cas)+".out").c_str(),"w",stdout);
	read(n); // I/O
	st=clock();
	for(int i=1;i<=n;i++) read(a[i]); // I/O
	ed=clock();
	p.first=ed-st;
	st=clock();
	for(int i=1;i<=n;i++) write(a[i]); // I/O
	flush();
	ed=clock();
	p.second=ed-st;
}
int main(){
	freopen("result.txt","w",stdout);
	cout<<"Case\tin\tout\n";
	for(int i=1;i<=10;i++){
		solve(i);
		freopen("result.txt","a",stdout);
		cout<<"Case #"<<i<<" \t"<<p.first<<'\t'<<p.second<<endl;
	}
	return 0;
}

