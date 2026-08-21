/* 플랫폼/문제: AtCoder ABC154 C - Distinct or Not
 * 느낀 점:
 * - 중복 확인하는 문제라 set을 사용하면 될 것 같았음
 * - 시간복잡도를 확인하지 않고 풀었음 (std::set의 시간복잡도를 몰랐기 때문)
 * - std::set의 .insert() 함수에 반환값이 있다는 것을 알게 됨
 * - Gemini 피셜, 경쟁 프로그래밍에서 이런 중복 체크 문제에서는 vector(또는 배열)에 다 담은 뒤, 정렬해서 인접한 원소를 비교하는 방식을 더 자주 사용한다고 함.
 * - 메모리 접근이 연속적이라 캐시 효율이 좋아 빠르게 동작하기 때문.
 * 
 * 
 * std::set의 시간복잡도:
 * 1. 탐색(find, count): O(log N)
 * 2. 삽입(insert): O(log N)
 * 3. 삭제(erase): O(log N)
 * 4. 전체 순회: O(N)
 * 
 * 
 * std::set의 .insert() 함수 반환값
 * - pair<iterator, bool>
 * - second가 true: 삽입 성공
 * - second가 false: 중복으로 인해 실패 
 */

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    int num;
    set<int> s;
    
    cin >> n;
    
    bool dupl = false;

    while(n--) {
        cin >> num;

        // 못찾았으면
        if(s.insert(num).second == false) { dupl = true; }
    }

    if(dupl) { cout << "NO"; }
    else { cout << "YES"; }

    return 0;
}