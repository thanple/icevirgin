package com.thanple.gs.app.session.login;

import lombok.Data;

/**
 * Created by Thanple on 2017/4/20.
 */

public interface ILogin {

    @Data
    public static class Result{
        boolean isSuccess;
        String msg;
    }

    Result login(String uniq,String pass);
}
