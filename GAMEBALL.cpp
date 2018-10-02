#include <bits/stdc++.h>

using namespace std;

bool matrix[11][11];

void move(vector<int> v[4], int x1, int y1, int x2, int y2) {
	
	v[0].push_back(x1+1);
	v[1].push_back(y1+1);
	v[2].push_back(x2+1);
	v[3].push_back(y2+1);

	matrix[x1][y1] = false;
	matrix[x2][y2] = true;
}

void printSoln(vector<int> v[4]) {

	for(int i = 0; i < v[0].size(); ++i) {
			cout<<v[0][i]<<" "<<v[1][i]<<" "<<v[2][i]<<" "<<v[3][i]<<endl;
	}
}

void clearRow(vector<int> v[4], int x, int n, int m) {

	int c = 0;
	while(c < m-2) {
		move(v, x, c+1, x, c);
		move(v, x, c+2, x, c+1);
		move(v, x, c, x, c+2);
		++c;
	}
}

void clearCol(vector<int> v[4], int y, int n, int m) {

	int c = 0;
	while(c < n-2) {
		move(v, c+1, y, c, y);
		move(v, c+2, y, c+1, y);
		move(v, c, y, c+2, y);
		++c;
	}
}

void clearLastRow(vector<int> v[4], int n, int m) {

	move(v, n-1, 0, n-2, 0);
	clearRow(v, n-1, n, m);
}

void clearLastCol(vector<int> v[4], int n, int m) {

	move(v, 0, m-1, 0, m-2);
	clearCol(v, m-1, n, m);
}

void moveRight(vector<int> v[4], int x, int y, int n, int m) {

	while(y < m-1) {
		move(v, x, y, x, y+1);
		++y;
	}
}

void moveLeft(vector<int> v[4], int x, int y, int n, int m) {

	while(y > 0) {
		move(v, x, y, x, y-1);
		--y;
	}
}

void moveUp(vector<int> v[4], int x, int y) {

	while(x > 0) {
		move(v, x, y, x-1, y);
		--x;
	}
}

int main() {

	int t, n, m;
	cin>>t;

	while(t--) {
		
		pair<int, int> blank;
		cin>>n>>m;
		char c;
		vector<int> v[4];
		if((n==1 && m==1) || (n==2 && m==2) || (n==1 && m==2) || (n==2 && m==1)) {
			cout<<-1<<endl;
			continue;
		}
		
		for(int i = 0; i < n; ++i) {	
			getchar();
			for(int j = 0; j < m; ++j) {
				c = getchar();
			    if(c == '*') {
			        matrix[i][j] = true;
			    }
			    else {
			        matrix[i][j] = false;
			        blank.first = i;
			        blank.second = j;
			        //cout<<blank.first<<endl;
			    }
			}
			
		}

		if(m != 1) {
			while(blank.second != 0) {

				if(blank.second > 1) {
					//cout<<blank.second<<endl;
					move(v, blank.first, blank.second-2, blank.first, blank.second);
					blank.second = blank.second-2;
				}
				else if(blank.second > 0) {
					move(v, blank.first, blank.second-1, blank.first, blank.second);;
					blank.second = blank.second-1;	
				} 
			}
		}

		if(n != 1) {
			while(blank.first != 0) {

				if(blank.first > 1) {
					move(v, blank.first-2, blank.second, blank.first, blank.second);;
					blank.first = blank.first-2;
				}
				else if(blank.first > 0) {
					move(v, blank.first-1, blank.second, blank.first, blank.second);;
					blank.first = blank.first-1;	
				}
			} 
		}

		if( n != 1 && m != 1) {

			clearRow(v, 0, n, m);
			for(int i = 0; i < m-1; ++i) {
				clearCol(v, i, n, m);
			}
			clearLastRow(v, n, m);
			clearLastCol(v, n, m);
			if(n >= 3) {

				moveRight(v, n-2, 0, n, m);
				move(v, n-1, m-1, n-3, m-1);
				moveUp(v, n-3, m-1);

				if(m > 2) {
					move(v, 0, m-1, 0, m-3);
				}
				else {
					move(v, 0, m-1, 1, m-1);
					move(v, 0, m-2, 0, m-1);
					move(v, 0, m-1, 2, m-1);
				}				
			}
			else {
				//cout<<v[0].size()<<endl;
				move(v, 0, m-2, 1, m-2);
				move(v, 1, m-1, 1, m-3);
				moveLeft(v, 1, m-3, n, m);
				move(v, 0, 0, 0, 1);
				move(v, 1, 0, 0, 0);
				move(v, 0, 0, 0, 2);
			}
		}
		else if(n == 1) {
			clearRow(v, 0, n, m);
		}
		else if(m == 1) {
			clearCol(v, 0, n, m);
		}

        cout<<v[0].size()<<endl;
		printSoln(v);
	}

	return 0;
}
