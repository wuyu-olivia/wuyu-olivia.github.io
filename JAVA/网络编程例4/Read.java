package 网络编程例4;

import java.io.*;
public class Read implements Runnable {
   DataInputStream in;
   public void setDataInputStream(DataInputStream in) {
      this.in = in;
   }
   public void run() {
      double result=0;
      while(true) {
        try{
        	result=in.readDouble(); //会产生阻塞，等待服务器的输出
        	System.out.println("圆的面积:"+result);
        	System.out.print("输入园的半径(放弃请输入N):");
        }
        catch(IOException e) { 
            System.out.println("与服务器已断开"+e);
            break;
        }   
      }
   }
}