#include<bits/stdc++.h>
using namespace std;
int mat[300][300];
string s;
int idx=0;

string rep(pair<int,int> R,pair<int,int> C)
{
    int ch = -1;
    for(int i=R.first;i<R.second;i++)
    {
        for(int j=C.first;j<C.second;j++)
        {
            if(i==R.first && j==C.first)
                ch=mat[i][j];

            else if(mat[i][j]!=ch)
            {
                int mid_row = (R.first + R.second+1)/2;
                int mid_col = (C.first + C.second+1)/2;

                string s1 = rep({R.first,mid_row},{C.first,mid_col});
                string s2 = rep({R.first,mid_row},{mid_col,C.second});
                string s3 = rep({mid_row,R.second},{C.first,mid_col});
                string s4 = rep({mid_row,R.second},{mid_col,C.second});
                return "D"+s1+s2+s3+s4;
            }
        }
    }
    // it the range does not cover any cell than ch == -1
    return ch!=-1?to_string(ch):"";
}
void bin(pair<int,int> R,pair<int,int> C){
    if(R.first == R.second || C.first==C.second)
        return;

    // Get 1 char from cin.
    char ch = s[idx++];
    if(ch == '0' || ch =='1')
    {

        for(int i=R.first;i<R.second;i++)
            for(int j=C.first;j<C.second;j++)
                mat[i][j]=ch-'0';
        return;
    }
    else{

        int mid_row = (R.first + R.second+1)/2;
        int mid_col = (C.first + C.second+1)/2;

        bin({R.first,mid_row},{C.first,mid_col});
        bin({R.first,mid_row},{mid_col,C.second});
        bin({mid_row,R.second},{C.first,mid_col});
        bin({mid_row,R.second},{mid_col,C.second});
    }


}
int main()
{
    char ch;
    while (cin >> ch && ch != '#')
    {

        int r, c;
        cin >> r >> c;

        memset(mat, 0, sizeof mat);
        printf("%c%4d%4d\n", ch == 'B' ? 'D' : 'B', r, c);

        if(ch=='B')
        {
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                {
                    char c;cin>>c;
                    mat[i][j]=c-'0';
                }


            string ans =  rep({0,r},{0,c});
            for(int i=0;i<ans.length();i++)
            {
                if(i>0 && i%50 ==0)
                    cout<<endl;
                cout<<ans[i];
            }
        }
        else if(ch=='D')
        {
            cin>>s;
            idx=0;
            bin({0,r},{0,c});


            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                {
                    // "Each line will contain 50 characters."
                    if (i + j > 0 && (i * c + j) % 50 == 0)
                        cout << endl;
                    cout<<mat[i][j];
                }
        }
        cout<<endl;
    }
    return 0;
}
