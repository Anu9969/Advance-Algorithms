#include <iostream>
#include <vector> // Include the vector header
using namespace std;

class KMP {
public:
    int lps(string s) {
        
        vector<int> lps(s.size(), 0);
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
        return lps[s.size() - 1]; // Return the longest prefix-suffix length
    }
};

int main() {
    int s;
    cin >> s;

    KMP kmp;  // Create the object only once
    while (s--) {
        string str;
        cin >> str;
        cout << kmp.lps(str) << "\n";  // Directly output the result
    }

    return 0;
}
