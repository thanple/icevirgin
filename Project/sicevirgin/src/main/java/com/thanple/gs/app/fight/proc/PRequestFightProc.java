package com.thanple.gs.app.fight.proc;

import com.thanple.gs.app.chat.toast.ToastUtil;
import com.thanple.gs.app.fight.FightConst;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.user.proc.PGetUserInfo;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.FightMonsterInstance;
import com.thanple.gs.common.berkeleydb.entity.PropertiesMap;
import com.thanple.gs.common.berkeleydb.entity.PvpInstance;
import com.thanple.gs.common.berkeleydb.table.FightMonsterInstanceTable;
import com.thanple.gs.common.berkeleydb.table.PropertiesMapTable;
import com.thanple.gs.common.berkeleydb.table.PvpInstanceTable;
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

            //插入数据
            FightMonsterInstance instance = new FightMonsterInstance();
            instance.setMonsterId(monsterid);
            instance.setEnermyBlood(100);
            instance.setMonsterAttack(20);
            instance.setMonsterDefance(20+ (int)(Math.random() * 5));
            instance.setPlayerBlood(100);

            fightMonsterInstanceTable.save(roleId,instance);

            //发送怪物消息
            _SFightMonsterInfo.SFightMonsterInfo.Builder info = _SFightMonsterInfo.SFightMonsterInfo.newBuilder();
            info.setMonsterId(monsterid);
            Onlines.send(roleId,info.build());

            ToastUtil.show(roleId,"怪物"+monsterid + "加入战斗,开始攻击吧，碾碎他们！");
        } else {

            //pvp副本

           /* PropertiesMap roleidInstanceidMap = propertiesMapTable.get(PropertiesMap.RoleidInstanceidMap);
            if(roleidInstanceidMap == null) {
                roleidInstanceidMap = new PropertiesMap();
                propertiesMapTable.insert(PropertiesMap.RoleidInstanceidMap,roleidInstanceidMap);
            }*/

            //创建Instance的一个id
            PropertiesMapTable propertiesMapTable = TableLoader.getTableInstance(PropertiesMapTable.class);
            PropertiesMap idGenMap = propertiesMapTable.get(PropertiesMap.ID_Createor);
            if(idGenMap == null) {
                idGenMap = new PropertiesMap();
                propertiesMapTable.insert(PropertiesMap.ID_Createor,idGenMap);
            }
            Long genInstanceId = (Long)(idGenMap.getMap().get(PropertiesMap.InstanceId));
            if(genInstanceId == null) {
                genInstanceId = 4096L;
                idGenMap.getMap().put(PropertiesMap.InstanceId,genInstanceId);
            }
            genInstanceId = (Long)idGenMap.getMap().get(PropertiesMap.InstanceId) + 1;
            idGenMap.getMap().put(PropertiesMap.InstanceId,genInstanceId);

            //创建Pvp副本
            PvpInstanceTable pvpInstanceTable = TableLoader.getTableInstance(PvpInstanceTable.class);
            PvpInstance pvpInstance = new PvpInstance();
            pvpInstance.setRole1(PvpInstance.RoleProperty.createRole(roleId));
            pvpInstance.setCount(1);
            pvpInstanceTable.save(genInstanceId,pvpInstance);

            //每个roleid对应一个instanceid
            PropertiesMap roleInstance = propertiesMapTable.get(PropertiesMap.RoleidInstanceidMap);
            if(null == roleInstance) {
                roleInstance = new PropertiesMap();
                propertiesMapTable.insert(PropertiesMap.RoleidInstanceidMap,roleInstance);
            }
            roleInstance.getMap().put(roleId,genInstanceId);

            ToastUtil.show(roleId,"找出buf");

        }

        //发送技能点剩余
        pexecuteWhileCommit(new PGetUserInfo(roleId));

        return true;
    }
}
