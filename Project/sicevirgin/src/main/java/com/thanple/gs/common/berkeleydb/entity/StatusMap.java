package com.thanple.gs.common.berkeleydb.entity;

import lombok.Data;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Thanple on 2017/6/2.
 */

@Data
public class StatusMap implements Serializable{

    public static final int task_1 = 1;
    public static final int task_2 = 2;

    private Map<Integer,Integer> statusTypeMapMap = new HashMap<>();

}
