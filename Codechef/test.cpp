#include <bits/stdc++.h>
using namespace std;
int dp1[100005];
int dp2[100005];
int dp3[100005];
int nums[100005];
int ans = 0;
unordered_map<int, vector<int>> dic;
inline void find_ijk(int A, int B)
{
    ans += (B-A);
    // cout<<A<<" "<<B<<endl;
    // // total_xor = dp1[B] ^ dp[A - 1];
    // int remove_l = dp1[A - 1];
    // int remove_r = dp2[B + 1];


    // for (int i = 0; i <(B - A); ++i)
    // {

    //     //i == i+1
    //    // int x=(dp1[A + i] ^ remove_l) ;
    //     //int y= (dp2[A + i + 1] ^ remove_r) ;
    //     if ((dp1[A + i] ^ remove_l) == (dp2[A + i + 1] ^ remove_r ) )
    //     {
    //      //   cout << A  << " " << A + i + 1 << " " << B << endl;
    //         ans++;
    //     }
       
    // }
  
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        ans = 0;
        memset(dp1, 0, sizeof(dp1));
        memset(dp2, 0, sizeof(dp2));
        memset(nums, 0, sizeof(nums));
        dic.clear();
        dic[0].push_back(0);
        for (int i = 1; i <= n; ++i)
            cin >> nums[i];

        for (int i = 1; i <= n; ++i){
                dp1[i] = dp1[i - 1] ^ nums[i];
            dp2[n - i + 1] = dp2[n - i + 2] ^ nums[n - i + 1];
            dp3[i]=dp2[n - i + 1];
            dic[dp1[i]].push_back(i);
            }

        for (int i = 1; i <= n; ++i)
        {

           // dp1[i] = dp1[i - 1] ^ nums[i];
            //dp2[n - i + 1] = dp2[n - i + 2] ^ nums[n - i + 1];
            if (dic.find(dp1[i]) != dic.end())
            {
                
                for (int w : dic[dp1[i]])
                    if (w + 1 < i)
                        find_ijk(w + 1, i);
                    else
                        break;
            }
            
        }

        cout << ans << "\n";
    }
    return 0;
}