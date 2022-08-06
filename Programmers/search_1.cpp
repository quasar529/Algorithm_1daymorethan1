#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers)
{
    int no1 = 0, no2 = 0, no3 = 0;
    for (int i = 0; i < answer.size(); i += 5)
    {
        for (int j = 1; j <= 5; j++)
        {
            if (i + j >= answer.size())
                break;
            if (j == answer[i + j])
            {
                no1++;
            }
        }
    }
    for (int i = 0; i < answer.size(); i += 2)
    {
        if (answer[i] == 2)
        {
            no2++;
        }
    }
    for (int i = 1; i < answer.size(); i += 8)
    {
        if (i >= answer.size() || i + 2 >= answer.size() || i + 4 >= answer.size() || i + 6 >= answer.size())
            break;
        if (answer[i] == 1)
            no2++;
        if (answer[i + 2] == 3)
            no2++;
        if (answer[i + 4] == 4)
            no2++;
        if (answer[i + 6] == 5)
            no2++;
    }
    for (int i = 0; i < answer.size(); i += 10)
    {
        if (answer[i + 2] == 1 || answer[i + 3] == 1 || answer[i + 4] == 2 || answer[i + 5] == 2 || answer[i] == 3 || answer[i + 1] == 3 || answer[i + 6] == 4 || answer[i + 7] == 4 || answer[i + 6] == 4 || answer[i + 9] == 4 || answer[i + 10] == 5)
            no3++;
    }
    vector<int> temp;
    temp.push_back(no1);
    temp.push_back(no2);
    temp.push_back(no3);

    int whichismax = *max_element(temp.begin(), temp.end());
    if (whichismax == no1)
        answer.push_back(1);
    if (whichismax == no2)
        answer.push_back(2);
    if (whichismax == no3)
        answer.push_back(3);
    sort(answer.begin(), answer.end());
    return answer;
}
int main()
{
    vector<int> answers;
    answers.push_back(1);
    answers.push_back(2);
    answers.push_back(3);
    answers.push_back(4);
    answers.push_back(5);
    cout << solution.size();
}