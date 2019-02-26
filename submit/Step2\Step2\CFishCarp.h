
/**
 * \file FishAngel.h
 *
 * \author kunyu chen
 *
 *
 */

#pragma once
#include "Item.h"
#include"Fish.h"

 /**
   * Implements a carp fish
   */
class CFishCarp :
	public CFish
{
public:
	CFishCarp(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishCarp() = delete;

	/// Copy constructor (disabled)
	CFishCarp(const CFishCarp &) = delete;
	/* load fish.
	* \return itemNode
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual ~CFishCarp();
	virtual void CFishCarp::SetLocation(double x, double y);
};
