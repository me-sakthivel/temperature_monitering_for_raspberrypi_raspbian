#include<iostream>
#include<unistd.h>
#include<string>
#include<cstdio>
#include<cstring>

int main()
{
const char* command = "cat /sys/class/thermal/thermal_zone0/temp";
char buffer[55];
std::string str;
int temp;
while(1)
{
FILE* pipe = popen(command, "r");
    if (!pipe) {
        std::cout << "Error" << std::endl;
        return 1;
    }

    // Read the output from the FILE
    while (fgets(buffer, 100, pipe) != nullptr) {
        str = str + buffer;
    }
    std::cout<<str;

     temp = stoi(str);

      if(temp >= 70000)
    {
          for(int i=0;i<5;i++)
          std::cout<<"\n WARNING TEMPRATURE MORE THAN "<<temp<<std::endl;
          sleep(5);


          system("sudo shutdown -h now");

     }

    // Close the FILE
    pclose(pipe);
    str = "";
    for(int i=0;i<55;i++)
    {
            buffer[i] = '\0';
    }
    sleep(5);
}

}
