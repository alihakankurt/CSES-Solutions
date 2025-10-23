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

    u32 n;
    cin >> n;

    vector<u32> array(n);
    for (u32& value : array)
    {
        cin >> value;
    }

    u64 answer = 0;
    set<u32> subarray;

    for (u32 start = 0, end = 0; end < n; end += 1)
    {
        u32 value = array[end];

        while (subarray.count(value) > 0)
        {
            subarray.erase(array[start]);
            start += 1;
        }

        subarray.insert(value);
        answer += subarray.size();
    }

    cout << answer;

    return 0;
}
