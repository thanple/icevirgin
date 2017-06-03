package com.thanple.gs.common.berkeleydb.table;

import com.sleepycat.je.Database;
import com.thanple.gs.common.berkeleydb.entity.Item;

/**
 * Created by Thanple on 2017/6/2.
 */

public class ItemTable extends TTable<Item> {
    public ItemTable(Database table) {
        super(table);
    }

}