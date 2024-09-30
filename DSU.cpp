class DSU
{
public:
    vector<int> parent;
    vector<int> size;

    DSU(int n)
    {
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int ultimateParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }

        parent[node] = ultimateParent(parent[node]);
        return parent[node];

        // return ultimateParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int parentU = ultimateParent(u);
        int parentV = ultimateParent(v);

        if (parentU == parentV)
        {
            return;
        }

        if (size[parentU] > size[parentV])
        {
            parent[parentV] = parentU;
            size[parentU] += size[parentV];
        }
        else
        {
            parent[parentU] = parentV;
            size[parentV] += size[parentU];
        }
    }
};