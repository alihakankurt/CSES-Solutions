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

struct Task
{
    u32 Duration;
    u32 Deadline;

    bool operator<(const Task& other) const
    {
        return Duration < other.Duration || (Duration == other.Duration && Deadline < other.Deadline);
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n;
    cin >> n;

    vector<Task> tasks(n);
    for (usize index = 0; index < n; index += 1)
    {
        u32 duration, deadline;
        cin >> duration >> deadline;
        tasks[index] = Task{duration, deadline};
    }

    sort(tasks.begin(), tasks.end());

    i64 totalReward = 0;
    u64 currentTime = 0;
    for (const Task& task : tasks)
    {
        currentTime += task.Duration;
        totalReward += task.Deadline - currentTime;
    }

    cout << totalReward;

    return 0;
}
