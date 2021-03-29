# Railway-Track-Crack-Detection-Robot
# Abstract:
An automatic railway track crack detector system for Indian Railway has been proposed here which aims in building a robot that can detect and analyse any kind of crack on the railway line and send the coordinates of that faulty line to the concerned authority. This robot includes an ultrasonic sensor, GPS, GSM modules, and Arduino Mega based crack detection assembly which is cost effective and robust to facilitate better safety standards in railways. As soon as the robot passes through a crack that might cause the derailment of a train, the ultrasonic sensors sense that and generate a signal. Then this signal is fed into the Arduino Mega. At that point, with the assistance of GSM and GPS modules, an alert SMS consisting of the geographic coordinate of that damaged track is sent to the nearby railway authority who can easily take necessary steps to resolve the problem before any major accident occurs. This will save several trains in India from an unwanted discontinuity from the rail track.

# Introduction: 
Safety and reliability are considered one of the main issues in all transport system, particularly in railways. There is a view from the experts that the present regulatory framework does not clarify effective deal with railway accidents and derailments, approximately 60% of a rail accident is due to the derailment, of which 90% are due to crack problems [1].

India has 164 years of great history of railway network. The first train in India was started on 16th April 1853, Saturday at 3:35 P.M. between Bori bunder to Belgaum. India has world’s top largest railway network. Its length is 1, 19, 630 Km of total track and running route is 66,687 km with 7216 stations. In India billions of passengers are traveling in railway. So, it is necessary to provide safety and reliability of railway network. According to newspaper 90% of railway accidents are occur due to railway track fault. Generally, railway track fault occurs due to natural climates or any other mechanical damage. This promotes railway accidents and damage railways and human lives. In recent years developing country like India needs more diversification and innovation in the transportation system. With the increasing number of the population the current safety framework needs to be equipped with safety legislation and more invulnerable. Safe railway track plays a significant role to carry more than sixty thousand people at a time. Therefore, a consistent system is required to detect the cracks in the railway tracks.

So, for reduction of railway accidents we came up with an idea. By using an autonomous railway track crack detection device, we can reduce railway accidents and save people life. 

# Proposed System:
In this project, a cost- effective autonomous railway crack detector robot is proposed for Indian railway. This device can generate a complete solution for the railway track that starts with crack detection, fault analysis using ultrasonic sensor and that end up with an SMS alert to the concerned authority which consists of the location of the crack. Therefore, making it easier to prevent accidents.
![image](https://user-images.githubusercontent.com/78199382/112831259-52eff200-90b1-11eb-951b-81bc128245ac.png)

# Architecture of the System:
The proposed crack detector robot is a microcontroller based low-cost intelligent device. The cracks in the railway track can be sensed by using ultrasonic sonic waves. This sensor is connected to Arduino Mega which is the central control unit of this project. A DC geared motor is used to move the wheels on the track. A motor driver circuit that passes commands to the dc gear motor and two wheels run the robot. The chassis of this prototype robot is made with the cardboard material. This device also has a feature of sending the location information using GPS and about the fault via SMS alert using a GSM module. An LCD display is connected with Arduino Mega to print the real-time crack status. In fig.3 the block diagram of this robot is given. The complete schematic diagram and Breadboard view is provided in fig.4 and fig.5. Afterwards, a complete description of the system components is provided.

![image](https://user-images.githubusercontent.com/78199382/112831337-6ac77600-90b1-11eb-87a2-89e9601a7d26.png)

# Result and Discussion:
The flow chart of the process is given. As soon as the robot is put on the railway track it starts the inspection.  If any crack is found on rail lines the robot stops and sends the location coordinates to the authority so that they can take essential steps. The robot continues its crack detection if no crack is found. A complete hardware is shown in the figure

![image](https://user-images.githubusercontent.com/78199382/112831552-bda12d80-90b1-11eb-895c-db0fc1b9cd9a.png)

![image](https://user-images.githubusercontent.com/78199382/112831578-c72a9580-90b1-11eb-9335-ff6c2ff78832.png)

The designed robot is kept on a dummy railway track made of plastic. In that track, we have considered the crack as the end point of the track where there is nothing present it is made to clarify the results. In Table 1 real-time status on LCD display and SMS alert on a cell phone are shown. As soon as the crack is detected the GPS location is sent to the cell phone via SMS alert.

![image](https://user-images.githubusercontent.com/78199382/112831617-d7db0b80-90b1-11eb-9e32-13882189ddf0.png)





