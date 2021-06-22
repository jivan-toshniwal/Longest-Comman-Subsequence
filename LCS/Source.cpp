#include <iostream>
#include <vector>
using namespace std;

string lcs(const string& x, const string& y)
{
    vector<vector<string>> lcf(y.length() + 1, vector<string>(x.length() + 1, ""));
    for (int i = 1; i <= y.size(); i++)
        for (int j = 1; j <= x.size(); j++) {
            if (y[i - 1] == x[j - 1]) {
                lcf[i][j] = lcf[i - 1][j - 1] + y[i - 1];
            }
            else if (lcf[i - 1][j].length() > lcf[i][j - 1].length()) {
                lcf[i][j] = lcf[i - 1][j];
            }
            else {
                lcf[i][j] = lcf[i][j - 1];
            }
        }
    return lcf[y.length()][x.length()];
}
int main()
{
    cout << lcs("abcdef", "acf");
    return 0;
}
