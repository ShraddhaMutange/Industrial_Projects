// Packing Final Code

import java.io.*;
import java.util.*;

class program606
{
    public static void main(String A[]) throws Exception
    {
        String Header = null;

        byte Key = 0x11;

        int iRet = 0;
        int i = 0, j = 0;

        byte Buffer[] = new byte[1024];     // Badlitun mug
        byte bHeader[] = new byte[100];

        Scanner keyboard = new Scanner(System.in);

        System.out.println("Enter the name of folder : ");
        String folderName = keyboard.nextLine();

        System.out.println("Enter the name of packed file : ");
        String packName = keyboard.nextLine();

                           // Folder's name
        File folderobj = new File(folderName);

        if((folderobj.exists()) && (folderobj.isDirectory()))
        {
            File packobj = new File(packName);

            packobj.createNewFile();

            FileOutputStream foobj = new FileOutputStream(packobj);

            FileInputStream fiobj = null;

            System.out.println("Folder is present");

            File fArr[] = folderobj.listFiles();

            System.out.println("Number of files in the folder are : " + fArr.length);

            for(i = 0; i < fArr.length; i++)
            {
                fiobj = new FileInputStream(fArr[i]);

                if(fArr[i].getName().endsWith(".txt"))
                {
                    // Header Formation
                    Header = fArr[i].getName() + " " + fArr[i].length();

                    for(j = Header.length(); j < 100; j++)
                    {
                        Header = Header + " ";
                    }

                    bHeader = Header.getBytes();

                    // Write header into pack file
                    foobj.write(bHeader, 0, 100);
                    
                    // Read the data from input files from Marvellous folder
                    while((iRet = fiobj.read(Buffer)) != -1)
                    {
                        // Encryption logic
                        for(j = 0; j < iRet; j++)
                        {
                            Buffer[j] = (byte)(Buffer[j] ^ Key);
                        }

                        // Write the file's data into pack file
                        foobj.write(Buffer, 0, iRet);
                    }
                }                

                fiobj.close();
            }

            foobj.close();
        }
        else
        {
            System.out.println("There is no such folder");
        }

        keyboard.close();
    }
}