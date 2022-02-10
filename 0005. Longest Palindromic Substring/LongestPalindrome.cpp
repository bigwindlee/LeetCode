#include "LongestPalindrome.h"
#include <vector>

using namespace std;

bool isPalindrome(const string& s)
{
    int len = s.length();
    for (int i = 0; i < len - 1 - i; i++) {
        // һͷһβ2��ָ��ͬʱ���м��ƶ�
        if (s[i] != s[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

/* ������⣺
 * 1) ����index i������������ַ���ʼ�������Ӵ����ӳ����̣�������Ӵ�Ϊ���ģ����ҵ��� index i ��ʼ����Ӵ���    
 * ʱ�临�Ӷȣ�
 * 1�������ַ����Ӵ���Ƕ��һ��ѭ����O(n^2)���ж��Ƿ�Ϊ���ģ��ٴ�Ƕ��һ��ѭ����O(n^3)��
 * ȱ�㣺
 * ʱ�临�Ӷ�̫�ߣ����ڳ��ַ����ᳬʱ��
 */
string LongestPalindrome::longestPalindrome_1(string s)
{
    if (s.length() < 2)
        return s;

    int longest = 0;
    int len = s.length();
    string palindrome;

    for (int i = 0; i < len; i++) {
        if (len - i < longest) {
            break;
        }
        for (int j = len - i; j > 0; j--) {
            if (j < longest) {
                continue;
            }
            string sub = s.substr(i, j);
            if (sub.length() <= longest) {
                continue;
            }
            if (isPalindrome(sub)) {
                longest = sub.length();
                palindrome = sub;
                continue;
            }
        }
    }
    return palindrome;
}

/*
* ��̬�滮
* һ�����ĵ���һ����ʲô״̬����һ��Ҳ�ǻ��ģ�dp[i + 1][j - 1]Ϊtrue����Ȼ������β���˷ֱ�����һ����ͬ���ַ���s[i] == s[j]����
* �� dp[i][j] ��ʾ���±� i ���±� j ���Ӵ��Ƿ��ǻ��ģ�����Ϊ true ������Ϊ false ��
* ���ĵĳ�ʼ״̬���߽���������ʲô����2����򵥵Ļ��ģ�1���������ַ�������"a"��"aba"��2��ż�����ַ������磺"abba"
* ��˴ӵ����ַ�����2����ͬ���ַ���ʼ�������䡣
*/
string LongestPalindrome::longestPalindrome_2(string s)
{
    int len = s.length();
    vector<vector<bool>> dp(len, vector<bool>(len, false)); // �� dp[i][j] ��ʾ���±� i ���±� j ���Ӵ��Ƿ��ǻ���
    int start = 0; // ���Ŀ�ʼ��index
    int longest = 1; // ���ĵĳ���

    // �����ַ�����2����ͬ���ַ���Ϊ���ĵı߽�����
    for (int i = 0; i < len; i++) {
        dp[i][i] = true;
    }
    for (int i = 0; i < len - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            start = i;
            longest = 2;
        }
    }

    // ���Ӵ����� n ��Ϊ���ѭ������������ô���������ƹ�ϵ�� n ��ȻҲ������ n
    for (int n = 3; n <= len; n++) { // �Ӵ����ȵı仯��Χ��[3, len]
        for (int i = 0; i <= len - n; i++) { // �����±�ı仯��Χ��[0, len-n]
            int j = i + n - 1; // ����Ϊn���Ӵ�����ĩindexΪ��i, j

            // ���ƹ�ϵ��״̬ת�Ʒ��̣�
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                start = i;
                longest = n;
            }
        }
    }

    return s.substr(start, longest);
}