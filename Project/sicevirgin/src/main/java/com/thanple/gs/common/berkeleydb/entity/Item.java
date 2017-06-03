package com.thanple.gs.common.berkeleydb.entity;

import lombok.Data;

import java.io.Serializable;
import java.util.HashMap;
import java.util.Map;

/**
 * Created by Thanple on 2017/6/2.
 */

@Data
public class Item implements Serializable {

    //key = itemId , value = count
    private Map<Integer,Integer> items = new HashMap<>()   ;
}
