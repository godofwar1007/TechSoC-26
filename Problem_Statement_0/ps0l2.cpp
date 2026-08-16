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
 for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(w[i]<w[j]){
                float c=w[i];
                w[i]=w[j];
                w[j]=c;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout << w[i] << " " << endl;
    }
cout << "Enter the value of k so that kth heaviest container can be found\n";
int k;
cin >> k;
cout << "The " << k << "th heaviest container is " << w[k-1] << "kg\n";
cout << "Enter the value of container to be searched" << endl;
float v;
int h=0;
cin >> v;
for(int i=0;i<n;i++){
    if(v==w[i]){
        cout << "Container " << w[i] << "kg found at position " << (i+1) << endl;
        h=1;
        break;
    }
}
if(h==0){
    cout << "Container not found\n";
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
     for(int i=0;i<n;i++){
        cout << "CONTAINER " << (i+1) << " (" << w[i] << "kg)" << ":";
        int k=w[i]/5;
        for(int j=0;j<k;j++){
            cout << "*";
        }
        cout << endl;
    }
    cout << "(*=5kg)\n";
    cout << "Wanna save this file?(Y/N)\n";
    char ch1;
    cin >> ch1;
    if(ch1=='Y'){
        ofstream file("shipment_report.txt"); // code to file
        if(file.is_open()){
            file << "Total Shipment Weight: " << s << endl;
            file << "Average Container Weight: " << avg << endl;
            file << "Heaviest Container Weight: " << max << endl;
            file << "Lightest Container Weight: " << min << endl;
            file << "Classification: " << (s>=200 ? "Heavy" : "Light") << endl;
            file << "Port Capacity: " << c << endl;
            if(s<=c){
                file << "Shipment can be unloaded." << endl;
            }
            else{
                file << "Shipment exceeds port capacity." << endl;
            }
            file << "Container Weights:\n";
            for(int i=0;i<n;i++){
                file << "Container " << (i+1) << " (" << w[i] << "kg): ";
                int k=w[i]/5;
                for(int j=0;j<k;j++){
                    file << "*";
                }
                file << endl;
            }
            file << "(*=5kg)";
            file.close();
            cout << "File saved\n";
        }
    }
     ifstream file("containers.txt"); // code to read file
    if(file.is_open()){
        int weight[n];
        file >> n;
        for(int i=0;i<n;i++){
            file >> weight[i];
        }
        file.close();
        cout << "LOADED " << n << " CONTAINERS FROM containers.txt\n";
        cout << "Weights:";
        for(int i=0;i<n;i++){
            cout << weight[i] << " ";
        }
    }
    cout << endl;
    cout << "Wanna continue this for another shipment? (y/n)\n";
    char ch;
    cin >> ch;
    if(ch=='y'){
        main();
    }
    else{
        cout << "THANKS FOR USING THIS PROGRAM\n";
    }
}