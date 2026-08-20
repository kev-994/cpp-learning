#include "LogicGates.h"

bool andGate(bool a, bool b)
{
    return a && b;
}

bool orGate(bool a, bool b)
{
    return a || b;
}

bool xorGate(bool a, bool b)
{
    return a ^ b;
}

bool notGate(bool a)
{
    return !a;
}

bool nandGate(bool a, bool b)
{
    return notGate(andGate(a, b));
}

bool norGate(bool a, bool b)
{
    return notGate(orGate(a, b));
}


