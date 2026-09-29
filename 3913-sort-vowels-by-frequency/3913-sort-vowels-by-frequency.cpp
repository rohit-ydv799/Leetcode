class Solution {
public:
    string sortVowels(string s) {

        vector<int> freq(5, 0);

        // 1. Count frequency of vowels
        for(int i = 0; i < s.size(); i++) {

            if(s[i] == 'a')
                freq[0]++;
            else if(s[i] == 'e')
                freq[1]++;
            else if(s[i] == 'i')
                freq[2]++;
            else if(s[i] == 'o')
                freq[3]++;
            else if(s[i] == 'u')
                freq[4]++;
        }

        // 2. Store first occurrence position
        vector<int> first(5, s.size());

        for(int i = 0; i < s.size(); i++) {

            int index = -1;

            if(s[i] == 'a') index = 0;
            else if(s[i] == 'e') index = 1;
            else if(s[i] == 'i') index = 2;
            else if(s[i] == 'o') index = 3;
            else if(s[i] == 'u') index = 4;

            if(index != -1 && first[index] == s.size()) {
                first[index] = i;
            }
        }

        // 3. Sort vowel types
        vector<int> order = {0, 1, 2, 3, 4};

        sort(order.begin(), order.end(), [&](int a, int b) {

            if(freq[a] != freq[b])
                return freq[a] > freq[b];

            return first[a] < first[b];
        });

        // 4. Put sorted vowels back
        int j = 0;

        for(int i = 0; i < s.size(); i++) {

            if(s[i] == 'a' || s[i] == 'e' ||
               s[i] == 'i' || s[i] == 'o' ||
               s[i] == 'u') {

                while(freq[order[j]] == 0) {
                    j++;
                }

                int v = order[j];

                s[i] = "aeiou"[v];

                freq[v]--;
            }
        }

        return s;
    }
};