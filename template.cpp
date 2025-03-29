#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);std::cin.tie(NULL);cout.tie(NULL)

// types
#define ll long long
#define lld long long double
#define lli long long int
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vc vector<char>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvl vector<vector<long long>>
#define vpii vector<pair<int,int>>
#define vpll vector<pair<long,long>>
#define mii map<int, int>
#define um unordered_map
#define umii unordered_map<int, int>
#define umll map<long long,long long>
#define si set<int>
#define sc set<char>
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define PI 3.1415926535897932384626433832795
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define forn(i,n) for(auto i=0; i<n; i++)

// Ordered Set
template <typename T,typename Compare=less<T>>
using ordered_set=__gnu_pbds::tree<
    T,
    __gnu_pbds::null_type,
    Compare,
    __gnu_pbds::rb_tree_tag,
    __gnu_pbds::tree_order_statistics_node_update
>;

// custom map
struct chash{ static uint64_t splitmix64(uint64_t x){ x+=0x9e3779b97f4a7c15;x=(x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;x=(x ^ (x >> 27)) * 0x94d049bb133111eb;return x ^ (x >> 31); }size_t operator()(uint64_t x) const{ static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();return splitmix64(x + FIXED_RANDOM); } };

template<typename T1,typename T2>
using safe_map=unordered_map<T1,T2,chash>;


// input
template <typename T>
istream& operator>>(istream& in,vector<T>& a){
    for(auto& x : a) in >> x;
    return in;
}

template <typename T>
ostream& operator<<(ostream& out,const vector<T>& a){
    for(const auto& x : a) out << x << " ";
    return out;
}

template <typename T>
istream& operator>>(istream& in,vector<vector<T>>& a){
    for(auto& row : a) in >> row;
    return in;
}

template <typename T>
ostream& operator<<(ostream& out,const vector<vector<T>>& a){
    for(const auto& row : a) out << row << "\n";
    return out;
}

template <typename T1,typename T2>
istream& operator>>(istream& in,vector<pair<T1,T2>>& a){
    for(auto& x : a) in >> x.first >> x.second;
    return in;
}

template <typename T1,typename T2>
ostream& operator<<(ostream& out,const vector<pair<T1,T2>>& a){
    for(const auto& x : a) out << x.first << " " << x.second << endl;
    return out;
}


// arrays
template <typename T>
vector<int> allOccur(const vector<T>& a,T e){
    vector<int> indices;
    for(int i=0; i < a.size(); ++i){
        if(a[i] == e) indices.push_back(i);
    }
    return indices;
}

template <typename T>
T gcdArr(vector<T>& a){
    return accumulate(a.begin() + 1,a.end(),a[0],[](T x,T y){
        return gcd(x,y);
    });
}

// functions

ll min(ll a,int b){ if(a < b) return a; return b; }
ll min(int a,ll b){ if(a < b) return a; return b; }
ll max(ll a,int b){ if(a > b) return a; return b; }
ll max(int a,ll b){ if(a > b) return a; return b; }
ll gcd(ll a,ll b){ if(b == 0) return a; return gcd(b,a % b); }
ll lcm(ll a,ll b){ return a / gcd(a,b) * b; }

// utils
#define yes printYes()
#define no printNo()
string to_upper(string a){ for(int i=0; i < (int)a.size(); ++i) if(a[i] >= 'a' and a[i] <= 'z') a[i]-='a' - 'A'; return a; }
string to_lower(string a){ for(int i=0; i < (int)a.size(); ++i) if(a[i] >= 'A' and a[i] <= 'Z') a[i]+='a' - 'A'; return a; }
bool prime(ll a){ if(a == 1) return 0; for(int i=2; i <= round(sqrt(a)); ++i) if(a % i == 0) return 0; return 1; }

void printYes(){ cout << "yes\n"; }
void printNo(){ cout << "no\n"; }

template<typename T>
T greatestFactor(T n){
    if(n <= 1) return n;
    for(T i=n / 2; i >= 1; --i){
        if(n % i == 0){
            return i;
        }
    }
    return -1;
}

// preprocessor
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

// int to binary string (bits)
string binstr(int n){
    return std::bitset<32>(n).to_string();
}
string binstr(long n){
    return std::bitset<64>(n).to_string();  // 64 bits for long
}
string binstr(long long n){
    return std::bitset<64>(n).to_string();  // 64 bits for long long
}

// DSU
class DSU{
public:
    vector<int> par,rank;
    DSU(int n){
        par.resize(n);
        rank.resize(n,0);
        for(int i=0; i < n; i++){
            par[i]=i;
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x]=find(par[x]);
    }

    void unite(int x,int y){
        int x_par=find(x);
        int y_par=find(y);
        if(x_par != y_par){
            if(rank[x_par] > rank[y_par]){
                par[y_par]=x_par;
            }
            else if(rank[x_par] < rank[y_par]){
                par[x_par]=y_par;
            }
            else{
                par[y_par]=x_par;
                rank[x_par]++;
            }
        }
    }
};


// main
void solve(){

}

// driver
int main(){
    fastio();

#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif

    int tc=1;
    cin>>tc;

    while(tc--){
        solve();
    }

    return 0;
}
