package com.thanple.gs.app.main;

import com.thanple.gs.common.berkeleydb.DBManager;
import com.thanple.gs.common.nio.manager.NettyServerManager;
import com.thanple.gs.common.provider.ProtocolLoader;
import org.xml.sax.SAXException;

import javax.xml.parsers.ParserConfigurationException;
import java.io.IOException;

/**
 * Created by Thanple on 2017/4/20.
 */

public class GameServerMain {

    private static NettyServerManager serverManager = NettyServerManager.getInstance();
    private static DBManager dbManager = DBManager.getInstance();
    private static ProtocolLoader protocolLoader = ProtocolLoader.getInstance();

    private static void init() throws ParserConfigurationException, SAXException, IOException {
        dbManager.open();

        protocolLoader.init();

        serverManager.init();
    }

    public static void main(String[] args) {

        //初始化
        try {
            init();
        } catch (Exception e) {
            e.printStackTrace();
            return;
        }

        dbManager.close();
    }
}
