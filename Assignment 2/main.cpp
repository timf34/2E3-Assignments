#include <iostream>
#include "date.hpp"
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

const int SIZE = 20;

bool is_zero(int a, int b, int c);
//void print_sorted_days(vector<pair <int, int> > day_num);



int main() {
  int y, m, d, placeholder;
  bool row_of_zero = false;
  int i=0;
  vector<date> dates;
  vector<int> sorted_date_indices;
  vector<pair <int, int> > day_num; //one for index, one for daynumber to help sorting

  cout << "Enter the dates in year month day format, one per line. To finish, enter the date 0 0 0." << endl;

  while(row_of_zero==false){
    /*if (i==0){ 
      cout << endl;
    }*/
    cin >> y >> m >> d;
    row_of_zero = is_zero(y, m, d);
    if (row_of_zero==true){
      break;
    }
    date newdate(y, m, d); //place holder object
    dates.push_back(newdate);
    
    //dates[i].print_diagnostics();
    day_num.push_back(make_pair (dates[i].get_date_number() , i));
    //cout << " " << day_num[i].first << " " << day_num[i].second << endl;

    i++;
  }

  sort(day_num.begin(), day_num.end());

  for (int i=0; i<day_num.size();i++){
    placeholder = day_num[i].second;
    dates[placeholder].print_diagnostics();
    cout << " " << day_num[i].first << endl;
  }
  
  return 0;
}


bool is_zero(int a, int b, int c){
  if (a==0 && b ==0 && c==0){
    return true;
  }
  else 
  return false;
}
