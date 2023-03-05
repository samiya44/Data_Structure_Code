#include <bits/stdc++.h>
using namespace std;

const int N = 999;
vector <int> parent (N);

void makeset(int v) //nijer parent nije banano
{
    parent[v] = v;
}

int findset(int v) // parent khuje ber kora
{
    if(v==parent[v])
    {
        return v;
    }
    else
    {
        return findset(parent[v]);
    }
}
void unionset(int a, int b)   //jekono akta parent select kora
{
    int x = findset(a);
    int y = findset(b);

    if (x!= y)
    {
        parent[y] = x;
    }
}


int main()
{
    int cost = 0;
    bool flag = false;
    for(int i = 0; i<N ; i++)
    {
        makeset(i);
    }
    int n,m;
    cin>>n>>m; //scanf("%d %d " , &n , &m );

    vector<vector<int>>edges;

    int u,v,w;
    for (int i =0 ; i<m ; i++)
    {
        cin>>u>>v>>w;
        edges.push_back({w,u,v});
    }
    sort(edges.begin(),edges.end());
    for (auto i: edges)
    {
        w = i[0];
        u = i[1];
        v = i[2];

        int x = findset(u);
       int y = findset(v);

        if(x == y)
        {
            //flag = true;
            continue;
        }
        else
        {
            cost = cost + w;
             printf("\n%d to %d", u, v);
            unionset(u,v);
        }
    }



    cout<<"\n"<<cost;

}
