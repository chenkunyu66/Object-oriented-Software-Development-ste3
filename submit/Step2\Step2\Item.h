/**
 * \file Item.h
 *
 * \author kunyu chen
 *
 * Base class for any item in our aquarium.
 */

#pragma once
#include <string>
#include <memory>
#include "Item.h"
#include "XmlNode.h"
class CAquarium;
/**
 * Base class for any item in our aquarium.
 */
class CItem
{
public:
	/// Default constructor (disabled)
	CItem() = delete;

	/// Copy constructor (disabled)
	CItem(const CItem &) = delete;

	///CItem();
	virtual ~CItem();
	/** The X location of the item
	 * \returns X location in pixels */
	double GetX() const { return mX; }

	/** The Y location of the item
	* \returns Y location in pixels */
	double GetY() const { return mY; }

	/// Set the item location
	/// \param x X location
	/// \param y Y location
	virtual void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Draw this item
	/// \param graphics Graphics device to draw on
	virtual void Draw(Gdiplus::Graphics *graphics);

	virtual bool HitTest(int x, int y);
	/// save fish.
	/// \return itemNode
	virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node);

	virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode> &node);
	/// Handle updates for animation
	/// \param elapsed The time since the last update
	virtual void Update(double elapsed) {}
	
	/// Get the aquarium this item is in
	/// \returns Aquarium pointer
	CAquarium *GetAquarium() { return mAquarium; }
	///getter to get width of item 
	double GetWidth() { return mItemImage->GetWidth(); }
	///getter to get hight of item
	double GetHight() { return mItemImage->GetHeight(); }

	/// Set the mirror status
	/// \param m New mirror flag
	void SetMirror(bool m) { mMirror = m; }

protected:
	/// The aquarium this item is contained in
	///param filename file for saving data
	CItem(CAquarium *aquarium, const std::wstring &filename);
	

private:
	/// The aquarium this item is contained in
	CAquarium   *mAquarium;
	// Item location in the aquarium
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item
	bool mMirror = false;   ///< True mirrors the item image
	/// The image of this fish
	std::unique_ptr<Gdiplus::Bitmap> mItemImage;
	
};
 
