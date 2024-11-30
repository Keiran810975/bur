import java.util.Scanner;
public class hello {
    public static int max(int a,int b){
        return (a>b)?a:b;
    }
    public static void main(String args[]){
        System.out.println("helloworld");
        int a=(int)1.1;
        System.out.println("a="+a);
        int b=2,c=3,d=4;
        System.out.println(a+" "+b+" "+" "+c+" "+d);
        System.out.println(a+"\n"+b);
        String s=a+"";//注释
        System.out.println(s);
        String s2="114514";
        String s3="1919810";
        //字符串强转成其他类型
        int n1=Integer.parseInt(s2);
        double n2=Double.parseDouble(s2);
        float n3=Float.parseFloat(s2);
        boolean b1=Boolean.parseBoolean("true");
        System.out.println(s2.charAt(3));//s2[3]
        System.out.println(s2+s3);
        System.out.println(1>2);
        //输入
        Scanner myScanner=new Scanner(System.in);//创建一个scanner的对象
        //String s4=myScanner.next();//输入字符串
        //int ff=myScanner.nextInt();//输入整数
        //double dd=myScanner.nextDouble();//输入double型
        //System.out.println(s4+" "+ff+" "+dd);
        //char cc=myScanner.next().charAt(0);//输入字符
        myScanner.close();
        //if(ff>=5)System.out.printf("%d\n",ff);
        //if(ff>5)System.out.println(ff);
        //else System.out.println("绷");
        for(int i=0;i<10;i++){
            System.out.print(6+" ");
        }
        System.out.println();
        int arr[]={1,2,3,4,5};
        for(int i=0;i<arr.length;i++)System.out.print(arr[i]+" ");
        System.out.println();
        int arr2[]=new int[5];
        arr2=arr;//数组直接写等号(传递的是地址)
        for(int i=0;i<arr2.length;i++)System.out.print(arr2[i]+" ");
        System.out.println();
        String shit="1234";
        if(shit.equals("1234"))System.out.println("yes");

        //类
        stu o1=new stu();
        o1.name="Keiran";
        o1.num=23373529;
        o1.score=99;
        stu o2=o1;
        System.out.println(o2.name);
        o1.speak();
        o1.beng();
        System.out.println(max(1,2));
            
        stu o3=o1.copyStu();
        System.out.println(o3.name);
        //构造器新建类的对象
        //stu o4=new stu("Lebron",23,98);
        //System.out.println(o4.name);
    }

    
}
class stu{
    String name;
    int num;
    int score;
    //构造器(可以传参不完全，只给其中部分属性赋值)
    // public stu(String s,int n,int f){
    //     name=s;
    //     num=n;
    //     score=f;
    // }
    public void speak(){
        System.out.println("不是哥们");
    }
    public void beng(){
        System.out.println(name);
    }
    public stu copyStu(){
        stu clone=new stu();
        clone.name=name;
        clone.num=num;
        clone.score=score;
        return clone;
    }
}