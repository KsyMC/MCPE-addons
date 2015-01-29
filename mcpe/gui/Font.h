#ifndef __FONT_H__
#define __FONT_H__

#include "../AppPlatformListener.h"

class Font : public AppPlatformListener {
public:
	Font();
	virtual ~Font();
	virtual void onAppSuspended();
	int width(const std::string &);
	int height(const std::string &, int);
	float getPixelLength(const std::string &) const;
};

#endif
