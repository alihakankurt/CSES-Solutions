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

    u16 n, m;
    cin >> n >> m;

    u16 stateLimit = 1 << n;
    auto dp = vector<vector<u32>>(m + 1, vector<u32>(stateLimit, 0));
    dp[0][0] = 1;

    for (u16 column = 1; column <= m; column += 1)
    {
        for (u16 previousState = 0; previousState < stateLimit; previousState += 1)
        {
            u32 numberOfWays = dp[column - 1][previousState];
            if (numberOfWays == 0)
            {
                continue;
            }

            stack<pair<u16, u16>> possibleTilings;
            possibleTilings.emplace(0, 0);

            while (!possibleTilings.empty())
            {
                auto [row, currentState] = possibleTilings.top();
                possibleTilings.pop();

                if (row == n)
                {
                    dp[column][currentState] = (dp[column][currentState] + numberOfWays) % Modulus;
                    continue;
                }

                if (previousState & (1 << row))
                {
                    possibleTilings.emplace(row + 1, currentState);
                    continue;
                }

                possibleTilings.emplace(row + 1, currentState | (1 << row));
                if (row + 1 < n && (previousState & (1 << (row + 1))) == 0)
                {
                    possibleTilings.emplace(row + 2, currentState);
                }
            }
        }
    }

    cout << dp[m][0];

    return 0;
}
