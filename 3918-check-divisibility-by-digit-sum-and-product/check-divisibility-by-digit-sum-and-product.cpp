class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int original = n;

        while(n != 0){

           int temp = n % 10;
           sum += temp;
           product = product * temp;
           n = n/10;
 
        }

        int total_sum = sum + product;

        return (total_sum != 0) && (original % total_sum == 0);
       


   
        
    }
};