import sys
input = sys.stdin.readline

# set(report)로 중복 제거
# 신고받은 사람 별 신고횟수만 저장하고 신고한 사람은 report에서 id_list.index() 이용해서 탐색
def solution(id_list, report, k):
    answer = [0] * len(id_list)
    reported = {x : 0 for x in id_list}
    
    for i in set(report):
        reported[i.split(" ")[1]] += 1

    for i in set(report):
        a, b = i.split(" ")
        if reported[b] >= k:
            answer[id_list.index(a)] += 1
    
    return answer
