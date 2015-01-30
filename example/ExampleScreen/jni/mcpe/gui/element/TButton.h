#ifndef __TBUTTON_H__
#define __TBUTTON_H__

#include "Button.h"

class MinecraftClient;

namespace Touch {
	class TButton : public Button {
	public:
		// Size : 128
		void *_ninepathLayer1;		// 120
		void *_ninepathLayer2;		// 124

		TButton(int, int, int, int, int, const std::string &);
		TButton(int, int, int, const std::string &, MinecraftClient *);
		TButton(int, const std::string &, MinecraftClient *, bool);
		virtual ~TButton();
		virtual void renderBg(MinecraftClient *, int, int);
		void init(MinecraftClient *);
	};
}

#endif
