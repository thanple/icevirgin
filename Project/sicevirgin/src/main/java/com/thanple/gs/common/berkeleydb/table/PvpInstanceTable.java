package com.thanple.gs.common.berkeleydb.table;

import com.sleepycat.je.Database;
import com.thanple.gs.common.berkeleydb.entity.PvpInstance;

/**
 * Created by Thanple on 2017/6/9.
 */

public class PvpInstanceTable extends TTable<PvpInstance> {
    public PvpInstanceTable(Database table) {
        super(table);
    }


}
