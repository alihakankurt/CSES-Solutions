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

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    u16 n;
    cin >> n;

    auto grid = vector<string>(n);
    for (string& row : grid)
    {
        cin >> row;
    }

    string answer(2 * n - 1, 0);
    vector<pair<u16, u16>> possibleSquares, nextPossibleSquares;

    answer.front() = grid[0][0];
    answer.back() = grid[n - 1][n - 1];
    possibleSquares.emplace_back(0, 0);

    auto updateState = [grid, &nextPossibleSquares](char minLetter, u16 y, u16 x)
    {
        if (grid[y][x] < minLetter)
        {
            minLetter = grid[y][x];
            nextPossibleSquares.clear();
        }

        if (grid[y][x] <= minLetter)
        {
            nextPossibleSquares.emplace_back(y, x);
        }

        return minLetter;
    };

    for (u16 index = 1; index < answer.length() - 1; index += 1)
    {
        nextPossibleSquares.clear();
        char minLetter = numeric_limits<char>::max();

        for (auto [y, x] : possibleSquares)
        {
            if (x + 1 < n)
            {
                minLetter = updateState(minLetter, y, x + 1);
            }

            if (y + 1 < n)
            {
                minLetter = updateState(minLetter, y + 1, x);
            }
        }

        sort(nextPossibleSquares.begin(), nextPossibleSquares.end());
        nextPossibleSquares.erase(
            unique(nextPossibleSquares.begin(), nextPossibleSquares.end()),
            nextPossibleSquares.end()
        );

        answer[index] = minLetter;
        swap(possibleSquares, nextPossibleSquares);
    }

    cout << answer;

    return 0;
}
