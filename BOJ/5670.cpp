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

const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX = 101010; // PLZ CHK!

struct trie {
    trie *ch[26];
    int cnt; // cnt는? 
    bool fin;
    trie() {
        fill(ch, ch+26, nullptr);
        fin=cnt=0;
    }
    ~trie() {
        for (int i=0; i<26; i++) if (ch[i]) delete ch[i];
    }
};

void insert(trie *root, string s) {
    trie *hr=root;
    int i=0; 
    while (i<sz(s)) {
        int x=s[i]-'a';
        if (hr->ch[x] == NULL) hr->ch[x]=new trie(), hr->cnt++;
        hr = hr->ch[x];
        i++;
    }
    hr->fin = true;
}

ll go(trie *root, string s) {
    trie *hr=root;
    int i=0, p=0; 
    while (i<sz(s)) {
        int x=s[i]-'a';
        hr=hr->ch[x];
        if (hr->cnt!=1 || hr->fin) p++;
        i++;
    }
    return 1ll*p;
}

int main() {
    fio();
    
    while (1) {
        int n; 
        cin>>n;
        if (cin.eof()) break;

        trie* root=new trie();
        vector<string> v(n);
        for (string &s:v) {
            cin>>s;
            insert(root, s);
        }

        ll sum=0;
        for (string s:v) {
            ll x=go(root,s);
            sum+=x;
        }

        cout<<fixed;
        cout.precision(2);
        cout<<(double)sum/n<<endl;

        delete root;
    }
    return 0;
}