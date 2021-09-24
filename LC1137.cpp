//Recursive solution 
//TC = O(3^n)
//SC = O(n)
class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        return tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};

//Recusrion with memorization
//TC = O(n)
//SC = O(n)
class Solution {
public:
    int memo[38];
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n<=2) return 1;
        if(memo[n]!=0) return memo[n];
        return memo[n] = tribonacci(n-1)+tribonacci(n-2)+tribonacci(n-3);
    }
};

//Iterative Solution
//TC = O(n)
//SC = O(n)
class Solution {
public:
    int memo[38];
    int tribonacci(int n) {
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        for(int i=3;i<=n;i++)
        {
            memo[i] = memo[i-1]+memo[i-2]+memo[i-3];
        }
        return memo[n];
    }
};

//Constant space solution
class Solution {
public:
    int tribonacci(int n) {
        int a = 0,b=1,c=1;
        if(n==0) return a;
        if(n==1 || n==2) return b;
        for(int i=3;i<=n;i++)
        {
            int d = a+b+c;
            a = b;
            b = c;
            c = d;
        }
        return c;
    }
};

