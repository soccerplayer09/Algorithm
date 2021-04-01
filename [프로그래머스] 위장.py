def solution(clothes):
    from collections import defaultdict
    c_num = defaultdict(int)
    answer = 0
    sum = 1
    for i in clothes:
        c_num[i[1]] += 1
    if(len(c_num.items())>1):
        for i in c_num.items():
             sum *= (i[1]+1)
        sum -= 1
    else:
        sum = list(c_num.items())[0][1]
    answer += sum

    return answer