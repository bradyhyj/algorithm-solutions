/* 플랫폼/문제: Goricon 2026 C - 호반우의 4구
 * 느낀 점:
 * - 코사인법칙으로 문제를 풀었음
 * - 문제 잘못읽어가지고,, 시간이 많이 걸려버림 (좌표 동일한 걸 항상 R_1으로 설정해야 하는걸 그냥 input 순서대로 들어오는 줄 알고 헷갈렸음..)
 * - 즉, r1, r2와 R1, R2는 서로 다름!! <-- 이런 문제는 진짜 조심해야할 듯..
 * - 근데 double, sqrt 등등 실수연산 사용해서 오차위험 있다는게 문제임
 * - 정해 피셜 벡터 내적, 조건분기로 풀 수 있다고 함..
 * - 한번더, 벡터내적으로 풀면서 기하 복습할 수 있어 좋았음
 * - 포인터와 참조자 차이 제대로 알게 되었음 (둘 다 주소 전달하는 기능은 동일!)
 * 
 * 포인터(*):
 * - 포인터 쓸 때 호출 시 & 필요
 * 
 * 참조자(&):
 * - 호출 시 일반 변수처럼 전달
 */
#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
};

bool is_aligned(const Point& a, const Point& b) {
    return (a.x == b.x) || (a.y == b.y); 
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    /*
    // 대회에서 풀었던 방법: 코사인법칙
    int w[2];
    int r1[2];
    int r2[2];
    
    for(auto &x : w) { cin >> x;}
    for(auto &x : r1) { cin >> x;}
    for(auto &x : r2) { cin >> x;}

   
    int r1_equal = 0;
    int r2_equal = 0;

    if(r1[0] == w[0] || r1[1] == w[1]) {r1_equal=1;} // r1이 좌표 동일한걸(R1)로 되는거임
    if(r2[0] == w[0] || r2[1] == w[1]) {r2_equal=1;} // r2가 좌표 동일한걸(R1)로 되는거임

    double a, b, c;
    if(r1_equal) {
        b = pow(r1[0]-w[0],2)+pow(r1[1]-w[1],2);
        c = pow(r2[0]-r1[0],2)+pow(r2[1]-r1[1],2);
        a = pow(r2[0]-w[0],2)+pow(r2[1]-w[1],2);
    }

    else {
        b = pow(r2[0]-w[0],2)+pow(r2[1]-w[1],2);
        c = pow(r1[0]-r2[0],2)+pow(r1[1]-r2[1],2);
        a = pow(r1[0]-w[0],2)+pow(r1[1]-w[1],2);
    }

    double cos_a = (double)(b + c - a) / (double)(2*sqrt(b)*sqrt(c));

    if(r1_equal && r2_equal) {cout << "0";}
    else if(cos_a * 10 > -10.000 && cos_a * 10 < 0.000) {cout << "1";}
    else {cout << "0";}
    */





    // 정해: 벡터의 내적 (u*v = |u|*|v|*cosθ = x_u * x_v + y_u  * y_v)
    // u = 벡터 r1->w
    // v = 벡터 r1->r2
    Point w, r1, r2;
    cin >> w.x >> w.y;
    cin >> r1.x >> r1.y;
    cin >> r2.x >> r2.y;

    bool match1 = is_aligned(w, r1);
    bool match2 = is_aligned(w, r2);

    // 흰 공과 좌표가 겹치는 빨간 공이 2개인 경우 (조건 1 위배)
    if(match1 == match2) {
        cout << "0";
        return 0;
    }

    Point R1 = match1 ? r1 : r2;
    Point R2 = match1 ? r2 : r1;

    // R1을 시점으로 한 벡터
    int ux = w.x - R1.x;
    int uy = w.y - R1.y;
    int vx = R2.x - R1.x;
    int vy = R2.y - R1.y;

    int dot_product = ux * vx + uy * vy; // 내적
    

    // 코사인 음수 범위: (pi/2, 3pi/2) -> 둔각!
    if(dot_product < 0) {  cout << "1";}
    else { cout << "0";}
    
    return 0;
}