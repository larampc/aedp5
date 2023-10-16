#include "funSetProblem.h"

FunSetProblem::FunSetProblem() {}


//=============================================================================
// Exercise 2: FunSetProblem
//=============================================================================
// TODO
pair<int,int> FunSetProblem::pairSum(const vector<int> &values, int sum) {
    set<int> s;
    for (int v: values) {
        s.insert(v);
    }
    for (int v: values) {
        s.erase(v);
        auto it = s.find(sum-v);
        if (it!=s.end()) return make_pair(v,*it);
    }
    return make_pair(0,0);
}
