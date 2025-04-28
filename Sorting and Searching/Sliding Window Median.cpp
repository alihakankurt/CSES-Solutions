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

void Add(multiset<i32>& lower, multiset<i32>& upper, i32 value, usize k)
{
    i32 median = *--lower.end();
    if (value > median)
    {
        upper.insert(value);
        if (upper.size() > k / 2)
        {
            lower.insert(*upper.begin());
            upper.erase(upper.begin());
        }
    }
    else
    {
        lower.insert(value);
        if (lower.size() > (k + 1) / 2)
        {
            auto it = --lower.end();
            upper.insert(*it);
            lower.erase(it);
        }
    }
}

void Remove(multiset<i32>& lower, multiset<i32>& upper, i32 value)
{
    if (auto it = lower.find(value); it != lower.end())
        lower.erase(it);
    else
        upper.erase(upper.find(value));

    if (lower.size() < upper.size())
    {
        lower.insert(*upper.begin());
        upper.erase(upper.begin());
    }
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n, k;
    cin >> n >> k;

    if (k == 1)
    {
        for (usize index = 0; index < n; index += 1)
        {
            i32 value;
            cin >> value;
            cout << value << ' ';
        }

        return 0;
    }

    vector<i32> nums(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> nums[index];
    }

    multiset<i32> lower;
    multiset<i32> upper;

    lower.insert(nums[0]);
    for (usize index = 1; index < k; index += 1)
    {
        Add(lower, upper, nums[index], k);
    }

    cout << *--lower.end();

    for (usize index = k; index < n; index += 1)
    {
        Remove(lower, upper, nums[index - k]);
        Add(lower, upper, nums[index], k);
        cout << ' ' << *--lower.end();
    }

    return 0;
}
