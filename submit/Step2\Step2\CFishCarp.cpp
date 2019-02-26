
/**
 * \file FishAngel.cpp
 *
 * \author kunyu chen
 */

#include "stdafx.h"
#include "CFishCarp.h"
#include "Aquarium.h"
#include "Item.h"
#include <string>
using namespace Gdiplus;
using namespace std;

/// Minmum speed in the X direction in
 /// in pixels per second
const double MinSpeedX = 200;
/// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedX = 300;
/// Minmum speed in the Y direction in
 /// in pixels per second
const double MinSpeedY = -70;
/// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedY = 70;
/// Fish filename 
const wstring FishCarpImageName = L"images/carp.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishCarp::CFishCarp(CAquarium *aquarium) :
	CFish(aquarium, FishCarpImageName)
{
	double SpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	double SpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);
	SetSpeed(SpeedX, SpeedY);
}

/**
 * Destructor
 */
CFishCarp::~CFishCarp()
{
}



/**get carp's location
 * 
 * \param x X location
 * \param y Y location
 */
void CFishCarp::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
	auto mAquarium = CItem::GetAquarium();
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishCarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"carp");
	return itemNode;
}
