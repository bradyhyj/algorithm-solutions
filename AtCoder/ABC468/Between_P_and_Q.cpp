/* 플랫폼/문제: AtCoder ABC468 	C - Between P and Q
 * 느낀 점:
 * - std::next_permutation, std::prev_permutation 함수 알게 됨
 * - N의 범위에 따라 허용되는 시간복잡도가 어떻게 되는지 알게 됨
 * 
 * 
 * 1초당 약 10^8(1억 번) 연산한다고 생각
 * N <= 10
 * : O(N!)
 * : (ex) 완전 탐색 / 순열
 * 
 * N <= 20
 * : O(2^N)
 * : (ex) 부분집합, 백트래킹
 * 
 * N <= 500 ~ 1000
 * : O(N^3) ~ O(N^2)
 * : (ex) 이중·삼중 for문, 단순 구현
 * 
 * N <= 10^5 ~ 10^6
 * : O(N log N), O(N)
 * : (ex) 정렬, 자료구조(해시/스택/큐), 투포인터, 이분탐색
 * 
 * N >= 10^9
 * : O(log N), O(1)
 * : (ex) 수학공식, 단순 나머지 연산
 * 
 * 전체 시간복잡도는 (테스트케이스 개수) * (케이스당 시간복잡도)로 계산
 * 여러 개의 입력변수(예: N과 M)의 경우 두 개의 관계 모두 확인해야 함
 * -> N <= 100, M <= 100000 (정점 N개, 간선 M개인 그래프)의 경우 O(N+M), O(M log N)으로 따져야 함
 */
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> p(n);
    vector<int> q(n);
    
    for(int i=0; i<n; i++) {cin >> p[i];}
    for(int i=0; i<n; i++) {cin >> q[i];}

    int cnt = 0;
    int finish = 0;

    while(next_permutation(p.begin(), p.end())) {
        if(p == q) { finish = 1; break;}

        cnt++;
    }

    if(!finish) { cout << "0";}
    else { cout << cnt;}

    return 0;
}