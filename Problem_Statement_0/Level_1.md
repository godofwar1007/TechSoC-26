#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

int main() {
    double C;  // Port capacity
    int N;     // Number of containers

    cin >> C;
    cin >> N;

    double total = 0;
    double weight;
    double heaviest = 0;
    double lightest = 0;

    for (int i = 0; i < N; i++) {
        cin >> weight;

        total += weight;

        if (i == 0) {
            heaviest = weight;
            lightest = weight;
        } else {
            heaviest = max(heaviest, weight);
            lightest = min(lightest, weight);
        }
    }

    double average = total / N;

    string classification;
    if (total >= 200)
        classification = "Heavy";
    else
        classification = "Light";

    string status;
    if (total <= C)
        status = "Shipment can be unloaded";
    else
        status = "Shipment exceeds port capacity";

    cout << fixed << setprecision(2);

    cout << "Total shipment weight: " << total << endl;
    cout << "Average container weight: " << average << endl;
    cout << "Heaviest container: " << heaviest << endl;
    cout << "Lightest container: " << lightest << endl;
    cout << "Classification: " << classification << endl;
    cout << "Port Capacity: " << C << endl;
    cout << "Status: " << status << endl;

    return 0;
}


  





















