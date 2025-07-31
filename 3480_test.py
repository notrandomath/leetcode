from itertools import combinations
from collections import defaultdict

def subarrays(x: list):
    m = len(x)
    for j in range(1, m+1):
        for i in range(m-j+1):
            yield x[i:i+j]

N = 10
for i in range(2, N+1):
    nums = [val for val in range(1, i+1)]
    pairs = list(combinations(nums, 2))
    pairs_to_num = defaultdict(int)
    for pair in pairs:
        for subarray in subarrays(nums):
            if pair[0] in subarray and pair[1] in subarray:
                pairs_to_num[pair] += 1
    print(sorted(pairs_to_num.items(), key=lambda x: (-x[1], x[0][0]))[:min(5, len(pairs_to_num))])
    m = i // 2 
    most_freq = m*(m+1) if (i-1) % 2 == 0 else m*m
    print(most_freq)
    