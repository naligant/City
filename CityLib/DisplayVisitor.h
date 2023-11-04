/**
 * @file DisplayVisitor.h
 * @author Prajeeth Naliganti
 *
 *
 */

#include "TileVisitor.h"
#include "TileGrass.h"
#include "TileHospital.h"
#ifndef CITY_CITYLIB_DISPLAYVISITOR_H
#define CITY_CITYLIB_DISPLAYVISITOR_H
/**
 * Class to display Helicopter
 */
class DisplayVisitor : public TileVisitor
{
private:
    ///boolean value to see if ambulance exists
    bool mAmbulanceInCity = false;
public:
    /**
     * Gets the boolean to see if ambulance exists
     * @return mAmbulanceInCity
     */
    bool GetAmbulanceInCity() {return mAmbulanceInCity;}
    //void VisitHospital(TileHospital *hospital) override;
    //void VisitGrass(TileGrass *grass) override;
    /**
     * Function to be able to visit landable tile
     * @param landable variable for landable
     */

    void VisitLanding(TileLandable *landable) override;
};

#endif //CITY_CITYLIB_DISPLAYVISITOR_H
