package com.thanple.gs.app;

import com.thanple.gs.common.berkeleydb.DBManager;
import com.thanple.gs.common.nio.manager.NettyServerManager;
import com.thanple.gs.common.provider.ProtocolLoader;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;

/**
 * Created by Thanple on 2017/1/20.
 */
public class NIOServerDemo1 {

    private static NettyServerManager serverManager = NettyServerManager.getInstance();
    private static DBManager dbManager = DBManager.getInstance();

    public static void main(String[] args) throws ParserConfigurationException, SAXException, IOException {
        dbManager.open();

        //协议文件初始化
        ProtocolLoader.getInstance().init();

        serverManager.init();

        dbManager.close();
    }
}
