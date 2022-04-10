class Solution
{
public:
    int calPoints(vector<string> &ops)
    {

        vector<int> scores;
        int n = ops.size();

        for (int i = 0; i < n; i++)
        {
            int size = scores.size();
            if (ops[i] == "+")
            {
                scores.push_back(scores[size - 1] + scores[size - 2]);
            }
            else if (ops[i] == "C")
            {
                scores.pop_back();
            }
            else if (ops[i] == "D")
            {
                scores.push_back(scores[size - 1] * 2);
            }
            else
            {
                scores.push_back(stoi(ops[i]));
            }
        }

        int sum = 0;

        for (int i = 0; i < scores.size(); i++)
            cout << scores[i] << " ";

        for (int i = 0; i < scores.size(); i++)
        {
            sum += scores[i];
        }
        return sum;
    }
};