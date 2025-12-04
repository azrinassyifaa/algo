#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int AT, BT;
    int remaining;
    int CT, TAT, WT, RT;
    bool started = false;
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
        p[i].remaining = p[i].BT;
    }

    // Sort berdasarkan AT
    sort(p.begin(), p.end(), [](Process a, Process b) {
        return a.AT < b.AT;
    });

    int complete = 0, time = 0, prev = -1;
    int preemption = 0;

    vector<pair<int,string>> gantt; // {start time, process name}

    while (complete < n) {
        int idx = -1;
        int mn = 1e9;

        // cari proses shortest remaining
        for (int i = 0; i < n; i++) {
            if (p[i].AT <= time && p[i].remaining > 0) {
                if (p[i].remaining < mn) {
                    mn = p[i].remaining;
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++;
            continue;
        } // sesuatu

        // proses berubah → simpan ke Gantt chartsssss
        if (prev != idx) {
            gantt.push_back({time, p[idx].name});
            if (prev != -1) preemption++;
            prev = idx;
        }

        // response time
        if (!p[idx].started) {
            p[idx].RT = time - p[idx].AT;
            p[idx].started = true;
        }

        p[idx].remaining--;
        time++;

        if (p[idx].remaining == 0) {
            p[idx].CT = time;
            complete++;
        }
    }

    //---------------------------------------------------
    // GANTT CHART FORMAT seperti yang kamu minta
    //---------------------------------------------------
    cout << "\n=== Gantt Chart ===\n";

    cout << " ";
    for (int i = 0; i < gantt.size(); i++) cout << "------";
    cout << "\n|";

    for (auto &g : gantt)
        cout << "  " << g.second << "  |";

    cout << "\n ";
    for (int i = 0; i < gantt.size(); i++) cout << "------";
    cout << "\n";

    // waktu di bawah blok
    for (auto &g : gantt)
        cout << g.first << setw(6 - to_string(g.first).length()) << " ";
    cout << time << "\n";

    //---------------------------------------------------
    // HITUNG TAT & WT
    //---------------------------------------------------
    for (int i = 0; i < n; i++) {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;
    }

    //---------------------------------------------------
    // OUTPUT TABEL
    //---------------------------------------------------
    cout << "\n=== Tabel Hasil ===\n";
    cout << "Proses\tAT\tBT\tCT\tTAT\tWT\tRT\n";
    for (auto &x : p) {
        cout << x.name << "\t" << x.AT << "\t" << x.BT << "\t"
             << x.CT << "\t" << x.TAT << "\t" << x.WT << "\t" << x.RT << "\n";
    }

    cout << "\nJumlah preemption: " << preemption << endl;
}
