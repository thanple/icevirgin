package com.thanple.gs.app.item.proc;

import com.thanple.gs.app.chat.toast.ToastUtil;
import com.thanple.gs.app.item.ItemConst;
import com.thanple.gs.app.user.proc.PGetUserInfo;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.*;
import com.thanple.gs.common.berkeleydb.table.ItemTable;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.provider.TableLoader;

/**
 * Created by Thanple on 2017/6/2.
 */

public class PBuyProc extends Procedure{

    private long roleId;
    private int type;
    public PBuyProc(long roleId , int type) {
        this.roleId = roleId;
        this.type = type;
    }

    @Override
    protected boolean process() {

        ItemTable itemTable = TableLoader.getTableInstance(ItemTable.class);
        Item item =  itemTable.get(roleId);
        if(item == null) {
            item = new Item();
            itemTable.insert(roleId,item);
        }

        User user = TableLoader.getTableInstance(UserTable.class).get(roleId);

        boolean monyNotEnough = false;
        boolean needUpdateUserInfo = false;
        if(type == ItemConst.SKILL_POINT) {
            if(user.getMoney() < ItemConst.SKILL_POINT_COST) {
                monyNotEnough = true;
            }else{
                user.setMoney(user.getMoney() - ItemConst.SKILL_POINT_COST);
                user.setNskills(user.getNskills() + 1);
            }
            needUpdateUserInfo = true;
        }else if(type == ItemConst.ADD_EXP) {
            if(user.getMoney() < ItemConst.ADD_EXP_COST) {
                monyNotEnough = true;
            }else{
                user.setMoney(user.getMoney() - ItemConst.ADD_EXP_COST);
                user.setExp(user.getExp() + 100);
            }
            needUpdateUserInfo = true;

        }else if(type == ItemConst.ADD_ATTACK) {
            if(user.getMoney() < ItemConst.ADD_ATTACK_COST) {
                monyNotEnough = true;
            }else{
                user.setMoney(user.getMoney() - ItemConst.ADD_ATTACK_COST);
            }
        }

        if(monyNotEnough) {
            ToastUtil.show(roleId,"您的金币不足，无法完成购买");
            return false;
        }

        if(item.getItems().containsKey(type)){
            int count = item.getItems().get(type);
            item.getItems().put(type,count + 1);
        }else{
            item.getItems().put(type,1);
        }

        ToastUtil.show(roleId,"购买成功，欢迎下次光临");

        //更新用户数据
        if(needUpdateUserInfo) {
            pexecuteWhileCommit(new PGetUserInfo(roleId));
        }

        return true;
    }
}
