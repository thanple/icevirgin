package com.thanple.gs.generator;

import com.thanple.gs.common.Constant;

import java.io.BufferedReader;
import java.io.File;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by Thanple on 2017/4/18.
 */

public class CreateProtocolCpp {

    /**
     * 通过执行cmd命令调用protoc.exe程序
     * protoc.exe -I=proto的输入目录 --java_out=java类输出目录 proto的输入目录包括包括proto文件
     * @param String protoFilePath proto源文件路径
     * @param String protoFile proto源文件名
     * */
    public static void createCmdProtocol(String protoFilePath , String protoFile){
        String protocExe = Constant.Path.TOOL_PROTOC;
        String strCmd = String.format("%s -I=%s --cpp_out=%s %s",
                protocExe,
                protoFilePath,
                "F:\\IdeaProjects\\icevirgin\\Project\\cicevirgin\\Classes\\protocol",
                protoFilePath+"/"+protoFile);
        //"d:/dev/protobuf-master/src/protoc.exe -I=./proto --java_out=./src/main/java ./proto/"+ protoFile;

        try {
            Process process = Runtime.getRuntime().exec(strCmd);

            //打印结果
            BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
            String str;
            while ((str = reader.readLine())!=null){
                System.out.println(str);
            }
            reader.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void main(String[] args) {
        //生成protobuff类
        for (File file : new File("F:\\IdeaProjects\\icevirgin\\Project\\protocol").listFiles()) {
            if(file.getName().endsWith(".proto")){
                createCmdProtocol(file.getParent(),file.getName());
            }

        }
    }
}
