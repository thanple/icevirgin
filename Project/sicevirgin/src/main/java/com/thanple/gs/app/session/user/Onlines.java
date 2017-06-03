package com.thanple.gs.app.session.user;


import io.netty.buffer.ByteBufAllocator;
import io.netty.channel.*;
import io.netty.util.Attribute;
import io.netty.util.AttributeKey;
import io.netty.util.concurrent.EventExecutor;
import lombok.Getter;

import java.net.SocketAddress;
import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/**
 * Created by Thanple on 2017/4/20.
 */

public class Onlines {

    @Getter
    private static Map<ISession,Long> sessionUser = new ConcurrentHashMap<>();
    @Getter
    private static Map<Long,ISession> userSession = new ConcurrentHashMap<>();


    /**
     * 查询角色id
     * */
    public static long findUserId(ISession userSession){
        Long userId = sessionUser.get(userSession);
        return userId == null ? -1 : userId;
    }

    /**
     * 插入角色在线状态信息
     * */
    public static void insertUserSession(long userId, ISession session){
        userSession.put(userId,session);
        sessionUser.put(session,userId);
    }

    /**
     * 下线
     * */
    public static void removeUser(long userId){
        ISession session = userSession.remove(userId);
        sessionUser.remove(session);
    }

    /**
     * 所有角色下线
     * */
    public static void removeAllUser(){
        sessionUser.clear();
        userSession.clear();
    }

    /**
     * 发送消息给客户端
     * */
    public static <V extends com.google.protobuf.MessageLite> void send(long userId , V obj){
        ISession session = userSession.get(userId);
        if(null != session){
            session.writeChanel(obj);
        }

    }

    /**
     * 广播消息给客户端
     * */
    public static <V extends com.google.protobuf.MessageLite> void broadMessageToAll(V msg){
        userSession.keySet().forEach((e)->{
            send(e,msg);
        });
    }


    public static void main(String[] args) {
        ChannelHandlerContext ctx = new ChannelHandlerContext() {
            @Override
            public <T> Attribute<T> attr(AttributeKey<T> attributeKey) {
                return null;
            }

            @Override
            public <T> boolean hasAttr(AttributeKey<T> attributeKey) {
                return false;
            }

            @Override
            public Channel channel() {
                return null;
            }

            @Override
            public EventExecutor executor() {
                return null;
            }

            @Override
            public ChannelHandlerInvoker invoker() {
                return null;
            }

            @Override
            public String name() {
                return null;
            }

            @Override
            public ChannelHandler handler() {
                return null;
            }

            @Override
            public boolean isRemoved() {
                return false;
            }

            @Override
            public ChannelHandlerContext fireChannelRegistered() {
                return null;
            }

            @Override
            public ChannelHandlerContext fireChannelUnregistered() {
                return null;
            }

            @Override
            public ChannelHandlerContext fireChannelActive() {
                return null;
            }

            @Override
            public ChannelHandlerContext fireChannelInactive() {
                return null;
            }

            @Override
            public ChannelHandlerContext fireExceptionCaught(Throwable throwable) {
                return null;
            }

            @Override
            public ChannelHandlerContext fireUserEventTriggered(Object o) {
                return null;
            }

            @Override
            public ChannelHandlerContext fireChannelRead(Object o) {
                return null;
            }

            @Override
            public ChannelHandlerContext fireChannelReadComplete() {
                return null;
            }

            @Override
            public ChannelHandlerContext fireChannelWritabilityChanged() {
                return null;
            }

            @Override
            public ChannelFuture bind(SocketAddress socketAddress) {
                return null;
            }

            @Override
            public ChannelFuture connect(SocketAddress socketAddress) {
                return null;
            }

            @Override
            public ChannelFuture connect(SocketAddress socketAddress, SocketAddress socketAddress1) {
                return null;
            }

            @Override
            public ChannelFuture disconnect() {
                return null;
            }

            @Override
            public ChannelFuture close() {
                return null;
            }

            @Override
            public ChannelFuture deregister() {
                return null;
            }

            @Override
            public ChannelFuture bind(SocketAddress socketAddress, ChannelPromise channelPromise) {
                return null;
            }

            @Override
            public ChannelFuture connect(SocketAddress socketAddress, ChannelPromise channelPromise) {
                return null;
            }

            @Override
            public ChannelFuture connect(SocketAddress socketAddress, SocketAddress socketAddress1, ChannelPromise channelPromise) {
                return null;
            }

            @Override
            public ChannelFuture disconnect(ChannelPromise channelPromise) {
                return null;
            }

            @Override
            public ChannelFuture close(ChannelPromise channelPromise) {
                return null;
            }

            @Override
            public ChannelFuture deregister(ChannelPromise channelPromise) {
                return null;
            }

            @Override
            public ChannelHandlerContext read() {
                return null;
            }

            @Override
            public ChannelFuture write(Object o) {
                return null;
            }

            @Override
            public ChannelFuture write(Object o, ChannelPromise channelPromise) {
                return null;
            }

            @Override
            public ChannelHandlerContext flush() {
                return null;
            }

            @Override
            public ChannelFuture writeAndFlush(Object o, ChannelPromise channelPromise) {
                return null;
            }

            @Override
            public ChannelFuture writeAndFlush(Object o) {
                return null;
            }

            @Override
            public ChannelPipeline pipeline() {
                return null;
            }

            @Override
            public ByteBufAllocator alloc() {
                return null;
            }

            @Override
            public ChannelPromise newPromise() {
                return null;
            }

            @Override
            public ChannelProgressivePromise newProgressivePromise() {
                return null;
            }

            @Override
            public ChannelFuture newSucceededFuture() {
                return null;
            }

            @Override
            public ChannelFuture newFailedFuture(Throwable throwable) {
                return null;
            }

            @Override
            public ChannelPromise voidPromise() {
                return null;
            }
        };
        Onlines.insertUserSession(4000L,new Session(ctx));

        Long id = Onlines.findUserId(new Session(ctx));

        System.out.println("id=" + id);

    }

}
