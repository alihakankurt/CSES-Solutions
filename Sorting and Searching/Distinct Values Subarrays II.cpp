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

    usize n, k;
    cin >> n >> k;

    vector<i32> nums(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> nums[index];
    }

    usize count = 0;
    map<i32, usize> items;

    for (usize start = 0, end = 0; end < n; end += 1)
    {
        items[nums[end]] += 1;
        while (items.size() > k)
        {
            auto it = items.find(nums[start]);
            it->second -= 1;
            if (it->second == 0)
            {
                items.erase(it);
            }
            start += 1;
        }

        count += end - start + 1;
    }

    cout << count;

    return 0;
}
