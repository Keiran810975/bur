public class hello2 {
    public static int sum(int... nums){
        int sum=0;
        for(int i=0;i<nums.length;i++)sum+=nums[i];
        return sum;
    }
    public static double sum(double... nums){
        double sum=0;
        for(int i=0;i<nums.length;i++)sum+=nums[i];
        return sum;
    }
    public static void main(String[] args) {
        System.out.println(sum(1,2,3,4,5.5,6,8));
        cat c=new cat("哈基米", 1);
        //dog d=new dog("旺财", 2);
        //System.out.println(c.name+" "+d.name);
        c.pr();
        cat cc=new cat();
        cc.pr();
        
    }
}
class cat{
    String name;
    int age;
    public cat(String name,int age){
        this.name=name;
        this.age=age;
    }
    public cat(){
        this("kat",114514);
    }
    public void pr(){
        System.out.println(name+" "+age);
    }
}
class dog{
    String name;
    int age;
    
}