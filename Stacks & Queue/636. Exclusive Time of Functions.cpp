#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
class Pair
{
public:
    int id;
    int startTime;
    int childTime;
};

vector<int> exclusiveTime(int n, vector<string> &logs)
{
    vector<int> Time(n, 0);

    int len = logs.size();

    stack<Pair> st;

    for (int i = 0; i < len; i++)
    {
        string log = logs[i]; // <id: start/end : time>

        int stringId = log[0] - '0';

        int status = 0;

        if (log[2] == 's')
        {
            status = 1; // start
        }
        else
        {
            status = 0; // end
        }

        int time = log[log.size() - 1] - '0';

        // cout << "stringId " << stringId << " status " << status << " time " << time << endl;

        if (status == 1)
        {
            st.push({stringId, time, 0});
        }

        else
        {
            Pair temp = st.top();
            st.pop();

            int timeStayed = (time - temp.startTime) + 1;
            int finalTime = timeStayed - temp.childTime;
            Time[temp.id] += finalTime;

            if (temp.id == 0)
            {
                cout << "time " << time << " startTime " << temp.startTime << " timeStayed " << timeStayed << " finalTime " << finalTime << " Time[] " << Time[temp.id] << endl;
            }

            if (st.size() > 0) // add childTime to top element
            {
                st.top().childTime += timeStayed;
            }
        }
    }

    return Time;
}

int main()
{
    int n = 8;
    vector<string> a = {"0:start:0", "1:start:5", "2:start:6", "3:start:9", "4:start:11", "5:start:12", "6:start:14", "7:start:15", "1:start:24", "1:end:29", "7:end:34", "6:end:37", "5:end:39", "4:end:40", "3:end:45", "0:start:49", "0:end:54", "5:start:55", "5:end:59", "4:start:63", "4:end:66", "2:start:69", "2:end:70", "2:start:74", "6:start:78", "0:start:79", "0:end:80", "6:end:85", "1:start:89", "1:end:93", "2:end:96", "2:end:100", "1:end:102", "2:start:105", "2:end:109", "0:end:114"};

    vector<int> t = exclusiveTime(n, a);

    for (int i = 0; i < n; i++)
    {
        cout << t[i] << " ";
    }

    cout << endl;

    return 0;
}