package com.thanple.gs.app.session.user;

import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.User;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.nio.protocol._SAddCharacter;
import com.thanple.gs.common.provider.TableLoader;

/**
 * Created by Thanple on 2017/6/6.
 *
 * 发送在线的玩家的数据
 */

public class PSendOnlineCharacters extends Procedure{

    public PSendOnlineCharacters(){
    }


    @Override
    protected boolean process() {

        UserTable userTable = TableLoader.getTableInstance(UserTable.class);

        _SAddCharacter.SAddCharacter.Builder sAddChacter = _SAddCharacter.SAddCharacter.newBuilder();
        for(long roleId : Onlines.getUserSession().keySet()) {
            User user = userTable.select(roleId);

            _SAddCharacter.SAddCharacter.CharacterItem.Builder item = _SAddCharacter.SAddCharacter.CharacterItem.newBuilder();
            item.setId((int)roleId);
            item.setBody(user.getBody());
            item.setHair(user.getHair());
            item.setWeapon(user.getWeapon());

            sAddChacter.addCharacters(item.build());
        }

        Onlines.broadMessageToAll(sAddChacter.build());

        return true;
    }
}
