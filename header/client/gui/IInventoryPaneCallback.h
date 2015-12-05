#pragma once

namespace Touch
{
class InventoryPane;

class IInventoryPaneCallback
{
public:
	virtual ~IInventoryPaneCallback();
	virtual void addItem(const Touch::InventoryPane *, int) = 0;
	virtual bool isAllowed(int) = 0;
	virtual void getItems(const Touch::InventoryPane *) = 0;
};
};
