/**
 * \file Fish.h
 *
 * \author kunyu chen
 *
 *
 */

#pragma once
#include "Item.h"
#include "XmlNode.h"

using namespace std;
 /**
   * Base class for a fish
   * This applies to all of the fish, but not the decor
   * items in the aquarium.
  */
class CFish :
	public CItem
{
public:
	/// Default constructor (disabled)
	CFish() = delete;

	/// Copy constructor (disabled)
	CFish(const CFish &) = delete;
	virtual ~CFish();

	void CFish::Update(double elapsed);
	/* load fish.
	* \return itemNode
	*/
	shared_ptr<xmlnode::CXmlNode>XmlSave(const shared_ptr<xmlnode::CXmlNode> &node);
	/* load fish.
	* \return itemNode
	*/
	void CFish::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);
	///setting speed
	void SetSpeed(double x, double y) { mSpeedX = x; mSpeedY = y; }
	///get speedx 
	double Getspeedx() {return mSpeedX; }
	///get speedy
	double Getspeedy() { return mSpeedY; }

protected:
	CFish(CAquarium *aquarium, const std::wstring &filename);

private:
	/// Fish speed in the X direction
	double mSpeedX;

	/// Fish speed in the Y direction
	double mSpeedY;
};
