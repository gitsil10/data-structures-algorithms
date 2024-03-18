#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static int dont_give_me_five(int start, int end) {
        /*
        @brief Count the number of integers between start and end that do not contain the digit 5
        @param start: The start of the range
        @param end: The end of the range
        @return The number of integers between start and end that do not contain the digit 5

        @note
        time: O(n)
        space: O(1)

        @details
        1. Iterate through the range from start to end
        2. Convert the integer to a string and check if it contains the digit 5
        3. If it does not contain the digit 5, increment the count
        4. Return the count
        */
        int count = 0;
        for (int i = start; i <= end; i++) {
            if (to_string(i).find('5') == string::npos) {
                count++;
            }
        }
        return count;
    }
};

int main(int argc, char **argv) {
    if (argc != 3) {
        cout << "Usage: ./dont_give_me_five <start> <end>" << endl;
        return 1;
    }
    int start = strtol(argv[1], NULL, 10), 
        end = strtol(argv[2], NULL, 10);
    
    if (end < start) {
        int temp = start;
        start = end;
        end = temp;
    }

    cout << Solution::dont_give_me_five(start, end) << endl;

    return 0;
}