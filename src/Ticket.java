import java.util.ArrayList;
import java.util.List;

public class Ticket{
    @CsvBindByName
    private String A;
    @CsvBindByName
    private String T;
    @CsvBindByName
    private String Entered;
    @CsvBindByName
    private String Phone;
    @CsvBindByName
    private String Hash;

    String getA(){
        return this.A;
    }
    String getT(){
        return this.T;
    }
    String getEntered(){
        return this.Entered;
    }
    String getPhone(){
        return this.Phone;
    }
    String getHash(){
        return this.Hash;
    }

    void setA(String setA){
        this.A = setA;
    }
    void setT(String setT){
        this.T = setT;
    }
    void setEntered(String setEntered){
        this.Entered = setEntered;
    }
    void setPhone(String setPhone){
        this.Phone = setPhone;
    }
    void setHash(String setHash){
        this.Hash = setHash;
    }
    
    static Ticket lookUpHash(String Hash, List<Ticket> ticketList){
        for(Ticket temp : ticketList){
            if(temp.getHash().equals(Hash)){
                return temp;
            }
        }
        throw new Exception("Ticket does not exist.");
    }

    public static void main(String[] args) {
        List<Ticket> ticketList = new ArrayList<Ticket>();
        CSVReader reader = new CSVReader(new FileReader("list.csv"));
        String[] nextLine;

        String testHash = new String("SDTSR19BJCN15JULA01T1");

        while ((nextLine = reader.readNext()) != null) {
            Ticket temp = new Ticket();
            temp.setA(nextLine[0]);
            temp.setT(nextLine[1]);
            temp.setEntered(nextLine[2]);
            temp.setPhone(nextLine[3]);
            temp.setHash(nextLine[4]);

            ticketList.add(temp);
        }

        //sample usage
        try {
            System.out.println("Phone number: " + lookUpHash(testHash, ticketList).getPhone());
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }

    }
}