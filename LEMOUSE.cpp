#include <iostream>
#include <cmath>
#include <vector>

#define MAX 100

using namespace std;

int Cell[MAX][MAX];
int oldCell[MAX][MAX];
char charCell[MAX][MAX];
int DP[MAX][MAX][2];

int main(){
	int T;
	int n, m, score[MAX][MAX];
	cin>>T;

	while(T--){
		cin>>m>>n;
		for(int i = 0; i < m; ++i){
			cin>>charCell[i];
		}
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				oldCell[i][j] = (int)charCell[i][j] - '0';
			}
		}
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				if(i == 0 && j == 0 && oldCell[i][j] == 1){
					Cell[i+1][j] = +1;
					Cell[i][j+1] = +1; 
				}
				else if(i == 0 && j == n-1 && oldCell[i][j] == 1){
					Cell[i+1][j] = +1;
					Cell[i][j-1] = +1;
				}
				else if(i == 0 && oldCell[i][j] == 1){
					Cell[i+1][j] = +1;
					Cell[i][j+1] = +1;
					Cell[i][j-1] = +1;
				}
				else if(j == 0 && i == m-1 && oldCell[i][j] == 1){
					Cell[i][j+1] = +1;
					Cell[i-1][j] = +1;
				}
				else if(j == 0 && oldCell[i][j] == 1){
					Cell[i-1][j] = +1;
					Cell[i+1][j] = +1;
					Cell[i][j+1] = +1;
				}

				else if(i == m-1 && j == n-1 && oldCell[i][j] == 1){
					Cell[i-1][j] = +1;
					Cell[i][j-1] = +1; 
				}
				else if(i == m-1 && oldCell[i][j] == 1){
					Cell[i-1][j] += 1;
					Cell[i][j+1] += 1;
					Cell[i][j-1] += 1;
				}
				else if(j == n-1 && oldCell[i][j] == 1){
					Cell[i-1][j] += 1;
					Cell[i+1][j] += 1;
					Cell[i][j-1] += 1;
				}
				else{
					Cell[i-1][j] += 1;
					Cell[i+1][j] += 1;
					Cell[i][j-1] += 1;
					Cell[i][j+1] += 1;					
				}
			}
		}

		//D[0][0] = Cell[0][0];
		for(int i = 0; i < m; ++i){
			for(int j = 0; j < n; ++j){
				//if(i == 0 && j == 0)	continue;
				//else if(i == 0)	score[i][j] = Cell[i][j] + score[i][j-1];
				//else if(j == 0)	score[i][j] = Cell[i][j] + score[i-1][j];
				//else{
					//score[i][j] = Cell[i][j] + min(score[i-1][j], score[i][j-1]);
				//}
				if(i == 0 || j == 0){
					DP[i][j][0]=Cell[i][j]-oldCell[i][j];
            		DP[i][j][1]=Cell[i][j]-oldCell[i][j];

				}
				DP[i][j][0]=Cell[i][j]-oldCell[i][j] + min(DP[i][j-1][0], DP[i][j-1][1] - oldCell[i-1][j]);
            	DP[i][j][1]=Cell[i][j]-oldCell[i][j] + min(DP[i-1][j][0] - oldCell[i][j-1], DP[i-1][j][1]);
				//cout<<Cell[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<min(DP[m-1][n-1][0], DP[m-1][n-1][1]) + oldCell[0][0] + oldCell[m-1][n-1]<<endl;
	}
	return 0;
}
