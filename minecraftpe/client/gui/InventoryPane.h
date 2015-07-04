#pragma once

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
};

}
