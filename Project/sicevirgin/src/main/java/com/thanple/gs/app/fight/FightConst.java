package com.thanple.gs.app.fight;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Thanple on 2017/6/1.
 */

public class FightConst {


    public static int FIGHT_TYPE_MONSTER = 1;
    public static int FIGHT_TYPE_USER = 2;

    public static final int NORMAL_ATTACK = 0;
    public static final int SKILL_1 = 11;
    public static final int SKILL_2 = 13;
    public static final int SKILL_3 = 15;
    public static final int SKILL_4 = 12;


    /*
    * 纯怪物配置
    * */
    public static final int Monster_11001 = 11000;
    public static final int Monster_12000 = 12000;
    public static final int Monster_13000 = 13000;
    public static final int Monster_14000 = 14000;
    public static final int Monster_20000 = 20000;
    public static final int Monster_21000 = 21000;
    public static final int Monster_22000 = 22000;
    public static final int Monster_23000 = 23000;
    public static final int Monster_24000 = 24000;
    public static final int Monster_25000 = 25000;
    public static final int Monster_26000 = 26000;
    public static final int Monster_27000 = 27000;
    public static final int Monster_30000 = 30000;
    public static final int Monster_31000 = 31000;
    public static final int Monster_32000 = 32000;

    public static List<Integer> monsters = new ArrayList<>();

    static {
        monsters.add(Monster_11001);
        monsters.add(Monster_12000);
        monsters.add(Monster_13000);
        monsters.add(Monster_14000);
        monsters.add(Monster_20000);
        monsters.add(Monster_21000);
        monsters.add(Monster_22000);
        monsters.add(Monster_23000);
        monsters.add(Monster_24000);
        monsters.add(Monster_25000);
        monsters.add(Monster_26000);
        monsters.add(Monster_27000);
        monsters.add(Monster_30000);
        monsters.add(Monster_31000);
        monsters.add(Monster_32000);
    }

    /*
    * 怪物中的人物
    * */
    public static final int Monster_40001 = 40001;
    public static final int Monster_40002 = 40002;
    public static final int Monster_40003 = 40003;
    public static final int Monster_40004 = 40004;

    public static List<Integer> monsterChars = new ArrayList<>();
    static {
        monsterChars.add(Monster_40001);
        monsterChars.add(Monster_40002);
        monsterChars.add(Monster_40003);
        monsterChars.add(Monster_40004);
    }

}
