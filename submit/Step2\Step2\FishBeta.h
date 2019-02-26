/**
 * \file FishBeta.h
 *
 * \author kunyu chen
 *
 * Class the implements a Beta fish
 */

#pragma once
#include <memory>
#include "Item.h"
#include"Fish.h"

 /**
  * Implements a Beta fish
  */
class CFishBeta : public CFish
{
public:
	CFishBeta(CAquarium *aquarium);

	/// Default constructor (disabled)
	CFishBeta() = delete;

	/// Copy constructor (disabled)
	CFishBeta(const CFishBeta &) = delete;
	/* load fish.
	* \return itemNode
	*/
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;

	virtual  ~CFishBeta();
};

