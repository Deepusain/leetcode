class Solution {
public:
    // Aapke bataye tarike se reverse aur bracket flip karne wala function
    string reverseAndFlip(string s, int start, int end) {
        string res = "";
        
        // Loop j = end se lekar start tak chalega (Peeche se aage)
        for (int j = end; j >= start; j--) {
            if (s[j] == ')') {
                res += '(';  // ')' ko '(' se replace kiya
            } else if (s[j] == '(') {
                res += ')';  // '(' ko ')' se replace kiya
            } else {
                res += s[j]; // Normal character ko vaise hi add kiya
            }
        }
        return res;
    }

    string reverseParentheses(string s) {
        // Hum loop chalaenge aur jab bhi innermost matching pair milega,
        // use aapke reverseAndFlip function se badal denge
        while (true) {
            int first_close = -1;
            int last_open = -1;

            // 1. Pehla milne wala ')' dhoondo
            for (int i = 0; i < s.length(); i++) {
                if (s[i] == ')') {
                    first_close = i;
                    break;
                }
            }

            // Agar koi ')' nahi bacha, matlab saare brackets solve ho gaye
            if (first_close == -1) break;

            // 2. Us ')' ke theek pehle wala sabse paas ka '(' dhoondo
            for (int i = first_close; i >= 0; i--) {
                if (s[i] == '(') {
                    last_open = i;
                    break;
                }
            }

            // 3. Innermost part ko aapke function se reverse aur flip karo
            // Hum brackets ko chhodkar andar ke maal (last_open + 1 se first_close - 1) ko bhejenge
            string reversed_part = reverseAndFlip(s, last_open + 1, first_close - 1);

            // 4. Purani string me is hisse ko replace kar do (brackets ke saath)
            s = s.substr(0, last_open) + reversed_part + s.substr(first_close + 1);
        }

        return s;
    }
};
