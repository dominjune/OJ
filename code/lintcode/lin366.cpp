// lintcode 366.Fibonacci
// Easy 
#include <cstdio>
#include <cstring>

using namespace std;

class Solution{
public:
    /**
     * @param n: an integer
     * @return an integer f(n)
     */
    int fibonacci(int n) {
        // write your code here
        // 感觉这样做n太大不行啊... 
        /*int *f = new int[n+1];
        memset(f, 0, sizeof(f));
        f[0] = f[1] = 0;
        f[2] = 1;
        for(int i=3; i<=n; i++)
        	f[i] = f[i-1] + f[i-2];
        return f[n];
        delete [] f;*/
        if(n == 2)	return 1;
        int a = 0;
        int b = 1;
        int c = 0;
        for(int i=3; i<=n; i++)
        {
        	c = a + b;
        	a = b;
        	b = c;
        }
        return c;
    }
};


int main()
{
	Solution sol;
	int n;
	while(scanf("%d", &n) != EOF)
		printf("%d\n", sol.fibonacci(n));
	return 0;
}
