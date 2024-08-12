#include <bits/stdc++.h>
using namespace std;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = ptrdiff_t;
using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using f32 = float_t;
using f64 = double_t;

inline constexpr i32 Modulus = 1e9 + 7;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    queue<usize> circle;
    for (usize num = 1; num <= n; num += 1)
        circle.push(num);

    while (circle.size() > 1)
    {
        circle.push(circle.front());
        circle.pop();
        cout << circle.front() << ' ';
        circle.pop();
    }

    cout << circle.front() << '\n';

    return 0;
}
