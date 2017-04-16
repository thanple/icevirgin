package com.thanple.gs.common.nio.handler;

import com.google.protobuf.ByteString;
import com.google.protobuf.MessageLite;
import com.thanple.gs.common.provider.ProtocolLoader;
import io.netty.channel.ChannelHandlerAdapter;
import io.netty.channel.ChannelHandlerContext;

import java.lang.reflect.Method;

/**
 * Created by Thanple on 2017/1/20.
 */
public class ServerHandler extends ChannelHandlerAdapter {
    
    private Class<?> getClassById(int classId){
        return ProtocolLoader.getInstance().getProtocolMap().get(classId).getCreate();
    }

    @Override
    public void channelRead(ChannelHandlerContext ctx, Object msg) throws Exception {

       /* //先使用万能消息模板接收消息
        _GameServerCMsg.GameServerCMsg clientMsg = (_GameServerCMsg.GameServerCMsg)msg;
        int id = clientMsg.getId();
        ByteString data = clientMsg.getMsg();

        //反射万能消息模板的data得到协议消息对象(protobuf生成的)
        Class<?> protocolCls = this.getClassById(id);
        Method parseProtoFromByteString = protocolCls.getDeclaredMethod("parseFrom",ByteString.class);
        MessageLite messageLite = (MessageLite)parseProtoFromByteString.invoke(null,data);

        //反射逻辑业务类（自定义生成）
        Class<? extends Protocol> logicProtocolCls = ProtocolLoader.getInstance().getProtocolByName(messageLite.getClass().getSimpleName()).getUser();
        Protocol obj = logicProtocolCls.getConstructor(protocolCls).newInstance(messageLite);


        //反射得到的协议分发业务方法
        //交由线程池处理
        ExecutorUtil.executeInThreadPool(new Runnable(){
            @Override
            public void run() {
                obj.process(ctx);
            }
        });
*/

//        ChannelFuture future = ctx.writeAndFlush(build());
        //发送数据之后，我们手动关闭channel，这个关闭是异步的，当数据发送完毕后执行。
//        future.addListener(ChannelFutureListener.CLOSE);
    }



}