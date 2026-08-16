#include<iostream>
#include<fstream>
using namespace std;
int main() {
     int c,n;
    cout << "ENTER THE MAXIMUM STORAGE CAPACITY OF PORT\n";
    cin >> c;
    cout << "ENTER THE NUMBER OF CONTAINERS\n";
    cin >> n;
    float w[n];
    for(int i=0;i<n;i++){
        cout << "ENTER THE WEIGHT OF " << (i+1) << " CONTAINER\n";
        cin >> w[i];
    }
    for(int i=0;i<n;i++){
        cout << w[i] << endl;
    }
     float s=0.0,max=w[0],min=w[0];
    for(int i=0;i<n;i++){
        s+=w[i];
        if(w[i]>max){
            max=w[i];
        }
        if(w[i]<min){
            min=w[i];
        }
    }
    float avg=s/n;
    cout << "TOTAL SHIPMENT WEIGHT=" << s << endl;
    cout << "AVERAGE SHIPMENT WEIGHT=" << avg << endl;
    cout << "WEIGHT OF HEAVIEST CONTAINER=" << max << endl;
    cout << "WEIGHT OF LIGHTEST CONTAINER=" << min << endl;
    if(s>=200){
        cout << "CLASSIFICATION:HEAVY\n";
    }
    else{
        cout << "CLASSIFICATION:LIGHT\n";
    }
    cout << "PORT CAPACITY" << c << endl;
    if(s<=c){
        cout << "SHIPMENT CAN BE UNLOADED\n";
    }
    else{
        cout << "SHIPMENT EXCEEDS PORT CAPACITY" << endl;
    }
}