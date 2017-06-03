package com.thanple.gs.app.task.msg;

import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;
import com.thanple.gs.common.berkeleydb.Procedure;
import com.thanple.gs.common.berkeleydb.entity.StatusMap;
import com.thanple.gs.common.berkeleydb.table.StatusMapTable;
import com.thanple.gs.common.nio.protocol._SRequestTaskStatus;
import com.thanple.gs.common.provider.TableLoader;

import java.util.Map;
import java.util.concurrent.ConcurrentHashMap;

/**
 * auto created by CreateProtocol
 * 2017-06-02 14:48:52
 * */

public class CRequestTaskStatus extends 
       com.thanple.gs.common.nio.manager.Protocol
               <com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus>{

    public CRequestTaskStatus(
           com.thanple.gs.common.nio.protocol._CRequestTaskStatus.CRequestTaskStatus msg){
        super(msg);
    }

    @Override
    public void process(io.netty.channel.ChannelHandlerContext ctx) {

        final long roleId = Onlines.findUserId(new Session(ctx));
        if(roleId<0){
            return;
        }

        new Procedure() {
            @Override
            protected boolean process() {

                StatusMapTable table = TableLoader.getTableInstance(StatusMapTable.class);
                StatusMap statusMap = table.get(roleId);
                if(statusMap == null) {
                    statusMap = new StatusMap();
                    table.insert(roleId,statusMap);
                }
                Integer status = statusMap.getStatusTypeMapMap().get(protocolBean.getType());

                if(status == null) {
                    status = 0;
                    statusMap.getStatusTypeMapMap().put(protocolBean.getType(),status);
                }

                _SRequestTaskStatus.SRequestTaskStatus.Builder builder = _SRequestTaskStatus.SRequestTaskStatus.newBuilder();
                builder.setStatus(_SRequestTaskStatus.SRequestTaskStatus.Status.valueOf(status));
                builder.setType(protocolBean.getType());

                Onlines.send(roleId,builder.build());

                if(status == 0) {
                    statusMap.getStatusTypeMapMap().put(protocolBean.getType(),1);
                }


                return true;
            }
        }.submit();
    }
}