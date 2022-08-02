#https://codeforces.com/problemset/problem/375/D

# C[N] is color
# N vertices 1 to N
# M queries V[M] and K[M]
# number of colors, such that v contains atleast k number of such colors

class Solution:
    def solve(
        n: int,#number of vertices
        m: int,#number of queries
        c: list[int], #colors
        adj: list[list[int]], #adjacency list
        q: list[list[int]] #queries
    ) -> list[int]:

        visited = [False]*n #Create a visited array

        #ITERATIVE DFS BUT A BIT MODIFIED
        
        stack = [0] #Start at root node

        colorCount = [{}]*n

        while stack != []:
            top = stack.pop(-1) #Recent element

            if not visited[top]:
                #Not visited logic goes here
                pass

            for e in adj[top]:
                if not visited[e]:
                    stack.append[e]
                else:
                    #Visited logic goes here
                    pass
        
if __name__ == '__main__':
    [n,m] = [int(x) for x in input().split()]

    adj = [None]*n
    
    queries = []
    
    for i in range(n):
        adj[i] = []
    
    color = [int(x) for x in input().split()]
    
    for i in range(n-1):
        [l,r] = [int(x)-1 for x in input().split()]
        adj[l].append(r)
        adj[r].append(l)
    
    for i in range(m):
        [v,k] = [int(x) for x in input().split()]
        queries.append( [ v-1,k ] )
    
    res = Solution.solve(n, m, color, adj, queries)

    for e in res:
        print(e)