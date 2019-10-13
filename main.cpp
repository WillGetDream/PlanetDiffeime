/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: william
 *
 * Created on October 12, 2019, 10:46 AM
 */

#include <cstdlib>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;


/*
 *
 */

class Field{
public:
    int second,min,hour,months;
    string timeS,timeE;
    int monthAry[];

};

Field* inputfunc(int );
int calculate(Field* );


Field* inputfunc(int i){
    Field* field=new Field();
    field->second=i;
    cin>>field->min>>field->hour>>field->months;
    field->monthAry[field->months];
    for(int i=0;i<field->months;i++){
        cin>>field->monthAry[i];
    }
    cin>>field->timeS>>field->timeE;
    return field;
};

int calculate(Field* field) {

    //calculate second
    char tmp[3];
    strncpy(tmp, field->timeS.c_str(), 2);
    int startmonth = atoi(tmp);

    strncpy(tmp, field->timeE.c_str(), 2);
    int endmonth = atoi(tmp);

    // cout << startmonth << " s__e" << endmonth;
    if (startmonth > endmonth) {
        return 0;
    }

    strncpy(tmp, field->timeS.c_str() + 3, 2);
    int startday = atoi(tmp);
    //   cout << "startday:" << startday << endl;

    strncpy(tmp, field->timeE.c_str() + 3, 2);
    int endday = atoi(tmp);
    // cout << "endday:" << endday << endl;

    strncpy(tmp, field->timeS.c_str() + 9, 2);
    int starthour = atoi(tmp);
    //  cout << "starthour:" << starthour << endl;

    strncpy(tmp, field->timeE.c_str() + 9, 2);
    int endhour = atoi(tmp);
    // cout << "endhour:" << endhour << endl;

    strncpy(tmp, field->timeS.c_str() + 12, 2);
    int startmin = atoi(tmp);
    ///   cout << "startmin:" << startmin << endl;

    strncpy(tmp, field->timeE.c_str() + 12, 2);
    int endmin = atoi(tmp);
    //  cout << "endmin:" << endmin << endl;

    strncpy(tmp, field->timeS.c_str() + 15, 2);
    int startsec = atoi(tmp);
    //  cout << "startsec:" << startsec << endl;

    strncpy(tmp, field->timeE.c_str() + 15, 2);
    int endsec = atoi(tmp);
    //  cout << "endsec:" << endsec << endl;


    //  cout << starthour << endhour << endl;

    int secondofday = field->hour * field->min * field->second;
    //cout << "secondofday:" << secondofday << endl;

    int startdaysec = starthour * field->min * field->second + startmin * field->second + startsec;
    // cout << "startdaysec:" << startdaysec << endl;
    int enddaysec = endhour * field->min * field->second + endmin * field->second + endsec;
    // cout << "enddaysec:" << enddaysec << endl;

    int day;
    int total;
    if (startmonth == endmonth) {

        day = endday - startday + 1;
        total = secondofday * day - startdaysec - (secondofday - enddaysec);
        // cout << "total:" << total << endl;
        return total;
    }else{

        //add a more day
        int  day1;
        day1 = field->monthAry[startmonth] - startday;
        day = endday + day1-1;
        total = (secondofday-startdaysec) +  enddaysec+secondofday*1;
        // cout << "total:" << total << endl;
        return total;
    }




    return 0;
};


int main(int argc, char** argv) {
    vector<Field*> vf;
    vector<int* > arr;
    Field *field;
    int c=199;
    int i;
    while(c){
        cin>>i;

        if(i==0){
            break;//'output
        };
        vf.push_back(inputfunc(i));


    }

    for(int i=0;i<vf.size();i++){
        cout<<calculate(vf.at(i))<<endl;
    }

    delete []field;

    return 0;
}


