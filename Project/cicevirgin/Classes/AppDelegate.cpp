#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "scene\GameScene.h"
#include "scene\FightScene.h"
#include "scene\LoginScene.h"

#include "util\MyProtoSocket.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate() 
{
}

//if you want a different context,just modify the value of glContextAttrs
//it will takes effect on all platforms
void AppDelegate::initGLContextAttrs()
{
    //set OpenGL context attributions,now can only set six attributions:
    //red,green,blue,alpha,depth,stencil
    GLContextAttrs glContextAttrs = {8, 8, 8, 8, 24, 8};

    GLView::setGLContextAttrs(glContextAttrs);
}

bool AppDelegate::applicationDidFinishLaunching() {
    // initialize director
    auto director = Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview) {
        glview = GLViewImpl::createWithRect("IceVirgin", Rect(0, 0, 800, 500));
        director->setOpenGLView(glview);
		int i = 0;
    }

    director->getOpenGLView()->setDesignResolutionSize(800, 500, ResolutionPolicy::SHOW_ALL);

    // turn on display FPS
    //director->setDisplayStats(true);

    // set FPS. the default value is 1.0/60 if you don't call this
    director->setAnimationInterval(1.0 / 60);

    FileUtils::getInstance()->addSearchPath("res");

	//开启网络
	MyProtoSocket::connect();

    // create a scene. it's an autorelease object
	//auto * layer = GameScene::create();
	//auto * layer = FightScene::create();
	auto * layer = LoginScene::create();
	auto scene = Common::scene(layer);

    // run
    director->runWithScene(scene);

	//子线程无法更新UI
	std::thread threadRecv(&AppDelegate::recev, this);
	threadRecv.detach();

    return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground() {
    Director::getInstance()->stopAnimation();

    // if you use SimpleAudioEngine, it must be pause
    // SimpleAudioEngine::getInstance()->pauseBackgroundMusic();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground() {
    Director::getInstance()->startAnimation();

    // if you use SimpleAudioEngine, it must resume here
    // SimpleAudioEngine::getInstance()->resumeBackgroundMusic();
}

void AppDelegate::recev()
{
	while (true)
	{
		//Sleep(10);
		MyProtoSocket::receive();
	}

}
