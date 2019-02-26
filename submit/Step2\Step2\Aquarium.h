/**
 * \file Aquarium.h
 *
 * \author kunyu chen
 *
 * 
 */

#pragma once
#include<memory>
#include<vector>
#include "XmlNode.h"

class CItem;
using namespace std;


/**
 * window Aquarium draw itself
 */
class CAquarium
{
public:
	CAquarium();
	virtual ~CAquarium();
	void OnDraw(Gdiplus::Graphics * graphics);
	void Add(std::shared_ptr<CItem> item);
	std::shared_ptr<CItem> HitTest(int x, int y);
	void CAquarium::Findfish(std::shared_ptr<CItem> item);
	void CAquarium::KillFish(CItem * item);
	void CAquarium::Save(const std::wstring &filename);
	void CAquarium::Load(const std::wstring &filename);
	void CAquarium::Clear();
	void CAquarium::Update(double elapsed);
	/// Get the width of the aquarium
	/// \returns Aquarium width
	int GetWidth() const { return mBackground->GetWidth(); }

	/// Get the height of the aquarium
	/// \returns Aquarium height
	int GetHeight() const { return mBackground->GetHeight(); }

private:
	///Creat file of item. 
	void CAquarium::XmlItem(const shared_ptr<xmlnode::CXmlNode> &node);
	std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image
	/// All of the items to populate our aquarium
	std::vector<std::shared_ptr<CItem> > mItems;
};

