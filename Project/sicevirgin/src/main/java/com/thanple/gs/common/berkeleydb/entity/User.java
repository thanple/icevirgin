package com.thanple.gs.common.berkeleydb.entity;

import lombok.Data;
import lombok.ToString;

import java.io.Serializable;

/**
 * Created by Thanple on 2017/1/17.
 */
@Data
public class User implements Serializable {
    private long id;
    private String name;
    private String number;  //账号
    private String password;    //密码


    private int body;   //角色
    private int hair;   //发型
    private int weapon; //武器

    private int money;  //金钱
    private int nskills;    //技能点

    private int exp;    //经验

}
