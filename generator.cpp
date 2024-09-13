#include<bits/stdc++.h>
#include<windows.h>
#define pb push_back
#define is insert
#define INF INT_MAX
#define Mod(a,m) (((a)%(m)+(m))%(m))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int CAS=205;
int cas,st,cnt;
string pn,dmn,stdn,u,order,flag;
struct Unknownn{int a[CAS];}U;
vector<Unknownn> v;
int main(){
	cout<<"Loading";Sleep(500);system("cls");
	cout<<"Problem's name? ";
	cin>>pn;
	cout<<"How many case do you want? ";
	cin>>cas;
	cout<<"The beginning ID? ";
	cin>>st;
	cout<<"DataMaker's name?(No \".exe\") ";
	cin>>dmn;
	Sleep(500);
	system("cls");
	cout<<"How many unknown do you want? ";
	cin>>cnt;
	for(int i=1;i<=cnt;i++){
		cout<<"Unknown "+to_string(i)+":\nname? ";
		cin>>u;
		cout<<"val?\n";
		for(int j=1;j<=cas;j++) cout<<"Case #"<<j<<":",cin>>U.a[j];
		v.pb(U);
		cout<<"Unknown "+to_string(i)+" already configured!\n";
	}
	Sleep(500);
	system("cls");
	cout<<"Do you want to delete other data?(Y/N) ";
	cin>>flag;
	if(flag[0]=='Y'){
		cout<<"Deleting..."<<endl;
		system(("del "+pn+"*.in").c_str());
		system(("del "+pn+"*.out").c_str());
	}
	Sleep(500);
	cout<<"Making Input..."<<endl;
	for(auto k:v){
		for(int i=1;i<=cas;i++) cout<<k.a[i]<<" ";
		puts("");
	}
	for(int i=st;i<=st+cas-1;i++){
		order=dmn+".exe";
		for(auto k:v) order+=" "+to_string(k.a[i-st+1]);
		order+=" > "+pn+to_string(i)+".in";
		system(order.c_str());
		cout<<order<<endl;
		Sleep(1000);
	}
	cout<<"Successful!";
	system("pause");
	return 0;
}

