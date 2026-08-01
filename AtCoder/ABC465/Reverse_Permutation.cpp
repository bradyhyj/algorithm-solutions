/* 플랫폼/문제: AtCoder ABC465 C - Reverse Permutation
 * 느낀 점:
 * - 처음에 2초라서 다 swap하면 O(n^2)이라 안될 것 같았음
 * - 알고리즘이 어떻게 이루어지는지 몰라 Gemini한테 도움받음
 * - 덱(deque) 자료구조 배웠음
 * - 역순으로 바꾸는 다양한 방법 배움(역방향 이터레이터, std::reverse (O(N)), views::reverse)
 * 
 * 
 * 역순으로 바꾸는 방법: 
 * 1. 역방향 이터레이터
 *      for(auto it = per.rbegin(); it != per.rend(); ++it) {
 *        cout << *it << " ";
 *      }
 * 
 * 2. std::reverse
 *      reverse(per.begin(), per.end());
 * 
 * 
 * 3. views::reverse (C++20)
 *      #include <ranges>
 *      for(auto x : per | views::reverse) {
 *        cout << x << " ";
 *      }
 */

#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int len = 0;
    int k = 0; // 0: 정방향, 1: 역방향
    string s;
    cin >> n >> s;

    deque<int> per;

    for(auto x : s) {
        len++;

        // k == 0 
        if(!k) {
            // 정방향인 경우 뒤에서 넣기
            per.push_back(len);

            if(x == 'o') { k=1; }
        }

        else {
            // 역방향인 경우 앞에서 넣기
            per.push_front(len);

            if(x == 'o') { k=0; }
        }
    }
    
    // 역방향인 경우 역순으로 뒤집어줘야함
    if(k) { reverse(per.begin(), per.end()); }

    for(auto x : per) { cout << x << " "; }


    return 0;
}