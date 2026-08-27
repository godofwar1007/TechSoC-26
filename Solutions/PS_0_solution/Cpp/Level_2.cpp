#include <iostream>
#include <numeric> // For gcd
#include <algorithm> // For swap function
#include <fstream> // Required for ofstream
#include <string> // For normal strings
using namespace std;

int main(){

    bool ship = true;
    // We will switch off the boolean if they want to end the program, else it runs for infinity
    while(ship){
        // Prev inputs 
    int C;
    cin >> C;
    int n;
    cin >> n;


    int weight[n];
    int sorted[n];
    for(int i=0; i<n; i++){
        cin >> weight[i];
        sorted[i] = weight[i];
    }

    // For Sorting, I will be using basic bubble sort, you can search and learn for it, as explaining it in code would be weird.
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(weight[j] > weight[i]){
                swap(sorted[j] , sorted[i]);
            }
        }
    }

    for(int j=0; j<n; j++){
        cout << sorted[j] << " ";
    }
    cout << endl;
    // we do an empty cout to end the line

    // For bar chart I am going to use a simple trick. Think, what should each * represent? without giving decimal results? , just take gcd of array

    int g = 0;
    for(int i=0; i<n; i++){
        g = gcd(g , weight[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<weight[i]/g; j++){
            cout << '*' << " ";
        }
        cout << endl;
    }

    //For search I am using basic linear search, as we already have sorted, we can use binary search, but well, it is what it is

    bool found = false;
    int get;
    cin >> get;
    for(int j=0; j<n; j++){
        if(weight[j] = get){
            found = true;
        }
    }
    if(found){
        cout << "found" << endl;
    }
    else{
        cout << "not found" << endl;
    }

    // For kth element, something most of you missed was, you already have sorted array, so just print the kth element from it.
    int k;
    cin >> k;

    if(k>=n || k<0){
        cout << "not valid" << endl;
    }
    else{
        cout << sorted[k-1] << endl;
    }

    // To save in file, mostly syntax
    bool file = false;
    cout << "save in txt? : y/n" << endl;
    string s;
    cin >> s;
    if(s == "y"){
        std::ofstream outFile("output.txt");
        if (outFile.is_open()) {
            for(int j=0; j<n; j++){
                outFile << sorted[j] << " ";
            }   
            outFile << endl;


            for(int i=0; i<n; i++){
                for(int j=0; j<weight[i]/g; j++){
                    outFile << '*' << " ";
                }
                outFile << endl;
            }

            // I am not entering more output, coz you get the point.
            outFile.close();
            std::cout << "Output saved to file." << std::endl;
        } 
        else{
        std::cout << "Unable to open file." << std::endl;
        }
    }

    cout << "do you want to continue? : y/n" << endl;
    string s2;
    cin >> s2;
    if(s2 != "y"){
        ship = false;
    }
    }
}