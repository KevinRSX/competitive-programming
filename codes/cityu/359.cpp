#include <cstdio>

int mem[32];

int todec(int bin)
{
  if (bin < 10)
  {
    return bin;
  }
  return bin % 10 + (todec(bin / 10) << 1);
}

int tobin(int dec)
{
  if (dec < 2)
  {
    return dec;
  }
  return dec % 2 + tobin(dec / 2) * 10;
}

int main()
{
  while (~scanf("%d", &mem[0]))
  {
    int acc = 0, pc = 0;
    for (int i = 1; i <= 31; i++)
    {
      scanf("%d", &mem[i]);
    }
    while (1)
    {
      int ins = mem[pc] / 100000;
      int opend = mem[pc] % 100000;
      int dec_ins = todec(opend);
      pc = (pc + 1) & 31;
      if (ins == 111) break;  // hlt
      if (ins == 0) //sta
      {
        mem[dec_ins] = tobin(acc);
      }
      else if (ins == 1)  // lda
      {
        acc = todec(mem[dec_ins]);
      }
      else if (ins == 10) // beq
      {
        if (acc == 0)
        {
          pc = dec_ins;
          continue;
        }
      }
      else if (ins == 11); // nop
      else if (ins == 100) // dec
      {
        acc = (acc - 1) & 255;
      }
      else if (ins == 101)  // inc
      {
        acc = (acc + 1) & 255;
      }
      else if (ins == 110)  // jmp
      {
        pc = dec_ins;
        continue;
      }
    }
    printf("%08d\n", tobin(acc));
  }
}
