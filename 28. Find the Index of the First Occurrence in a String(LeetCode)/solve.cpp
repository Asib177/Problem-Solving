class Solution {
public:
    int strStr(string haystack, string needle) {

        if(needle.size() > haystack.size()) return -1;

        for(int i=0; i<haystack.size(); i++){
            int j, k = i;
            for(j=0; j<needle.size() && k<haystack.size(); j++, k++){
                if(haystack[k] != needle[j]) break;
            }
            if(j == needle.size()) return i;
        }
        return -1;
    }
};