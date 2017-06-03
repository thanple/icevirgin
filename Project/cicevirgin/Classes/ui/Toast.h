#pragma once
#include "Common.h"

class Toast : public Layer {
public:
	Toast();
	~Toast();
	virtual bool init();
	CREATE_FUNC(Toast);
	static Toast* create(const char* text, int fontsize = 30, float time = 1);
private:
	//ÉèÖÃÎÄ×Ö
	void setText(const char* text, int fontsize, float time);
	//ÉèÖÃ±³¾°
	void setBackgound();
	//É¾³ı
	void removeSelf();
private:
	LayerColor *m_backgound;
	Label *m_label;
};