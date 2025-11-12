import math

nums = set()
for a in range(2, 101):
    for b in range(2, 101):
        nums.add(math.pow(a, b))

print(len(nums))
