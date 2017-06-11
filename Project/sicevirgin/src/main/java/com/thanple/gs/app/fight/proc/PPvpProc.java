package com.thanple.gs.app.fight.proc;

import com.thanple.gs.app.chat.toast.ToastUtil;
import com.thanple.gs.app.fight.FightConst;
import com.thanple.gs.app.item.ItemConst;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.user.proc.PGetUserInfo;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.Item;
import com.thanple.gs.common.berkeleydb.entity.PropertiesMap;
import com.thanple.gs.common.berkeleydb.entity.PvpInstance;
import com.thanple.gs.common.berkeleydb.entity.User;
import com.thanple.gs.common.berkeleydb.table.ItemTable;
import com.thanple.gs.common.berkeleydb.table.PropertiesMapTable;
import com.thanple.gs.common.berkeleydb.table.PvpInstanceTable;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.nio.protocol._SFightBlood;
import com.thanple.gs.common.nio.protocol._SPvpAttackFlag;
import com.thanple.gs.common.provider.TableLoader;

/**
 * Created by Thanple on 2017/6/10.
 */

public class PPvpProc extends Procedure{
    private long roleId;
    private int skillType;
    public PPvpProc(long roleId,int skillType) {
        this.roleId = roleId;
        this.skillType = skillType;
    }


    @Override
    protected boolean process() {

        PropertiesMapTable propertiesMapTable = TableLoader.getTableInstance(PropertiesMapTable.class);
        PvpInstanceTable pvpInstanceTable = TableLoader.getTableInstance(PvpInstanceTable.class);
        ItemTable itemTable = TableLoader.getTableInstance(ItemTable.class);

        User user = TableLoader.getTableInstance(UserTable.class).get(roleId);
        Long instanceId = (Long)propertiesMapTable.select(PropertiesMap.RoleidInstanceidMap).getMap().get(roleId);
        if(instanceId == null) {
            return false;
        }
        PvpInstance instance  = pvpInstanceTable.get(instanceId);
        if(instance == null) {
            return false;
        }

        //看技能算伤害
        float decrease = 20f;
        switch (skillType)
        {
            case FightConst.NORMAL_ATTACK:
                Item item =  itemTable.select(roleId);
                if(item!=null && item.getItems().containsKey(ItemConst.ADD_ATTACK)) {
                    for(int i=0,len = item.getItems().get(ItemConst.ADD_ATTACK) ;i<len ;i++) {
                        decrease *= 1.1f;
                    }
                }
                break;
            case FightConst.SKILL_1:
                decrease *= 1.2;
                user.setNskills(user.getNskills() - 2);
                break;
            case FightConst.SKILL_2:
                decrease *= 1.5;
                user.setNskills(user.getNskills() - 5);
                break;
            case FightConst.SKILL_3:
                decrease *= 1.7;
                user.setNskills(user.getNskills() - 7);
                break;
            case FightConst.SKILL_4:
                decrease *= 2.0;
                user.setNskills(user.getNskills() - 10);
                break;
        }

        if(instance.getRole1().getRoleId() == roleId ) {
            this.executeEnermyHurt(instance.getRole2() , (int)decrease,user);
        }else{
            this.executeEnermyHurt(instance.getRole1() , (int)decrease,user);
        }

        //发送给客户端
        _SFightBlood.SFightBlood.Builder sfightblood = _SFightBlood.SFightBlood.newBuilder();
        sfightblood.setFighthType(FightConst.FIGHT_TYPE_USER);

        //A方血量
        _SFightBlood.SFightBlood.FighterInfo.Builder info = _SFightBlood.SFightBlood.FighterInfo.newBuilder();
        info.setId((int)instance.getRole1().getRoleId());
        info.setBlood(instance.getRole1().getBlood());

        //B方血量
        _SFightBlood.SFightBlood.FighterInfo.Builder info2 = _SFightBlood.SFightBlood.FighterInfo.newBuilder();
        info2.setId((int)instance.getRole2().getRoleId());
        info2.setBlood(instance.getRole2().getBlood());

        sfightblood.addInfo(info);
        sfightblood.addInfo(info2);
        Onlines.send(info.getId(),sfightblood.build());
        Onlines.send(info2.getId(),sfightblood.build());

        //发送技能点剩余
        pexecuteWhileCommit(new PGetUserInfo(info.getId()));
        pexecuteWhileCommit(new PGetUserInfo(info2.getId()));

        return true;
    }

    private void executeEnermyHurt(PvpInstance.RoleProperty enermyProperty,int decrease,User user) {
        enermyProperty.setBlood(Math.max(enermyProperty.getBlood() - decrease,0));
        if(enermyProperty.getBlood() <= 0) {
            ToastUtil.show(roleId,"恭喜你挑战成功，获得金币400，经验400！");
            user.setExp(user.getExp() + 400);
            user.setMoney(user.getMoney() + 400);
        }

        //发送让敌方攻击数据同步
        _SPvpAttackFlag.SPvpAttackFlag.Builder attackFlag = _SPvpAttackFlag.SPvpAttackFlag.newBuilder();
        attackFlag.setSkillType(skillType);
        Onlines.send(enermyProperty.getRoleId() , attackFlag.build());

    }
}
