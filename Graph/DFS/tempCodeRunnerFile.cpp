    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[j][i] && map[j][i])
            {
                dfs(ii(j, i));
                components++;
            }
        }
    }
    cout << components << '\n';