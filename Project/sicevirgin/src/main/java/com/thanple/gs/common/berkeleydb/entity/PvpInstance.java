package com.thanple.gs.common.berkeleydb.entity;

import lombok.Data;

import java.io.Serializable;

/**
 * Created by Thanple on 2017/6/9.
 */

@Data
public class PvpInstance implements Serializable{

    @Data
    public static class RoleProperty implements Serializable{
        private long roleId;
        private int blood = 100;

        public static RoleProperty createRole(long roleId) {
            RoleProperty roleProperty = new RoleProperty();
            roleProperty.setRoleId(roleId);
            return roleProperty;
        }
    }

    private RoleProperty role1;
    private RoleProperty role2;

    private int count = 0;  //房间人数
}
