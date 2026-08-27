#include <iostream>
using namespace std;

int main(){
    int C;
    cin >> C;
    int n;
    cin >> n;

    // Make an array of weights, with size n. Making array of variable size is only allowed for gcc compiler (won't work in Clang or MSVC).
    int weight[n];
    for(int i=0; i<n; i++){
        cin >> weight[i];
    }

    // First one , total sum
    int total = 0;
    for(int i=0; i<n; i++){
        total += weight[i];
    }
    cout << "Total Shipment Weight:" << " " << total << endl;

    // Second one , avg. , we take float for decimals, and divide by 1.0 for float division.
    float avg = total/(1.0*n);
    cout << "Average Container Weight:" << " " << avg << endl;

    // Third and Fourth, we will do together. We pass one single loop, checking min and max;
    int minn = weight[0];
    int maxx = weight[0];
    for(int i=1; i<n; i++){
        if(weight[i] > maxx){
            maxx = weight[i];
        }
        if(weight[i] < minn){
            minn = weight[i];
        }
    }

    cout << "Heaviest Container:" << " " << maxx << endl;
    cout << "Lightest Container:" << " " << minn << endl;

    // Fifth one is just a single if statement
    if(total >=200){
        cout << "Classification:" << " " << "Heavy" << endl;
    }
    else{
        cout << "Classification:" << " " << "Light" << endl;
    }

    // Sixth one is direct output
    cout << "Port Capacity:" << " " << C << endl;

    //Last one is a if statement too
    if(total > C){
        cout << "Status:" << " " << "Shipment exceeds port capacity" << endl;
    }
    else{
        cout << "Status:" << " " << "Shipment can be unloaded" << endl;
    }
}