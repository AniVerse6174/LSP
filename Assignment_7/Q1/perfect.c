#include "perfect.h"
#include "helper.h"

int IsPerfect(int No) {
    return SumOfFactors(No) == No;
}