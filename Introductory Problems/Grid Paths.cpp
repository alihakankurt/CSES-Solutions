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
    if (y == 6 && x == 0)
    {
        return (index == 48) ? 1 : 0;
    }

    if (index == 48)
    {
        return 0;
    }

    if ((path[index] == 'U' && y == 0) || (path[index] == 'D' && y == 6))
    {
        return 0;
    }

    if ((path[index] == 'L' && x == 0) || (path[index] == 'R' && x == 6))
    {
        return 0;
    }

    u32 positions = 0;
    visited[y][x] = true;

    if ((path[index] == '?' || path[index] == 'U') && y > 0 && !visited[y - 1][x])
    {
        if (x == 0 || x == 6 || !(y == 1 || visited[y - 2][x]) || (visited[y - 1][x - 1] || visited[y - 1][x + 1]))
        {
            positions += FindMatchingPaths(path, visited, index + 1, y - 1, x);
        }
    }

    if ((path[index] == '?' || path[index] == 'D') && y < 6 && !visited[y + 1][x])
    {
        if (x == 0 || x == 6 || !(y == 5 || visited[y + 2][x]) || (visited[y + 1][x - 1] || visited[y + 1][x + 1]))
        {
            positions += FindMatchingPaths(path, visited, index + 1, y + 1, x);
        }
    }

    if ((path[index] == '?' || path[index] == 'L') && x > 0 && !visited[y][x - 1])
    {
        if (y == 0 || y == 6 || !(x == 1 || visited[y][x - 2]) || (visited[y - 1][x - 1] || visited[y + 1][x - 1]))
        {
            positions += FindMatchingPaths(path, visited, index + 1, y, x - 1);
        }
    }

    if ((path[index] == '?' || path[index] == 'R') && x < 6 && !visited[y][x + 1])
    {
        if (y == 0 || y == 6 || !(x == 5 || visited[y][x + 2]) || (visited[y - 1][x + 1] || visited[y + 1][x + 1]))
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

    auto visited = vector<vector<bool>>(7, vector<bool>(7, false));
    u32 matches = FindMatchingPaths(path, visited, 0, 0, 0);
    cout << matches;

    return 0;
}
