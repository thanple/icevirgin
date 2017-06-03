package com.thanple.gs.common.nio.handler;

import com.google.protobuf.ByteString;
import com.google.protobuf.MessageLite;
import com.thanple.gs.app.session.user.ISession;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;
import com.thanple.gs.app.user.UserConst;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.User;
import com.thanple.gs.common.berkeleydb.table.ItemTable;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.nio.manager.Protocol;
import com.thanple.gs.common.nio.manager._GameServerCMsg;
import com.thanple.gs.common.provider.ProtocolLoader;
import com.thanple.gs.common.provider.TableLoader;
import com.thanple.gs.common.util.ExecutorUtil;
import io.netty.channel.Channel;
import io.netty.channel.ChannelHandlerAdapter;
import io.netty.channel.ChannelHandlerContext;
import io.netty.channel.ChannelPromise;

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

        //先使用万能消息模板接收消息
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

        System.out.print("[协议"+messageLite.getClass()+"] " + messageLite);

    /*
        if(Onlines.findUserId(new Session(ctx)) == -1){

            Onlines.insertUserSession(4097L,new Session(ctx));

            new Procedure() {
                @Override
                protected boolean process() {

                    //user属性表
                    UserTable userTable = TableLoader.getTableInstance(UserTable.class);
                    User user = new User();
                    user.setId(4097L);
                    user.setMoney(200);
                    user.setNskills(20);
                    user.setName("步惊云");
                    user.setNumber("806585542");

                    user.setHair(UserConst.Hair_11002);
                    user.setWeapon(UserConst.Weapon_14000);
                    user.setBody(UserConst.PLAYER_11002);

                    userTable.save(4097L,user);

                    return true;
                }
            }.submit();

        }
*/


        //反射得到的协议分发业务方法
        //交由线程池处理
        ExecutorUtil.executeInThreadPool(new Runnable(){
            @Override
            public void run() {
                obj.process(ctx);
            }
        });


//        ChannelFuture future = ctx.writeAndFlush(build());
        //发送数据之后，我们手动关闭channel，这个关闭是异步的，当数据发送完毕后执行。
//        future.addListener(ChannelFutureListener.CLOSE);
    }

    @Override
    public void channelInactive(ChannelHandlerContext ctx) throws Exception {
        if(Onlines.getSessionUser().containsKey(new Session(ctx))) {
            new Procedure() {
                @Override
                protected boolean process() {

                    User user = TableLoader.getTableInstance(UserTable.class).select(Onlines.getSessionUser().get(new Session((ctx))));
                    System.out.println("[离线]:玩家"+user+" 已经下线...");
                    Onlines.removeUser(user.getId());
                    return true;
                }
            }.submit();
        }else {
            System.out.println("[离线]:"+ctx+"已经离线...");
        }
        super.channelInactive(ctx);
    }


    @Override
    public void exceptionCaught(ChannelHandlerContext ctx, Throwable cause) {
        Channel incoming = ctx.channel();
        if(!incoming.isActive())
            System.out.println("SimpleClient:" + incoming.remoteAddress()
                    + "异常");

        //cause.printStackTrace();
        ctx.close();
    }


}