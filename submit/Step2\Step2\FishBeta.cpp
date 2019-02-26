/**
 * \file FishBeta.cpp
 *
 * \author kunyu chen
 */

#include "stdafx.h"
#include "FishBeta.h"
#include "Item.h"
#include "XmlNode.h"
#include <string>
using namespace Gdiplus;
using namespace std;


/// Minmum speed in the X direction in
/// in pixels per second
const double MinSpeedX = 90;
/// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedX = 50;
/// Minmum speed in the Y direction in
 /// in pixels per second
const double MinSpeedY = -50;
/// Maximum speed in the X direction in
 /// in pixels per second
const double MaxSpeedY = 50;

 /// Fish filename 
const wstring FishBetaImageName = L"images/beta.png";

/** Constructor
 * \param aquarium The aquarium this is a member of
*/
CFishBeta::CFishBeta(CAquarium *aquarium) :
	CFish(aquarium, FishBetaImageName)
{
	double SpeedX = MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX);
	double SpeedY = MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY);
	SetSpeed(SpeedX, SpeedY);
}

/**
 * Destructor
 */
CFishBeta::~CFishBeta()
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return itemNode
 */
std::shared_ptr<xmlnode::CXmlNode>
CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
	auto itemNode = CFish::XmlSave(node);
	itemNode->SetAttribute(L"type", L"beta");
	return itemNode;
}
