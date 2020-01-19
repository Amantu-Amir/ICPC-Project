#include<bits/stdc++.h>
#define int long long int
using namespace std;
const int N = 2e5+50;
const int mod = 1e9+7;
void fast(){ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int fx[]={0,0,1,-1};    //grid visit
int fy[]={1,-1,0,0};

//5 5
//#P...
//##.#.
//..#..
//#....
//D.##.


string s[205];
class data{
public:
    int ff, ss;
};

int row, col;
int bfs(int x, int y){
    int vis[205][205];
    memset(vis, 0, sizeof vis);
    queue<data>q; int cost = 1<<28;
    q.push({x, y});
    while(!q.empty()){
        data child = q.front(); q.pop();
        for(int i=0; i<4; i++){
            int xx = child.ff + fx[i];
            int yy = child.ss + fy[i];
            if(xx >= 0 and xx < row and yy >= 0 and yy < col and s[xx][yy] != '#' and !vis[xx][yy]){
                vis[xx][yy] = vis[child.ff][child.ss] + 1;
                if(s[xx][yy] == 'D'){
                    cost = min(cost, vis[xx][yy]);
                }
                q.push({xx, yy});
            }
        }
    }
    if(cost == (1<<28)) return -1;
    return cost;
}

int32_t main(){
    //fast();
    cin>>row>>col;
    int px, py, dx, dy;
    for(int i=0; i<row; i++){
        cin>>s[i];
        for(int j=0; j<col; j++){
            if(s[i][j] == 'P'){
                px = i; py = j;
            }
            else if(s[i][j] == 'D'){
                dx = i; dy = j;
            }
        }
    }
    int res = bfs(px, py);
    if(res == -1){
        cout<<"Impossible\n";
    }
    else{
        cout<<"Yes\n"<<res-1<<"\n";
    }
    return 0;
}

