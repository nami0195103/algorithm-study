r = 0
ans = [-1]
ryan = [0] * 11
appeach = []
cur_diff = 1    #비기는 경우(0) 갱신하지 않기 위해 최소값 1로 설정

#라이언 - 어피치 점수 차 return
def calc():
    global appeach, ryan

    num_ap = 0
    num_li = 0
    for i in range(0, 11):
        if appeach[i] == 0 and ryan[i] == 0:
            continue
        if appeach[i] >= ryan[i]:
            num_ap += 10 - i
        else:
            num_li += 10 - i
    return num_li - num_ap

#cnt : 현재까지 쏜 화살 개수, pos : 현재 보고있는 ryan idx
def dfs(cnt, pos):
    global r, cur_diff, ans, ryan

    if cnt == r:    #화살을 다 쏜 경우
        retval = calc()
        if retval > cur_diff:
            ans = ryan.copy()
            cur_diff = retval
        elif retval == cur_diff:    #더 오른쪽 idx 값이 큰 경우(더 낮은 점수를 많이 맞춘 경우)만 복사
            for i in range(10, 0, -1):
                if ans[i] == 0 and ryan[i] == 0:
                    continue
                else:
                    if ryan[i] > ans[i]:
                        ans = ryan.copy()
                    break
        return
    
    if pos == 10:   #0점에 화살을 쏘는 경우
        ryan[pos] = r - cnt
        dfs(r, pos + 1)
        ryan[pos] = 0
        return
    
    if cnt + appeach[pos] + 1 <= r: #쏜 화살의 총 개수가 r을 넘지 않는 경우만 더함
        ryan[pos] = appeach[pos] + 1
        dfs(cnt + ryan[pos], pos + 1)
    ryan[pos] = 0
    dfs(cnt, pos + 1)

def solution(num, info):
    global r, appeach, ans
    r = num
    appeach = info

    dfs(0, 0)
    return ans
