#include<iostream>
using namespace std;

int main () {
    float slab22_23OldRegime[4][4] = {{250000, 0, 0, 0},
                                    {300000, 5, 0, 0},
                                    {500000, 5, 5, 0},
                                    {1000000, 20, 20, 20}
                                    }; // income slab: (<60, <80, >80)

    float slab22_23NewRegime[8][3] = {{250000, 0, 0},
                                    {300000, 5, 0},
                                    {500000, 5, 5},
                                    {600000, 10, 5},
                                    {750000, 10, 10},
                                    {900000, 15, 10},
                                    {1000000, 15, 15},
                                    {1200000, 20, 15}
                                    }; // income slab, FY 22-23, FY 23-24)


    float income;
    int age;
    cout << "\t\tFORMAT\nincome\tage\n";
    cin >> income >> age;

    cout << "Old tax Regime\tNew Tax regime\n\t\t{FY 22-23\tFY 23-24}\n";

    if (age <= 60)
        age = 1;
    else if (age <= 80)
        age = 2;
    else
        age = 3;

    bool flag = false;
    for (int i = 0; i <= 4; i++) {
        if (income <= slab22_23OldRegime[i][0]) {
            flag = true;
            float taxpercentage = slab22_23OldRegime[i][age];
            cout << income * taxpercentage / 100 << "\t\t";
            break;
        }
    }
    if (flag == false) {
        float taxpercentage = 30;
        cout << income * taxpercentage / 100 << "\t\t";
    }

    bool flag = false;
    for (int i = 0; i <= 8; i++) {
        if (income <= slab22_23NewRegime[i][0]) {
            flag = true;
            cout << income * slab22_23NewRegime[i][1] / 100 << "\t" << income * slab22_23NewRegime[i][2] / 100;
            break;
        }
    }
    if (flag == false) {
        cout << income * 30 / 100 << "\t" << income * 30 / 100;
    }
    
    return 0;
}