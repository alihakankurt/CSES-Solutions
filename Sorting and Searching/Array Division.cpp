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

template <typename TScalar, typename... TRest>
inline constexpr TScalar Max(TScalar first, TRest... rest)
{
    static_assert((is_same_v<TScalar, TRest> && ...), "All arguments must have the same type");
    if constexpr (sizeof...(rest) == 0)
        return first;
    else
        return (first > Max(rest...)) ? first : Max(rest...);
}

bool IsDivisible(const std::vector<i32>& nums, usize k, i64 maximumSum)
{
    usize subarrayCount = 0;
    i64 currentSum = 0;

    for (const i32& num : nums)
    {
        currentSum += num;
        if (currentSum > maximumSum)
        {
            subarrayCount += 1;
            currentSum = num;
        }
    }

    if (currentSum > 0)
    {
        subarrayCount += 1;
    }

    return subarrayCount <= k;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n, k;
    cin >> n >> k;

    i64 left = 0, right = 0;
    vector<i32> nums(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> nums[index];
        left = Max<i64, i64>(left, nums[index]);
        right += nums[index];
    }

    while (left < right)
    {
        i64 middle = left + (right - left) / 2;
        if (IsDivisible(nums, k, middle))
            right = middle;
        else
            left = middle + 1;
    }

    cout << left;

    return 0;
}
