package com.thanple.gs.app.user.msg;

import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;
import com.thanple.gs.app.user.proc.PGetUserInfo;

/**
 * auto created by CreateProtocol
 * 2017-06-02 12:18:38
 * */

public class CRequestUserInfo extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo>{

    public CRequestUserInfo(
           com.thanple.gs.common.nio.protocol._CRequestUserInfo.CRequestUserInfo msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {
        long roleId = Onlines.findUserId(new Session(ctx));
        if(roleId < 0) {
            return;
        }

        new PGetUserInfo(roleId).submit();
    }
}