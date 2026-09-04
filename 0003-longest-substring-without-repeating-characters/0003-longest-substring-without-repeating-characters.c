int lengthOfLongestSubstring(char* s) {
    int lastIndex[256];

    // Initialize all values to -1
    for (int i = 0; i < 256; i++) {
        lastIndex[i] = -1;
    }

    int start = 0;
    int maxLen = 0;

    for (int i = 0; s[i] != '\0'; i++) {

        // If character already exists in current window
        if (lastIndex[(unsigned char)s[i]] >= start) {
            start = lastIndex[(unsigned char)s[i]] + 1;
        }

        // Update last seen index
        lastIndex[(unsigned char)s[i]] = i;

        int currentLen = i - start + 1;

        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }

    return maxLen;
}