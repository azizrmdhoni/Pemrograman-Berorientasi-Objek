#include <stdio.h>
#include <queue>
#include <unordered_map>
using namespace std;

int main() {
    int x;
    scanf("%d", &x);

unordered_map<int,int> timsiswa;
    for (int timid = 0; timid < x; timid++) {
        int y;
        scanf("%d", &y);
        for (int j = 0; j < y; j++) {
            int siswa;
            scanf("%d", &siswa);
            timsiswa[siswa] = timid;
        }
    }

unordered_map<int, queue<int>> timqueue;
queue<int> timorder;
unordered_map<int,bool> timinqueue;

    char command[10];
    while (scanf("%s", command) == 1) {
        if (command[0] == 'E') {
            int siswa;
            scanf("%d", &siswa);
            int tim = timsiswa[siswa];

            if (!timinqueue[tim]) {
                timorder.push(tim);
                timinqueue[tim] = true;
            }
            timqueue[tim].push(siswa);
        } else if (command[0] == 'D') {
            if (!timorder.empty()) {
                int tim = timorder.front();
                int siswa = timqueue[tim].front();
                timqueue[tim].pop();
                printf("%d\n", siswa);

                if (timqueue[tim].empty()) {
                    timorder.pop();
                    timinqueue[tim] = false;
                }
            }
        }
    }
}
