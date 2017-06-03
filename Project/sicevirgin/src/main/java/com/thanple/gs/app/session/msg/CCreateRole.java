package com.thanple.gs.app.session.msg;

import com.thanple.gs.app.chat.toast.ToastUtil;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.PropertiesMap;
import com.thanple.gs.common.berkeleydb.entity.User;
import com.thanple.gs.common.berkeleydb.table.PropertiesMapTable;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.provider.TableLoader;

import java.util.Map;

/**
 * auto created by CreateProtocol
 * 2017-06-03 11:48:27
 * */

public class CCreateRole extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole>{

    public CCreateRole(
           com.thanple.gs.common.nio.protocol._CCreateRole.CCreateRole msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {

        final String name = protocolBean.getName();
        final String number = protocolBean.getNumber();
        final String password = protocolBean.getPassword();
        final int body = protocolBean.getBody();
        final int hair = protocolBean.getHair();
        final int weapon = protocolBean.getWeapon();

        new Procedure() {
            @Override
            protected boolean process() {

                PropertiesMapTable propertiesMapTable = TableLoader.getTableInstance(PropertiesMapTable.class);
                PropertiesMap numberIdMap = propertiesMapTable.get(PropertiesMap.NumberIdMap);
                if(numberIdMap == null) {
                    numberIdMap = new PropertiesMap();
                    propertiesMapTable.insert(PropertiesMap.NumberIdMap,numberIdMap);
                }

                if(numberIdMap.getMap().containsKey(number)) {
                    ToastUtil.show(ctx,"账号已经存在");
                    return true;
                }

                //key generator
                PropertiesMap idGenMap = propertiesMapTable.get(PropertiesMap.ID_Createor);
                if(idGenMap == null) {
                    idGenMap = new PropertiesMap();
                    propertiesMapTable.insert(PropertiesMap.ID_Createor,idGenMap);
                }
                long roleId;
                Long genRoleId = (Long)(idGenMap.getMap().get(PropertiesMap.RoleId));
                if(genRoleId == null) {
                    genRoleId = 4096L;
                    idGenMap.getMap().put(PropertiesMap.RoleId,genRoleId);
                }
                roleId = (Long)idGenMap.getMap().get(PropertiesMap.RoleId) + 1;
                idGenMap.getMap().put(PropertiesMap.RoleId,roleId);

                //插入账号和id的映射
                numberIdMap.getMap().put(number,roleId);

                //插入角色信息
                UserTable userTable = TableLoader.getTableInstance(UserTable.class);
                User user = new User();
                user.setId(roleId);
                user.setName(name);
                user.setNumber(number);
                user.setPassword(password);
                user.setBody(body);
                user.setHair(hair);
                user.setWeapon(weapon);
                user.setMoney(200);
                user.setNskills(20);
                user.setExp(0);

                userTable.save(roleId,user);


                ToastUtil.show(ctx,"注册成功");
                return true;
            }
        }.submit();
    }
}