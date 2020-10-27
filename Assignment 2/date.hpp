#pragma once

class date{
  private:
  int year;
  int month;
  int day;


  public:
  date(int y, int m, int d); //constructor to set date
  date(); // default constructor
  ~date();
  //getters and setters
  int get_day_number(); //need no parameters as all the info is in the object itself
  //methods
  void print_diagnostics();
  int get_date_number();
};

