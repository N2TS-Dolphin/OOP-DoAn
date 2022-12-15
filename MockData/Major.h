#pragma once
#pragma once

#include <map>
#include <string>

using namespace std;

enum Major 
{
    IT = 10,
    Chemistry = 11,
    Physics = 12,
    Biology = 13
};

static const map<Major, string> MajorNames = map<Major, string>
{
    {Major::IT, "Cong nghe thong tin"},
    {Major::Chemistry, "Hoa hoc"},
    {Major::Physics, "Vat li"},
    {Major::Biology, "Sinh hoc"}
};