

def prims_mst(
    n, #Number of vertices
    edges, #Edges
):
    adj = [[INF]*n]*n
    for e in edges:
        adj[e[0]][e[1]] = e[2]
        adj[e[1]][e[0]] = e[2]
    #Initializing keys and mst set
    keys = [INF]*n
    keys[0] = 0
    mstSet =  []
    while len(mstSet) < n:
        #Pick a vertex not in mstSet having minimum key
        mv = INF
        mi = 0
        for i in range(v):
            if keys[i] < mv and i not in mstSet:
                mv = keys[i]
                mi = i
        #minimum index is decided mi
        for i in range(n):
            #Adjacent elements 
            if adj[mi][i] != INF and adj[mi][i] < keys[i]:
                keys[i] = adj[mi][i]
        
if __name__ == '__main__':
    pass