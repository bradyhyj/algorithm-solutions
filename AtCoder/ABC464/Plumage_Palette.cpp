/* 플랫폼/문제: AtCoder ABC464 C - Plumage Palette
 * 느낀 점:
 * - 처음엔 브루트포스로 해결해서 TLE 났음. 날짜별 이벤트로 접근해야 하는 문제...
 * - 어려워서 Editorial 참고해서 풀었음
 */

#include <bits/stdc++.h>

using namespace std;
using pi = pair<int,int>;

int main()
{
    int n, m; // n: birds
    int kind = 0;
    cin >> n >> m;
    vector<int> cnt(n+1); // color count
    vector<vector<pi>> change(m+1); // [day]에 {a,b}라고 바뀔거라고 등록이 될 것임

    for(int i=0; i<n; i++) {
        int a, b, d; // a: prev color, b: next color
        cin >> a >> d >> b;

        if(cnt[a] == 0) {kind++;}
        cnt[a]++;
        change[d].push_back({a,b});        
    }

    for(int i = 1; i<=m; i++) {
        for(auto &nx : change[i]) { // event 목록인 change에서 i일에 해당하는 이벤트들 다 가져옴
            cnt[nx.first]--;
            if(cnt[nx.first] == 0) {kind--;} // 색깔 바뀌기 전 cnt에 없으면 새가 없다는 것. kind(종류 줄여야함)
            if(cnt[nx.second] == 0) {kind++;} // 색깔 바뀐 후 cnt에 없으면 그 색깔 새가 없었다는 거니 kind 늘려야함.
            cnt[nx.second]++;
        }

        cout << kind << "\n";
    }

    return 0;
}