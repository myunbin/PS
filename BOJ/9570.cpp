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

vector<set<string>> tt(33);
vector<vector<string>> q,v(33);
int n,k;
int all=1, ad=0;

void go(int i, int k, int a) {
    if (i==ad || k==0) return;
    int na=a/sz(v[i]);
    for (int j=0; j<sz(v[i]); j++) {
        int le=j*na, ri=(j+1)*na;
        if (le<k && k<=ri) {
            cout<<v[i][j]<<sp;
            go(i+1, k-le, na);
            break;
        }
    }
}

int go2(vector<string> &qry, int i, int a) {
    if (i==ad) return 1;
    int na=a/sz(v[i]);
    int ret=0;
    for (int j=0; j<sz(v[i]); j++) {
        int le=j*na, ri=(j+1)*na;
        if (v[i][j]==qry[i]) {
            ret=le+go2(qry, i+1, na);
            break;
        }
    }
    return ret;
}


int main() {
    fio();
    
    cin>>n>>k;
    cin.ignore();

    for (int i=0; i<n; i++) {
        string s;
        getline(cin, s); cin.ignore();
        s=s.substr(18);
        s=s.substr(0, sz(s)-5);

        vector<string> t;
        int p=0, sz=sz(s);
        while (p<sz) {
            string x;
            while (p<sz && s[p]!=' ') {
                x+=s[p];
                p++;
            }
            if (!x.empty()) t.pb(x);
            p++;
        }
        
        if (!t.empty()) {
            ad=sz(t);
            for (int j=0; j<ad; j++) tt[j].insert(t[j]);
            q.pb(t);
        }
    }

    for (int i=0; i<ad; i++) {
        all*=sz(tt[i]);
        for (string s:tt[i]) v[i].pb(s);
    }

    vector<int> del;
    for (int i=0; i<n; i++) del.pb(go2(q[i], 0, all));
    sort(all(del));

    auto ok=[&](int x){
        int c=ub(all(del), x)-del.begin();
        return x-c>=k;        
    };

    int le=k, ri=all, nk=k;
    while (le<=ri) {
        int md=(le+ri)>>1;
        if (ok(md)) {
            nk=md;
            ri=md-1;
        }
        else le=md+1;
    }
    
    go(0,nk,all);

    return 0;
}