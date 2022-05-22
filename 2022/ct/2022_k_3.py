import math
import sys
input = sys.stdin.readline

def solution(fees, records):
    answer = []
    incars = {} # {num : time}
    outcars = {} # {num : time}
    
    for i in records:
        time, num, status = i.split(' ')
        num = int(num)
        if status == "IN":
            incars[num] = int(time.split(':')[0]) * 60 + int(time.split(':')[1])
        else:
            outtime = int(time.split(':')[0]) * 60 + int(time.split(':')[1])
            #이전 주차내역 확인
            if num in outcars:
                outcars[num] += outtime - incars[num]
            else:
                outcars[num] = outtime - incars[num]
            del incars[num]
    
    #출차되지 않은 차 처리
    for num, intime in incars.items():
        time = 23 * 60 + 59 - intime
        if num in outcars:
            outcars[num] += time
        else:
            outcars[num] = time
    
    #주차요금 계산
    nums = list(outcars.keys())
    list.sort(nums)
    for num in nums:
        cost = fees[1]
        if outcars[num] > fees[0]:
            cost += math.ceil((outcars[num] - fees[0]) / fees[2]) * fees[3]
        answer.append(cost)
    
    return answer
