import math

num = int(input())

l = 0
r = 1000000
ans = -1
while l<=r:
    mid = (l+r)//2
    if pow(6, mid) >= num:
        ans = mid
        r = mid-1
    else:
        l = mid+1
print(ans)

