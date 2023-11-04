#include <pch.h>
#include "gtest/gtest.h"

#include <City.h>
#include <TileLandscape.h>
#include <TileBuilding.h>
#include <TileHospital.h>
#include <TileGrass.h>

TEST(CityTest, Adjacent)
{
    City city;
    int grid = City::GridSpacing;

    // Add a center tile to test
    auto center = std::make_shared<TileHospital>(&city);
    center->SetLocation(grid * 10, grid * 17);
    city.Add(center);

    // Upper left
    auto ul = std::make_shared<TileHospital>(&city);
    ul->SetLocation(grid * 8, grid * 16);
    city.Add(ul);
    city.SortTiles();

    ASSERT_EQ(ul, city.GetAdjacent(center, -1, -1)) << L"Upper left test";
    ASSERT_EQ(nullptr,city.GetAdjacent(center, 1, -1)) << L"Upper right null test";

    // Upper right
    auto ur = std::make_shared<TileHospital>(&city);
    ur->SetLocation(grid * 12, grid * 16);
    city.Add(ur);

    // Lower left
    auto ll = std::make_shared<TileHospital>(&city);
    ll->SetLocation(grid * 8, grid * 18);
    city.Add(ll);

    // Lower right
    auto lr = std::make_shared<TileHospital>(&city);
    lr->SetLocation(grid * 12, grid * 18);
    city.Add(lr);

    city.SortTiles();

    ASSERT_EQ(ur, city.GetAdjacent(center, 1, -1)) << L"Upper right test";
    ASSERT_EQ(ll, city.GetAdjacent(center, -1, 1)) << L"Lower left test";
    ASSERT_EQ(lr, city.GetAdjacent(center, 1, 1)) << L"Lower right test";
}
class TestVisitor : public TileVisitor
{
public:
    virtual void VisitBuilding(TileBuilding* build) override { mNumBuildings++; }
    virtual void VisitLandscape(TileLandscape* build) override { mNumLandscapes++; }
    virtual void VisitGrass(TileGrass* build) override { mNumGrass++; }
    virtual void VisitHospital(TileHospital* build) override { mNumHospitals++; }

    int mNumBuildings = 0;
    int mNumLandscapes = 0;
    int mNumGrass = 0;
    int mNumHospitals = 0;
};

TEST(CityTest, Iterator)
{
    // Construct a city object
    City city;

    // Add some tiles
    auto tile1 = std::make_shared<TileHospital>(&city);
    auto tile2 = std::make_shared<TileHospital>(&city);
    auto tile3 = std::make_shared<TileHospital>(&city);

    city.Add(tile1);
    city.Add(tile2);
    city.Add(tile3);

    // Begin points to the first item
    auto iter1 = city.begin();

    // End points after the last item
    auto iter2 = city.end();

    ASSERT_EQ(tile1, *iter1) << L"First item correct";
    ++iter1;
    ASSERT_EQ(tile2, *iter1) << L"Second item correct";
    ++iter1;
    ASSERT_EQ(tile3, *iter1) << L"Third item correct";
    ++iter1;
    ASSERT_FALSE(iter1 != iter2);

}

TEST(CityTest, Visitor)
{
    // Construct a city object
    City city;

    // Add some tiles of each type
    auto tile1 = std::make_shared<TileGrass>(&city);
    auto tile2 = std::make_shared<TileBuilding>(&city);
    auto tile3 = std::make_shared<TileLandscape>(&city);
    auto tile4 = std::make_shared<TileHospital>(&city);

    city.Add(tile1);
    city.Add(tile2);
    city.Add(tile3);
    city.Add(tile4);

    TestVisitor visitor;
    city.Accept(&visitor);
    ASSERT_EQ(1, visitor.mNumBuildings) <<
                                        L"Visitor number of buildings";
    ASSERT_EQ(1, visitor.mNumLandscapes) <<
                                        L"Visitor number of Landscapes";
    ASSERT_EQ(1, visitor.mNumGrass) <<
                                         L"Visitor number of Grass";
    ASSERT_EQ(1, visitor.mNumHospitals) <<
                                         L"Visitor number of Hospitals";
}

