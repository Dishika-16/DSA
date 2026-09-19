class Solution {
public:
    string predictPartyVictory(string s) {

        queue<int> q;
        queue<int> r;
        queue<int> d;

        for (int i = 0; i < s.length(); i++) {
            q.push(i);

            if (s[i] == 'R')
                r.push(i);
            else
                d.push(i);
        }

        while (q.size() > 1) {

            if (s[q.front()] == 'x') {
                q.pop();
            }

            else if (s[q.front()] == 'R') {

                if (d.size() == 0)
                    return "Radiant";

                // Ban next Dire
                s[d.front()] = 'x';
                d.pop();

                // Move current R to the back of q
                q.push(q.front());
                q.pop();

                // Move current R to the back of r
                r.push(r.front());
                r.pop();
            }

            else if (s[q.front()] == 'D') {

                if (r.size() == 0)
                    return "Dire";

                // Ban next Radiant
                s[r.front()] = 'x';
                r.pop();

                // Move current D to the back of q
                q.push(q.front());
                q.pop();

                // Move current D to the back of d
                d.push(d.front());
                d.pop();
            }
        }

        if (s[q.front()] == 'R')
            return "Radiant";
        else
            return "Dire";
    }
};