#1과 로직 동일 - 파이썬으로 언어만 포팅
str = input()
type = ""
i = 0

while str[i] != ' ':
    type += str[i]
    i += 1
i += 1  #' ' skip
    
while i < len(str):
    name = ""
    while str[i].isalpha():
        name += str[i]
        i += 1

    opt = ""
    while str[i] != ',' and str[i] != ';':
        opt += str[i]
        i += 1
    i += 2  #", " skip

    print(type, end='')
    if len(opt) > 0:
        j = len(opt) - 1
        while j >= 0:
            if opt[j] == ']':
                print("[]", end='')
                j -= 2
            else:
                print(opt[j], end='')
                j -= 1
    print(" " + name + ";")
