package com.thanple.gs.app.fight.msg;

import com.thanple.gs.app.fight.proc.PRequestFightProc;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;

/**
 * auto created by CreateProtocol
 * 2017-06-01 21:23:45
 * */

public class CRequestFight extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CRequestFight.CRequestFight>{

    public CRequestFight(
           com.thanple.gs.common.nio.protocol._CRequestFight.CRequestFight msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {
        long roleId = Onlines.findUserId(new Session(ctx));
        if(roleId < 0) {
            return;
        }
        new PRequestFightProc(roleId,protocolBean.getFighthType(),protocolBean.getFighthId()).submit();
    }
}