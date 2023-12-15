import math
def square_root(num):
   res = 0
   bit = 1 << 16

   while(bit > num):
      bit >>= 2

   #print(f"oikea bit:{bit}")

   bit = 1

   while(1):
      #print(f"looping bit: {bit}")
      variable = bit
      variable = variable + variable
      variable = variable + variable
      
      variable2 = num
      variable2 = variable2 - variable
      if(variable2 < 0): break
      
      bit = bit << 2

   #print(f"oma bit:{bit}")

   while (bit != 0):
      #print("################################")
      #print(f"r11:{res}, r12:{bit}, r13:{num}")
      print(f"res:{res}, bit:{bit}, num:{num}")
      if (num >= res + bit):
         num -= res + bit
         res = (res >> 1) + bit
      else:
         res >>= 1
      
      bit >>= 2

   return res

if __name__ == "__main__":
   for i in range(1,20):
      for j in range(1,20):
         assert((i >= j) == (not (i < j)))

   # num = square_root(81)
   #for i in range(2,3):
   i = 4
   num = square_root(i)
   #print("################")
   print(f"NUM: {i}, OMA: {num}, OIKEA: {math.sqrt(i)}")
   print("################")
