class Solution:
    def findJudge(self, n: int, trust: list[list[int]]) -> int:
        adjList = [None]*n
        for pair in trust:
            l,r = pair[0],pair[1]
            if adjList[l] is None:
                adjList[l] = []
            if adjList[r] is None:
                adjList[r] = []
            adjList[ l ].append( r )
            adjList[ r ].append( l )
        return -1





if __name__=='__main__':
    n = 2
    trust=[[1,2]]
    print(
        Solution.findJudge( Solution, n, trust)
    )