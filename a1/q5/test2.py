import sys

if __name__ == "__main__":
    flag = int(sys.argv[1])
    #print(flag)
    if (flag == 1):
        #print("in")
        n = sys.stdin.readline()
        #print(n[0])
        list_num = n.split()
        #print(list_num)
        ans = 0
        for i in list_num:
            ans += int(i)

        print(ans)

    else:

        print("nothing")
