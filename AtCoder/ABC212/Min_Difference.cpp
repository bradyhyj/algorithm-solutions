/* 플랫폼/문제: AtCoder ABC212 C - Min Difference
 * 느낀 점:
 * - 투 포인터 알고리즘 다시 복습하였음
 * - 오랜만에 제미나이 없이 풀 수 있을줄 알았으나.. 시간복잡도 최적화를 못하겠어가지고 힌트 얻었음(투 포인터)
 * - min을 변수명으로 쓰면 안됨(std::min과 충돌 위험성 있음)
 * - 선형배열 하나에만 투 포인터 알고리즘 사용할 수 있는 줄 알았는데 그런 건 꼭 아니었음
 * - 정렬 시간복잡도가 O(n log n)인 거 오랜만에 복습하였음 (자료구조 교수님 죄송합니다 ㅎㅎ;;)
 * - 9월 4일에 다 해결하려 하였으나,, 독일 일정 때문에 ㅎㅎ..
 */
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    
    cin >> n >> m;

    /*
     * 첫 번째 풀이
     * Gemini한테 투 포인터로 풀 수 있다고 힌트 얻은 뒤 풀어봤음
     * 이렇게 하면 멀리 떨어진 원소도 비교해야해서 효율이 좋지 못함
     * std::set::contains는 O(log N)임
     * gemini피셜 vector<pair<int,int>> all; 로 {값, 출처} 형태로 저장하면 O(1)만에 가능함
     * 이렇게 하면 시간복잡도는 O(N log N + M log M)이라고 볼 수 있을 듯 (정렬 때문에)
    int num;
    vector<int> all(n+m);
    set<int> a, b;

    for(int i=0; i<n; i++) { 
        cin >> num;
        all[i] = num;
        a.insert(num);
    }
    for(int i=0; i<m; i++) { 
        cin >> num;
        all[n+i] = num;
        b.insert(num);
    }
    
    sort(all.begin(), all.end());

    
    int L=0, R;
    int min_diff = 1000000000-1;
    for(R = 1; R < n+m; R++) {
        while(L < R) {
            int cal = abs(all[L]-all[R]);
            if(min_diff > cal && (a.contains(all[L]) && b.contains(all[R]) || (a.contains(all[R]) && b.contains(all[L])))) { min_diff = cal;} 
            L++;
        }
    }

    cout << min_diff;
    */
   
    
    // 두 번째 풀이
    // 첫 번째 풀이로 푼 다음 제미나이가 추천해준 풀이임
    // 똑같이 투 포인터로 푸는 방식인데, 배열을 합치지 않고 푸는 방식
    // 시작은 똑같이 0번 index부터 시작함
    // 다만 포인터를 두 포인터 중 더 작은 걸로 골라서 이동시키는 방식임
    // 여기서도 시간복잡도는 동일하게 O(N log N + M log M) (정렬 때문에)
    vector<int> a(n), b(m);
    for(int i=0; i<n; i++) { cin >> a[i];}
    for(int i=0; i<m; i++) { cin >> b[i];}
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int min_diff = 1000000000-1;
    for(int i=0, j=0; i<n && j<m;) {
        int cal = abs(a[i]-b[j]);
        if(min_diff > cal) { min_diff = cal;}
        
        // 둘 중 더 작은 값을 가리키는 포인터를 이동시키면 됨
        // 왜냐하면 더 작은 걸 이동시켜야 절댓값이 줄어들 수 있기 때문
        if(a[i] > b[j]) {j++;}
        else {i++;}
    }

    cout << min_diff;  


    return 0;
}