#include <bits/stdc++.h>
using namespace std;

using u8 = uint8_t;
using u16 = uint16_t;
using u32 = uint32_t;
using u64 = uint64_t;
using usize = size_t;
using uptr = uintptr_t;

using i8 = int8_t;
using i16 = int16_t;
using i32 = int32_t;
using i64 = int64_t;
using isize = make_signed_t<size_t>;
using iptr = intptr_t;

using f32 = float_t;
using f64 = double_t;

constexpr i32 Modulus = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    constexpr u16 N = 8u;
    constexpr array<i16, 8> dY = {-2, -2, -1, -1, +1, +1, +2, +2};
    constexpr array<i16, 8> dX = {-1, +1, -2, +2, -2, +2, -1, +1};

    u16 sx, sy;
    cin >> sx >> sy;
    --sx, --sy;

    auto board = vector<vector<u16>>(N, vector<u16>(N));

    function<bool(u16, u16, u16)> search = [&](auto y, auto x, auto move) -> bool {
        board[y][x] = move;
        if (move == N * N)
            return true;

        vector<pair<u16, u16>> candidates;
        candidates.reserve(8);
        for (u16 direction = 0u; direction < 8u; ++direction)
        {
            u16 ny = y + dY[direction];
            u16 nx = x + dX[direction];

            if (ny >= N || nx >= N || board[ny][nx] != 0u)
                continue;

            u16 moves = 0u;
            for (u16 cdirection = 0u; cdirection < 8u; ++cdirection)
            {
                u16 cy = ny + dY[cdirection];
                u16 cx = nx + dX[cdirection];

                if (cy >= N || cx >= N || board[cy][cx] != 0u)
                    continue;

                ++moves;
            }

            candidates.emplace_back(moves, direction);
        }

        sort(candidates.begin(), candidates.end());

        for (auto [_, direction] : candidates)
        {
            u16 ny = y + dY[direction];
            u16 nx = x + dX[direction];

            if (search(ny, nx, move + 1u))
            {
                return true;
            }
        }

        board[y][x] = 0u;
        return false;
    };

    search(sy, sx, 1u);

    for (u16 y = 0u; y < N; ++y)
    {
        for (u16 x = 0u; x < N; ++x)
        {
            cout << board[y][x] << ' ';
        }

        cout << '\n';
    }

    return 0;
}
