
#pragma once
//#include "Common.h"

#define CHARACTER_PATH "char_"
#define MONSTER_PATH "monster_"
#define HAIR_PATH "hair_"
#define WEAPON_PATH "weapon_"
#define SKILL_CASTER_PATH "caster_"
#define SKILL_LOCUS_PATH "locus_"
#define SKILL_EXPLOSION_PATH "explosion_"
#define NPC_PATH "npc_"

#define CHARACTER_ROUTE "character/"
#define MONSTER_ROUTE "monster/"
#define HAIR_ROUTE "hair/"
#define WEAPON_ROUTE "weapon/"
#define SKILL_ROUTE "skill/"
#define NPC_ROUTE "npc/"
#define OTHER_ROUTE "set/"
#define MUSIC_ROUTE "music/"

#define TEXTURE_SUFFIX	".plist"	
#define TEXTURE_PNG_SUFFIX  ".png"


//获取PATH的宏定义
#define THANPLE_GET_PATH(_suffix_) static std::string PATH(int num) \
	{\
	char str[10]; \
	sprintf(str, "%d", num); \
	return string(_suffix_) + str; };

//获取.plist所在文件路径
#define THANPLE_GET_PLIST_ROUTE(_route_,_suffix) static std::string PLIST_PATH(int num) \
	{\
	char str[10]; \
	sprintf(str, "%d", num); \
	return string(_route_) + string(_suffix) + str + string(TEXTURE_SUFFIX); };


namespace ResourceProvider
{
	//鼠标动画
	namespace MouseAction
	{
		const std::string PLIST_PATH = "ui/touch_mouse.plist";
		const std::string PATH = "touch_mouse";
	};

	class Character
	{
	public:
		typedef enum 
		{
			PLAYER_11001 = 11001,
			PLAYER_11002 = 11002,
			PLAYER_12001 = 12001,
			PLAYER_12002 = 12002,
			PLAYER_13001 = 13001,
			PLAYER_13002 = 13002,
			PLAYER_14001 = 14001,
			PLAYER_14002 = 14002,
			PLAYER_15001 = 15001,
			PLAYER_15002 = 15002,
			PLAYER_16001 = 16001,
			PLAYER_16002 = 16002,
		}Number;
		THANPLE_GET_PATH(CHARACTER_PATH);
		THANPLE_GET_PLIST_ROUTE(CHARACTER_ROUTE, CHARACTER_PATH);
	};

	class Monster
	{
	public:
		typedef enum
		{
			Monster_11001 = 11000,
			Monster_12000 = 12000,
			Monster_13000 = 13000,
			Monster_14000 = 14000,
			Monster_20000 = 20000,
			Monster_21000 = 21000,
			Monster_22000 = 22000,
			Monster_23000 = 23000,
			Monster_24000 = 24000,
			Monster_25000 = 25000,
			Monster_26000 = 26000,
			Monster_27000 = 27000,
			Monster_30000 = 30000,
			Monster_31000 = 31000,
			Monster_32000 = 32000,

			//下面的其实是人物
			Monster_40001 = 40001,
			Monster_40002 = 40002,
			Monster_40003 = 40003,
			Monster_40004 = 40004,
		}Number;
		THANPLE_GET_PATH(MONSTER_PATH);
		THANPLE_GET_PLIST_ROUTE(MONSTER_ROUTE, MONSTER_PATH);
	};

	class Hair
	{
	public:
		typedef enum
		{
			Hair_10001 = 10001,
			Hair_10002 = 10002,
			Hair_11001 = 11001,
			Hair_11002 = 11002,
			Hair_12001 = 12001,
			Hair_12002 = 12002,
		}Number;
		THANPLE_GET_PATH(HAIR_PATH);
		THANPLE_GET_PLIST_ROUTE(HAIR_ROUTE, HAIR_PATH);
	};

	class Weapon
	{
	public:
		typedef enum
		{
			Weapon_10000 = 10000,
			Weapon_11000 = 11000,
			Weapon_12000 = 12000,
			Weapon_13000 = 13000,
			Weapon_14000 = 14000,
			Weapon_15000 = 15000,
		}Number;
		THANPLE_GET_PATH(WEAPON_PATH);
		THANPLE_GET_PLIST_ROUTE(WEAPON_ROUTE, WEAPON_PATH);
	};

	class Npc
	{
	public:
		typedef enum
		{
			Npc_10113 = 10113,
			Npc_10114 = 10114,
			Npc_10115 = 10115,
			Npc_10213 = 10213,
			Npc_10214 = 10214,
			Npc_10215 = 10215,
		} Number;
		THANPLE_GET_PATH(NPC_PATH);
		THANPLE_GET_PLIST_ROUTE(NPC_ROUTE, NPC_PATH);
	};

	class Skill
	{
	public:
		typedef enum
		{
			Skill_1 = 11,
			Skill_2 = 13,
			Skill_3 = 15,
			Skill_4 = 12,
		} Number;
		THANPLE_GET_PATH(SKILL_EXPLOSION_PATH);
		THANPLE_GET_PLIST_ROUTE(SKILL_ROUTE, SKILL_EXPLOSION_PATH);
	};



	namespace MUSIC
	{
		const char ATTACK[] = "music/gongjiyouxiao.mp3";
		const char SKILL_1[] = "music/jiaodao3.mp3";
		const char SKILL_2[] = "music/6feibiao.mp3";
		const char SKILL_3[] = "music/2chuan.mp3";
		const char SKILL_4[] = "music/dici.mp3";

		const char MONSTER_ATTACK[] = "music/dajianpugong4.mp3";
		const char MONSTER_GIRL[] = "music/nvpugong4.mp3";

		const char LOGIN_BACKMUSIC[] = "music/logn.mp3";
		const char LOGIN_ACCTACK_MAN[] = "music/nantiaogong.mp3";
		const char LOGIN_ATTACK_GIRL[] = "music/nvpugong4.mp3";

		const char GAME_SCENE_MUSIC[] = "music/dali.mp3";

		const char FIGHT_SCENE_MUSIC[] = "music/bossmusic.mp3";
		
	};


};
