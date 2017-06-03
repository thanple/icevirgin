package com.thanple.gs.app.chat.toast;

import com.thanple.gs.app.session.user.ISession;
import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.app.session.user.Session;
import com.thanple.gs.common.nio.manager.Protocol;
import com.thanple.gs.common.nio.protocol._SToastMsg;
import io.netty.channel.ChannelHandlerContext;

/**
 * Created by Thanple on 2017/5/31.
 */

public class ToastUtil {

    /**
     * 弹出Toast提示
     * */
    public static void show(ChannelHandlerContext ctx, String msg) {
        _SToastMsg.SToastMsg.Builder toast = _SToastMsg.SToastMsg.newBuilder();
        toast.setMsg(msg);
        Protocol.send(ctx,toast.build());
    }

    public static void show(long roleId,String msg) {
        ISession session = Onlines.getUserSession().get(roleId);
        _SToastMsg.SToastMsg.Builder toast = _SToastMsg.SToastMsg.newBuilder();
        toast.setMsg(msg);
        session.writeChanel(toast.build());
    }
}
