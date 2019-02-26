/**
 * \file FishStar.cpp
 *
 * \author kunyu chen
 */


/**
 * \file FishAngel.cpp
 *
 * \author kunyu chen
 */

#include "stdafx.h"
#include "FishStar.h"
#include <string>
using namespace Gdiplus;
using namespace std;

/// Minmum speed in the X direction in
 /// in pixels per second
const double MinSpeedX = 5;
/// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedX = 30;
/// Minmum speed in the Y direction in
 /// in pixels per second
const double MinSpeedY = -10;
/// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedY = 10;

/// Fish filename 
const wstring FishStarImageName = L"images/starfish.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishStar::CFishStar(CAquarium *aquarium) :
	CFish(aquarium, FishStarImageName)
{
	double SpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	double SpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);
	SetSpeed(SpeedX, SpeedY);
}


/**
 * Destructor
 */
CFishStar::~CFishStar()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishStar::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"star");
	return itemNode;
}

