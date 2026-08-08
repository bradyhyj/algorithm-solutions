/* 플랫폼/문제: AtCoder ABC466 C - Count Close Pairs
 * 느낀 점:
 * - 투 포인터 알고리즘 알게 되었음
 * - 투 포인터 알고리즘 몰라서 Gemini 참고하면서 풀었음
 * 
 * 
 * 투 포인터:
 * - 이중 for문은 O(N^2)이지만, 선형 배열을 O(N) 시간에 탐색 가능케함
 * - 단조성이 만족되어야 함(배열이 오름차순이어야 함)
 * - 한 단계에서 Left 포인터나 Right 포인터 둘 중 하나만이 움직일 수 있다.
 * - Left 포인터가 뒤로(왼쪽으로) 되돌아가지 않는다는 게 큰 특징
 */

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    int n;
    cin >> n;
    
    int cnt = 0;
    string s;

    int q = 0;
    int L = 1;

    for(int R = 2; R <= n; R++) { // L이 범위초과하면 R이 늘어나, 탐색 범위가 증가
        while(L < R) {
            cout << "? " << L << " " << R << endl;
            cin >> s;
            
            if(s[0] == 'Y') { break; }
            else { L++; } // No라면 L이 늘어나서 탐색 범위를 줄임
        }

        cnt += R-L; // L ~ R-1에 해당하는 거 다 추가 (사이에 있는 것도 1 이하일테니)
    }
    cout << "! " << cnt << endl;
    return 0;
}