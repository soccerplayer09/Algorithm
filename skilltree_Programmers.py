def solution(skill, skill_trees):
    answer = 0

    for i in skill_trees:
        list = []
        flag = True

        for j in i:
            if j in skill:
                list.append(j)

        for k in range(len(list)):
            if (list[k] != skill[k]):
                flag = False
                break

        if (flag == True):
            answer += 1

    return answer

