package com.thanple.gs.app.item.msg;

import com.thanple.gs.app.item.proc.PBuyProc;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;

/**
 * auto created by CreateProtocol
 * 2017-06-02 19:18:44
 * */

public class CBuy extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CBuy.CBuy>{

    public CBuy(
           com.thanple.gs.common.nio.protocol._CBuy.CBuy msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {
        long roleId = Onlines.findUserId(new Session(ctx));
        if(roleId < 0) {
            return;
        }

        new PBuyProc(roleId,protocolBean.getShop()).submit();
    }
}