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

struct Number
{
    u32 Value;
    usize Position;

    bool operator<(const Number& other) const
    {
        return Value < other.Value;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    u32 target;
    cin >> target;

    vector<Number> nums(n);
    for (usize index = 0; index < n; index += 1)
    {
        u32 num;
        cin >> num;
        nums[index] = {num, index + 1};
    }

    sort(nums.begin(), nums.end());

    usize left = 0, right = n - 1;
    while (left < right)
    {
        u64 sum = static_cast<u64>(nums[left].Value) + nums[right].Value;
        if (sum < target)
        {
            left += 1;
        }
        else if (sum > target)
        {
            right -= 1;
        }
        else
        {
            cout << nums[left].Position << ' ' << nums[right].Position;
            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}
