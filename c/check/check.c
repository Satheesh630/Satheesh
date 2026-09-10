#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int sherlockAndAnagrams(char* s) {
    int n = strlen(s);
    int count = 0;

    // Generate first substring
    for (int i = 0; i < n; i++) {

        int freq[26] = {0};

        // Extend the substring from i
        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;

            // Compare with every substring after j
            int freq2[26];

            for (int k = i + 1; k < n; k++) {
                for (int x = 0; x < 26; x++) {
                    freq2[x] = 0;
                }

                // Build frequency of substring s[k...k+(j-i)]
                int length = j - i + 1;

                if (k + length > n) {
                    break;
                }

                for (int x = k; x < k + length; x++) {
                    freq2[s[x] - 'a']++;
                }

                // Compare frequency arrays
                bool same = true;

                for (int x = 0; x < 26; x++) {
                    if (freq[x] != freq2[x]) {
                        same = false;
                        break;
                    }
                }

                if (same) {
                    count++;
                }
            }
        }
    }

    return count;
}
int main()
{
	printf("%d\n",sherlockAndAnagrams("abba"));
}
