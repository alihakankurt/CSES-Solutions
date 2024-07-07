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

u32 FindMatchingPaths(const string& path, vector<vector<bool>>& visited, usize index, u16 y, u16 x)
{
    if ((y == 7 && x == 1) || index == 48)
    {
        return (y == 7 && x == 1) && index == 48;
    }

    u32 positions = 0;
    visited[y][x] = true;

    if ((path[index] == '?' || path[index] == 'U') && !visited[y - 1][x])
    {
        if (!visited[y - 2][x] || (visited[y - 1][x - 1] || visited[y - 1][x + 1]))
        {
            positions += FindMatchingPaths(path, visited, index + 1, y - 1, x);
        }
    }

    if ((path[index] == '?' || path[index] == 'D') && !visited[y + 1][x])
    {
        if (!visited[y + 2][x] || (visited[y + 1][x - 1] || visited[y + 1][x + 1]))
        {
            positions += FindMatchingPaths(path, visited, index + 1, y + 1, x);
        }
    }

    if ((path[index] == '?' || path[index] == 'L') && !visited[y][x - 1])
    {
        if (!visited[y][x - 2] || (visited[y - 1][x - 1] || visited[y + 1][x - 1]))
        {
            positions += FindMatchingPaths(path, visited, index + 1, y, x - 1);
        }
    }

    if ((path[index] == '?' || path[index] == 'R') && !visited[y][x + 1])
    {
        if (!visited[y][x + 2] || (visited[y - 1][x + 1] || visited[y + 1][x + 1]))
        {
            positions += FindMatchingPaths(path, visited, index + 1, y, x + 1);
        }
    }

    visited[y][x] = false;
    return positions;
}

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string path;
    cin >> path;

    auto visited = vector<vector<bool>>(9, vector<bool>(9, false));
    for (usize index = 0; index < 9; index += 1)
    {
        visited[index][0] = true;
        visited[index][8] = true;
        visited[0][index] = true;
        visited[8][index] = true;
    }

    u32 matches = FindMatchingPaths(path, visited, 0, 1, 1);
    cout << matches;

    return 0;
}
