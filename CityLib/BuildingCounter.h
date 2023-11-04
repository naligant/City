/**
 * @file BuildingCounter.h
 * @author Prajeeth Naliganti
 *
 *
 */
#include "TileVisitor.h"
#ifndef CITY_CITYLIB_BUILDINGCOUNTER_H
#define CITY_CITYLIB_BUILDINGCOUNTER_H
/**
 * Class to count buildings
 */
class BuildingCounter : public TileVisitor
{
private:
    /// Buildings counter
    int mNumBuildings = 0;

public:
    /**
     * Get the number of buildings
     * @return Number of buildings
     */
    int GetNumBuildings() const { return mNumBuildings; }

    /**
     * Visit a TileBuilding object
     * @param building Building we are visiting
     */
    void VisitBuilding(TileBuilding* building) override
    {
        mNumBuildings++;
    }

};

#endif //CITY_CITYLIB_BUILDINGCOUNTER_H
