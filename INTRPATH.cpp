#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int bfs(vector<int> adj[], vector<int> & parent, vector<int> & depth, vector<int> & subtr, int s) {
    for(int i = 0; i < adj[s].size(); ++i) {
        if(adj[s][i] == parent[s])  continue;
        depth[adj[s][i]] = depth[s] + 1;
        parent[adj[s][i]] = s;
        subtr[s] += bfs(adj, parent, depth, subtr, adj[s][i]);
    }
    return subtr[s];
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int t, n, q, u, v, sum, sum2;
	ll result, result1, result2;
	cin>>t;
	while(t--) {
        cin>>n>>q;
        vector<int> adj[n];
        for(int i = 0; i < n-1; ++i) {
            cin>>u>>v;
            adj[u-1].push_back(v-1);
            adj[v-1].push_back(u-1);
        }
        vector<int> parent(n, -1);
        vector<int> depth(n, 0);
        vector<int> subtr(n, 1);
        unordered_map<string, int> um, dpp;
        bfs(adj, parent, depth, subtr, 0);
        vector<ll> sum2vec(n, 0);
        for(int i = 0; i < n; ++i) {
            sum2vec[i] = 0;
            for(int j = 0; j < adj[i].size(); ++j) {
                if(adj[i][j] != parent[i])
                    sum2vec[i] += subtr[adj[i][j]] * subtr[adj[i][j]];
            }
        }
        for(int i = 0; i < n; ++i) {
            int x = i, cx = i;
            result = 0;
            while(x != -1) {
                sum = subtr[x] - 1;
                sum2 = sum2vec[x];
                if(x != cx) {
                    sum -= subtr[cx];
                    sum2 -= subtr[cx] * subtr[cx];
                }
                result += 1 + sum  + (sum*sum - sum2)/2;
                if(i <= x) {
                    dpp[to_string(i) + '-' + to_string(x)] = result;
                    //cout<<to_string(i+1) + '-' + to_string(x+1)<< " = "<<result<<endl;
                }
                else {
                    dpp[to_string(x) + '-' + to_string(i)] = result;
                    //cout<<to_string(x+1) + '-' + to_string(i+1)<< " = "<<result<<endl;
                }
                cx = x;
                x = parent[x];
            }
        }
        while(q--) {
            cin>>u>>v;
            if(u > v)   swap(u, v);
            --u;
            --v;
            string gkey = to_string(u) + '-' + to_string(v);
            if(um.find(gkey) != um.end()) {
                cout<<um[gkey]<<endl;
                continue;
            }
            int pu = u, pv = v;
            int cu = -2, cv = -2;
            vector<int> pathu, pathv;
            while((depth[pu] > 0 || depth[pv] > 0) && (pu != pv)) {
                if(depth[pu] > depth[pv]) {
                    pathu.push_back(pu);
                    pu = parent[pu];
                }
                else if(depth[pu] < depth[pv]) {
                    pathv.push_back(pv);
                    pv = parent[pv];
                }
                else {
                    pathu.push_back(pu);
                    pathv.push_back(pv);

                    pu = parent[pu];
                    pv = parent[pv];
                }
            }
            int nu = pathu.size(), nv = pathv.size();
            result = 0;
            result1 = 0;
            result2 = 0;
            int l, g;
            if(nu > 0) {
                g = max(pathu[0], pathu[nu-1]), l = min(pathu[0], pathu[nu-1]);
                result += dpp[to_string(l) + '-' + to_string(g)];
                cu = pathu[nu-1];
            }
            if(nv > 0) {
                g = max(pathv[0], pathv[nv-1]), l = min(pathv[0], pathv[nv-1]);
                result += dpp[to_string(l) + '-' + to_string(g)];
                cv = pathv[nv-1];
            }
            sum = subtr[pu]-1;
            sum2 = sum2vec[pu];
            if(parent[pu] != -1) {
                sum += n - subtr[pu];
                sum2 += (n - subtr[pu]) * (n - subtr[pu]);
            }
            if(cu >= 0) {
                sum -= subtr[cu];
                sum2 -= subtr[cu] * subtr[cu];
            }
            if(cv >= 0) {
                sum -= subtr[cv];
                sum2 -= subtr[cv] * subtr[cv];
            }
            result += 1 + sum  + (sum*sum - sum2)/2;
            um[to_string(u) + '-' + to_string(v)] = result;
            cout<<result<<endl;
        }
	}
	return 0;
}