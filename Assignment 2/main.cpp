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

  while(row_of_zero==false){ //row_of_zero refers to the bool which checks whether the input is 3 0's, signifying the end of the input, however it is rather superfluous here as the I check again within loop.
    /*if (i==0){ 
      cout << endl;
    }*/
    cin >> y >> m >> d;
    //TODO: Clean up this up a bit, the initial while loop condition is pointless with this here - however it does work.
    row_of_zero = is_zero(y, m, d); //checking for 
    if (row_of_zero==true){
      break;
    }
    date newdate(y, m, d); //place holder object
    dates.push_back(newdate); // the real object. Theres probably a way to instantiate and add to the vector at the same time, meaning I wouldn't need a placceholder.
    
    //dates[i].print_diagnostics();
    day_num.push_back(make_pair (dates[i].get_date_number() , i)); //vector of tuples, date_number and its position ('i'). We are adding the position ('i') so that when we sort the date_numbers later, we can keep track of the original positions so that we can match the date_numbers to their actual dates in the 'dates vector'.
    //cout << " " << day_num[i].first << " " << day_num[i].second << endl;

    i++;
  }

  sort(day_num.begin(), day_num.end()); //sort day_num vector

  for (int i=0; i<day_num.size();i++){ 
    placeholder = day_num[i].second; //this placeholder holds the original position of the now sorted day_num vector
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
