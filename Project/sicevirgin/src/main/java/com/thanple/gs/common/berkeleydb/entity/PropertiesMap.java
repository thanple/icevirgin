package com.thanple.gs.common.berkeleydb.entity;

import lombok.Data;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Thanple on 2017/6/3.
 */

@Data
public class PropertiesMap implements Serializable{

    //最外侧PropertiesMapTable key=>NumberIdMap,value=PropertiesMap
    public static final long NumberIdMap = 1L;    //账号和id的映射
    public static final long ID_Createor = 2L;    //id增加器
    public static final long RoleidInstanceidMap = 3L;  //角色在哪个副本id里


    //里层map的映射
    public static final int RoleId = 1;       //角色id
    public static final int InstanceId = 2;  //副本id

    private Map<Object,Object> map = new HashMap<>();

}
