/* 플랫폼/문제: AtCoder ABC206 C - Swappable
 * 느낀 점:
 * - 값을 받은 다음 배열을 for문으로 탐색돌리면 될 것 같았음
 * - 하지만 그렇게 하면 시간복잡도가 O(n^2)이 되므로 시간초과로 나오게 됨.
 * - 결국에 잘 모르겠어가지고 Gemini 도움 조금 받았음 (여사건, std::map 등등..)
 * - std::map 복습했음. (물론 백준 풀면서 알았지만, 오랜만에 복습함.)
 * 
 * 
 * std::map
 * - (key, value) 쌍으로 관리
 * - std::vector랑 다르게 이진트리(정확히는, 자가 균형 이진 탐색 트리)임
 * - m[key]로 접근 (key는 정수, 문자열 등 다양하게 지정 가능)
 * - O(log N) (std::vector는 O(N))
 * - key기준 오름차순으로 항상 자동 정렬
 */

#include <bits/stdc++.h>

using namespace std;
using ll = long long;


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll n;
    int in;
    ll cases;
    map<int, int> num_cnt;

    cin >> n;
    cases = n * (n-1) / 2;

    for(int i = 0; i<n; i++) {
        cin >> in;

        // map은 아직 존재하지 않는 key에 접근하면 자동으로 value를 0으로 초기화 해줌
        num_cnt[in]++; // 즉, 이 코드에서 초기화되지 않았다면 0. (후위연산자로 1로 증가)
    }

    // 개수 2개 이상인 것들 고려해야 함.
    for(auto x : num_cnt) {
        ll i = x.second;
        if(i > 1) { cases -= i * (i-1) / 2; }
    }

    cout << cases;

    return 0;
}