package com.thanple.gs.common.berkeleydb.table;

import com.sleepycat.je.Database;
import com.thanple.gs.common.berkeleydb.entity.FightMonsterInstance;

/**
 * Created by Thanple on 2017/6/1.
 */

public class FightMonsterInstanceTable extends TTable<FightMonsterInstance> {
    public FightMonsterInstanceTable(Database table) {
        super(table);
    }

}