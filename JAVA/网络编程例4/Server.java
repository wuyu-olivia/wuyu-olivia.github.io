package ��������4;

import java.io.*;
import java.net.*;
import java.util.*;
public class Server {
   public static void main(String args[]) {
      ServerSocket server=null;
      ServerThread thread;
      Socket you=null;
      while(true) {
        try{  server=new ServerSocket(8080);
        }
        catch(IOException e1) { 
              System.out.println("���ڼ���"); //ServerSocket�������ظ�����
        } 
        try{  System.out.println(" �ȴ��ͻ�����");
              you=server.accept();
              System.out.println("�ͻ��ĵ�ַ:"+you.getInetAddress());
        } 
        catch (IOException e) {
              System.out.println("���ڵȴ��ͻ�");
        }
        if(you!=null) { 
              new ServerThread(you).start(); //Ϊÿ���ͻ�����һ��ר�ŵ��߳�  
        }
      }
   }
}
class ServerThread extends Thread {
   Socket socket;
   DataOutputStream out=null;
   DataInputStream  in=null;
   String s=null;
   ServerThread(Socket t) {
      socket=t;
      try {  out=new DataOutputStream(socket.getOutputStream());
             in=new DataInputStream(socket.getInputStream());
      }
      catch (IOException e){}
   }  
   public void run() {        
      while(true) {
         try{
        	 double r=in.readDouble();//����״̬�����Ƕ�ȡ����Ϣ
        	 double area=Math.PI*r*r;
        	 System.out.println("���ڼ���뾶Ϊ"+r+"��Բ���");
        	 Thread.sleep(5000);
        	 out.writeDouble(area);
        	 System.out.println("����������ѷ��͸��ͻ���");
        	 
        	 
         }
         catch (IOException e) {
               System.out.println("�ͻ��뿪");
                return;
         } catch (InterruptedException e) {
			// TODO �Զ����ɵ� catch ��
			e.printStackTrace();
		}
      }
   } 
}
