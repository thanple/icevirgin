package com.thanple.gs.common.berkeleydb.table;

import com.sleepycat.je.Database;
import com.thanple.gs.common.berkeleydb.entity.StatusMap;

/**
 * Created by Thanple on 2017/6/2.
 */

public class StatusMapTable extends TTable<StatusMap> {
    public StatusMapTable(Database table) {
        super(table);
    }
}

