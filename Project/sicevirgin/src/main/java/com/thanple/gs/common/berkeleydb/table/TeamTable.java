package com.thanple.gs.common.berkeleydb.table;

import com.sleepycat.je.Database;
import com.thanple.gs.common.berkeleydb.entity.Team;

/**
 * Created by Thanple on 2017/1/17.
 */
public class TeamTable extends TTable<Team> {
    public TeamTable(Database table) {
        super(table);
    }

}
