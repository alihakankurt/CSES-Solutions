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

    u32 x;
    cin >> x;

    vector<u32> weights(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> weights[index];
    }

    sort(weights.begin(), weights.end());

    u32 gondola = 0;
    isize left = 0, right = n - 1;
    while (left <= right)
    {
        if (x - weights[right] >= weights[left])
        {
            left += 1;
        }

        right -= 1;
        gondola += 1;
    }

    cout << gondola;

    return 0;
}
