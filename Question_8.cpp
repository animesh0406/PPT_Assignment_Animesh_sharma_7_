/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
*/
#include <bits/stdc++.h>
 
using namespace std;
 
bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        double slope = (double)(coordinates[1][1] - coordinates[0][1]) / 
                (coordinates[1][0] - coordinates[0][0]);
       
        for(int i = 2; i < coordinates.size(); i++){
            vector<int> a = coordinates[i], b = coordinates[i-1];
            
            if(slope != (double)(a[1] - b[1]) / (a[0] - b[0])){
                return false;
            }
        }
        cout << endl;
        
        return true;
    }