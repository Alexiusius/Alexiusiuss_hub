import time
vvod = "t tt tttqt. tttt qqqtt .tqtqtttqtqq q ttqq qqqqqq t ttt .qttttq t ttqttt. q qqq qqqtqqttt"
spisok2 = vvod.split()
spisok2 = ''.join(spisok2)
spisok3 = []
spisok4 = ""

i = 0
j = 0
k = 0

for i in spisok2:
    if i == '.':
        j += 1
        if j % 2 == 0:
            i = ','
    if i == 'q':
        k += 1
        if k % 2 == 0:
            i = 'w'
    spisok3.append(i)
    spisok4 = spisok4 + i
print(spisok3)
print(spisok4)
print(time.process_time())