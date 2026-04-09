class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int result = 10; // Covers 0-digit (1) and 1-digit (9) numbers
        int uniqueDigits = 9; // Current k-digit unique count
        int availableDigits = 9; // Remaining choices for next position

        for (int i = 2; i <= n && availableDigits > 0; i++) {
            uniqueDigits *= availableDigits;
            result += uniqueDigits;
            availableDigits--;
        }
        return result;
    }
};