def dfs(i, v, visited,ordering,graph):
    visited[v] = True

    for k in graph[v]:
        if not visited[k]:
            i = dfs(i,k,visited,ordering,graph)

    ordering[i] = v
    return i-1

def topsort(N,Edges):
    visited = [False]*N
    ordering = [0]*N
    adj = [None]*N
    for i in range(N):
        adj[i] = []
    for e in Edges:
        adj[ e[0] ].append( e[1] )
    i = N-1 #Lets start from the end

    for v in range(N):
        if not visited[v]:
            i = dfs(i, v, visited, ordering,adj)
    return ordering

if __name__ == '__main__':
    n = int(input().strip())
    e = int(input().strip())
    edges = []
    for i in range(e):
        edges.append(
            [ int(x) for x in input().split() ]
        )
    print( topsort(n, edges) )