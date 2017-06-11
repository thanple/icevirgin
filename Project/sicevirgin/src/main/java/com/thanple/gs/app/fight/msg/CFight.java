package com.thanple.gs.app.fight.msg;

import com.thanple.gs.app.fight.FightConst;
import com.thanple.gs.app.fight.proc.PMonsterProc;
import com.thanple.gs.app.fight.proc.PPvpProc;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;

/**
 * auto created by CreateProtocol
 * 2017-06-01 21:20:52
 * */

public class CFight extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CFight.CFight>{

    public CFight(
           com.thanple.gs.common.nio.protocol._CFight.CFight msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {
        long roleId = Onlines.findUserId(new Session(ctx));
        if(roleId < 0) {
            return;
        }
        int skillType = protocolBean.getSkillType();
        int fighterId = protocolBean.getFighthId();
        if(protocolBean.getFighthType() == FightConst.FIGHT_TYPE_MONSTER){
            new PMonsterProc(roleId,skillType,fighterId).submit();
        }else{
            new PPvpProc(roleId,skillType).submit();
        }
    }
}