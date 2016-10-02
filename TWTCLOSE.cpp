#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;

int main(){
	int K,N,i,counter = 0;
	char inp[10], num;
	cin>>N>>K;
	bool open[N];
	getchar();
	for(int i=0; i<=N ;++i) open[i] = false;
	while(K--){
        counter = 0;
		cin>>inp;
		if (!strcmp(inp,"CLOSEALL")){
            for(int i=0; i<=N ;++i) open[i] = false;
        }
		else{

            cin>>num;
            i = num - '0';
            if(!open[i]) open[i] = true;
			else open[i] = false;
			for(int itr = 0; itr <= N; ++itr){
                if(open[itr] == true) ++counter;
            }
            }
		cout<<counter<<endl;
		}
	return 0;
}
