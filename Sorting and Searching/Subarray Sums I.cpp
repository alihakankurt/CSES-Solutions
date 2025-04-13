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

    u64 target;
    cin >> target;

    vector<u32> nums(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> nums[index];
    }

    usize count = 0;
    u64 currentSum = 0;
    for (usize left = 0, right = 0; right < n; right += 1)
    {
        currentSum += nums[right];

        while (currentSum > target)
        {
            currentSum -= nums[left];
            left += 1;
        }

        if (currentSum == target)
        {
            count += 1;
        }
    }

    cout << count;

    return 0;
}
