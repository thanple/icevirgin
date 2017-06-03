package com.thanple.gs.common.berkeleydb;


import com.thanple.gs.app.session.user.Onlines;
import com.thanple.gs.common.berkeleydb.table.TTable;
import com.thanple.gs.common.exception.BerkeleyNotInProcedureException;
import com.thanple.gs.common.util.ExecutorUtil;
import com.thanple.gs.common.util.LockKeysUtil;
import lombok.AllArgsConstructor;
import lombok.Data;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;

/**
 * Created by Thanple on 2017/1/13.
 *
 * 每个Procedure都是一个线程，包括同步和异步，线程之间遵循可串行化事务隔离度
 */
public abstract class Procedure {

    /*
    * 责任链模式
    * 为什么要这样设计呢，
    * 设置一个Procedure集合的目的是一个Procedure里面可以嵌套多个Procedure，
    * 相当于是一个队列，按照顺序轮训调度
    * */
    private static ThreadLocal<ArrayList<Procedure>> procedureList = new ThreadLocal<ArrayList<Procedure>>(){
        protected ArrayList<Procedure> initialValue() {
            return new ArrayList<Procedure>();
        }
    };
    private static  ThreadLocal<ArrayList<Procedure>> procedureAfterCommitList = new ThreadLocal<ArrayList<Procedure>>(){
        protected ArrayList<Procedure> initialValue() {
            return new ArrayList<Procedure>();
        }
    };
    private static  ThreadLocal<ArrayList<Procedure>> procedureAfterRollBackList = new ThreadLocal<ArrayList<Procedure>>(){
        protected ArrayList<Procedure> initialValue() {
            return new ArrayList<Procedure>();
        }
    };


    /**
     * 提交时发送消息
     *
    @Data
    @AllArgsConstructor
    private static class IdAndMsg{
        private long userId;
        private Object obj;
    }
    private static ThreadLocal<ArrayList<IdAndMsg>> sendsWhileCommit = new ThreadLocal<ArrayList<IdAndMsg>>(){
        protected ArrayList<IdAndMsg> initialValue() {
            return new ArrayList<IdAndMsg>();
        }
    }; */


    //回调处理函数
    protected abstract boolean process();


    private boolean runProcedure(){
        try {

            //进入Procedure标志
            BerkeleyNotInProcedureException.beginInTheProcedure();

            //开启事务
            TransactionManager.startTransaction();

            boolean rs = this.process();
            TransactionManager.savePoint(rs);

            //更新锁住的数据（即get出来的数据）
            for(LockKeysUtil.LockItem lockItem : LockKeysUtil.getLocalLockItems()){
                TTable tTable = lockItem.getTtTable();
                Long key = lockItem.getKey();
                Serializable entityValue = lockItem.getEntity();

                if(entityValue!=null)
                    tTable.save(key,entityValue);
            }

        }catch (Exception e){
            TransactionManager.savePoint(false);    //回滚事务标志
            e.printStackTrace();
        }finally {

            //get出来的数据保存的引用全部清空
            LockKeysUtil.getLocalLockItems().clear();

            //释放keylock(这样做的好处是当前Procedure如果抛出异常也继续释放锁)
            LockKeysUtil.unlockAll();

            //提交事务(返回false时已经提交)
            boolean transactionSucess = TransactionManager.commit();
            if(transactionSucess){
                procedureAfterCommitList.get().forEach(p->{
                    p.submit();
                });
                /*sendsWhileCommit.get().forEach(Idmsg->{
                    Onlines.send(Idmsg.getUserId(),Idmsg.getObj());
                });*/

            }else{
                procedureAfterRollBackList.get().forEach(p->{
                    p.submit();
                });
            }
            procedureList.get().forEach(p->{
                p.submit();
            });

            //清除ThreadLocal数据
            procedureList.get().clear();
            procedureAfterCommitList.get().clear();
            procedureAfterRollBackList.get().clear();
            //sendsWhileCommit.get().clear();

            //离开Procedure标志
            BerkeleyNotInProcedureException.endInTheProcedure();

            return transactionSucess;
        }
    }


    public Future<Boolean> submit(){
        Future<Boolean> future = ExecutorUtil.executeFuture(()-> Procedure.this.runProcedure());
        return future;
    }

    /**
     * 同步执行函数Call，等待Procedure执行完之后执行
     * */
    public boolean call(Procedure procedure) throws ExecutionException, InterruptedException {
        return procedure.call();
    }
    public boolean call() throws ExecutionException, InterruptedException {
        return this.submit().get();
    }

    //异步执行函数,当父Procedure执行完后执行
    public void pexecute(Procedure procedure){
        procedureList.get().add(procedure);
    }

    //异步执行函数，当父Procedure提交后执行
    public void pexecuteWhileCommit(Procedure procedure){
        procedureAfterCommitList.get().add(procedure);
    }

    //异步执行函数，当父Procedure回滚后执行
    public void pexecuteWhileRollBack(Procedure procedure){
        procedureAfterRollBackList.get().add(procedure);
    }


    //提交时发送消息
    /*public static void psendWhileCommit(long userId,Object obj){
        sendsWhileCommit.get().add(new IdAndMsg(userId,obj));
    }*/

}
