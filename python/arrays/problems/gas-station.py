def tour(self,lis, n):
    #Code here
    begin = 0
    end = 0
    petrul = 0
    while begin < n:
        petrul += lis[end%n][0] - lis[end%n][1]
        if petrul <= 0:
            begin = end+1,end+1
            petrul = 0
            continue
        if end-begin == n:
            return n
        end += 1
    return -1

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n = int(input())
        arr = [ int(x) for x in input().split().tolist() ]