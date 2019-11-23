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



## Factorial

```c++
LL fac(int k) {
  LL sum = 1;
  for(int i = 2; i <= k; ++i)
    sum *= i;
  return sum;
}

int ncr(int n, int r) {
  if(r == 0 || n == r) return 1;
  r = min(r, n-r);

  LL nf = fac(n);
  LL rf = fac(r);
  LL nrf = fac(n - r);
  return nf/(rf * nrf);
}
// LL is long long
```

