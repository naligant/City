/**
 * @file TileLandable.h
 * @author Charles Owen
 *
 * Intermediate base class for tiles that can be
 * landed on by the air ambulance
 */

#ifndef CITY_CITYLIB_TILELANDABLE_H
#define CITY_CITYLIB_TILELANDABLE_H

#include "Tile.h"
#include "AirAmbulance.h"
/**
 * Intermediate base class for tiles that can be
 * landed on by the air ambulance
 */
class TileLandable : public Tile
{
private:

    /// Air Ambulance drawing offset. This is used to
    /// put the ambulance the correct x,y location on
    /// a hospital roof or a grass tile.
    wxRealPoint mAmbulanceOffset;
    
    ///pointer to air ambilance
    std::shared_ptr<AirAmbulance> mAmbulance = nullptr;



protected:
    TileLandable(City *city);

public:
    /// Default constructor (disabled)
    TileLandable() = delete;

    /// Copy constructor (disabled)
    TileLandable(const TileLandable &) = delete;

    /// Assignment operator
    void operator=(const TileLandable &) = delete;

    /**
     * Get the ambulance offset relative to this tile.
     * @return Ambulance offset
     */
    const wxRealPoint &GetAmbulanceOffset() const {return mAmbulanceOffset;}

    /**
     * Set the ambulance offset relative to this tile.
     * @param x Ambulance X offset
     * @param y Ambulance Y offset
     */
    void SetAmbulanceOffset(double x, double y) {mAmbulanceOffset.x = x; mAmbulanceOffset.y = y;}

    void AirAmbulanceIsGone();
    void AirAmbulanceHasLanded();
    bool PendingDelete() override;
    /**
     * Gets the pointer to ambulance
     * @return mAbulance
     */
    auto GetAirAmbulance() { return mAmbulance;}
    /**
     * Sets the pointer to ambulance
     * @param ambulance
     */
    void SetAirAmbulance(std::shared_ptr<AirAmbulance> ambulance){mAmbulance = ambulance;}
    /**
     * updates tilelandable
     * @param elapsed
     */

    void Update(double elapsed) override;\
    /**
     * draws tilelandable
     * @param dc
     */
    void Draw(wxDC *dc) override;

    /**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
    void Accept(TileVisitor* visitor) override;
};

#endif //CITY_CITYLIB_TILELANDABLE_H
