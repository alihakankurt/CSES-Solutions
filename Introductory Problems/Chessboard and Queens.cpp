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

inline constexpr u64 N = 8;

u64 CountPositions(const vector<vector<bool>>& chessboard, vector<bool>& files, vector<bool>& leftDiagonal, vector<bool>& rightDiagonal, u64 rank = 1)
{
    u64 positions = 0;
    for (u64 file = 1; file <= N; file += 1)
    {
        u64 leftIndex = rank + (N - file);
        u64 rightIndex = rank + (file - 1);

        if (!chessboard[rank][file] || !files[file] || !leftDiagonal[leftIndex] || !rightDiagonal[rightIndex])
            continue;

        if (rank == N)
        {
            positions += 1;
            continue;
        }

        files[file] = false;
        leftDiagonal[leftIndex] = false;
        rightDiagonal[rightIndex] = false;

        positions += CountPositions(chessboard, files, leftDiagonal, rightDiagonal, rank + 1);

        rightDiagonal[rightIndex] = true;
        leftDiagonal[leftIndex] = true;
        files[file] = true;
    }

    return positions;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    auto chessboard = vector<vector<bool>>(N + 1, vector<bool>(N + 1, true));
    for (u64 rank = N; rank >= 1; rank -= 1)
    {
        for (u64 file = 1; file <= N; file += 1)
        {
            char ch;
            cin >> ch;
            if (ch == '*')
            {
                chessboard[rank][file] = false;
            }
        }
    }

    vector<bool> files(N + 1, true);
    vector<bool> leftDiagonal(2 * N, true), rightDiagonal(2 * N, true);

    u64 positions = CountPositions(chessboard, files, leftDiagonal, rightDiagonal);
    cout << positions;

    return 0;
}
