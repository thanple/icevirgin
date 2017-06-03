package com.thanple.gs.app.session.msg;

import com.thanple.gs.app.chat.toast.ToastUtil;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.PropertiesMap;
import com.thanple.gs.common.berkeleydb.entity.User;
import com.thanple.gs.common.berkeleydb.table.PropertiesMapTable;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.nio.manager.Protocol;
import com.thanple.gs.common.nio.protocol._SLogin;
import com.thanple.gs.common.provider.TableLoader;

/**
 * auto created by CreateProtocol
 * 2017-06-03 13:31:30
 * */

public class CLogin extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CLogin.CLogin>{

    public CLogin(
           com.thanple.gs.common.nio.protocol._CLogin.CLogin msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {


        final String number = protocolBean.getNumber();
        final String password = protocolBean.getPassword();

        new Procedure() {
            @Override
            protected boolean process() {

                PropertiesMapTable propertiesMapTable = TableLoader.getTableInstance(PropertiesMapTable.class);
                PropertiesMap numberIdMap = propertiesMapTable.get(PropertiesMap.NumberIdMap);
                if(numberIdMap == null) {
                    numberIdMap = new PropertiesMap();
                    propertiesMapTable.insert(PropertiesMap.NumberIdMap,numberIdMap);
                }

                if(!numberIdMap.getMap().containsKey(number)) {
                    ToastUtil.show(ctx,"账号不存在");
                    return true;
                }

                //去User表验证
                Long roleId = (Long)numberIdMap.getMap().get(number);
                User user = TableLoader.getTableInstance(UserTable.class).get(roleId);
                if(password.equals(user.getPassword())) {
                    ToastUtil.show(ctx,"密码错误");
                    return true;
                }

                //加入会话状态
                Onlines.insertUserSession(roleId,new Session(ctx));
                System.out.println("[上线] 角色"+user+"已经上线...");

                //登录成功
                ToastUtil.show(roleId,"登录成功");
                _SLogin.SLogin.Builder slogin = _SLogin.SLogin.newBuilder();
                Protocol.send(ctx,slogin.build());

                return true;
            }
        }.submit();
    }
}