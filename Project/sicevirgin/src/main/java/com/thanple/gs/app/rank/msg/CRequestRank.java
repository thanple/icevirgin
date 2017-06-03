package com.thanple.gs.app.rank.msg;

import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.User;
import com.thanple.gs.common.berkeleydb.table.UserTable;
import com.thanple.gs.common.nio.protocol._SRequestRank;
import com.thanple.gs.common.provider.TableLoader;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * auto created by CreateProtocol
 * 2017-06-02 21:34:03
 * */

public class CRequestRank extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CRequestRank.CRequestRank>{

    public CRequestRank(
           com.thanple.gs.common.nio.protocol._CRequestRank.CRequestRank msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {

        final long roleId = Onlines.findUserId(new Session(ctx));
        if(roleId < 0) {
            return;
        }

        new Procedure() {
            @Override
            protected boolean process() {

                //统计所有上线玩家
                List<User> users = new ArrayList<User>();
                for(long roleId : Onlines.getUserSession().keySet()) {
                    User user = TableLoader.getTableInstance(UserTable.class).select(roleId);
                    users.add(user);
                }

                //按经验排序
                Collections.sort(users, new Comparator<User>() {
                    @Override
                    public int compare(User o1, User o2) {
                        return o2.getExp() - o1.getExp();
                    }
                });

                StringBuilder stringBuilder = new StringBuilder();
                int count = 0;
                for(User user : users) {
                    count ++;

                    stringBuilder.append(String.format("%5d",count) );
                    stringBuilder.append(String.format("%10s",user.getNumber()));
                    stringBuilder.append(String.format("%8s",user.getName()));
                    stringBuilder.append(String.format("%4d",user.getExp()));
                    stringBuilder.append("\n");
                }

                //发送给客户端
                _SRequestRank.SRequestRank.Builder rankMsg = _SRequestRank.SRequestRank.newBuilder();
                rankMsg.setName(stringBuilder.toString());

                Onlines.send(roleId,rankMsg.build());

                return true;
            }
        }.submit();
    }
}