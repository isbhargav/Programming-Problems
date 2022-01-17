#include <bits/stdc++.h>
using namespace std;

// 2 2 2 2
int nums[100005];
long long int ans = 0;
unordered_map<int,pair<long long int,pair<int,int>> > dic;

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
        dic.clear();
        dic[0]={0,{0,0}};

    int cor=0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> nums[i];
            cor = cor^ nums[i];
            if (dic.find(cor) != dic.end())
            {
                int w = dic[cor].second.first;
                    if (w + 1 < i)
                        {
                            int s=(i-(w + 1));

                            long long int ans_t=( dic[cor].first + dic[cor].second.second * (s+1));
                            ans_t+=s;
                            dic[cor]={ans_t,{i,dic[cor].second.second+1}};
                            ans+=ans_t;
                        
                        }      
                    
            }
            else
            dic[cor]={0,{i,0}};

            
            
        }

        cout << ans << "\n";
    }
    return 0;
}