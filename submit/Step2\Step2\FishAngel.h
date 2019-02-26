/**
 * \file FishAngel.h
 *
 * \author kunyu chen
 *
 * 
 */

#pragma once
#include <memory>
#include "Item.h"
#include"Fish.h"
 /**
   * Implements a angel fish
   */
class CFishAngel :
	public CFish
{
public:
	CFishAngel(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishAngel() = delete;

	/// Copy constructor (disabled)
	CFishAngel(const CFishAngel &) = delete;
	/* load fish.
	* \return itemNode
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	virtual ~CFishAngel();

};

