# Math

## Getting prime numbers

```c++
void getprime(int n)
{
    bool flag[N];
    memset(flag, true, sizeof(flag));
    int cnt = 0;	// total number found prime now
    for (int i = 2; i <= n; i++)
    {
        if (flag[i])
            prime[++cnt] = i;	// if a number is not filtered, it is prime
        for (int j = 1; j <= cnt && i * prime[j] <= n; j++)
        {
            flag[i * prime[j]] = false;
            if (i % prime[j] == 0) break;
        }
    }
}
```



## Euler's Totient Function

$$
\phi(n)=n\underset{p|n}{\Pi}(1-1/p)
$$

