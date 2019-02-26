/**
 * \file DecorCastle.h
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
 * add castle
 */
class CDecorCastle :
	public CItem
{
public:
	CDecorCastle(CAquarium *aquarium);

	/// Default constructor (disabled)
	CDecorCastle() = delete;

	/// Copy constructor (disabled)
	CDecorCastle(const CDecorCastle &) = delete;
	/// save fish.
	///return itemNode
	virtual std::shared_ptr<xmlnode::CXmlNode>
		XmlSave(const std::shared_ptr<xmlnode::CXmlNode> &node) override;
	
	virtual ~CDecorCastle();
};

