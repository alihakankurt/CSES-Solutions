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

struct Movie
{
    u32 Start;
    u32 End;

    bool operator<(const Movie& other) const
    {
        return End < other.End;
    }
};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    usize n, k;
    cin >> n >> k;

    vector<Movie> movies(n);
    for (Movie& movie : movies)
    {
        cin >> movie.Start >> movie.End;
    }

    sort(movies.begin(), movies.end());

    usize watched = 0;
    multiset<u32> members;
    for (usize index = 0; index < k; index += 1)
    {
        members.insert(0);
    }

    for (const Movie& movie : movies)
    {
        auto it = members.upper_bound(movie.Start);
        if (it == members.begin())
            continue;

        members.erase(--it);
        members.insert(movie.End);
        watched += 1;
    }

    cout << watched;

    return 0;
}
