def lps(S):
    n,plps,i = len(S),0,0
    lpslist = [0]*n #LPS Vector 
    while i < n:
        if S[i] == S[plps]:
            plps+=1
            lpslist[i] = plps
            i+=1
        else:
            if plps!=0:
                plps = lpslist[plps-1]
            else:
                lpslist[i] = 0
                i+=1
        i+=1
    return lpslist

def kmpSearch(pattern, txt):
    m = len(pattern)
    n = len(txt)

    result = []
    lpslist = lps(pattern)

    i,j = 0,0

    while(i<n):
        if pattern[j] == txt[i]:
            j+=1
            i+=1
        if j == m:
            result.append(i-j)
            j = lpslist[j-1]
        elif i < n and pattern[j] != txt[i]:
            if j != 0:
                j = lpslist[j-1]
            else:
                i+=1
    return result

            


if __name__ == '__main__':
    txt = 'txtetxtercrmjkcewrurcrmjkcewrunhjtxtskcremtxtjilctxtercrmjkcewruefsatxtercrmjkcewruxkwtxtefbgftxtxtercrmjkcewrutercrmjkcewrtxtercrmjkcewruuctxtercrtxtercrmjkcewrumjkcewrujtxtxyiarxecvfbumntxtukhmitxtnbhfcfxdefdxwdxtxtctvhnhbnhknbjgvftgnfbngmujbgvfttxtercrmjkcewru'
    pattern = 'txtercrmjkcewru'
    print( kmpSearch(pattern, txt) )