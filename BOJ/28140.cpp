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

int main() {
    fio();
    int n,q;
    cin>>n>>q;
    string s; cin>>s;
    
    vector<int> idx[30];
    for (int i=0; i<n; i++) idx[s[i]-'A'].pb(i);

    while (q--) {
        int l,r;
        cin>>l>>r;
        int R='R'-'A', B='B'-'A';
        
        int a=lb(all(idx[R]),l)-idx[R].begin();
        int b=a+1;

        if (b>=sz(idx[R])) {
            cout<<-1<<endl;
            continue;
        }

        int c=lb(all(idx[B]),idx[R][b])-idx[B].begin();
        int d=c+1;

        if (d>=sz(idx[B]) || idx[B][d]>r) {
            cout<<-1<<endl;
            continue;
        }

        cout<<idx[R][a]<<sp<<idx[R][b]<<sp<<idx[B][c]<<sp<<idx[B][d]<<endl;
    }

    return 0;
}