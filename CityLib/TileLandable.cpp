/**
 * @file TileLandable.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "TileLandable.h"
#include "City.h"
#include "DisplayVisitor.h"

/**
 * Constructor
 * @param city City this tile belongs to
 */
TileLandable::TileLandable(City *city) : Tile(city)
{
}


/**
 * Indicate that this object is about to be deleted by
 * begin dragged into the trash can. If the function
 * override returns false, the delete will not occur.
 * @return true if okay to delete.
*/
bool TileLandable::PendingDelete()
{

    return true;
}

/**
 * This function is called when the AirAmbulance has
 * landed on some other tile. It is no longer accessible to
 * this tile.
*/
void TileLandable::AirAmbulanceIsGone()
{

}

/**
 * This function is called when the AirAmbulance has landed on this
 * tile. This tile should now become the launching tile.
*/
void TileLandable::AirAmbulanceHasLanded()
{

}

void TileLandable::Update(double elapsed)
{
    Tile::Update(elapsed);
    if (mAmbulance != nullptr)
    {
        mAmbulance->Update(this, elapsed);
    }
}

void TileLandable::Draw(wxDC *dc)
{
    Tile::Draw(dc);
    if (mAmbulance != nullptr) {
        mAmbulance->Draw(this, dc);
    }


}

void TileLandable::Accept(TileVisitor* visitor)
{
    visitor->VisitLanding(this);
}