#!/usr/bin/env python
# Lists and dictionaries are mutable
# List (multiple supported types)
# Arrays are lists, but contain data of the same type (no mixing!)
nums=[13, 15.398, "apple", 'banana', 'kiwi', 'apple', 'banana']
print(nums)
print(nums[3])
nums[3]="dragonfruit"
print(nums)
print(nums[3])

for num in nums:
  print(num)
for i in range(len(nums)):
  print(nums[i])

# Dictionary (associative array/list or map)
dict={1: "rocks", 2: "pebbles"}

# Tuples and sets are immutable
# Tuple
toople=(1, 2, 2)
print(toople)
print(toople[1])
#toople[1]=5 # Won't work -- immutable!

# Sets (demonstrate unique data)
set = {1, 2, 2, 7, 2, 1, 7} # only one instance of each number will appear
print(set)
