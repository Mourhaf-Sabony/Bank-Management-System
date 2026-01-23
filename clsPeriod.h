#pragma once
#include "clsDate.h"

class clsPeriod
{
public:

    clsDate start_date;
    clsDate end_date;

    clsPeriod(clsDate start_date, clsDate end_date)
    {
        this->start_date = start_date;
        this->end_date = end_date;

    }

    //problem 58
    static bool is_overlap_periods(clsPeriod period1, clsPeriod period2)
    {

        if (
            clsDate::compare_dates(period2.end_date, period1.start_date) == clsDate::en_date_compare::before
            ||
            clsDate::compare_dates(period2.start_date, period1.end_date) == clsDate::en_date_compare::after
            )
            return false;
        else
            return true;

    }

    bool is_overlap_periods(clsPeriod period2)
    {
        return is_overlap_periods(*this, period2);
    }

    void Print()
    {
        cout << "Period Start: ";
        start_date.print();


        cout << "Period End: ";
        end_date.print();


    }

};
