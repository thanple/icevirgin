package com.thanple.gs.generator;


import com.thanple.gs.common.Constant;
import com.thanple.gs.common.provider.ConfigConst;
import com.thanple.gs.common.util.CommonUtil;
import org.w3c.dom.Document;
import org.w3c.dom.Node;
import org.w3c.dom.NodeList;
import org.xml.sax.SAXException;

import javax.xml.parsers.DocumentBuilderFactory;
import javax.xml.parsers.ParserConfigurationException;
import java.io.*;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Thanple on 2017/1/22.
 */
public class CreateProtocol {

    /**
     * 通过执行cmd命令调用protoc.exe程序
     * protoc.exe -I=proto的输入目录 --java_out=java类输出目录 proto的输入目录包括包括proto文件
     * @param String protoFilePath proto源文件路径
     * @param String protoFile proto源文件名
     * */
    public static void createCmdProtocol(String protoFilePath , String protoFile){
        String protocExe = Constant.Path.TOOL_PROTOC;
        String strCmd = String.format("%s -I=%s --java_out=%s %s",
                protocExe,
                protoFilePath,
                Constant.Path.SRC_ROOT_PATH,
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

    public static void createUserProtocol(String createPackage,String userdictionaryPath, String userPackagez,String className){
        File dictionary = new File(userdictionaryPath);
        if(!dictionary.exists())   dictionary.mkdirs();
        try {
            //只生成一次，避免覆盖
            File file = new File(userdictionaryPath + "/" + className + ".java");
            if (file.exists())  return;

            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(
                    new FileOutputStream(file)));

            StringBuilder builder = new StringBuilder();
            builder.append("package ").append(userPackagez).append(";\n\n");

            //注释
            builder.append("/**").append("\n");
            builder.append(" * auto created by CreateProtocol").append("\n");
            builder.append(" * ").append(new SimpleDateFormat("yyyy-MM-dd HH:mm:ss").format(new Date())).append("\n");
            builder.append(" * */").append("\n\n");

            //类
            builder.append("public class ").append(className)
                    .append(" extends ").append("\n")
                    .append("       com.thanple.gs.common.nio.manager.Protocol").append("\n")
                    .append("               ").append("<").append(createPackage)
                    .append("._"+className).append("."+className).append(">{").append("\n\n");
            //构造函数
            builder.append("    public ").append(className).append("(").append("\n")
                    .append("           ").append(createPackage)
                    .append("._"+className).append("."+className).append(" msg")
                    .append("){").append("\n");
            builder.append("        super(msg);").append("\n");
            builder.append("    }").append("\n\n");

            //process方法
            builder.append("    @Override\n");
            builder.append("    public void process(io.netty.channel.ChannelHandlerContext ctx) {\n");
            builder.append("\n");
            builder.append("    }\n");
            builder.append("}");

            writer.write(builder.toString());
            writer.close();
        }catch (IOException e) {
            e.printStackTrace();
        }
    }


    public static void main(String[] args) throws ParserConfigurationException, IOException, SAXException {

        //从大工程的目录下复制文件到resources下
        for(File file : new File("F:\\IdeaProjects\\icevirgin\\Project\\protocol").listFiles()){
            if(file.getName().endsWith(".proto")){
                Files.copy(Paths.get(file.getPath()),
                        new FileOutputStream(new File(Constant.Path.RESOURCE_ROOT_PATH+"/protobuf/"+file.getName())));
            }else if(file.getName().endsWith(".protocol.xml")){
                Files.copy(Paths.get(file.getPath()),
                        new FileOutputStream(new File(Constant.Path.RESOURCE_ROOT_PATH+"/"+file.getName())));
            }

        }

        System.out.println("复制完毕...");

        //生成protobuff类
        for (File file : new File(Constant.Path.RESOURCE_ROOT_PATH + "/protobuf").listFiles()) {
            createCmdProtocol(Constant.Path.RESOURCE_ROOT_PATH+"/protobuf",file.getName());
        }
        System.out.println("生成Protobuff类完毕...");


        //根据生成的协议类生成自定义的协议类
        //key=>protocolName , value=>userProtocolClasName
        Map<String,String> classMap = new HashMap<>();
        Document document = DocumentBuilderFactory.newInstance().newDocumentBuilder().parse(new File(ConfigConst.USER_PROTOCOL_PROPERTIES_PATH));
        Node root = document.getFirstChild();
        NodeList protocols = root.getChildNodes();
        for(int i=0,len=protocols.getLength(); i<len; i++){
            if(protocols.item(i).getNodeName().equals("Protocol")){
                String userCls = protocols.item(i).getTextContent().trim();
                String classzName = userCls.substring(userCls.lastIndexOf(".")+1,userCls.length());

                classMap.put(classzName,userCls);
            }
        }

        File protoDic = new File(Constant.Path.RESOURCE_ROOT_PATH + "/protobuf");
        for (File each : protoDic.listFiles()){
            String fileName = each.getName();
            if(fileName.endsWith(".proto")){

                //生成业务协议java文件
                String fileNameWithoutPro = each.getName().substring(0,each.getName().indexOf(".proto"));
                if(!classMap.containsKey(fileNameWithoutPro))   continue;
                String userCls = classMap.get(fileNameWithoutPro);

                String packagez = CommonUtil.getPackageByClassName(userCls);
                String simpleCls = CommonUtil.getSimpleNameByClassName(userCls);
                String dic = CommonUtil.getDitionaryByPackage(packagez);

                createUserProtocol(ConfigConst.CREATE_PROTOCOL_PACKAGE,dic,packagez,simpleCls);

            }
        }

        System.out.println("生成自定义协议类完成...");

    }

}
