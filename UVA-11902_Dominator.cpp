#include <bits/stdc++.h>
#define endl               "\n"
#define int                long long int
#define yes                cout << "YES" << endl
#define no                 cout << "NO" << endl
#define fastIO             ios::sync_with_stdio(false); cin.tie(NULL);
// #define int                unsigned long long int
#define all(v)             v.begin(),v.end()
#define print(v)           for(auto x : v) cout << x << " "; cout << endl;
#define init(arr, val)     memset(arr, val, sizeof(arr))
#define testcase(x)        cout << "Case " << x << ":"
using namespace std;

vector<int>vis(105);
vector<vector<int>>v;
vector<vector<int>>ans(105,vector<int>(105,0));
void dfs(int vertex,int dominator){
    if(vertex==dominator) return;
    vis[vertex]=1;
    for(int i=0;i<v.size();i++){
        if(v[vertex][i]==1 && vertex!=i && vis[i]!=1) dfs(i,dominator);
    }
}
void DFS(int vertex){
    // if(vertex==dominator) return;
    vis[vertex]=1;
    for(int i=0;i<v.size();i++){
        if(v[vertex][i]==1 && vertex!=i && vis[i]!=1) DFS(i);
    }
}
int32_t main() {
    fastIO;
    int t; cin >> t;
    // cout << MAX << endl;
    for(int test=1;test<=t;test++){
        testcase(test) << endl;;
        int n; cin >> n;
        for(int i=0;i<n;i++){
            vector<int>temp;
            for(int j=0;j<n;j++){
                int x; cin >> x;
                temp.push_back(x);
            }
            v.push_back(temp);
        }
        for(int i=0;i<n;i++){
            dfs(0,i);
            vector<int>temp_vis = vis;
            for(int i=0;i<105;i++) vis[i]=0;
            DFS(0);    
            for(int j=0;j<n;j++){
                if(vis[j]!=temp_vis[j]){
                    ans[i][j]=1;
                }
            }
            for(int i=0;i<105;i++) vis[i]=0;
        }
        for(int i=0;i<n;i++){
            cout << "+";
            for(int cnt=0;cnt<n*2-1;cnt++)cout << "-";
            cout << "+"<< endl;
            for(int j=0;j<n;j++){
                if(ans[i][j]) cout << "|Y";
                else cout << "|N";
            }
            cout <<"|"<< endl;
        }
        cout << "+";
        for(int cnt=0;cnt<n*2-1;cnt++)cout << "-";
        cout << "+"<<endl;
        for(int i=0;i<105;i++){
            for(int j=0;j<105;j++){
                ans[i][j]=0;
            }
        }
        v.clear();
    }
    return 0;
}
