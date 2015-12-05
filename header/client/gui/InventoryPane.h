#pragma once

#include "ScrollingPane.h"
#include "../AppPlatformListener.h"

namespace Controller
{
	class StickDirection;
}

class IntRectangle;
class ItemInstance;

namespace Touch
{

// Size : 896
class InventoryPane : public ScrollingPane, public AppPlatformListener
{
public:
	char filler1[236];	// 660

public:
	InventoryPane(Touch::IInventoryPaneCallback *, MinecraftClient &, const IntRectangle &, int, float, int, int, int, bool, bool, bool);
	virtual ~InventoryPane();
	virtual void renderBatch(std::vector<ScrollingPane::GridItem> &, float, float, float);
	virtual void onSelect(int, bool);
	virtual void refreshItems();
	virtual void onAppSuspended();
	virtual void onAppResumed();
	void buildInventoryItemsChunk(std::vector<const ItemInstance *> &, ItemRenderChunkType);
	void drawRectangleOnSelectedItem(ScrollingPane::GridItem &);
	void drawScrollBar(ScrollBar &);
	void onSelectItem();
	void renderSelectedItem(std::vector<ScrollingPane::GridItem> &, std::vector<const ItemInstance *>, Tessellator &, ScrollingPane::GridItem *&, float &, float &);
	void setControllerDirection(Controller::StickDirection);
	void setRenderDecorations(bool);
	void tick();
};

};
