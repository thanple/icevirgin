package com.thanple.gs.common;

import java.io.File;

/**
 * Created by Thanple on 2016/12/15.
 * 工程的常量配置文件
 */
public class Constant {

    public static class Path{

        //工程根目录
        //F:\IdeaProjects\ThinkingInWorld
        public static final String ROOT_PATH = System.getProperty("user.dir");

        //运行class目录
        // /F:/IdeaProjects/ThinkingInWorld/target/classes/
        public static final String RUN_CLASS_PATH = Thread.currentThread().getContextClassLoader().getResource("").getPath();

        //tools目录
        public static final String TOOLS_PATH = ROOT_PATH + "/tools";
        public static final String TOOL_PROTOC = TOOLS_PATH + "/protoc.exe";

        //src目录下
        public static final String SRC_ROOT_PATH = ROOT_PATH + "/src/main/java";

        //resource目录下
        public static final String RESOURCE_ROOT_PATH = ROOT_PATH + "/src/main/resources";
    }

    public static void main(String[] args) {
        System.out.println(Thread.currentThread().getContextClassLoader().getResource("").getPath());
        System.out.println(Constant.class.getClassLoader().getResource("").getPath());
        System.out.println(ClassLoader.getSystemResource("").getFile());
        System.out.println(Constant.class.getResource("").getPath());
        System.out.println(Constant.class.getResource("/").getPath()); //Class文件所在路径
        System.out.println(new File("/").getAbsolutePath());
        System.out.println(new File(System.getProperty("user.dir")).getParent());
    }

}
