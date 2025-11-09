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

struct Project
{
    u32 Start;
    u32 End;
    u32 Reward;

    bool operator<(const Project& other) const
    {
        return End < other.End;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    vector<Project> projects(n);
    for (Project& project : projects)
    {
        cin >> project.Start >> project.End >> project.Reward;
    }

    sort(projects.begin(), projects.end());

    u64 earning = 0;
    map<u32, u64> dp;
    dp[0] = 0;

    for (auto [start, end, reward] : projects)
    {
        auto iter = --dp.lower_bound(start);
        earning = max(earning, iter->second + reward);
        dp[end] = earning;
    }

    cout << earning;

    return 0;
}
