#include <bits/stdc++.h>
#include <limits>
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

constexpr array<pair<i16, i16>, 8> directions{{
    {-2, -1}, {-2, 1}, {-1, -2}, {-1, 2},
    {2, -1}, {2, 1}, {1, -2}, {1, 2}
}};

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u16 n;
    cin >> n;

    auto board = vector<vector<u16>>(n, vector<u16>(n, numeric_limits<u16>::max()));
    auto qu = queue<pair<u16, u16>>();

    board[0][0] = 0;
    qu.emplace(0, 0);

    while (!qu.empty())
    {
        auto [rank, file] = qu.front();
        qu.pop();

        u16 moves = board[rank][file];

        for (auto [drank, dfile] : directions)
        {
            u16 nrank = rank + drank;
            u16 nfile = file + dfile;

            if (nrank >= n || nfile >= n)
            {
                continue;
            }

            u16& square = board[nrank][nfile];

            if (square == numeric_limits<u16>::max())
            {
                square = moves + 1;
                qu.emplace(nrank, nfile);
            }
        }
    }

    for (u16 rank = 0; rank < n; rank += 1)
    {
        for (u16 file = 0; file < n; file += 1)
        {
            cout << board[rank][file] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
