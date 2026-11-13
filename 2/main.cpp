#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s1, s2;
    cout << "Enter first string: ";
    getline(cin, s1);
    cout << "Enter second string: ";
    getline(cin, s2);

    int n = (int)s1.size();
    int m = (int)s2.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    int maxLength = 0;
    int endIndex = 0;

    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <=m; j++)
        {
            if(s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
                if(dp[i][j] > maxLength)
                {
                    maxLength = dp[i][j];
                    endIndex = i;
                }
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    string lcs;
    if (maxLength > 0) {
        lcs = s1.substr(endIndex - maxLength, maxLength);
    }

    // 5. 输出结果
    cout << "最长公共子串的长度是" << maxLength
         << "，最长公共子串字符为：" << lcs << endl;

    return 0;
}