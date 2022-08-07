import sys
input = sys.stdin.readline

# math.sqrt 대신 i * i <= n 으로 경계 판단
def is_prime(n):
    if n == 1:
        return False
    else:
        i = 2
        while i * i <= n:
            if not n % i:
                return False
            i += 1
        return True

def solution(n, k):
    answer = 0
    s = ""
    
    while n:
        s += str(n % k)
        n = int(n / k)
    s = s[::-1]
    
    for num in s.split('0'):
        if not num:
            continue
        if is_prime(int(num)):
            answer += 1
        
    return answer
