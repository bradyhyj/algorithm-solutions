/* 플랫폼/문제: Goricon 2026 B - 나는 호반우가 좋아!
 * 느낀 점:
 * - 내가 작성한 코드의 시간복잡도는 O(N log N)임 (정렬 때문에)
 * - 카운팅 정렬 사용하면 O(N)만에 가능함 (알파벳은 26개니까 길이가 26인 배열 만들어서 세서 출력하면 됨)
 * - string 이어붙이기가 되네.. (+= 연산자로..) (해봤는데 까먹은거일 수도 있음)
 */
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    char k;
    int H_cnt=0;
    string x;    

    for(int i=0; i<n; i++) {
        cin >> k;

        if(k == 'H') {H_cnt++;}
        else {x+=k;}
    }
    sort(x.begin(), x.end());
    
    while(H_cnt--) {cout << "H";}
    cout << x;

    return 0;
}