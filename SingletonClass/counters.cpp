#include "counters.h"

Counters::Counters(QObject *parent)
    : QObject{parent}
    ,m_turnsRemaining(3)
    , m_matchCounter(0)
{}
