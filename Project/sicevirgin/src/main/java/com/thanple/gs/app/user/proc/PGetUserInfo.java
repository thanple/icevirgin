package com.thanple.gs.app.user.proc;

import com.thanple.gs.app.chat.toast.ToastUtil;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.User;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.nio.protocol._SRequestUserInfo;
import com.thanple.gs.common.provider.TableLoader;

/**
 * Created by Thanple on 2017/6/2.
 */

public class PGetUserInfo extends Procedure{

    private long roleId;
    public PGetUserInfo(long roleId) {
        this.roleId = roleId;
    }

    @Override
    protected boolean process() {


        UserTable userTable = TableLoader.getTableInstance(UserTable.class);
        User user = userTable.select(roleId);

        _SRequestUserInfo.SRequestUserInfo.Builder builder = _SRequestUserInfo.SRequestUserInfo.newBuilder();
        builder.setId((int)user.getId());
        builder.setName(user.getName());
        builder.setMoney(user.getMoney());
        builder.setBody(user.getBody());
        builder.setHair(user.getHair());
        builder.setWeapon(user.getWeapon());
        builder.setExp(user.getExp());
        builder.setNskill(user.getNskills());
        builder.setNumber(user.getNumber());

        Onlines.send(roleId,builder.build());

        return true;
    }
}
