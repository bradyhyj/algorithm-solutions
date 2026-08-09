/* 플랫폼/문제: AtCoder ABC467 C - Adjacent Sums (easy)
 * 느낀 점:
 * - 최초로 C를 해결했으나 계속 틀렸음
 * - 반례를 몰라서 Gemini 참고해서 풀었음
 * - Gemini 힌트를 참고한 다음, 코드를 완성하였음
 * - 그리고 사고과정 아래와 같이 정리하였음
 */
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    
    vector<int> A_original(n);
    vector<int> A_change(n);
    vector<int> B(n);
    for(int i = 0; i<n; i++) { cin >> A_original[i]; }
    for(int i = 0; i<n-1; i++) { cin >> B[i]; }
    A_change = A_original; // 이렇게 하면 복사할 수 있음


    // 점화식 a_i + a_(i+1) mod M(2) == B_i 를 만족하여야 한다
    // 더하기만 가능하고
    // 수열의 값이 "입력될 때", 0이나 1만이 가능하다.
    // 무조건 뒤쪽에 하는게 이득인듯? 라고 생각했지만
    // 앞에서 하는게 좋은 반례가 존재.. 
    // 4 2
    // 0 1 1 1
    // 0 0 0

    // 그렇다고 해서 앞에서부터 뒤까지 1 증가시킬 때 굳이 앞으로 되돌아갈 필요가 없음
    // 되돌아가서 증가시킨다면 점화식을 만족시키지 않기 때문
    // 그리고 무조건 뒤에를 증가시킨다고 최적화되지는 않음. (cf. 반례)
    // 그러면 '무조건'을 제외하고 생각하자.
    // 뒤로 가면서 점화식 체크하면서 증가시킨다는 논리는 고정시키고
    // 반례처럼 앞에 있는 항들을 꼭 증가시켜야만 하는 경우가 있는데
    // 이건 첫번째 항을 1 증가시키는 걸로 해결할 수 있음
    // 즉, 첫번째 항 하나를 증가시킨 배열과 원래의 배열 투 트랙으로 진행하면 된다!


    int cnt_o = 0;
    int cnt_c = 0;
    A_change[0]++; cnt_c++;

    for(int i=0; i<n-1; i++) {
        // 원래
        if((A_original[i] + A_original[i+1]) % m != B[i]) { cnt_o++; A_original[i+1]++; }

        // 0번 index 수정한 경우
        if((A_change[i] + A_change[i+1]) % m != B[i]) { cnt_c++; A_change[i+1]++; }
    }

    cout << min(cnt_c, cnt_o);

    return 0;
}