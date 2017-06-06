package com.thanple.gs.app.session.user;

import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.nio.protocol._SRemoveCharacter;

/**
 * Created by Thanple on 2017/6/6.
 */

public class PRemoveCharacter extends Procedure{

    private long characterId;

    public PRemoveCharacter(long characterId) {
        this.characterId = characterId;
    }

    @Override
    protected boolean process() {


        _SRemoveCharacter.SRemoveCharacter.Builder sremove = _SRemoveCharacter.SRemoveCharacter.newBuilder();

        sremove.setId((int)characterId);

        Onlines.broadMessageToAll(sremove.build());

        return true;
    }
}
