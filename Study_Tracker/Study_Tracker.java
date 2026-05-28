import java.util.*;
import java.time.LocalDate;
import java.io.*;

class Study_Tracker
{
    public static void main(String A[])
    {
        Scanner sobj = new Scanner(System.in);
        StudyTracker stobj = new StudyTracker();

        System.out.println("--------------------------------------------------------------------");
        System.out.println("----------------- Welcome to Marvellous Study Tracker --------------");
        System.out.println("--------------------------------------------------------------------");

        int iChoice = 0;

        do
        {
            System.out.println("Please select appropriate option: ");
            System.out.println("1. Insert new study log");
            System.out.println("2. View all study logs");
            System.out.println("3. Export study logs to CSV file");
            System.out.println("4. Summary of study log by date");
            System.out.println("5. Summary of study log by subject");
            System.out.println("6. Exit the application");

            iChoice = sobj.nextInt();

            switch(iChoice)
            {
                // Insert new study log
                case 1 :                    
                    stobj.InsertLog();
                    break;
                
                // View all study logs
                case 2 :
                    stobj.DisplayLog();
                    break;

                // Export study logs to CSV file
                case 3 :
                
                    stobj.ExportCSV();
                    break;

                // Summary of study log by date
                case 4 :
                    stobj.SummaryByDate();
                    break;

                // Summary of study log by subject
                case 5 :
                    stobj.SummaryBySubject();
                    break;  
                    
                // Exit the application
                case 6 :
                    System.out.println("--------------------------------------------------------------------");
                    System.out.println("---------- Thank you for using Marvellous Study Tracker ------------");
                    System.out.println("--------------------------------------------------------------------");
                    break;

                default :
                    System.out.println("Please enter valid option");
                    break;

            }

        }while(iChoice != 6);   // End of do-while

        sobj.close();
    } // End of main
} // End of class program900

// DONE
class StudyTracker
{
    public ArrayList <StudyLog> Database = new ArrayList<StudyLog>();

    public void InsertLog()
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("--------------------------------------------------------------------");
        System.out.println("--------------------Enter your valid study details------------------");
        System.out.println("--------------------------------------------------------------------");

        LocalDate DateObj = LocalDate.now();

        System.out.println("Please enter the name of subject like C/C++/Java/Python");
        String sub = sobj.nextLine();

        System.out.println("Enter the time period of your study in hours");
        Double dur = sobj.nextDouble();

        sobj.nextLine();

        System.out.println("Please provide the description of your study");
        String desc = sobj.nextLine();
        
        StudyLog studyobj = new StudyLog(DateObj, sub, dur, desc);

        Database.add(studyobj);

        System.out.println("Study log gets stored succesfully");
        System.out.println("--------------------------------------------------------------------");
    }

    public void DisplayLog()
    {
        System.out.println("--------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("----------------------- Nothing to Display -------------------------");
            System.out.println("--------------------------------------------------------------------");
            return;
        }
        
        System.out.println("------------- Log Report of Marvellous Study Tracker ---------------");
        System.out.println("--------------------------------------------------------------------");

        for(StudyLog s : Database)
        {
            System.out.println(s);
        }

        System.out.println("--------------------------------------------------------------------");
    }

    public void ExportCSV()
    {
        if(Database.isEmpty())
        {
            System.out.println("--------------------------------------------------------------------");
            System.out.println("----------------------- Nothing to Export --------------------------");
            System.out.println("--------------------------------------------------------------------");
            return;
        }

        String FileName = "StudyTracker.csv";

        try(FileWriter fwobj = new FileWriter(FileName))
        {
            fwobj.write("Date,Subject,Duraction,Description\n");

            for(StudyLog s : Database)
            {
                fwobj.write(s.getDate()+","+
                            s.getSubject().replace(","," ")+","+
                            s.getDuration()+","+
                            s.getDescription().replace(","," ")+"\n");
            }

            System.out.println("Data gets exported in CSV " + FileName);
        }
        catch(Exception eobj)
        {
            System.out.println("Exception occured in CSV Handling");
        }
    }

    public void SummaryByDate()
    {
        System.out.println("--------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("------------ Nothing to Display as Database id empty ---------------");
            System.out.println("--------------------------------------------------------------------");

            return;
        }

        System.out.println("---------------- Summary by Date from Study Tracker ----------------");
        System.out.println("--------------------------------------------------------------------");

        TreeMap <LocalDate, Double> tobj = new TreeMap<LocalDate, Double>();

        LocalDate lobj = null;
        double d = 0.0;
        double old = 0.0;

        for(StudyLog sobj : Database)
        {
            lobj = sobj.getDate();
            d = sobj.getDuration();

            if(tobj.containsKey(lobj))
            {
                old = tobj.get(lobj);

                tobj.put(lobj, d+old);
            }
            else
            {
                tobj.put(lobj,d);
            }
        }

        // Display the Details as per date

        for(LocalDate ld : tobj.keySet())
        {
            System.out.println("Date : " + ld + " Total Study Duration : " + tobj.get(ld));
        }

        System.out.println("--------------------------------------------------------------------");

    }

    public void SummaryBySubject()
    {
        System.out.println("--------------------------------------------------------------------");

        if(Database.isEmpty())
        {
            System.out.println("------------ Nothing to Display as Database id empty ---------------");
            System.out.println("--------------------------------------------------------------------");

            return;
        }

        System.out.println("------------- Summary by Subject from Study Tracker ----------------");
        System.out.println("--------------------------------------------------------------------");

        TreeMap <String, Double> tobj = new TreeMap<String, Double>();

        String s = null;
        double d = 0.0;
        double old = 0.0;

        for(StudyLog sobj : Database)
        {
            s = sobj.getSubject();
            d = sobj.getDuration();

            if(tobj.containsKey(s))
            {
                old = tobj.get(s);

                tobj.put(s, d+old);
            }
            else
            {
                tobj.put(s,d);
            }
        }

        // Display the Details as per subject

        for(String str : tobj.keySet())
        {
            System.out.println("Subject : " + str + " Total Study Duration : " + tobj.get(str));
        }

        System.out.println("--------------------------------------------------------------------");


    }
}

// DONE
class StudyLog
{
    // Characteristics
    private LocalDate Date;
    private String Subject;
    private double Duration;
    private String Description;

    // Parameterized Constructor
    public StudyLog(LocalDate a, String b, Double c, String d)
    {
        this.Date = a;
        this.Subject = b;
        this.Duration = c;
        this.Description = d;
    }

    // Getter Methods
    public LocalDate getDate()
    {
        return this.Date;
    }

    public String getSubject()
    {
        return this.Subject;
    }

    public Double getDuration()
    {
        return this.Duration;
    }

    public String getDescription()
    {
        return this.Description;
    }

    @Override
    public String toString()
    {
        return Date+" | "+Subject+" | "+Duration+" | "+Description;
    }
}

