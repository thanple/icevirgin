package com.thanple.gs.app.person1.msg;

import com.thanple.gs.common.berkeleydb.Procedure;

/**
 * auto created by CreateProtocol
 * 2017-04-18 21:37:03
 * */

public class CPerson1 extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CPerson1.CPerson1>{

    public CPerson1(
           com.thanple.gs.common.nio.protocol._CPerson1.CPerson1 msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {
        new Procedure() {
            @Override
            protected boolean process() {



                return true;
            }
        }.submit();
    }
}