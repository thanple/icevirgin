package com.thanple.gs.app.chat.msg;

import com.thanple.gs.app.chat.toast.ToastUtil;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.nio.protocol._SChatMsg;
import com.thanple.gs.common.provider.TableLoader;

/**
 * auto created by CreateProtocol
 * 2017-05-31 00:17:02
 * */

public class CChatMsg extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CChatMsg.CChatMsg>{

    public CChatMsg(
           com.thanple.gs.common.nio.protocol._CChatMsg.CChatMsg msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {

        _SChatMsg.SChatMsg.Builder chatMsg = _SChatMsg.SChatMsg.newBuilder();
        String fromClient = protocolBean.getMsg();
        if(null == fromClient || "".equals(fromClient)){
            ToastUtil.show(ctx,"请输入字符串");
            return;
        }

        if(fromClient.length() > 10) {
            ToastUtil.show(ctx,"请输入在10字以内");
            return;
        }

        final long roleId = Onlines.findUserId(new Session(ctx));
        if(roleId<0){
            return;
        }

        new Procedure() {
            @Override
            protected boolean process() {

                String name = TableLoader.getTableInstance(UserTable.class).select(roleId).getName();

                chatMsg.setMsg(name + ":" + fromClient);

                Onlines.broadMessageToAll(chatMsg.build());

                return true;
            }
        }.submit();

    }
}