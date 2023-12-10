res = 0
bit = 1 << 16
num = 2345

print(f"bit:{bit}")
while(bit > num):
    bit >>= 2

print(f"oikea:{bit}")

bit = 1

while(bit<<2 <= num):
    bit = bit << 2

print(f"oma:{bit}")

while (bit != 0):
   if (num >= res + bit):
      num -= res + bit
      res = (res >> 1) + bit
   else:
      res >>= 1
   
   bit >>= 2

print(f"vastaus:{res}")
