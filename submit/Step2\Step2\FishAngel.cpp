/**
 * \file FishAngel.cpp
 *
 * \author kunyu chen
 */

#include "stdafx.h"
#include "FishAngel.h"
#include <string>
using namespace Gdiplus;
using namespace std;

/// Minmum speed in the X direction in
 /// in pixels per second
const double MinSpeedX = 100;
/// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedX = 200;
/// Minmum speed in the Y direction in
 /// in pixels per second
const double MinSpeedY = -200;
/// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedY = 300;

/// Fish filename 
const wstring FishAngelImageName = L"images/angelfish.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishAngel::CFishAngel(CAquarium *aquarium) :
	CFish(aquarium, FishAngelImageName)
{
	double SpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	double SpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);
	SetSpeed(SpeedX, SpeedY);
}

/**
 * Destructor
 */
CFishAngel::~CFishAngel()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishAngel::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"angel");
	return itemNode;
}
