
#include "PvpShowUI.h"
#include "protocol\CRequestPvpRooms.pb.h"
#include "protocol\CRequestFight.pb.h"
#include "util\MyProtoSocket.h"
#include "scene\PvpFightScene.h"
#include "protocol\SEnterPvpRoom.pb.h"
#include "protocol\CEnterPvpRoom.pb.h"


PvpShowUI::PvpShowUI() : rootNode(NULL) 
{
	m_join = false;
}
PvpShowUI::~PvpShowUI()
{

}
bool PvpShowUI::init()
{
	if (!Layer::init())
		return false;

	//rootNode
	auto rootNode = CSLoader::createNode("PvpShow.csb");
	this->rootNode = rootNode;
	this->addChild(rootNode);


	//关闭按钮
	Button * closeBtn = dynamic_cast<Button*>(rootNode->getChildByName("Close"));
	closeBtn->addTouchEventListener(CC_CALLBACK_2(PvpShowUI::onCloseModal, this));

	//创建房间
	Button * onCreateRoom = dynamic_cast<Button*>(rootNode->getChildByName("CreateRoom"));
	onCreateRoom->addTouchEventListener(CC_CALLBACK_2(PvpShowUI::onCreateRoom, this));

	//ListView显示所有PVP的房间
	this->schedule([this](float f)
	{
		if (m_rooms.rooms().size() > 0)
		{
			ListView * pvpRooms = dynamic_cast<ListView *>(this->rootNode->getChildByName("ListView"));
			pvpRooms->removeAllChildren();

			int count = 0;
			for (::google::protobuf::RepeatedPtrField<::SRequestPvpRooms_Item>::const_iterator & it
				= m_rooms.rooms().begin(); it != m_rooms.rooms().end(); it++)
			{
				::SRequestPvpRooms_Item item = *it;

				//显示房间名
				TextBMFont * fontText = TextBMFont::create();
				string roomLabel = to_string(item.instanceid());
				roomLabel += "房间";
				fontText->setText(Common::FontToUTF8(roomLabel.c_str()));
				fontText->setContentSize(Size(100, 30));
				fontText->setPosition(Size(70, 0));

				//按钮
				Button * enterRoomBtn = Button::create("res/public_btn_menu2.png", "res/public_btn_menu2_sele.png","res/public_btn_menu2_sele.png");
				enterRoomBtn->setName("Title Button");
				if (item.status() == 1)
				{
					enterRoomBtn->setTitleText(Common::FontToUTF8("进入房间"));
					enterRoomBtn->addTouchEventListener([item](Ref* pSender, Widget::TouchEventType type){
						CEnterPvpRoom enterRoom;
						enterRoom.set_instanceid(item.instanceid());
						MyProtoSocket::send(1030, enterRoom.SerializeAsString());
					});
				}
				else
				{
					enterRoomBtn->setTitleText(Common::FontToUTF8("房间已满"));
					enterRoomBtn->setTouchEnabled(false);
					enterRoomBtn->setEnabled(false);
				}
				
				enterRoomBtn->setScale9Enabled(true);
				enterRoomBtn->setContentSize(Size(50, 30));
				enterRoomBtn->setPosition(Size(150, 0));

				//要通过Layout添加到ListView中
				Layout * itemLayout = Layout::create();
				itemLayout->setContentSize(Size(200, 30));
				itemLayout->setPosition(Point(300, 0) );
				itemLayout->addChild(fontText);
				itemLayout->addChild(enterRoomBtn);

				//加入到ListView中
				Point p1 = pvpRooms->getPosition();
				Point p2 = itemLayout->getPosition();
				pvpRooms->insertCustomItem(itemLayout, count++);

				//这里不能用addChild，否则会出现错位问题，至今无解
				//但是在init方法中调用addChild又可以，在schedule中看概率，大部分情况都是错位
				//沉痛纪念在此浪费的2个小时，时间就是金钱，不说了 ---2017-6-9
				//pvpRooms->addChild(itemLayout);
			}

			m_rooms = SRequestPvpRooms();
		}


		//收到服务器命令加入房间
		if (m_join)
		{
			auto fightScene = PvpFightScene::create();
			fightScene->setButtonEnabled(false);
			Character * character = fightScene->getPlayer();
			Player * player = Player::sharePlayer();
			character->setRoleId(player->getRoleId());
			character->pBody->setFigureId(player->pBody->getFigureId());
			character->pHair->setFigureId(player->pHair->getFigureId());
			character->pWeapon->setFigureId(player->pWeapon->getFigureId());
			character->setIState(CharacterStateType::FStateStand);
			character->setDirectionType(CharacterDirectionType::FDirDownAndLeft);

			Director::getInstance()->replaceScene(Common::scene(fightScene));
		}


	}, 0.8f,"pvpShowUI");


	//隐藏
	this->setVisible(false);
	m_iShow = false;

	return true;
}



void PvpShowUI::displayModal()
{
	this->setVisible(true);
	m_iShow = true;

	ListView * pvpRooms = dynamic_cast<ListView *>(rootNode->getChildByName("ListView"));
	pvpRooms->removeAllChildren();

	MyProtoSocket::send(1027, CRequestPvpRooms().SerializeAsString());

}
void PvpShowUI::onCloseModal(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	this->setVisible(false);

	//这一块必须延时，不然关闭后就自动寻路了
	this->scheduleOnce([this](float f){
		m_iShow = false;
	}, 0.5f, "closeModalPvpShowUI");
}

void PvpShowUI::onCreateRoom(Ref* pSender, Widget::TouchEventType type)
{
	if (type != Widget::TouchEventType::BEGAN)	return;
	CRequestFight request;
	request.set_fighthtype(2);
	request.set_fighthid(-1);

	MyProtoSocket::send(1009, request.SerializeAsString());

	auto fightScene = PvpFightScene::create();
	Character * character = fightScene->getPlayer();
	Player * player = Player::sharePlayer();
	character->setRoleId(player->getRoleId());
	character->pBody->setFigureId(player->pBody->getFigureId());
	character->pHair->setFigureId(player->pHair->getFigureId());
	character->pWeapon->setFigureId(player->pWeapon->getFigureId());
	character->setIState(CharacterStateType::FStateStand);
	character->setDirectionType(CharacterDirectionType::FDirDownAndLeft);

	Director::getInstance()->replaceScene(Common::scene(fightScene));
}