/* 플랫폼/문제: AtCoder ABC214 C - Distribution
 * 느낀 점:
 * - std::vector::assign 함수 배움 (이것 때문에 컴파일 에러남)
 * - snuke N이 snuke 1에게 줄 때, 안줄때 나눠서 하려고 하였으나 snuke N이 다카하시에게 직접 받는 것보다 N-1애한테서 전달받는게 더 빠를 수도 있음
 *   '3
 *    1 1 1
 *    100 1 100' 일 경우 2번->3번->1번으로 3 1 2가 답이 나옴
 *    근데 내가 한 풀이대로 할 경우 100 1 2로 답이 나올거임
 * - 처음으로 거의 푼 DP 문제?라고 함(제미나이 피셜..)
 * - 점화식까진 찾았는데 원형으로 돌 수 있는 걸 깜빡해가지고.. 조건을 제대로 보자
 *   여기선 두 번 돌리면 중간에 있는 거와 뒤에 있는 거에서 시간 적게 걸리는 걸 알 수 있으니 for문을 두 번 돋려버리면 됨
 * - 출력이 long long형으로 나올거면 중간계산에 있는 변수도 long long 범위인지 체크하자
 * - 항상 변수 초기화 잘했는지 확인..
 * 
 * 
 * std::vector::assign
 * - v.assign(n, value)
 *   : value값으로 벡터를 채우고, 크기를 n개로 바꿈
 *   : 기존 데이터는 모두 사라짐
 *
 * - v.assign(first, last)
 *   : 다른 컨테이너의 반복자 시작점(first)과 끝점(last) 범위에 있는 원소들을 복사해서 가져옴
 */
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    (점화식)
    case가 
    P_n이 공을 처음 갖는 시간
    (i) P_n = T_n인 경우 (첫 번째의 경우는 무조건 이거)
    (ii) P_n = T_n-1 + S_n-1
    (iii) P_n = P_n-1 + S_n-1


    (제미나이 피셜+내 생각)
    항상 P_{i-1} <= T_{i-1} 임.
    -> 우리가 P_i를 공을 처음 갖는 시간이라고 약속했기 때문
    -> 그렇다면 P_i <= T_i
               P_i <= P_{i-1} + S_{i-1} 를 항상 만족함
    -> 따라서 P_{i-1} + S_{i-1} <= T_{i-1} + S_{i-1}이 성립하므로
    
    min(P_{i-1} + S_{i-1}, T_i)로만 고려하면 됨
    */
    
    int n;
    long long total = 0; // sum of P
    vector<vector<int>> arr;
    cin >> n;
    arr.assign(n, vector<int>(2));
    vector<long long> prev(n); // 이전의 P값


    for(int i = 0; i<n; i++) { cin >> arr[i][0]; }
    for(int i = 0; i<n; i++) { cin >> arr[i][1]; }


    /* 
    폐기
    vector<vector<long long>> prev; // 이전의 P 값
    prev.assign(n, vector<long long>(2));

    // snuke N이 snuke 1에게 안줄 때
    prev[0][0] = arr[0][1];
    total = prev[0][0];

    for(int i=1; i<n; i++) {
        long long one = arr[i][1];
        long long two = arr[i-1][1] + arr[i-1][0];
        long long three = prev[i-1][0] + arr[i-1][0];
        
        prev[i][0] = min(one, min(two, three));
        total += prev[i][0];
    }

    // 
    prev[0][1] = arr[n-1][1] + arr[n-1][0];
    total = prev[0][1];

    for(int i=1; i<n; i++) {
        long long one = arr[i][1];
        long long two = arr[i-1][1] + arr[i-1][0];
        long long three = prev[i-1][1] + arr[i-1][0];
        
        prev[i][1] = min(one, min(two, three));
        total += prev[i][1];
    }
    */

    // for문 자체를 2N번 돌리면서 %연산
    prev[0] = arr[0][1];
    total = prev[0];

    for(int i=1; i<2*n; i++) {
        long long one = arr[i%n][1];
        long long two = arr[(i-1)%n][1] + arr[(i-1)%n][0];
        long long three = prev[(i-1)%n] + arr[(i-1)%n][0];
        
        if(i >= n) { prev[i%n] = min(one, min(two, min(three, prev[i%n]))); }
        else { prev[i] = min(one, min(two, three));}
            
        if(i == n) { total = prev[0];}
        else { total += prev[i%n];}
    }

    

    for(int i=0; i<n; i++) { cout << prev[i] << "\n"; }


    return 0;
}


/*
    더 최적화한다면
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> s(n);
    vector<long long> ans(n);

    for(auto &x: s) {cin >> x;}
    for(auto &x: ans) { cin >> x;}

    for(int i=0; i< 2*n; i++) {
        int cur = i % n;
        int next = (i+1) % n;
        ans[next] = min(ans[next], ans[cur] + s[cur]);
    }

    for(int i=0; i<n; i++) { cout << ans[i] << "\n";}

    return 0;
*/