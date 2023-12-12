#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")

#define fileio() freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
#define fio() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) (x).begin(), (x).end()
#define allr(x) x.rbegin(), x.rend()
#define cmprs(x) sort(all(x)),x.erase(unique(all(x)),x.end())
#define endl "\n"
#define sp " "
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define rz resize
#define sz(a) (int)(a.size())
#define clr(a) a.clear()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef tuple<int, int, int> tpi;
typedef tuple<ll, ll, ll> tpl;
typedef pair<double, ll> pdl;
typedef pair<double, int> pdi;

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,1,-1,1,-1,1,-1};
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

vector<string> a(4);
set<array<string,5>> ans;
pii ud[3]={{0,2}, {1,3}, {4,5}};

void go(int i, vector<string> &cur, string &up) {
    if (i==4) {
        for (int j=0; j<4; j++) {
            int r=0,g=0,b=0,y=0;
            for (int k=0; k<4; k++) {
                if (cur[j][k]=='R') r++;
                if (cur[j][k]=='G') g++;
                if (cur[j][k]=='B') b++;
                if (cur[j][k]=='Y') y++;
            }
            if (!r || !g || !b || !y) return;
        }

        // for (string x:cur) cout<<x<<sp; cout<<up<<endl;

        bool ok=1;
        for (int j=0; j<4; j++) {
            if (ans.find({cur[0],cur[1],cur[2],cur[3],up})!=ans.end()) ok=0;
            rotate(cur.begin(), cur.begin()+1, cur.end());
        }
        
        if (ok) ans.insert({cur[0],cur[1],cur[2],cur[3],up});
        return;
    }

    string d=a[i];
    if (i==0) {
        for (int j=0; j<6; j++) {
            string x;
            if (j==0) x+=d[1],x+=d[5],x+=d[3],x+=d[4];
            if (j==1) x+=d[0],x+=d[4],x+=d[2],x+=d[5];
            if (j==2) x+=d[1],x+=d[4],x+=d[3],x+=d[5];
            if (j==3) x+=d[0],x+=d[5],x+=d[2],x+=d[4];
            if (j==4) x+=d[0],x+=d[3],x+=d[2],x+=d[1];
            if (j==5) x+=d[0],x+=d[1],x+=d[2],x+=d[3];

            for (int l=0; l<4; l++) cur[l].pb(x[l]);
            go(i+1, cur, up);
            for (int l=0; l<4; l++) cur[l].pop_back();
        }
    }
    else if (i<3) {
        for (int j=0; j<6; j++) {
            string x;
            if (j==0) x+=d[1],x+=d[5],x+=d[3],x+=d[4];
            if (j==1) x+=d[0],x+=d[4],x+=d[2],x+=d[5];
            if (j==2) x+=d[1],x+=d[4],x+=d[3],x+=d[5];
            if (j==3) x+=d[0],x+=d[5],x+=d[2],x+=d[4];
            if (j==4) x+=d[0],x+=d[3],x+=d[2],x+=d[1];
            if (j==5) x+=d[0],x+=d[1],x+=d[2],x+=d[3];


            for (int k=0; k<4; k++) {
                for (int l=0; l<4; l++) cur[l].pb(x[l]);
                go(i+1, cur, up);
                for (int l=0; l<4; l++) cur[l].pop_back();
                rotate(x.begin(), x.begin()+1, x.end());
            }
        }
    }
    else {
        for (int j=0; j<6; j++) {
            string x;
            if (j==0) x+=d[1],x+=d[5],x+=d[3],x+=d[4];
            if (j==1) x+=d[0],x+=d[4],x+=d[2],x+=d[5];
            if (j==2) x+=d[1],x+=d[4],x+=d[3],x+=d[5];
            if (j==3) x+=d[0],x+=d[5],x+=d[2],x+=d[4];
            if (j==4) x+=d[0],x+=d[3],x+=d[2],x+=d[1];
            if (j==5) x+=d[0],x+=d[1],x+=d[2],x+=d[3];

            for (int k=0; k<4; k++) {
                for (int l=0; l<4; l++) cur[l].pb(x[l]);

                up+=d[j];
                go(i+1, cur, up);
                up.pop_back();

                up+=d[j];
                go(i+1, cur, up);
                up.pop_back();

                for (int l=0; l<4; l++) cur[l].pop_back();
                rotate(x.begin(), x.begin()+1, x.end());
            }
        }
    }
}

int main() {
    fio();
    for (string &s:a) cin>>s;
    
    vector<string> cur(4);
    string up;
    go(0,cur,up);

    cout<<sz(ans);
    
    return 0;
}