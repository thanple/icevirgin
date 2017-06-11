
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


	//�رհ�ť
	Button * closeBtn = dynamic_cast<Button*>(rootNode->getChildByName("Close"));
	closeBtn->addTouchEventListener(CC_CALLBACK_2(PvpShowUI::onCloseModal, this));

	//��������
	Button * onCreateRoom = dynamic_cast<Button*>(rootNode->getChildByName("CreateRoom"));
	onCreateRoom->addTouchEventListener(CC_CALLBACK_2(PvpShowUI::onCreateRoom, this));

	//ListView��ʾ����PVP�ķ���
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

				//��ʾ������
				TextBMFont * fontText = TextBMFont::create();
				string roomLabel = to_string(item.instanceid());
				roomLabel += "����";
				fontText->setText(Common::FontToUTF8(roomLabel.c_str()));
				fontText->setContentSize(Size(100, 30));
				fontText->setPosition(Size(70, 0));

				//��ť
				Button * enterRoomBtn = Button::create("res/public_btn_menu2.png", "res/public_btn_menu2_sele.png","res/public_btn_menu2_sele.png");
				enterRoomBtn->setName("Title Button");
				if (item.status() == 1)
				{
					enterRoomBtn->setTitleText(Common::FontToUTF8("���뷿��"));
					enterRoomBtn->addTouchEventListener([item](Ref* pSender, Widget::TouchEventType type){
						CEnterPvpRoom enterRoom;
						enterRoom.set_instanceid(item.instanceid());
						MyProtoSocket::send(1030, enterRoom.SerializeAsString());
					});
				}
				else
				{
					enterRoomBtn->setTitleText(Common::FontToUTF8("��������"));
					enterRoomBtn->setTouchEnabled(false);
					enterRoomBtn->setEnabled(false);
				}
				
				enterRoomBtn->setScale9Enabled(true);
				enterRoomBtn->setContentSize(Size(50, 30));
				enterRoomBtn->setPosition(Size(150, 0));

				//Ҫͨ��Layout��ӵ�ListView��
				Layout * itemLayout = Layout::create();
				itemLayout->setContentSize(Size(200, 30));
				itemLayout->setPosition(Point(300, 0) );
				itemLayout->addChild(fontText);
				itemLayout->addChild(enterRoomBtn);

				//���뵽ListView��
				Point p1 = pvpRooms->getPosition();
				Point p2 = itemLayout->getPosition();
				pvpRooms->insertCustomItem(itemLayout, count++);

				//���ﲻ����addChild���������ִ�λ���⣬�����޽�
				//������init�����е���addChild�ֿ��ԣ���schedule�п����ʣ��󲿷�������Ǵ�λ
				//��ʹ�����ڴ��˷ѵ�2��Сʱ��ʱ����ǽ�Ǯ����˵�� ---2017-6-9
				//pvpRooms->addChild(itemLayout);
			}

			m_rooms = SRequestPvpRooms();
		}


		//�յ�������������뷿��
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


	//����
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

	//��һ�������ʱ����Ȼ�رպ���Զ�Ѱ·��
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