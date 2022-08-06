// #include <string>
// #include <vector>
// #include <iostream>
// #include <algorithm>
// using namespace std;

// // string solution(vector<int> numbers)
// // {
// //     string answer = "";
// //     vector<vector<int>> adj;

// //     for (int i = 0; i < numbers.size(); i++)
// //     {
// //         vector<int> tmp;
// //         vector<int>::iterator it = numbers.begin();
// //         int curr = *(it + i);
// //         tmp = numbers;
// //         tmp.erase(it + i);
// //         for (int j = 0; j < numbers.size() - 1; j++)
// //         {
// //             adj[curr].push_back(tmp[j]);
// //         }
// //     }
// //     cout << adj[0][0];
// //     return answer;
// // }

// int main()
// {
//     vector<int> numbers = {6, 10, 2};
//     vector<vector<int>> adj;
//     // adj.resize(100000);
//     for (int i = 0; i < numbers.size(); i++)
//     {
//         vector<int> tmp;
//         vector<int>::iterator it = numbers.begin();
//         int curr = *(it + i);
//         tmp = numbers;
//         tmp.erase(it + i);
//         for (int j = 0; j < numbers.size() - 1; j++)
//         {
//             adj[curr].push_back(tmp[j]);
//         }
//     }
//     cout << adj[0][0];
//     return 0;
// }

//         vec[vec.begin()+i].push_back
//         vector<int> tmp =numbers;
//         vector<int>::iterator it = tmp.begin();
//         int curr = *(it+i);
//         tmp.erase(it+i);
//         string str="";
//         str+=to_string(curr);
//         for(int j=0;j<numbers.size()-1; j++){
//             //str+=to_string(*(it+j));
//             vector<int> tmptmp = tmp;
//             vector<int>::iterator tmpit= tmptmp.begin();
//             str+=to_string(tmptmp.front());

//         }
//         cout<<str<<' ';
//         strvec.push_back(str);
//     }

//     vector<int> res;
//     for(int i=0;i<strvec.size();i++){
//         res.push_back(stoi(strvec[i]));
//     }
//     cout<<res.size()<<'\n';
//     sort(res.begin(),res.end(),greater<int>());

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<int> numbers;
    numbers.push_back(6);
    numbers.push_back(10);
    numbers.push_back(2);
    vector<string> strvec;
    vector<int> vec[100000];

    for (int i = 0; i < numbers.size(); i++)
    {
        vector<int> tmp = numbers;
        tmp.erase(tmp.begin() + i);
        for (int j = 0; j < tmp.size(); j++)
        {
            vec[numbers[i]].push_back(tmp[j]);
        }
    }
    for (int v : vec[10])
    {
        cout << v << ' ';
    }
    return 0;
}