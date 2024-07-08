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

    usize n, m;
    cin >> n >> m;

    u32 k;
    cin >> k;

    vector<u32> applicants(n);
    for (usize index = 0; index < n; index += 1)
    {
        cin >> applicants[index];
    }

    vector<u32> apartments(m);
    for (usize index = 0; index < m; index += 1)
    {
        cin >> apartments[index];
    }

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    u32 result = 0;
    usize applicantIndex = 0, apartmentIndex = 0;
    while (applicantIndex < n && apartmentIndex < m)
    {
        u32 applicant = applicants[applicantIndex];
        u32 apartment = apartments[apartmentIndex];
        if (applicant < apartment)
        {
            if (apartment - applicant <= k)
            {
                result += 1;
                apartmentIndex += 1;
            }

            applicantIndex += 1;
        }
        else
        {
            if (applicant - apartment <= k)
            {
                result += 1;
                applicantIndex += 1;
            }

            apartmentIndex += 1;
        }
    }

    cout << result;

    return 0;
}
