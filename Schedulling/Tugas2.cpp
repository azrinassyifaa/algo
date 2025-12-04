#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int AT, BT;
    int remaining;
    int priority;
    int CT, WT, TAT, RT;
    bool started = false;

    // aging tracker
    int wait_time = 0;
};

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);

    for (int i = 0; i < n; i++) {
        cout << "Nama proses : ";
        cin >> p[i].name;
        cout << "Arrival Time : ";
        cin >> p[i].AT;
        cout << "Burst Time : ";
        cin >> p[i].BT;
        cout << "Priority (lebih kecil = lebih tinggi) : ";
        cin >> p[i].priority;

        p[i].remaining = p[i].BT;
    }

    // sort berdasarkan arrival time
    sort(p.begin(), p.end(), [](Process &a, Process &b) {
        return a.AT < b.AT;
    });

    int time = 0, completed = 0;
    int prev = -1;
    int priority_changed = 0;

    vector<pair<int,string>> gantt; // waktu mulai + nama proses

    while (completed < n) {

        // aging: setiap proses yang menunggu > 5 waktu → priority--
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].remaining > 0) {
                if (prev != i) p[i].wait_time++;  // proses tidak berjalan → waiting

                if (p[i].wait_time > 5) {
                    p[i].priority--;
                    if (p[i].priority < 0) p[i].priority = 0; // batas bawah
                    p[i].wait_time = 0;
                    priority_changed++;
                }
            }
        }

        // cari proses PRIORITAS TERBAIK
        int idx = -1;
        int best_priority = 9999;

        for (int i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].remaining > 0) {
                if (p[i].priority < best_priority) {
                    best_priority = p[i].priority;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        }

        // proses berubah → ganti blok di Gantt chart
        if (prev != idx) {
            gantt.push_back({time, p[idx].name});
            prev = idx;
        }

        // response time
        if (!p[idx].started) {
            p[idx].RT = time - p[idx].AT;
            p[idx].started = true;
        }

        // proses berjalan → reset wait time
        p[idx].wait_time = 0;

        p[idx].remaining--;
        time++;

        if (p[idx].remaining == 0) {
            p[idx].CT = time;
            completed++;
        }
    }

    // hitung TAT & WT
    for (int i = 0; i < n; i++) {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT  = p[i].TAT - p[i].BT;
    }

    // =========================
    //     OUTPUT GANTT CHART
    // =========================
    cout << "\n=== Gantt Chart ===\n";

    cout << " ";
    for (int i = 0; i < gantt.size(); i++) cout << "------";
    cout << "\n|";

    for (auto &g : gantt)
        cout << "  " << g.second << "  |";

    cout << "\n ";
    for (int i = 0; i < gantt.size(); i++) cout << "------";
    cout << "\n";

    for (auto &g : gantt)
        cout << g.first << setw(6 - to_string(g.first).length()) << " ";
    cout << time << "\n";

    // =========================
    //     OUTPUT TABLE
    // =========================
    cout << "\n=== Tabel Hasil ===\n";
    cout << "Proses\tAT\tBT\tPri\tCT\tTAT\tWT\tRT\n";
    for (auto &x : p) {
        cout << x.name << "\t" << x.AT << "\t" << x.BT << "\t"
             << x.priority << "\t" << x.CT << "\t" << x.TAT << "\t"
             << x.WT << "\t" << x.RT << "\n";
    }

    cout << "\nJumlah perubahan priority (aging): " << priority_changed << endl;

    return 0;
}
