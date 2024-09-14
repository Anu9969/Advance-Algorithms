#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KMP {
public:
    void lpsfind(vector<int>& lps, const string& s) {
        int pre = 0, suf = 1;
        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                suf++;
                pre++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }

    int strStr(const string& txt, const string& pattern) {
        if (pattern.empty()) return 0;  // Handle empty pattern case

        vector<int> lps(pattern.size(), 0);
        lpsfind(lps, pattern);

        int i = 0;  // index for txt
        int j = 0;  // index for pattern

        while (i < txt.size() && j < pattern.size()) {
            if (txt[i] == pattern[j]) {
                i++;
                j++;
            } else {
                if (j == 0) {
                    i++;
                } else {
                    j = lps[j - 1];
                }
            }
        }

        // Pattern found
        if (j == pattern.size()) {
            return i - j;
        } else {
            // Pattern not found
            return -1;
        }
    }
};

int main() {
    string txt, pattern;
    KMP kmp;  // Create the KMP object

    cout << "Enter the text: ";
    cin >> txt;

    cout << "Enter the pattern: ";
    cin >> pattern;

    int result = kmp.strStr(txt, pattern);

    if (result != -1) {
        cout << "Pattern found at index: " << result << "\n";
    } else {
        cout << "Pattern not found\n";
    }

    return 0;
}