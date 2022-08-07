import sys
input = sys.stdin.readline

# is_reported[신고한 사람][신고당한 사람] 이용해서 중복체크
def solution(id_list, report, k):
    n = len(id_list)
    index = {id_list[i] : i for i in range(n)}
    is_reported = [[False] * n for _ in range(0, n)]
    cnt = [0] * n
    answer = [0] * n
    
    for elem in report:
        a, b = elem.split(" ")
        if not is_reported[index[a]][index[b]]:
            is_reported[index[a]][index[b]] = True
            cnt[index[b]] += 1
    
    for i in range(0, n):
        if cnt[i] >= k:
            for j in range(0, n):
                if is_reported[j][i]:
                    answer[j] += 1
    
    return answer
