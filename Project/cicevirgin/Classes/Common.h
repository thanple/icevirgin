#pragma once

//c++ standard
#include <iostream>
#include <fstream>
using namespace std;

//cocos2d��Ҫ��������
#include "cocos2d.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "cocostudio/CocoStudio.h"  
#include "ui/CocosGUI.h"  
using namespace cocostudio::timeline;
USING_NS_CC;
USING_NS_CC_EXT;
using namespace cocos2d::ui;
using namespace CocosDenshion;



//protobuff����lib
#pragma comment(lib, "libprotobuf.lib")  
#pragma comment(lib, "libprotoc.lib")  

//��Ҫ�����Ĺ�������
#include "util\ResourceProvider.h"


//���ڴ�С�궨��
#define winSize CCDirector::sharedDirector()->getWinSize()

#define TAG_ANIMATE 0xfffffff0
#define TAG_MOVET 0xfffffff1
#define TAG_MOUSE_ACTION 0xfffffff2

//���巽��
typedef enum
{
	FDirUp = 8,
	FDirLeftAndUp = 7,
	FDirLeft = 6,
	FDirDownAndLeft = 5,
	FDirDown = 4,
	FDirRightAndDown = 3,
	FDirRight = 2,
	FDirUpAndRight = 1,
	FDirNone = 0
}CharacterDirectionType;



//����texture��·������
typedef enum
{
	TexturePathFigure = 1,
	TexturePathMonster = 2,
	TexturePathHair = 3,
	TexturePathWeapon = 4,
	TexturePathSkillCaster = 5,
	TexturePathSkillLocus = 6,
	TexturePathSkillExplosion = 7
}TexturePathType;

/*
���������ͱ���
*/
struct Common
{
	/*
	����Layer����Scene
	*/
	static CCScene* scene(CCLayer* layer)
	{

		// 'scene' is an autorelease object
		auto scene = CCScene::create();

		// 'layer' is an autorelease object
		// add layer as a child to scene
		scene->addChild(layer);

		// return the scene
		return scene;

	}
	static void moveNode(CCNode* node, CCPoint pt)
	{
		node->setPosition(node->getPosition() + pt);
	}
	static char* format(int v, const char* prefix = "", const char* suffix = "")
	{
		static char buf[2048];
		sprintf(buf, "%s%d%s", prefix, v, suffix);
		return buf;
	}

	/**
	* ��������δ�и��ͼƬ����һ������
	*/
	static CCAnimation* createAnimation(const char* filename, int start, int end, int width, float delay)
	{
		CCTexture2D * texture = CCTextureCache::sharedTextureCache()->addImage(filename);
		Vector<CCSpriteFrame *> * spriteFrameVector = new Vector<CCSpriteFrame *>();
		for (int i = start; i <= end; ++i)
		{
			CCSpriteFrame* frame = CCSpriteFrame::createWithTexture(texture, CCRectMake(i*width, 0, width, texture->getContentSize().height));
			spriteFrameVector->pushBack(frame);
		}

		return CCAnimation::createWithSpriteFrames(*spriteFrameVector, delay);
	}

	static ActionInterval *  createActionsFromCache(std::string path, int startIndex = 1, float rate = 0.06f)
	{
		Vector<SpriteFrame *> spriteFrames;
		int flag = startIndex;
		do
		{
			CCString * string = CCString::createWithFormat("%s_%02d.png", path.c_str(), flag);
			CCSpriteFrame* spriteFrame = CCSpriteFrameCache::sharedSpriteFrameCache()->spriteFrameByName(string->getCString());
			CC_BREAK_IF(spriteFrame == NULL);

			spriteFrames.pushBack(spriteFrame);
			flag++;
		} while (1);

		Animation * action = Animation::createWithSpriteFrames(spriteFrames, rate);
		return Animate::create(action);
	}


	static char * FontToUTF8(const char* font)
	{
		int len = MultiByteToWideChar(CP_ACP, 0, font, -1, NULL, 0);
		wchar_t *wstr = new wchar_t[len + 1];
		memset(wstr, 0, len + 1);
		MultiByteToWideChar(CP_ACP, 0, font, -1, wstr, len);
		len = WideCharToMultiByte(CP_UTF8, 0, wstr, -1, NULL, 0, NULL, NULL);
		char *str = new char[len + 1];
		memset(str, 0, len + 1);
		WideCharToMultiByte(CP_UTF8, 0, wstr, -1, str, len, NULL, NULL);
		if (wstr)delete[] wstr;
		return str;
	}
};
