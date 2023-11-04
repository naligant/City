/**
 * @file DisplayVisitor.cpp
 * @author Prajeeth Naliganti
 */

#include "pch.h"
#include "DisplayVisitor.h"

void DisplayVisitor::VisitLanding(TileLandable *landable)
{
    if (landable->GetAirAmbulance() != nullptr)
    {
        mAmbulanceInCity = true;
    }
}
