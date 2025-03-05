import sys

slist=list(input().split())  
tlist=list(input().split())  
# print(slist)
class Bit:
    def __init__(self, n):
        self.size = n
        self.tree = [0] * (n + 1)
  
    def sum(self, i):
        s = 0
        while i > 0:
            s += self.tree[i]
            i -= i & -i
        return s
  
    def add(self, i, x):
        while i <= self.size:
            self.tree[i] += x
            i += i & -i
# 出てくる最大の数
bita = Bit(100)
bitb = Bit(100)
tentoua=0
tentoub=0

for i, p in enumerate(slist):
    q=ord(p)-ord('A')
    bita.add(q, 1)
    tentoua += i + 1 - bita.sum(q)
for i, p in enumerate(tlist):
    q=ord(p)-ord('A')
    bitb.add(q, 1)
    tentoub += i + 1 - bitb.sum(q) 

if(tentoua%2==tentoub%2):
    print("Yes")
else:
    print("No")
