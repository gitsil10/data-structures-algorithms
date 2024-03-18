#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    static int dont_give_me_five(int start, int end) {
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