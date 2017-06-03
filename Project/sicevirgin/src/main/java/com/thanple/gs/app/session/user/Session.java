package com.thanple.gs.app.session.user;


import com.thanple.gs.common.nio.manager.Protocol;
import io.netty.channel.ChannelHandlerContext;
import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.RequiredArgsConstructor;

/**
 * Created by Thanple on 2017/4/20.
 */

@AllArgsConstructor
public class Session implements ISession {

    @Getter
    private ChannelHandlerContext channelHandler;

    @Override
    public boolean equals(Object obj) {
        if(!(obj instanceof Session)){
            return false;
        }
        Session session = (Session)obj;
        return session.getChannelHandler().equals(channelHandler);
    }

    @Override
    public int hashCode() {
        return channelHandler.hashCode();
    }

    @Override
    public <V extends com.google.protobuf.MessageLite> void writeChanel(V obj){
        Protocol.send(channelHandler,obj);
    }
}
