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

struct Range
{
    usize Index;
    usize Start;
    usize End;
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    vector<Range> ranges(n);
    for (usize index = 0; index < n; index += 1)
    {
        usize start, end;
        cin >> start >> end;
        ranges[index] = Range{index, start, end};
    }

    sort(ranges.begin(), ranges.end(), [](const Range& left, const Range& right) {
        return (left.End == right.End) ? left.Start > right.Start : left.End < right.End;
    });

    vector<bool> contains(n, false), contained(n, false);
    usize minStart = numeric_limits<usize>::max(), maxStart = 0;

    for (usize index = 0; index < n; index += 1)
    {
        if (ranges[index].Start <= maxStart)
            contains[ranges[index].Index] = true;
        else
            maxStart = ranges[index].Start;
    }

    for (isize index = n - 1; index >= 0; index -= 1)
    {
        if (ranges[index].Start >= minStart)
            contained[ranges[index].Index] = true;
        else
            minStart = ranges[index].Start;
    }

    for (usize index = 0; index < n; index += 1)
    {
        cout << contains[index] << ' ';
    }

    cout << '\n';

    for (usize index = 0; index < n; index += 1)
    {
        cout << contained[index] << ' ';
    }

    return 0;
}
