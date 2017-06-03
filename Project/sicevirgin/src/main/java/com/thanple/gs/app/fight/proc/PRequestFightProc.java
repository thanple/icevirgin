package com.thanple.gs.app.fight.proc;

import com.thanple.gs.app.chat.toast.ToastUtil;
import com.thanple.gs.app.fight.FightConst;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.user.proc.PGetUserInfo;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.FightMonsterInstance;
import com.thanple.gs.common.berkeleydb.table.FightMonsterInstanceTable;
import com.thanple.gs.common.nio.protocol._SFightMonsterInfo;
import com.thanple.gs.common.provider.TableLoader;

import java.util.List;
import java.util.Random;

/**
 * Created by Thanple on 2017/6/1.
 */

public class PRequestFightProc extends Procedure{

    private  long roleId;
    private int fighthType;
    private int fighthId;




    public PRequestFightProc(long roleId,int fighthType,int fighthId) {
        this.roleId = roleId;
        this.fighthId = fighthId;
        this.fighthType = fighthType;
    }

    @Override
    protected boolean process() {

        if(fighthType == FightConst.FIGHT_TYPE_MONSTER) {
            FightMonsterInstanceTable fightMonsterInstanceTable = TableLoader.getTableInstance(FightMonsterInstanceTable.class);

            //随机产生怪物
            List<Integer> monsters = FightConst.monsters;
            List<Integer> monsterChar = FightConst.monsterChars;

            int monsterid;
            if(fighthId > 0) {
                monsterid = fighthId;
            }else{
                do {
                    //产生人物还是怪物
                    if(Math.random() < 0.5){
                        int randomIndex = (int)(Math.random() * monsterChar.size());
                        monsterid = monsterChar.get(randomIndex);
                    }else{
                        int randomIndex = (int)(Math.random() * monsters.size());
                        monsterid = monsters.get(randomIndex);
                    }

                }while (monsterid == 32000);
            }

//            monsterid = 40002;


            //插入数据
            FightMonsterInstance instance = new FightMonsterInstance();
            instance.setMonsterId(monsterid);
            instance.setEnermyBlood(100);
            instance.setMonsterAttack(20 + (int)(Math.random() * 20));
            instance.setMonsterDefance(20+ (int)(Math.random() * 20));
            instance.setPlayerBlood(100);

            fightMonsterInstanceTable.save(roleId,instance);

            //发送怪物消息
            _SFightMonsterInfo.SFightMonsterInfo.Builder info = _SFightMonsterInfo.SFightMonsterInfo.newBuilder();
            info.setMonsterId(monsterid);
            Onlines.send(roleId,info.build());

            ToastUtil.show(roleId,"怪物"+monsterid + "加入战斗,开始攻击吧，碾碎他们！");
        }

        //发送技能点剩余
        pexecuteWhileCommit(new PGetUserInfo(roleId));

        return true;
    }
}
