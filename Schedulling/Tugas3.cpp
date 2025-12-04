#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Process {
    string name;
    int AT, BT, qclass;
    int remaining;
    int CT, TAT, WT, RT;
    bool started = false;
};

// Untuk Gantt Chart
struct Gantt {
    int start;
    string pname;
    int level;
};

int main() {
    int n;
    cout << "Masukkan jumlah proses: ";
    cin >> n;

    vector<Process> p(n);
    for (int i = 0; i < n; i++) {
        cout << "\nNama proses : ";
        cin >> p[i].name;
        cout << "Arrival time : ";
        cin >> p[i].AT;
        cout << "Burst time : ";
        cin >> p[i].BT;
        cout << "Queue (1=RR, 2=FCFS): ";
        cin >> p[i].qclass;
        p[i].remaining = p[i].BT;
    }

    // Sort by arrival
    sort(p.begin(), p.end(), [](Process &a, Process &b){
        return a.AT < b.AT;
    });

    queue<int> Q1, Q2;    // MLQ
    int time = 0, done = 0;
    int nextArr = 0;

    vector<Gantt> gantt;

    while (done < n) {

        // Masukkan proses yang baru datang
        while (nextArr < n && p[nextArr].AT <= time) {
            if (p[nextArr].qclass == 1) Q1.push(nextArr);
            else Q2.push(nextArr);
            nextArr++;
        }

        int idx = -1;
        int level = 0;

        // -------- PRIORITAS LEVEL 1 (RR) -------
        if (!Q1.empty()) {
            idx = Q1.front();
            Q1.pop();
            level = 1;

            // Jika pertama kali jalan
            if (!p[idx].started) {
                p[idx].RT = time - p[idx].AT;
                p[idx].started = true;
            }

            // Eksekusi quantum 2
            int Q = 2;
            int startT = time;

            while (Q-- > 0 && p[idx].remaining > 0) {
                time++;
                p[idx].remaining--;

                // masukkan proses baru yang datang saat RR jalan
                while (nextArr < n && p[nextArr].AT <= time) {
                    if (p[nextArr].qclass == 1) Q1.push(nextArr);
                    else Q2.push(nextArr);
                    nextArr++;
                }
            }

            gantt.push_back({startT, p[idx].name, 1});

            if (p[idx].remaining == 0) {
                p[idx].CT = time;
                done++;
            } else {
                // Masukkan kembali ke queue 1
                Q1.push(idx);
            }
        }

        // -------- JIKA LEVEL 1 KOSONG → LEVEL 2 (FCFS) -------
        else if (!Q2.empty()) {
            idx = Q2.front();
            Q2.pop();
            level = 2;

            if (!p[idx].started) {
                p[idx].RT = time - p[idx].AT;
                p[idx].started = true;
            }

            int startT = time;

            while (p[idx].remaining > 0) {
                p[idx].remaining--;
                time++;

                // masukkan proses yang datang ketika FCFS sedang jalan
                while (nextArr < n && p[nextArr].AT <= time) {
                    if (p[nextArr].qclass == 1) Q1.push(nextArr);
                    else Q2.push(nextArr);
                    nextArr++;
                }

                // Jika ada proses queue 1 datang → hentikan FCFS
                if (!Q1.empty()) break;
            }

            gantt.push_back({startT, p[idx].name, 2});

            if (p[idx].remaining == 0) {
                p[idx].CT = time;
                done++;
            } else {
                // FCFS tidak preemptive kecuali karena Q1 muncul → kembali ke Q2
                Q2.push(idx);
            }
        }

        else {
            // Idle time
            time++;
        }
    }

    // Hitung TAT & WT
    double avgWT1 = 0, avgWT2 = 0, avgTAT1 = 0, avgTAT2 = 0;
    int cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++) {
        p[i].TAT = p[i].CT - p[i].AT;
        p[i].WT = p[i].TAT - p[i].BT;

        if (p[i].qclass == 1) {
            avgWT1 += p[i].WT;
            avgTAT1 += p[i].TAT;
            cnt1++;
        } else {
            avgWT2 += p[i].WT;
            avgTAT2 += p[i].TAT;
            cnt2++;
        }
    }

    //======================
    // GANTT CHART
    //======================

    cout << "\n=== GANTT CHART ===\n";
    cout << "-----------------------------------------------------------\n";
    for (auto &g : gantt)
        cout << "| " << g.pname << "(Q" << g.level << ") ";
    cout << "|\n";
    cout << "-----------------------------------------------------------\n";

    for (int i = 0; i < gantt.size(); i++)
        cout << gantt[i].start << "\t";
    cout << time << "\n";

    //======================
    // TABEL HASIL
    //======================

    cout << "\n=== TABEL HASIL ===\n";
    cout << "Proses\tAT\tBT\tQ\tCT\tTAT\tWT\tRT\n";
    for (auto &x : p) {
        cout << x.name << "\t" << x.AT << "\t" << x.BT << "\t" 
             << x.qclass << "\t" << x.CT << "\t" << x.TAT
             << "\t" << x.WT << "\t" << x.RT << "\n";
    }

    //======================
    // PERBANDINGAN RATA-RATA
    //======================

    cout << "\n=== PERBANDINGAN RATA-RATA ===\n";
    if (cnt1 > 0) {
        cout << "Queue 1 (RR) - Avg WT: " << avgWT1 / cnt1
             << ", Avg TAT: " << avgTAT1 / cnt1 << "\n";
    }
    if (cnt2 > 0) {
        cout << "Queue 2 (FCFS) - Avg WT: " << avgWT2 / cnt2
             << ", Avg TAT: " << avgTAT2 / cnt2 << "\n";
    }

    return 0;
}
