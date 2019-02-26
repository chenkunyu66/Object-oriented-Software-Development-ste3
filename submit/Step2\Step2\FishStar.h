/**
 * \file FishStar.h
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
 * Implements a star fish
 */
class CFishStar :
	public CFish
{
public:
	CFishStar(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishStar() = delete;

	/// Copy constructor (disabled)
	CFishStar(const CFishStar &) = delete;
	/* load fish.
	* \return itemNode
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual ~CFishStar();

};

