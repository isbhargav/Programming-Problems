import re

n = int(input())
for i in range(n):
    s = str(input())
    ns = re.split(r"\+|\d+",)

    min_val = eval(s) # * has priority 
    for ch  in ns:
        if ch in ["*","+"]:
            catt
    max_val = eval(ns)
    print(f"The maximum and minimum are {max_val} and {min_val}.")

