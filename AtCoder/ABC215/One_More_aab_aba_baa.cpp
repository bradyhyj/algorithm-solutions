/* 플랫폼/문제: AtCoder ABC215 C - One More aab aba baa
 * 느낀 점:
 * - std::next_permutation 복습할 수 있어서 좋았음
 * - vector 말고도 string에 대해서도 next_permutation이 가능함을 알게 되었음
 */
#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    int k;

    cin >> s >> k;
    
    sort(s.begin(), s.end());

    int cnt = 1;
    while (cnt < k && next_permutation(s.begin(), s.end())) {
        cnt++;
    }
    
    cout << s;

    return 0;
}