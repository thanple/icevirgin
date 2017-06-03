package com.thanple.gs.common.berkeleydb.entity;


import lombok.Data;

import java.io.Serializable;

/**
 * Created by Thanple on 2017/6/1.
 */

@Data
public class FightMonsterInstance implements Serializable {

    int monsterId;  //id
    int monsterAttack;  //攻击力
    int monsterDefance; //防御力

    //双方血量记录
    int enermyBlood;
    int playerBlood;
}

