package com.thanple.gs.app.user;

import java.util.ArrayList;
import java.util.List;

/**
 * Created by Thanple on 2017/6/2.
 */

public final class UserConst {

    public static final int PLAYER_11001 = 11001;
    public static final int PLAYER_11002 = 11002;
    public static final int PLAYER_12001 = 12001;
    public static final int PLAYER_12002 = 12002;
    public static final int PLAYER_13001 = 13001;
    public static final int PLAYER_13002 = 13002;
    public static final int PLAYER_14001 = 14001;
    public static final int PLAYER_14002 = 14002;
    public static final int PLAYER_15001 = 15001;
    public static final int PLAYER_15002 = 15002;
    public static final int PLAYER_16001 = 16001;
    public static final int PLAYER_16002 = 16002;

    public static final List<Integer> bodys = new ArrayList<>();
    static {
        bodys.add(PLAYER_11001);
        bodys.add(PLAYER_11002);
        bodys.add(PLAYER_12001);
        bodys.add(PLAYER_12002);
        bodys.add(PLAYER_13001);
        bodys.add(PLAYER_13002);
        bodys.add(PLAYER_14001);
        bodys.add(PLAYER_14002);
        bodys.add(PLAYER_15001);
        bodys.add(PLAYER_15002);
        bodys.add(PLAYER_16001);
        bodys.add(PLAYER_16002);
    }


    public static final int Hair_10001 = 10001;
    public static final int Hair_10002 = 10002;
    public static final int Hair_11001 = 11001;
    public static final int Hair_11002 = 11002;
    public static final int Hair_12001 = 12001;
    public static final int Hair_12002 = 12002;
    public static final List<Integer> hairs = new ArrayList<>();

    static {
        hairs.add(Hair_10001);
        hairs.add(Hair_10002);
        hairs.add(Hair_11001);
        hairs.add(Hair_11002);
        hairs.add(Hair_12001);
        hairs.add(Hair_12002);
    }


    public static final int Weapon_10000 = 10000;
    public static final int Weapon_11000 = 11000;
    public static final int Weapon_12000 = 12000;
    public static final int Weapon_13000 = 13000;
    public static final int Weapon_14000 = 14000;
    public static final int Weapon_15000 = 15000;

    public static final List<Integer> weapons = new ArrayList<>();
    static {
        weapons.add(Weapon_10000);
        weapons.add(Weapon_11000);
        weapons.add(Weapon_12000);
        weapons.add(Weapon_13000);
        weapons.add(Weapon_14000);
        weapons.add(Weapon_15000);
    }

}
