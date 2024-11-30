#include <iostream>
#include <unordered_map>
#include <utility>
#include <cmath>
using namespace std;
#define int long long
typedef pair<int,int> pii;
pii sit[1100];
pii hashh[1100];
int gcd(int x, int y)
{
	if (x == 0 || y == 0)
		return x + y;
	return x % y == 0 ? y : gcd(y, x % y);
}
// 自定义哈希函数
struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator ( ) (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);   // 哈希键的第一个元素
        auto h2 = std::hash<T2>{}(p.second);  // 哈希键的第二个元素
        return h1 ^ h2;  // 合并哈希值
    }
};


signed main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>sit[i].first>>sit[i].second;
        }
        int q;
        cin>>q;
        unordered_map<pair<int, int>, int, pair_hash> map;
        while(q--){
            int x,y;
            int cnt=0;
            cin>>x>>y;
            //清空哈希表
            map.clear();
            int xx,yy;
            for(int i=0;i<n;i++){
                xx=sit[i].first-x;
                yy=sit[i].second-y;
                int g=gcd(abs(xx),abs(yy));
                if(g!=0){
                    xx/=g;yy/=g;
                }
                if(xx<0){
                    xx=-xx;yy=-yy;
                }else if(xx==0&&yy<0){
                    yy=-yy;
                }
                pii p={xx,yy};
                map[p]+=1;
                if(map[p]==2)cnt++;
            }
            printf("%lld\n",cnt);
        }
    }
    return 0;
}