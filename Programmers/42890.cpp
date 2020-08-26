def solution(relation):
    answer = list()
    for i in range(1, 1 << len(relation[0])): # 조합 생성
        tmp_set = set()
        for j in range(len(relation)):
            tmp = ''
            for k in range(len(relation[0])):
                if i & (1 << k):
                    tmp += str(relation[j][k])
            tmp_set.add(tmp)
            
        if len(tmp_set) == len(relation):
            able = True
            for num in answer:
                if (num & i) == num:
                    able = False
                    break
            if able:
                answer.append(i)
    return len(answer) 
