#pragma once

#include <vector>
#include "GuiElement.h"
#include "../../util/Vec3.h"

class ScrollBar;

// Size : 660
class ScrollingPane : public GuiElement
{
public:
	class GridItem
	{
	public:
	};

public:
	char filler1[552];	// 108

public:
	ScrollingPane();
	virtual ~ScrollingPane();
	virtual void renderBatch(std::vector<ScrollingPane::GridItem> &, float, float, float);
	virtual void renderItem(ScrollingPane::GridItem &, float);
	virtual void didEndDragging();
	virtual void didEndDecelerating();
	virtual void willBeginDecelerating();
	virtual void willBeginDragging();
	virtual void onSelect(int, bool);
	virtual void refreshItems();
	void _onSelect(int);
	void addDeltaPos(float, float, float, int);
	void adjustContentSize();
	void beginTracking(float, float, int);
	void contentOffset();
	void getColumns();
	void getContentOffset();
	void getGridItemFor_slow(int, ScrollingPane::GridItem &);
	void getItemForPos(float, float, bool);
	void getNumItems();
	void getRows();
	void getSelectedItemId();
	void getVerticleScrollBar();
	void handleUserInput();
	void hideScrollIndicators();
	void onHoldItem();
	void onNavigate();
	void queryHoldTime(int *, int *);
	void recalculateRows(int);
	void refreshPane();
	void render(int, int, float, MinecraftClient *);
	void scrollDownBy(float);
	void scrollUpBy(float);
	void setContentOffset(Vec3);
	void setContentOffset(float, float);
	void setContentOffsetWithAnimation(Vec3, bool);
	void setNumItems(int);
	void setRenderSelected(bool);
	void setSelected(int, bool);
	void shouldRenderSelected();
	void snapContentOffsetToBounds(bool);
	void startDecelerationAnimation(bool);
	void stepThroughDecelerationAnimation(bool);
	void stopDecelerationAnimation();
	void tick();
	void touchesBegan(float, float, int);
	void touchesCancelled(float, float, int);
	void touchesEnded(float, float, int);
	void touchesMoved(float, float, int);
	void translate(float, float);
	void updateHorizontalScrollIndicator();
	void updateScrollFade(ScrollBar &);
	void updateVerticalScrollIndicator();
};
