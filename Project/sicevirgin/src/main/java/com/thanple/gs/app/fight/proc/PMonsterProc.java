package com.thanple.gs.app.fight.proc;

import com.thanple.gs.app.chat.toast.ToastUtil;
import com.thanple.gs.app.fight.FightConst;
import com.thanple.gs.app.item.ItemConst;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.user.proc.PGetUserInfo;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.FightMonsterInstance;
import com.thanple.gs.common.berkeleydb.entity.Item;
import com.thanple.gs.common.berkeleydb.entity.User;
import com.thanple.gs.common.berkeleydb.table.FightMonsterInstanceTable;
import com.thanple.gs.common.berkeleydb.table.ItemTable;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.nio.protocol._SFightBlood;
import com.thanple.gs.common.provider.TableLoader;

/**
 * Created by Thanple on 2017/6/1.
 */

public class PMonsterProc extends Procedure{

    private long roleId;
    private int skillType;
    private int fighterId;

    public PMonsterProc(long roleId,int skillType , int fighterId) {
        this.roleId = roleId;
        this.skillType = skillType;
        this.fighterId = fighterId;
    }

    @Override
    protected boolean process() {

        FightMonsterInstanceTable fightMonsterInstanceTable = TableLoader.getTableInstance(FightMonsterInstanceTable.class);

        FightMonsterInstance fightMonsterInstance = fightMonsterInstanceTable.get(roleId);
        if(fightMonsterInstance == null) {
            ToastUtil.show(roleId,"找不到副本中怪物信息");
            return false;
        }

        int monsterId = fightMonsterInstance.getMonsterId();
        int monsterAttack = fightMonsterInstance.getMonsterAttack();
        int monsterDefence = fightMonsterInstance.getMonsterDefance();

        int monsterBlood = fightMonsterInstance.getEnermyBlood();
        int playerBlood = fightMonsterInstance.getPlayerBlood();

        //我方攻击
        if((int)roleId == fighterId) {

            float decrease = 20f;
            User user = TableLoader.getTableInstance(UserTable.class).get(roleId);
            //看技能吧
            switch (skillType)
            {
                case FightConst.NORMAL_ATTACK:
                    ItemTable itemTable = TableLoader.getTableInstance(ItemTable.class);
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

            //再看怪物的防御力
            decrease -= monsterDefence * 0.3;
            if(decrease <= 0) {
                decrease = 20;
            }

            monsterBlood  -= (int)decrease;
            monsterBlood = Math.max(0,monsterBlood);

            if(monsterBlood <=0){
                ToastUtil.show(roleId,"恭喜你挑战成功，获得金币200，经验200！");
                user.setExp(user.getExp() + 200);
                user.setMoney(user.getMoney() + 200);
            }

            fightMonsterInstance.setEnermyBlood(monsterBlood);

        }else{

            //怪物攻击
            playerBlood -= monsterAttack;
            playerBlood = Math.max(playerBlood,0);

            if(playerBlood <= 0) {
                ToastUtil.show(roleId,"挑战失败，再接再厉！");
            }
            fightMonsterInstance.setPlayerBlood(playerBlood);
        }

        //发送给客户端
        _SFightBlood.SFightBlood.Builder sfightblood = _SFightBlood.SFightBlood.newBuilder();
        sfightblood.setFighthType(FightConst.FIGHT_TYPE_MONSTER);

        //我方血量
        _SFightBlood.SFightBlood.FighterInfo.Builder info = _SFightBlood.SFightBlood.FighterInfo.newBuilder();
        info.setId((int)roleId);
        info.setBlood(fightMonsterInstance.getPlayerBlood());

        //怪物血量
        _SFightBlood.SFightBlood.FighterInfo.Builder info2 = _SFightBlood.SFightBlood.FighterInfo.newBuilder();
        info2.setId(monsterId);
        info2.setBlood(fightMonsterInstance.getEnermyBlood());

        sfightblood.addInfo(info);
        sfightblood.addInfo(info2);
        Onlines.send(roleId,sfightblood.build());

        //发送技能点剩余
        pexecuteWhileCommit(new PGetUserInfo(roleId));

        return true;
    }
}
