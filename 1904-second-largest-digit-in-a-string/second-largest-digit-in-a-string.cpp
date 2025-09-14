class Solution {
public:
    int secondHighest(string s) {
        int largest = -1;
        int secondLargest = -1;
        for(char c : s){
            if(isdigit(c)){
                int num = c - '0';
                if(num > largest){
                    secondLargest = largest;
                    largest = num;
                }
                else if(num < largest && num > secondLargest){
                    secondLargest = num;
                }

            }
        }
        return secondLargest;
        
    }
};