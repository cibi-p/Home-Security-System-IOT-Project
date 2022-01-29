# Home-Security-System-IOT-Project
1.1 INTRODUCTION 

Home is the place where we live, kept our valuable things, it has our loved ones and it is the part of us in our daily life. But the security for the home is less now a days. We need a security system for our Home to safe our things. To avoid this, we are introducing a project called Home Security System This Home Security System is compact box which will be attached to the door and connected to the door lock. If the someone wants to open the door lock to get into the home, they first need to verify their identity by scanning their finger on their phone under the app that we created. Suppose if the phone does not have the finger print sensor, then they need to enter the password to open the door lock. If the identity is matched then the app will send open signal with RFID to the home security system. Then the system checks the RFID and it will open the door lock. This acts as a two-factor authentication for our home. 

1.2 PROBLEM OF STATEMENT 

Security is the main thing to safeguard our things. In today scenario thief’s and theft are increased due to the loss of security. Due to that loss of security some people losses their money, jewellery, and more. So, we need a system which authenticate us and verify our identity to open the door and we need to know when someone hitting or destroying our door. When this happens, we need a system to tell us that some one hitting or destroying the door. And also, we need to make that system at affordable price to reach the all people. To solve this all problem, we come up with the solution called home security system 

1.3 AIM OF THE PROJECT 

Aim of the Project is to give the consumers, a 2nd layer of the security system for their home to safeguard their valuable things. This project provides us a two-factor authentication for our Home. 2 

1.4 MOTIVATION 

Security is necessary in Home. Our goal is to give a dual layer security to house at affordable price. We get inspired on phone's two-factor authentication system. We think why don’t we do project regarding providing two-factor authentication n on house door. Two-factor authentication means to get access to something, we need to verify our identity in case of phone we get verified either via Phone number or email ID. But here in this project we verify the Reference ID which is the unique ID that will be programmed in Microcontroller and finger print. First, we have the idea to buy the Fingerprint sensor, then we look at the Price of fingerprint sensor which Rs.1000+. Then we noticed that, most of the people have the phone with fingerprint sensor, then we decide Why don’t we design a app to access the fingerprint sensor in phone and send the signal to microcontroller to open door from the app. This idea will minimize the cost of our product in market. Using this technique, we can safeguard our sweet home.


EXPLANATION

Here you can see in figure 2.1 is a block diagram that NodeMCU is connected to
Vibration sensor, Wi-Fi module, Servo motor, Switch and power source. For first time use,
user need to register and create password for their product with the unique reference ID allotted
to that product. The created password and reference ID will get stored on CloudDB. To open
the door, user should turn on the data transfer and click scan button on the app that we created
using the MIT app inventor and they need to scan their fingerprint. If the fingerprint is matched
it will send the Open() signal along with the reference id to NodeMCU. Then the Arduino
checks if the Reference Id matches or not. If it matches then it will open the door lock using
the servo motor. Then it wait for if the button is become '0' if it became '0' NodeMCU send
door_opened() function to app, then the app will save that information with time in CloudDB.
If button become '1' NodeMCU send door_closed() signal to app this also will get saved in
cloudDB. We can get this info later whenever we want. Mean While if the strong vibration is
produced in the door. NodeMCU decide it as someone destroying the door and send Alert() to
the app.
Figure 2.1-Block diagram

![image](https://user-images.githubusercontent.com/57592824/151653224-73712a00-d990-4bce-a3e9-0e54e75fc11a.png)

Screens of the APP Made using MIT APP INVENTOR for this home securit Project

![image](https://user-images.githubusercontent.com/57592824/151653503-e082315c-1115-4a09-9016-442a1b4998b1.png)

![image](https://user-images.githubusercontent.com/57592824/151653515-d6df231e-8c91-401c-98ac-fb5c36140c12.png)




