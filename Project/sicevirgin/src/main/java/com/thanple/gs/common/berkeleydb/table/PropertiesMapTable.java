package com.thanple.gs.common.berkeleydb.table;

import com.sleepycat.je.Database;
import com.thanple.gs.common.berkeleydb.entity.PropertiesMap;

/**
 * Created by Thanple on 2017/6/3.
 */

public class PropertiesMapTable extends TTable<PropertiesMap> {
    public PropertiesMapTable(Database table) {
        super(table);
    }

}